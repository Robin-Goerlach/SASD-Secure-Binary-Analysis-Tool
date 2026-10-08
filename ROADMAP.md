# SASD Secure Binary Analysis Tool — Roadmap

**Status:** planning / pre-implementation  
**Baseline:** 2026-10-08

This roadmap turns the requirements and architecture into release-oriented implementation slices. Requirements remain normative; a checked item means implementation and required verification actually exist.

## Planning principles

1. Architecture before breadth: Phase 0 establishes durable boundaries first.
2. Read-only first: writing, devices and recovery remain separate later risk classes.
3. Large-file capability by design: no full-load architecture to retrofit later.
4. Vertical slices: prefer small end-to-end increments over framework construction.
5. Evidence before claims: tests/measurements must support completion claims.
6. One product core: GUI, later CLI and automation use the same Application/Domain capabilities.
7. Scope changes are explicit and update requirements/architecture where needed.

## Phase 0 — Engineering Foundation

**Target:** roughly 10–15 focused commits.

- [ ] ADR-001 core language/platform.
- [ ] ADR-002 GUI technology and SASD UI relationship.
- [ ] ADR-003 ByteProvider/large-file/cache model.
- [ ] ADR-004 project persistence and migration.
- [ ] ADR-005 V1 format-definition representation.
- [ ] ADR-006 Pattern Registry/rule-pack format.
- [ ] ADR-007 Evidence/Confidence model.
- [ ] ADR-008 hash/checksum abstraction.
- [ ] ADR-009 reporting pipeline.
- [ ] ADR-010 dependency/licence policy.
- [ ] Establish source/test layout, reproducible build and CI.
- [ ] Establish formatting/static checks appropriate to the selected toolchain.
- [ ] Add deterministic fixture policy and performance harness.
- [ ] Add security/logging baseline.
- [ ] Implement the smallest read-only ByteProvider → ByteRange → test vertical slice.
- [ ] Demonstrate cancellation/progress on a representative long operation.

**Exit:** the Architecture Definition of Done is satisfied; Domain/Core has no UI dependency.

## V0.1 — Core File Access

**Cumulative target:** 20–30 commits.

- [ ] read-only FileByteProvider;
- [ ] 64-bit offsets and safe ByteRange semantics;
- [ ] random reads and explicit EOF/short-read behavior;
- [ ] bounded page/chunk cache;
- [ ] source identity/change detection;
- [ ] page/chunk-boundary, overflow and malformed-input tests;
- [ ] 1 GB/10 GB performance fixtures;
- [ ] minimal UI-independent navigation service.

## V1.0-alpha — First Usable Viewer

**Cumulative target:** 35–45 commits.

- [ ] desktop shell;
- [ ] virtualized Hex/Text view;
- [ ] synchronized selection and Go-to Offset;
- [ ] copy Hex/Text/Offset+Length;
- [ ] required Data Inspector interpretations and bit view;
- [ ] keyboard/accessibility baseline;
- [ ] appropriate UI smoke verification.

## V1.0-beta — Analysis Workspace

**Cumulative target:** 50–65 commits.

- [ ] streaming/cancellable hex and text search;
- [ ] ASCII/UTF-8 string extraction;
- [ ] bookmarks and range annotations;
- [ ] project save/open and migrations;
- [ ] source-fingerprint mismatch warning;
- [ ] SHA-256/SHA-512 and CRC32;
- [ ] no secrets/unnecessary payload copies in projects.

## V1.0-rc1 — Pattern, Evidence and Meaning

**Cumulative target:** 65–85 commits.

- [ ] Pattern Registry and versioned rule packs;
- [ ] magic/fixed/masked/string patterns;
- [ ] scans across chunk boundaries and deterministic overlaps;
- [ ] findings with provenance and Confidence;
- [ ] Confirmed/Strong/Probable/Heuristic/Unknown presentation;
- [ ] filterable overlays;
- [ ] minimal declarative format model and nested Structure Inspector;
- [ ] fixed/magic/range/bounds/reference validation;
- [ ] Info/Warning/Error findings;
- [ ] deterministic PNG/ZIP/PE/ELF and SASD fixtures.

## V1.0-rc2 — Insight, Reporting and Hardening

**Cumulative target:** 80–100 commits.

- [ ] global/sliding-window entropy and byte-frequency statistics;
- [ ] analysis-result-to-byte navigation;
- [ ] Markdown and HTML reports;
- [ ] controlled sensitive-content inclusion;
- [ ] facts vs heuristics preserved in reports;
- [ ] corrupt/truncated-input hardening;
- [ ] performance, accessibility and keyboard pass;
- [ ] dependency/licence review and security regression suite.

## V1.0 — Secure Binary Analysis Foundation

**Expected cumulative size:** roughly 90–115 focused commits.

V1 contains read-only large-file access, Hex/Text, Data Inspector, search, strings, projects, bookmarks/annotations, hashes, Pattern/Evidence, minimal structures, validation, entropy/statistics and reproducible reporting.

V1 explicitly excludes general binary editing, physical-device writing, partition repair, debugger/decompiler, broad executable RE, generic scripting/plugins, Vault key/decrypt logic, password cracking, remote agents and mandatory cloud services.

## V1.1 — Compare and CLI

- [ ] byte diff and synchronized difference navigation;
- [ ] CLI using the same Application/Core;
- [ ] inspect/hash/scan/analyse/validate/report/diff contracts;
- [ ] deterministic validation/automation exit codes.

## V1.2 — Format Workbench

- [ ] richer format authoring;
- [ ] justified dynamic lengths/offsets/conditions;
- [ ] structure diff;
- [ ] format diagnostics and test fixtures.

## V1.5 — Kaitai and Controlled Extensibility

- [ ] Kaitai interoperability/import evaluation;
- [ ] stable extension APIs;
- [ ] trust/permission design before executable extensions.

## V2.0 — Executable Insight

Requires ADR-011. PE/COFF first, then ELF, Mach-O later; sections/segments, entry point, imports/exports/symbols, file-offset ↔ virtual-address mapping and reviewed external disassembly. No exploit generation, crack workflow, debugger or home-grown decompiler.

## V2.5 — Secure/Crypto Insight

Requires ADR-012. Evidence-aware crypto metadata/statistics and controlled SASD Vault provider. Vault retains authentication/key ownership; avoid plaintext temporary files. Password brute force, key extraction, protection bypass and universal decryption remain out of scope.

## V3.0 — Disk and Filesystem Insight

Requires ADR-013. RAW/DD/IMG/ISO, MBR/GPT and selected filesystem metadata; explicit read-only physical-device provider. No one-click partition repair.

## V3.5 — Automation and Plugins

Stable plugin boundary, explicit capabilities/permissions, no automatic code execution on project open, controlled headless enablement, and separation of scripting from declarative formats.

## V4.0 — Controlled Editing

Only after dedicated safety/architecture approval: explicit Edit Mode, Copy-on-Write/patch model, undo/redo, review-before-save, backup/atomic replacement and audit.

## V5+ — Optional Recovery/Repair

Only if product evidence justifies it. Diagnosis, dry run, mandatory backup, explicit confirmation, audit and rollback precede repair.

## Cross-cutting release gates

Every slice preserves Domain/Core independence from UI, bounded large-file access, cancellation for long work, safe bounds/overflow handling, evidence/provenance, no secrets in project/log output, deterministic tests, dependency/licence review and synchronized documentation.

## Traceability

See [Product Requirements](docs/en/requirements/REQUIREMENTS.md), [Implementation Specification](docs/en/requirements/SPECIFICATION.md), [Architecture](docs/en/architecture/ARCHITECTURE.md), [detailed German architecture](docs/de/architecture/ARCHITEKTUR.md) and [ADR index](docs/adr/README.md).
