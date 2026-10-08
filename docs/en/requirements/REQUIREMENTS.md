# SASD Secure Binary Analysis Tool
## Product Requirements Document – Customer/User Requirements

**Product:** SASD Secure Binary Analysis Tool  
**Working/UI name:** SASD Binary Insight  
**Baseline:** 2026-10-08  
**Status:** product requirements baseline  
**Document type:** requirements specification describing **what** is needed and **why**; technical implementation and concrete architecture belong in the implementation specification and ADRs.

> **Product vision:** SASD Binary Insight should not merely display binary data. It should make binary data comprehensible in a traceable way and turn byte-level observations into verifiable, annotatable, validatable and reusable analysis results.

## 1. Context and motivation

SASD needs a tool for development, administration, training, research and later authorised security/forensic scenarios involving unknown or insufficiently documented binary data. Traditional hex editors display bytes reliably but do not cover the complete SASD workflow.

Typical work includes investigating unknown formats; identifying headers, identifiers, fields, strings, numeric values and recurring patterns; comparing versions; recording and retesting structural assumptions; checking hashes, checksums, statistical anomalies and format violations; reusing findings in documentation, tests and parsers; analysing large files without loading them completely into memory; and performing this work locally without a mandatory cloud service.

The required product is therefore a **secure, project-oriented binary-analysis workbench**, not simply another general-purpose hex editor.

## 2. Goals

The primary goal is a dependable workspace in which binary data can be investigated from raw bytes through documented structure while preserving the resulting knowledge reproducibly.

The product shall: open binary files safely and read-only first; handle large files; present synchronized hex/text views; interpret selected bytes; search content; recognise signatures/patterns/structures; distinguish evidence from heuristic assumptions; preserve bookmarks/annotations/structure knowledge; validate data; provide hashes, entropy and basic byte statistics; persist analysis projects; produce reports; and provide a controlled path toward comparison, automation, executable analysis, Crypto/Vault analysis and disk/filesystem analysis.

Risky writing and repair capabilities must remain separated from normal analysis.

## 3. Non-goals and boundaries

V1 is not intended to be a complete replacement for Ghidra/IDA-class suites, a malware-development tool, password cracker, universal decryptor, recovery suite, automatic disk-repair tool, mandatory cloud service or full binary editor that casually overwrites original files.

Analysis takes precedence over manipulation. Later writing, patching, recovery or device operations require separate safety boundaries and approval.

## 4. Target users

Primary V1 users are SASD software developers, Linux/Unix and system administrators, technical trainers/learners and developers of custom file/import/protocol formats.

Later audiences may include technical staff in small and medium-sized organisations, embedded/firmware developers, researchers/educators, migration/support teams and authorised security/forensic users.

## 5. Representative use cases

### 5.1 Understand an unknown format

Open a file, inspect hex/text and typed values, find strings/signatures, annotate suspected fields and gradually build a documented structure model.

### 5.2 Validate a known format

Check a file against a known definition including magic values, ranges, offsets, lengths, references and checksums, with navigable findings.

### 5.3 Compare versions

Compare two files and, later, interpreted structures to determine where and which semantic fields changed.

### 5.4 Analyse a large file

Open gigabyte-scale input without a complete RAM copy, navigate/search it, calculate hashes and cancel long operations.

### 5.5 Document an analysis

Create bookmarks, named ranges, comments and findings; save the project; reopen it reproducibly; export facts and explicitly labelled assumptions in a report.

### 5.6 Later executable analysis

Inspect PE/COFF and ELF headers, sections/segments, imports/exports, entry points and disassembly.

### 5.7 Later authorised Crypto/Vault analysis

Analyse encrypted SASD data through a controlled Vault interface without duplicating key management inside Binary Insight.

### 5.8 Later disk analysis

Inspect disk images and physical devices read-only at sector, partition-table and selected filesystem-metadata levels.

## 6. Mandatory V1 requirements

Requirement identifiers **LA-V1-xxx** provide traceability into implementation specification, tests and releases.

### File and navigation

**LA-V1-001 – Read-only open:** regular binary files shall open read-only by default.  
**LA-V1-002 – Large files:** files larger than 1 GB shall be openable and navigable over the complete address space without a full in-memory copy.  
**LA-V1-003 – Hex/text view:** offsets, hexadecimal bytes and corresponding text shall be visible together.  
**LA-V1-004 – Synchronized selection:** hex and text selection shall represent the same byte range.  
**LA-V1-005 – Offset navigation:** users shall be able to jump directly to an offset.  
**LA-V1-006 – Copy:** selected data shall be copyable at least as hex, text and offset/length.  
**LA-V1-007 – Source-change detection:** external source changes shall not silently leave the user working against stale assumptions.

### Data interpretation

**LA-V1-010 – Data Inspector:** selected bytes shall be interpretable at least as signed/unsigned 8/16/32/64-bit integers, little/big endian, float/double, ASCII, UTF-8, UTF-16, hex and, when size permits, Unix timestamps and GUID/UUID.  
**LA-V1-011 – Bit view:** suitable values shall have a bit-level representation.

### Search and strings

**LA-V1-020 – Hex search:** search byte/hex sequences.  
**LA-V1-021 – Text search:** search textual content.  
**LA-V1-022 – Whole source:** large-file search shall cover the logical source and not lose matches at internal block boundaries.  
**LA-V1-023 – Search results:** results shall include at least offset and preview and be directly navigable.  
**LA-V1-024 – Cancellation:** long searches shall be cancellable.  
**LA-V1-025 – Strings:** find ASCII and UTF-8 strings with configurable minimum length.

### Pattern recognition and evidence

**LA-V1-030 – Pattern Registry:** known patterns/signatures shall be centrally manageable and versioned.  
**LA-V1-031 – Recognition types:** at least magic bytes, fixed and masked byte sequences and appropriate string/encoding patterns.  
**LA-V1-032 – Finding information:** findings shall expose category/name, description, offset, length, evidence/confidence and rule origin.  
**LA-V1-033 – Visual marking:** detected ranges shall be clearly marked and filterable; colour shall not be the only carrier of meaning.  
**LA-V1-034 – Overlaps:** overlapping findings shall be handled deterministically and transparently.  
**LA-V1-035 – User rules:** users should be able to add pattern rules without recompiling the application.  
**LA-V1-036 – Confidence/Evidence:** automated claims shall distinguish Confirmed, Strong, Probable, Heuristic and Unknown.  
**LA-V1-037 – No false certainty:** heuristic indicators shall not be presented as proof; high entropy alone, for example, is not proof of encryption.

### Bookmarks, annotations and analysis projects

**LA-V1-040 – Bookmarks:** store offsets and ranges as bookmarks.  
**LA-V1-041 – Annotations:** name, categorise and comment byte ranges.  
**LA-V1-042 – Project persistence:** persist bookmarks, annotations, relevant findings, selected format definitions and required analysis context.  
**LA-V1-043 – Reproducible reopening:** reopening a project shall allow the analysis to be understood and continued.  
**LA-V1-044 – Source identity:** the project shall detect whether the referenced source still corresponds to the saved analysis.  
**LA-V1-045 – No unnecessary secrets:** project files shall not persist keys, passwords or unnecessary sensitive payload copies.  
**LA-V1-046 – Versionability:** the project format should be versioned, migratable and suitable for version control where practical.

### Structured binary formats

**LA-V1-050 – Structure definitions:** users shall be able to describe simple binary structures declaratively.  
**LA-V1-051 – V1 elements:** names, offsets, primitive types, lengths, endianness, descriptions, enums, fixed/magic values, simple arrays and nesting shall be representable.  
**LA-V1-052 – Structure Inspector:** interpreted fields shall be displayed structurally and linked to their bytes.  
**LA-V1-053 – Simple validation:** format definitions shall support simple validation rules.

### Validation

**LA-V1-060 – Format validation:** magic/fixed values, ranges, bounds and references/offsets shall be checkable.  
**LA-V1-061 – Checksums:** checksum validation should be modular.  
**LA-V1-062 – Severity:** findings shall support at least information, warning and error.  
**LA-V1-063 – Finding navigation:** validation findings shall navigate to the affected bytes/structure.

### Hashes, entropy and statistics

**LA-V1-070 – Modern hashes:** SHA-256 and SHA-512 shall be available.  
**LA-V1-071 – Legacy hashes:** MD5/SHA-1 may be available for compatibility/identification but shall be marked cryptographically obsolete.  
**LA-V1-072 – CRC32:** CRC32 should be available as a modular checksum.  
**LA-V1-073 – Large data:** hashing shall not require a full RAM copy.  
**LA-V1-074 – Entropy:** provide whole-source and position/window-based entropy analysis.  
**LA-V1-075 – Analysis navigation:** navigate from positional entropy results to the corresponding bytes.  
**LA-V1-076 – Byte frequency:** provide byte-frequency statistics.

### Reporting

**LA-V1-080 – Analysis report:** users shall be able to export a traceable analysis report.  
**LA-V1-081 – Core formats:** Markdown and HTML are core formats; PDF should be available through a defined export path.  
**LA-V1-082 – Facts vs heuristics:** reports shall distinguish established findings from heuristic claims.  
**LA-V1-083 – Export privacy:** users shall control which sensitive content is included.

## 7. Quality requirements

### Security

**LA-Q-001** Local processing is the default.  
**LA-Q-002** No mandatory telemetry or automatic file upload.  
**LA-Q-003** V1 shall not automatically modify analysed files.  
**LA-Q-004** Opening a file shall not automatically execute embedded scripts.  
**LA-Q-005** Logs shall not silently capture complete sensitive payloads.  
**LA-Q-006** Malformed/adversarial input shall not cause uncontrolled memory access.  
**LA-Q-007** Parsers/structure interpretation shall detect out-of-bounds access.

### Robustness

**LA-Q-010** Truncated, inconsistent or unknown input shall not crash the application.  
**LA-Q-011** Errors should be explained at the affected location where practical.  
**LA-Q-012** Long-running analysis shall be cancellable.  
**LA-Q-013** Failure in one analysis service should not unnecessarily invalidate the complete analysis.

### Performance and scalability

**LA-Q-020** Navigation through large files shall remain responsive.  
**LA-Q-021** Performance validation shall include at least 1 GB and 10 GB fixtures.  
**LA-Q-022** Only data needed for the current task should need processing/rendering.  
**LA-Q-023** Search, hashing, pattern scanning and entropy shall not depend on a full RAM copy.

### Usability and accessibility

**LA-Q-030** Core functions shall have understandable navigation.  
**LA-Q-031** Hex View, Data Inspector, Structure Inspector, results and findings shall cross-navigate.  
**LA-Q-032** Meaning shall not be conveyed by colour alone.  
**LA-Q-033** Technical findings should have understandable names and descriptions.

### Portability

**LA-Q-040** Linux is required for V1.  
**LA-Q-041** Windows should be supported in V1 or no later than V1.1/V1.5.  
**LA-Q-042** macOS is a later target.  
**LA-Q-043** OpenBSD Core/CLI support is desirable where dependencies permit.

### Maintainability and reuse

**LA-Q-050** Domain analysis shall not be permanently tied to one GUI technology.  
**LA-Q-051** Format, pattern and project knowledge shall be versionable.  
**LA-Q-052** Suitable reusable libraries shall be evaluated before reinvention.  
**LA-Q-053** External dependencies and licences shall be documented.

## 8. Post-V1 should-requirements

### V1.1 – Compare and CLI

Byte diff with synchronized navigation/difference ranges; first CLI for repeatable analysis; reuse of the same analysis capabilities as the GUI.

### V1.2 – Format Workbench

More convenient format-definition authoring; dynamic lengths/conditions; unions/bit fields; computed fields/includes; Structure Diff.

### V1.5 – Interoperability and extensibility

Kaitai Struct import or defined compatibility; extended format/analysis interfaces; preparation for controlled extensibility.

## 9. Long-term requirements

### V2 – Executable Insight

Structured PE/COFF and ELF, later Mach-O, including headers, sections/segments, imports/exports, available symbols, entry point, file-offset ↔ virtual-address mapping and disassembly. Prefer a proven disassembler library over implementing a CPU decoder.

### V2.5 – Secure/Crypto Insight

Authorised Crypto metadata and controlled SASD Vault integration. Authentication/key ownership stays in the Vault. Binary Insight shall not persist keys and should retain plaintext only as long as required.

### V3 – Disk & Filesystem Insight

RAW/DD/IMG/ISO, partition tables, sector navigation, read-only physical devices and selected filesystem metadata. Analysis and repair remain separate.

### V3.5 – Automation and plugins

Controlled scripting, plugins and headless automation with an explicit permission/trust model. Opening a file shall never silently activate untrusted code.

### V4 – Controlled Editing

Optional explicitly activated editing with undo/redo, copy-on-write, patch files, review before save, backup and safe writing where feasible. Original files shall not be changed casually.

### V5+ – Recovery/Repair

Optional, potentially separate module/product. Diagnosis, dry run, backup, auditability and controlled approval are prerequisites.

## 10. SASD integration

The product should enable synergy without unnecessary hard coupling:

- **SASD Optical Media Workbench:** read-only sector/hex experience and possible shared byte/analysis components;
- **SASD Editor Toolkit/Toolbox:** navigation, selection, commands and later undo/redo concepts;
- **SASD UI Toolkit/UI Platform:** reusable UI concepts while keeping the analysis core independent;
- **SASD Desktop Secret Manager/Vault:** sole ownership of authentication/key management; Binary Insight later consumes a controlled interface.

## 11. Data and protection needs

Analysed sources may contain confidential, personal, proprietary or security-sensitive information. Therefore local processing is default; automatic cloud transfer is excluded; project files avoid unnecessary source duplication; report content is controllable; Vault keys are not persisted; temporary plaintext is handled deliberately; and physical-device access is read-only by default.

## 12. Licence and procurement requirements

Existing components shall be evaluated before reinvention. Studying functionality and reusing source code are separate decisions.

MIT, BSD and Apache-2.0 dependencies are preferred. LGPL requires a deliberate integration review. GPL/AGPL code shall not be incorporated into an incompatibly licensed application without an explicit licensing decision.

Hex controls, Kaitai Struct, Capstone/Zydis and libmagic or suitable alternatives shall be evaluated in particular.

## 13. Deliverables

### V1

At minimum: runnable desktop application for the V1 target platform(s); documented analysis core; Hex/Text view and Data Inspector; search and strings; pattern/evidence functions; bookmarks/annotations; analysis projects; minimal structure model and validation; hashes/entropy/statistics; reporting; automated tests; reproducible build and CI; user/developer documentation for implemented scope; documented third-party dependencies/licences.

### Explicitly outside V1

Byte diff/CLI, full executable analysis, Vault decryption, physical disk analysis, plugins/scripting, editing and recovery are not mandatory V1 deliverables unless a later approved baseline moves them forward.

## 14. V1 acceptance criteria

V1 acceptance requires at least:

1. Open and navigate a >1 GB file without a full RAM copy.
2. Correctly interpret defined little- and big-endian fixtures.
3. Hex/text search finds matches across internal page/block boundaries.
4. Save and reproducibly reopen a project containing bookmarks, annotations and findings.
5. Detect a source file changed after the analysis was saved.
6. Recognise agreed PNG, ZIP, PE and ELF fixtures/signatures.
7. Present an intentionally ambiguous finding as heuristic rather than established fact.
8. Correctly display a defined nested SASD test format.
9. Diagnose a corrupt/truncated fixture instead of crashing.
10. Hashing and entropy work on large fixtures and long operations can be cancelled.
11. Export a report containing key results with facts and heuristics distinguishable.
12. Build, automated tests and agreed static checks run reproducibly in CI.

## 15. Priorities

**Must for V1:** read-only large-file access, Hex/Text, Data Inspector, search, strings, Pattern Engine, Confidence/Evidence, bookmarks/annotations, project persistence, minimal structure model, validation, hashing, entropy/byte frequency, reporting, robustness and tests.

**Should immediately follow:** byte diff, CLI, richer format definitions, Structure Diff and Kaitai interoperability.

**May follow later:** Executable Insight, Vault/Crypto Insight, Disk/Filesystem Insight, plugins/scripting, Controlled Editing and Recovery/Repair according to roadmap and separate safety decisions.

## 16. Product success criteria

The product succeeds when Binary Insight is used in real SASD work as more than a hex viewer: analysis knowledge survives sessions; findings are understandable to others; assumptions are not confused with facts; format knowledge is versionable/testable; results can feed documentation, tests, parsers or other SASD tools; and common binary-analysis work requires fewer disconnected utilities and manual notes.

## 17. Relationship to implementation specification and ADRs

This requirements document states expectations from the customer/user perspective. The [implementation specification](SPECIFICATION.md) defines the derived technical solution and release planning. Durable architecture decisions are recorded in ADRs.

Changes should preserve traceability **requirements → implementation specification → ADR/implementation → test/acceptance**.
