# SASD Secure Binary Analysis Tool
## Consolidated Product Specification – Repository Edition

**Product:** SASD Secure Binary Analysis Tool  
**Working/UI name:** SASD Binary Insight  
**Baseline:** 2026-10-08  
**Status:** normative development baseline before implementation

> **Guiding statement:** We are not building another hex editor because hex editors are missing. We are building a secure, project-oriented analysis workbench that detects, explains, documents, validates and compares binary data and turns findings into reusable engineering knowledge.

## 1. Product goal

SASD Binary Insight bridges the space between a classic hex editor, a binary-format parser, reverse-engineering tooling and technical documentation. Raw bytes remain the verifiable foundation; product value comes from meaning, evidence, project knowledge and reproducibility.

It is deliberately **not** an HxD or Ghidra clone, malware laboratory, password cracker, universal decryptor or cloud-only service.

## 2. Engineering principles

1. **Read-only first.** Analysis is the default; writing requires a later explicit security decision.
2. **Meaning before editing.** Understanding takes priority over byte manipulation.
3. **Evidence before assumption.** Confirmed, strong, probable and heuristic findings are visibly different.
4. **Large-file capable by design.** The architecture must not require a complete file in RAM.
5. **Core independent from UI.** The same engine should serve GUI, CLI and later automation.
6. **Local first.** No mandatory cloud service or telemetry.
7. **Reproducible analysis.** Knowledge is persisted as versioned project artifacts.
8. **Security by design.** Crypto, plugins, devices and write operations have explicit trust boundaries.
9. **Reuse before reinvention.** Suitable libraries are evaluated before basic technology is reimplemented.
10. **No monolith.** Executable, crypto, disk and forensic capabilities remain modules around the core.

## 3. V1 workbench

The long-term workbench consists of a Hex View, File Information, Pattern Categories, Structure Inspector, Pattern Details, Data Inspector and a bottom workbench for Entropy, Strings, Search Results, Compare, Statistics and Log.

Colour must never be the only carrier of meaning. Selection, pattern findings and validation state must remain distinguishable.

## 4. Functional requirements

### 4.1 Byte access and large files

Read-only access, random access, paged/chunked loading and cache eviction are mandatory. Analysis code must depend on a ByteProvider abstraction rather than an operating-system file class. External source changes must be detected. The provider model must allow later disk-image, device and Vault streams.

### 4.2 Hex/text view

Synchronized hex/text presentation and selection, go-to-offset, copy as hex/text/offset+length, navigation through bookmarks/patterns/fields/search hits and rendering restricted to visible data.

### 4.3 Data Inspector

At minimum: signed/unsigned 8/16/32/64-bit integers, little/big endian, float/double, ASCII, UTF-8, UTF-16, hex, bit fields, Unix timestamps and GUID/UUID when the selected size is appropriate.

### 4.4 Search

Hex sequences and text; blockwise search across large files; result list with offset and preview; cancellation. Later: wildcards, masks, numeric and structure-aware searches.

### 4.5 Pattern Engine

Versioned registry and rule packs; magic bytes, fixed and masked byte sequences, string/encoding recognition; findings with category, name, description, offset, length, confidence and source; coloured/filterable overlays; deterministic overlap priorities; user rules without recompilation; streaming and cancellable scans.

### 4.6 Confidence and evidence

Automated findings are classified as **Confirmed**, **Strong**, **Probable**, **Heuristic** or **Unknown**. High entropy, for example, must never be presented as proof of encryption.

### 4.7 Strings, bookmarks and annotations

ASCII and UTF-8 in V1, UTF-16 later; configurable minimum length; bookmarks on offsets or ranges; named/categorised/commented ranges; project persistence and report export.

### 4.8 Analysis project

Projects persist the source reference/fingerprint, bookmarks, annotations, selected format definitions, findings and relevant navigation state. They must not store unnecessary copies of sensitive payloads or secrets. The project format is versioned, migratable and preferably Git-friendly.

### 4.9 Structure model

V1 deliberately starts with a limited declarative model: name, offset, primitive type, length, endianness, description, enum, fixed/magic values, simple arrays, nesting and simple validation. Later versions add dynamic lengths, conditions, unions, bit fields, computed fields, includes and transformed substreams.

### 4.10 Validation

Magic/fixed-value checks, ranges, bounds, references/offsets and modular checksums. Findings use Info/Warning/Error and are visible in both Hex View and Structure Inspector.

### 4.11 Hashing, entropy and statistics

SHA-256 and SHA-512; MD5/SHA-1 only for compatibility/identification and clearly marked as cryptographically obsolete; modular CRC32. Hashing must stream.

Entropy includes an overall value, sliding-window graph, navigation from graph to bytes and byte-frequency statistics. Statistical indicators are not cryptographic proof.

### 4.12 Diff and reporting

V1.1 introduces byte diff with synchronized navigation and difference ranges; structure-aware diff follows later.

Markdown and HTML are primary report formats; PDF is produced through a defined export/conversion path. Reports distinguish facts from heuristics and allow sensitive-content controls.

### 4.13 CLI and automation

GUI and CLI use the same core engine. Planned operations include inspect, hash, scan, analyse, validate, report and diff. Scripting/plugins come only after a stable core and require an explicit permission model.

## 5. Later domain modules

### V2 – Executable Insight

PE/COFF and ELF first, Mach-O later. Headers, sections/segments, imports/exports, entry point and file-offset ↔ virtual-address mapping. Disassembly should use an evaluated engine such as Capstone or Zydis rather than a home-grown CPU decoder.

### V2.5 – Secure/Crypto Insight

Crypto metadata and SASD Vault integration are for authorised analysis only. Authentication and key ownership remain with the Vault. Plaintext should stay in memory where practical; project files never persist keys or secrets.

### V3 – Disk & Filesystem Insight

RAW/DD/IMG/ISO providers, MBR/GPT, sector navigation, read-only device access and selected filesystem metadata. MBR/GPT repair is outside the normal analysis mode.

### V4 – Controlled Editing

Only after a separate security decision: edit mode, undo/redo, copy-on-write, patch files, review before save, backup and atomic writes where feasible.

### V5+ – Recovery/Repair

Optional or separate module: diagnosis, dry run, mandatory backup/audit and controlled repair.

## 6. Architecture

```text
Desktop UI / TUI / CLI
        |
Application Services / Commands
        |
Project | Search | Pattern | Format | Diff | Report
        |
Analysis Model / Evidence / Validation
        |
ByteProvider / Address Space / Cache / Transform Streams
        |
File | Disk Image | Device | Vault | Future Sources
```

Long-running operations such as hashing, search, pattern scanning, entropy, parsing, diff and reporting must not block the UI and must support progress and cancellation.

## 7. Non-functional requirements

Linux is required for V1; Windows is targeted for V1 or at the latest V1.1/V1.5; macOS follows later; OpenBSD Core/CLI support is desirable where dependencies permit.

Malformed/truncated input must not crash the application. Parsers perform bounds checks. No telemetry or automatic upload by default. No automatic script execution on open. Logs must not capture sensitive payloads without explicit intent. Performance fixtures include at least 1 GB and 10 GB files.

## 8. Roadmap

| Release | Focus | approximate cumulative commits |
|---|---|---:|
| Phase 0 | engineering foundation, ADRs, build, tests, CI | 10–15 |
| V0.1 | ByteProvider, file provider, cache, random access | 20–30 |
| **V1.0-alpha** | first stable Hex/ASCII viewer + inspector | 35–45 |
| **V1.0-beta** | search, bookmarks, annotations, project, hashes, strings | 50–65 |
| **V1.0-rc1** | Pattern Engine, confidence, structure model, validation | 65–85 |
| **V1.0-rc2** | entropy, statistics, performance, reporting, hardening | 80–100 |
| **V1.0 FINAL** | secure, tested binary-analysis foundation | **90–115** |
| V1.1 | compare + CLI | – |
| V1.2 | format workbench + structure diff | – |
| V1.5 | Kaitai + extensibility | – |
| V2.0 | Executable Insight | – |
| V2.5 | Secure/Crypto Insight | – |
| V3.0 | Disk & Filesystem Insight | – |
| V3.5 | automation & plugins | – |
| V4.0 | controlled editing | – |
| V5+ | optional recovery/repair | – |

## 9. V1 acceptance

V1 must open >1 GB files without full loading, navigate the complete address space, decode LE/BE fixtures correctly, search across page boundaries, reopen projects reproducibly, detect source changes, recognize defined PNG/ZIP/PE/ELF fixtures, distinguish heuristic findings, parse a nested test format, diagnose corrupt input without crashing and calculate entropy as a streaming/cancellable operation.

Build, tests and static checks must run reproducibly in CI.

## 10. Licence and dependency policy

Functional inspiration is separate from code reuse. MIT, BSD and Apache-2.0 are preferred. LGPL requires review; GPL/AGPL components are not embedded without an explicit licensing decision.

Evaluation candidates include QHexEdit2 or another suitable hex control, Capstone, Zydis, Kaitai Struct and libmagic.

## 11. SASD integration

- **Optical Media Workbench:** reuse lessons from the existing read-only sector/hex viewer and evaluate shared components.
- **Editor Toolkit/Toolbox:** evaluate command, navigation, selection and later undo/redo concepts.
- **UI Toolkit/UI Platform:** reuse UI technology only without coupling the analysis core.
- **Desktop Secret Manager/Vault:** authentication and keys stay in the Vault; Binary Insight later consumes a controlled interface.

## 12. Product differentiation

> **A secure, evidence-aware binary analysis workbench that turns byte-level findings into reproducible engineering knowledge.**

Differentiation is the complete chain **finding → meaning → evidence → structure → annotation → validation → comparison → report → automation**, not any single hex-editor feature.

**Start recommendation:** Phase 0 and V0.1 may begin after the initial ADR decisions.
