# SASD Secure Binary Analysis Tool

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
![Status](https://img.shields.io/badge/status-planning%20%2F%20pre--implementation-orange)
![Security](https://img.shields.io/badge/security-read--only%20first-blue)
![Documentation](https://img.shields.io/badge/docs-EN%20%7C%20DE-informational)

**A secure, project-oriented workbench for reproducible binary-data analysis and documentation.**

> **Project status:** planning / pre-implementation. This README describes the approved product and requirements direction, not already implemented functionality.

**English (default)** · [Deutsch](docs/de/README.md)

---

## Why Binary Insight?

Hex editors are excellent at showing bytes. Reverse-engineering suites can deeply analyse executables. Format languages can describe binary structures. In real engineering work, however, the knowledge gained from these tools often ends up fragmented across notes, screenshots, scripts and isolated utilities.

**SASD Binary Insight** is intended to close that gap:

> **finding → meaning → evidence → structure → annotation → validation → comparison → report → automation**

Raw bytes remain the verifiable foundation. The real product value comes from making analysis knowledge **traceable, persistent, versionable, testable and reusable**.

The project therefore does not aim to clone HxD, ImHex, 010 Editor or Ghidra. It combines selected proven ideas into a SASD-oriented **Binary Knowledge Workbench**.

## Product goals

Binary Insight is intended to:

- investigate unknown and partially documented binary formats;
- analyse large files without loading the complete source into RAM;
- combine Hex/Text view, Data Inspector, search and string analysis;
- detect signatures and patterns while exposing their origin;
- visibly distinguish **facts, strong evidence and heuristic assumptions**;
- preserve bookmarks, annotations and structural knowledge in analysis projects;
- describe and validate binary structures declaratively;
- provide hashes, checksums, entropy and byte statistics;
- document findings in reproducible reports;
- eventually serve GUI, CLI and controlled automation from the same analysis foundation.

## What Binary Insight is not

V1 is explicitly **not** a complete Ghidra/IDA replacement, malware laboratory, password cracker, universal decryptor, data-recovery suite or mandatory cloud service.

Writing, patching, device access and recovery are not casual extensions of normal analysis. They belong to later, explicitly approved risk classes.

## V1 – planned Secure Binary Analysis Foundation

| Area | Planned capability |
|---|---|
| Byte access | read-only, random access, large files, page/chunk based |
| Hex View | offset + hex + text, synchronized selection and navigation |
| Data Inspector | integers, float/double, endianness, strings, bits, timestamps, UUID |
| Search | hex/text across the complete source, result list, cancellation |
| Strings | ASCII/UTF-8 with configurable minimum length |
| Pattern Engine | magic bytes, fixed/masked patterns, rule packs, overlays |
| Evidence | Confirmed, Strong, Probable, Heuristic, Unknown |
| Knowledge | bookmarks, annotations, categories and comments |
| Projects | source/fingerprint, findings, format knowledge and analysis state |
| Structures | limited declarative V1 format model + Structure Inspector |
| Validation | fixed/magic values, ranges, bounds, references and checksums |
| Integrity | SHA-256/SHA-512, CRC32; legacy hashes clearly marked |
| Analysis | entropy and byte-frequency statistics |
| Reporting | Markdown/HTML; PDF through a defined export path |
| Quality | reproducible builds, tests, CI, robustness and performance validation |

The binding detail is maintained in the [Product Requirements](docs/en/requirements/REQUIREMENTS.md) and [Implementation Specification](docs/en/requirements/SPECIFICATION.md).

## Evidence instead of false certainty

A central product idea is the separation of observation from conclusion. A validated magic-byte match can provide strong evidence; high entropy may be caused by encryption, compression or other unpredictable data.

Binary Insight therefore plans to classify automated findings:

- **Confirmed** – established through definition or validation;
- **Strong** – very strong technical evidence;
- **Probable** – plausible interpretation with remaining uncertainty;
- **Heuristic** – indicator, not an assertion;
- **Unknown** – insufficient basis for a reliable classification.

Reports should preserve this distinction.

## Planned workbench

The long-term desktop workbench is modular:

~~~text
┌────────────────────────────────────────────────────────────────────┐
│ File / Search / Analysis / Tools                                  │
├───────────────┬───────────────────────────────────┬────────────────┤
│ File Info     │                                   │ Structure      │
│ Patterns      │          Hex / Text View          │ Inspector      │
│ Bookmarks     │                                   │ Pattern Detail │
│               │                                   │ Data Inspector │
├───────────────┴───────────────────────────────────┴────────────────┤
│ Entropy | Strings | Search Results | Compare | Statistics | Log   │
└────────────────────────────────────────────────────────────────────┘
~~~

This UI is a target concept. A visible long-term workbench area does not automatically imply V1 scope.

## Security model

**Read-only first** is a product principle, not merely a UI default.

- local processing by default;
- no mandatory telemetry;
- no automatic upload of analysed sources;
- no automatic script execution when opening a file;
- no unnecessary sensitive payloads in projects or logs;
- malformed/truncated data must be diagnosed safely;
- parsers must enforce bounds;
- future Vault keys remain owned by SASD Vault;
- future physical-device access is read-only by default;
- editing and recovery require separate security decisions.

## Architectural direction

Detailed technology decisions are made through ADRs, but the product baseline already requires separation of concerns:

~~~text
Desktop UI / TUI / CLI
        │
Application Services / Commands
        │
Project | Search | Pattern | Format | Diff | Report
        │
Analysis Model / Evidence / Validation
        │
ByteProvider / Address Space / Cache / Transform Streams
        │
File | Disk Image | Device | Vault | Future Sources
~~~

The analysis core should not depend on a particular GUI technology. GUI and future CLI should consume the same domain capabilities. Long-running operations must support progress/cancellation and must not block the UI.

## Platform strategy

| Platform | Target |
|---|---|
| Linux | required for V1 |
| Windows | V1 or no later than V1.1/V1.5 |
| macOS | later |
| OpenBSD | future Core/CLI target where dependencies permit |

Language, GUI technology and concrete dependencies remain initial ADR decisions.

## Roadmap

| Release | Focus |
|---|---|
| Phase 0 | engineering foundation, ADRs, build, tests, CI |
| V0.1 | ByteProvider, file provider, cache, random access |
| V1.0 Alpha | stable Hex/ASCII viewer + Inspector |
| V1.0 Beta | search, bookmarks, annotations, projects, hashes, strings |
| V1.0 RC1 | Pattern Engine, evidence, structure model, validation |
| V1.0 RC2 | entropy, statistics, performance, reporting, hardening |
| **V1.0** | **Secure Binary Analysis Foundation** |
| V1.1 | Compare + CLI |
| V1.2 | Format Workbench + Structure Diff |
| V1.5 | Kaitai + extensibility |
| V2.0 | Executable Insight – PE/COFF, ELF, later Mach-O/disassembly |
| V2.5 | Secure/Crypto Insight + controlled Vault integration |
| V3.0 | Disk & Filesystem Insight |
| V3.5 | Automation & Plugins |
| V4.0 | Controlled Editing |
| V5+ | optional Recovery/Repair |

The roadmap is a planning baseline, not a claim that these capabilities already exist.

## Research foundation

The product specification was informed by a review of classic and modern hex editors, format/parser tools, reverse-engineering platforms, diff tools, large-file editors and embeddable components. Important references include 010 Editor, ImHex, Hex Fiend, Synalyze It!, Kaitai Struct, Ghidra, radare2/Rizin/Cutter, rehex, HexWalk, Q22, fhex, wxHexEditor and VBinDiff.

- [Feature and market analysis](docs/en/research/FEATURE-ANALYSIS.md)
- [Open-source hex editor catalogue](docs/en/research/OPEN-SOURCE-HEX-EDITOR-CATALOG.md)

Research informs functionality. Reusing source code remains a separate licensing and architecture decision.

## SASD integration

Binary Insight remains a standalone product while reusing SASD experience where appropriate:

- **SASD Optical Media Workbench** – read-only sector/hex experience and possible shared analysis components;
- **SASD Editor Toolkit/Toolbox** – navigation, selection, commands and later undo/redo concepts;
- **SASD UI Toolkit / UI Platform** – possible UI reuse without coupling the analysis core;
- **SASD Desktop Secret Manager / Vault** – future controlled interface; authentication and keys remain owned by the Vault.

## Repository layout

The implementation structure will be established during Phase 0. The documentation baseline already separates requirements, strategy, research, ADRs and history:

~~~text
.
├── README.md                     English default
├── LICENSE
└── docs/
    ├── README.md
    ├── adr/
    ├── history/
    ├── de/
    │   ├── README.md
    │   ├── requirements/
    │   │   ├── LASTENHEFT.md
    │   │   └── PFLICHTENHEFT.md
    │   ├── strategy/
    │   └── research/
    └── en/
        ├── README.md
        ├── requirements/
        │   ├── REQUIREMENTS.md
        │   └── SPECIFICATION.md
        ├── strategy/
        └── research/
~~~

## Project governance and status

- [Project status](PROJECT-STATUS.md)
- [Roadmap](ROADMAP.md)
- [Contributing](CONTRIBUTING.md)
- [Security policy](SECURITY.md)
- [Changelog](CHANGELOG.md)
- [Agent operating contract](AGENTS.md)

## Documentation

### Requirements

- [Product Requirements](docs/en/requirements/REQUIREMENTS.md) – **what** is needed and **why**;
- [Implementation Specification](docs/en/requirements/SPECIFICATION.md) – **how** the requirements are intended to be fulfilled.

### Architecture

- [Architecture](docs/en/architecture/ARCHITECTURE.md) – system boundaries, layers, core abstractions, security and evolution;
- [Detailed German architecture](docs/de/architecture/ARCHITEKTUR.md).

### Strategy and research

- [Product strategy](docs/en/strategy/PRODUCT-STRATEGY.md)
- [Feature analysis](docs/en/research/FEATURE-ANALYSIS.md)
- [Open-source hex editor catalogue](docs/en/research/OPEN-SOURCE-HEX-EDITOR-CATALOG.md)
- [ADR index](docs/adr/README.md)
- [Documentation history](docs/history/README.md)
- [German documentation](docs/de/README.md)

## Build and development

**Not available yet.** The repository is still pre-implementation. Documenting build or run commands before the language, build system, GUI technology and initial architecture ADRs are decided and implemented would be misleading.

After Phase 0 establishes the engineering baseline, this section will be extended with reproducible prerequisites, build, test, run and CI instructions.

## Quality targets

V1 planning includes tests for page/chunk boundaries and large offsets, robust malformed/truncated input handling, defined format fixtures, reproducible project persistence, at least 1 GB and 10 GB performance fixtures, reproducible builds/CI, static checks and documented dependencies/licences.

Concrete V1 acceptance criteria are maintained in the [Product Requirements](docs/en/requirements/REQUIREMENTS.md#14-v1-acceptance-criteria).

## Licence and dependencies

This repository is licensed under the [MIT License](LICENSE).

MIT, BSD and Apache-2.0 dependencies are preferred. LGPL requires deliberate integration review; GPL/AGPL components will not be embedded without an explicit licensing decision.

Evaluation candidates include suitable hex controls, Kaitai Struct, Capstone/Zydis and libmagic or appropriate alternatives.

## Project status

The current status is **Planning / Pre-Implementation**. The product and requirements baseline exists; initial architecture decisions must be completed before implementation begins.

In other words, this README describes the **planned product**. V1/V2/... sections are target scope, not implementation claims.

---

**SASD Binary Insight**  
*A secure, evidence-aware binary analysis workbench that turns byte-level findings into reproducible engineering knowledge.*
