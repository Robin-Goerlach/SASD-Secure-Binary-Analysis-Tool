# Architecture – SASD Binary Insight

**Product:** SASD Secure Binary Analysis Tool  
**Working/UI name:** SASD Binary Insight  
**Baseline:** 2026-10-08  
**Status:** pre-implementation architecture baseline

> This document is the English architecture companion. The detailed German architecture document is currently the authoritative descriptive baseline; technology choices remain subject to ADRs.

## Architectural goal

Build a secure, read-only-first and UI-independent binary-analysis platform that can inspect large data sources efficiently and turn byte-level observations into reproducible, versioned engineering knowledge.

## Core drivers

- read-only analysis by default;
- large files without full RAM loading;
- one analysis core for desktop UI, later CLI/TUI and automation;
- evidence/confidence as domain concepts;
- persistent, versioned analysis projects;
- local-first operation without mandatory cloud or telemetry;
- robust handling of malformed/truncated input;
- modular Executable, Crypto/Vault, Disk/FileSystem, Plugin and Editing capabilities;
- reuse behind explicit adapters and licence review;
- deterministic testability without a GUI.

## Layering

```text
Hosts / Presentation
        ↓
Application / Use Cases
        ↓
Domain / Analysis Model
        ↑
Ports / Interfaces
        ↑
Infrastructure / Adapters
```

Dependencies point inward. Domain code must not depend on GUI technology, OS file APIs, serialization frameworks, network services or concrete third-party engines.

## Main architecture

```text
Desktop UI / later CLI / optional TUI
                │
Application Services / Commands
                │
Project | Search | Pattern | Format | Validation | Report
                │
Analysis Model / Evidence / Provenance
                │
ByteProvider / Address Space / Cache / Transform Streams
                │
File | later Disk Image | Device | Vault | Future Sources
```

## ByteProvider

The ByteProvider is the primary I/O boundary. It provides 64-bit-capable, read-only random access without assuming that the source is memory resident. Higher-level scanners operate in chunks and must correctly handle matches across chunk boundaries. Cache policy is an optimisation and must not affect semantic results.

V1 starts with file offsets. The address model must later support virtual addresses, sectors/LBAs and transformed logical streams.

## Analysis model

Core domain concepts include `ByteRange`, `Address`, `AddressSpace`, `AnalysisFinding`, Evidence/Confidence, Provenance, Bookmark, Annotation, FormatDefinition, ParsedField, ValidationFinding and AnalysisProject.

Confidence is explicitly represented as Confirmed, Strong, Probable, Heuristic or Unknown. Automated findings retain their rule/source/version so reports never silently detach a claim from its provenance.

## Analysis pipeline

```text
Byte Source
   ↓
ByteProvider / Cache
   ↓
Search · Strings · Patterns · Decoding · Entropy · Format Parsing
   ↓
Evidence + Provenance
   ↓
Structure + Annotation
   ↓
Validation
   ↓
Project
   ↓
Report / later Diff / CLI / Automation
```

Observation is not automatically fact. Validation and evidence determine how strongly an interpretation may be presented.

## Format and validation

V1 deliberately uses a limited declarative format model: names, offsets, primitive types, lengths, endianness, descriptions, enums, fixed/magic values, simple arrays, nesting and basic validation. Parsing and validation remain separate. Parsers read only through the ByteProvider, enforce bounds and return diagnostics for malformed input.

## Projects

The analysis project is a knowledge artifact, not a copy of the analysed source. It stores source identity/fingerprint, bookmarks, annotations, relevant findings, format/pattern references and required analysis context. It does not store passwords, keys or unnecessary sensitive payload copies. Project format and migration are decided by ADR-004.

## Long-running work

Search, string/pattern scans, hashing, entropy, parsing, validation, diff and reporting are cancellable operations. They must not block the UI thread, must bound resource consumption and must define progress/error/partial-result semantics.

## Security boundaries

All analysed data is untrusted. Parsers check bounds/overflow, limit allocation and recursion, distrust embedded lengths and never execute embedded scripts automatically. V1 has no general write path. Plugins/scripting, Vault, physical devices and Controlled Editing are separate future trust boundaries with their own ADRs and permission/safety models.

## Modules and evolution

```text
V1 Core
├─ ByteProvider + Cache
├─ Search / Strings / DataDecoder
├─ Pattern + Evidence
├─ Format + Validation
├─ Project
├─ Hash / Entropy
└─ Reporting

V1.1  Diff + CLI
V1.2  richer Format Workbench / Structure Diff
V1.5  Kaitai / Extensibility
V2.0  Executable + Disassembly
V2.5  CryptoAnalysis + VaultIntegration
V3.0  DiskImage + Partition + FileSystem
V3.5  Scripting + PluginHost
V4.0  Controlled Editing
V5+   Recovery / Repair
```

Later modules must not make the V1 core depend on their technology stacks.

## Testing as architecture

The design requires unit tests for ranges/decoding/evidence/validation, boundary/property tests for page/chunk and malformed input, integration tests for provider/scanner/project/report flows, deterministic golden fixtures, 1 GB/10 GB performance tests and security regressions.

## Implementation baseline

The initial Phase-0 implementation uses a C++20 core built with CMake. The
repository keeps language-specific modules separate; future languages integrate
through an explicit ABI, process protocol or reviewed binding. This does not
make the Domain/Core dependent on a UI or another language runtime.

## ADR boundary

ADR-001 establishes the initial C++20/CMake core platform. The architecture
does not yet decide GUI toolkit, storage syntax or third-party engines.
ADR-002 through ADR-010 cover GUI, ByteProvider, project format, format
definitions, pattern packs, evidence, hashes/checksums, reporting and
dependency/licence policy. Later ADRs cover disassembly, Vault/secure buffers
and disk/device access.

## Architecture invariants

- V1 source access is read-only.
- Domain is independent of UI.
- Long operations never block the UI.
- Large sources do not require full loading.
- Parsers use abstract byte access and enforce bounds.
- Heuristics are never presented as proven facts.
- Findings preserve provenance.
- Projects contain no secrets.
- Opening a source/project never implicitly executes foreign code.
- Risky future modules do not silently enter the V1 core.
- GUI and later CLI use the same application use cases.

For component responsibilities, security boundaries, persistence, reporting, performance, testing and the Phase-0 architecture completion criteria, see the [detailed German architecture](../../de/architecture/ARCHITEKTUR.md).
