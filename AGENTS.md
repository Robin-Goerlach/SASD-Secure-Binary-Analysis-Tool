# AGENTS.md — SASD Secure Binary Analysis Tool

## Purpose

This file is the repository-wide operating contract for Codex and other coding agents working on **SASD Secure Binary Analysis Tool / SASD Binary Insight**. Agents should move the current milestone forward while preserving security, evidence semantics, large-file capability, reproducibility and clean architectural boundaries.

Explicit instructions from the repository owner for the current task take precedence. Accepted ADRs and current implementation/tests outrank stale planning prose; conflicts must be identified rather than silently guessed away.

## 1. Mission and non-negotiable principles

Binary Insight turns raw byte observations into traceable, persistent, versionable, testable and reusable engineering knowledge.

Preserve:
- read-only first;
- meaning before editing;
- evidence before assumption;
- large-file capability by design;
- Core independent from UI;
- local-first operation;
- reproducible analysis;
- security by design;
- reuse before reinvention;
- modular evolution rather than a monolith.

Do not turn the project into a generic hex editor, Ghidra/IDA clone, malware-development tool, password cracker, universal decryptor, cloud-only service or premature recovery suite.

## SASD Development Standard adoption

Apply the [SASD adoption assessment](docs/SASD-DEVELOPMENT-STANDARD.md) and [project brief](docs/PROJECT-BRIEF.md). The upstream German Approved normative baseline governs interpretation of applicable SASD requirements; English here is the default presentation language only. Determine project quality level and applicable profiles through formal classification before claiming compliance. Supporting upstream templates/tooling do not create independent requirements. Preserve proportionality and record actual verification evidence; do not claim SASD conformity from document presence alone.

## 2. Source-of-truth hierarchy

Before changing anything, inspect the actual target branch. Use this precedence:

1. current source/public contracts;
2. current tests and CI;
3. accepted ADRs in `docs/adr/`;
4. architecture documents;
5. Implementation Specification / Pflichtenheft;
6. Product Requirements / Lastenheft;
7. `ROADMAP.md` and README status;
8. research/history.

Start discovery at `README.md`, `ROADMAP.md`, `CONTRIBUTING.md`, `SECURITY.md`, `docs/README.md`, architecture, requirements and `docs/adr/`.

Research informs decisions but is not normative implementation specification.

## 3. Current state and Phase 0

The repository is currently **planning / pre-implementation**. Do not invent build commands, package names, source layout or runtime requirements before the relevant ADRs establish them.

Phase 0 priority is ADR-001 through ADR-010, repository/build/test structure, CI, fixtures, performance harness and the smallest read-only ByteProvider vertical slice. Do not start broad feature work while a foundational ADR required by that work is unresolved.

## 4. Dependency rule

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

Domain/Core must not depend on GUI frameworks, OS file APIs, network/cloud services, concrete external analysis engines or plugin runtimes. Application orchestrates use cases; analysis services consume abstract byte access; Infrastructure implements concrete I/O/persistence/external adapters.

Do not violate this boundary merely because a framework makes it convenient.

## 5. Byte access and large-file rules

The ByteProvider boundary is foundational.

- use 64-bit-capable offsets;
- validate range arithmetic and overflow;
- never require complete large sources in RAM;
- keep caches bounded;
- define EOF/short-read semantics;
- handle matches across chunk/page boundaries;
- treat cache/page size as implementation detail;
- keep V1 source access read-only;
- test boundaries, malformed input and truncation.

Do not add V1 write APIs "for later convenience."

## 6. Evidence and provenance

Automated findings must not overstate certainty. Preserve the conceptual levels **Confirmed, Strong, Probable, Heuristic, Unknown**.

High entropy is not proof of encryption. A signature is not automatically proof of complete file identity. Persisted/reportable findings retain suitable provenance such as source/rule and version. Confidence is a domain concept, not only a UI color.

## 7. Untrusted-input security

Treat every analysed source as untrusted.

- bounds-check offsets/lengths and arithmetic;
- distrust embedded sizes/counts/pointers;
- bound allocations, recursion and concurrency;
- return diagnostics for malformed/truncated input;
- never automatically execute embedded/project-provided code;
- do not log complete sensitive payloads by default;
- never store passwords/keys in projects;
- do not add telemetry or automatic uploads;
- do not weaken read-only behavior.

Vault, plugins, physical devices, editing and recovery each require their approved trust boundary/ADR before implementation.

## 8. Release discipline

Follow `ROADMAP.md`. Do not pull later features into V1 merely because they are easy to add.

- Diff/CLI: V1.1
- richer Format Workbench: V1.2
- Kaitai/extensibility: V1.5
- Executable/disassembly: V2
- Crypto/Vault: V2.5
- Disk/filesystem/device: V3
- scripting/plugins: V3.5
- Controlled Editing: V4
- Recovery/Repair: V5+

Scope changes update requirements/roadmap/architecture intentionally.

## 9. Coding rules

Until ADR-001 chooses the language/toolchain, do not impose language-specific conventions repository-wide.

After implementation starts:
- prefer clear, testable code over clever abstractions;
- document public contracts and non-obvious safety decisions;
- avoid speculative abstractions outside the current milestone;
- make error/diagnostic behavior explicit;
- avoid hidden global state;
- keep deterministic core behavior independent from UI/network/time where practical;
- fix the intended contract, not production semantics merely to satisfy a bad test.

## 10. Tests and fixtures

Use proportionate unit, boundary/property, integration, golden-fixture, corrupt/truncated, performance, security-regression and UI-smoke tests.

Never claim a build/test passed unless it actually ran successfully. Fixtures must be redistributable/generated; never commit customer/confidential data. Record provenance/licence for third-party fixture data.

## 11. Long-running operations

Search, strings, Pattern Scan, hashing, entropy, parsing, validation, diff and reporting must support cancellation, bounded resources and non-blocking UI operation. Define progress and partial-result semantics explicitly. Do not spawn uncontrolled parallel work.

## 12. Dependencies and licences

Before adding a mandatory dependency:
1. justify why it is needed now;
2. verify current upstream licence;
3. review transitive/runtime implications;
4. verify target platforms;
5. isolate external engines behind adapters where appropriate;
6. document durable choices in ADRs.

MIT/BSD/Apache-2.0 are preferred. LGPL requires deliberate review. GPL/AGPL must not be embedded casually. Never copy code simply because a project appears in research documentation.

## 13. Git and GitHub workflow

Agents may autonomously inspect repository state/history, fetch/prune, fast-forward local `main`, create a focused task branch, edit source/tests/docs, run established safe verification, create focused commits, push the non-main branch, create/update a PR and repair task-caused CI failures.

Use focused names such as `codex/<topic>`, `feat/<topic>`, `fix/<topic>`, `docs/<topic>`.

Before every push:
1. inspect status;
2. inspect diff/staged diff;
3. run relevant verification;
4. confirm the branch is not `main`;
5. push only the task branch.

Never autonomously:
- push directly to `main`;
- force-push/rewrite published history;
- destructively reset/clean unrelated user work;
- delete branches/tags/releases;
- publish releases/packages;
- change repository settings/secrets/permissions;
- install system-wide software;
- add a major dependency without required review.

Autonomous merge is allowed only when the owner/current task explicitly authorizes it and required checks are green. Otherwise leave a reviewable PR.

## 14. Development-environment safety

Prefer repository-local tools. Do not install system-wide software with winget/choco/MSI/apt/brew unless explicitly authorized. Do not alternate incompatible Git clients against the same working tree where this risks line-ending/permission corruption.

## 15. Documentation

English is the repository default; German documentation is maintained in parallel where established.

When contracts change, update the relevant normative document and ADR. Mark roadmap items complete only with evidence. Keep README claims aligned with implementation and concept UI explicitly labelled as concept. Avoid duplicating normative requirements when a reference is sufficient.

## 16. Stop conditions

Stop and ask rather than guess when alternatives materially change public semantics, a required foundational ADR is unresolved, a new mandatory runtime dependency is proposed, a security boundary would be weakened, write/device/recovery behavior is outside approved scope, credentials/signing/release publication are required, destructive history/data changes are needed, a supported platform would knowingly break, or licence compatibility is materially uncertain.

## 17. Definition of Done

A task is complete when applicable behavior/docs are complete, architecture boundaries remain intact, meaningful tests exist and actually ran, errors/cancellation/security implications are handled, ADR/roadmap/docs are synchronized, dependency licences are reviewed, the final diff is inspected, unrelated work is excluded and remaining limitations are stated.

For Phase 0 also apply the Architecture Definition of Done in `docs/de/architecture/ARCHITEKTUR.md`.

> Preserve the chain: **byte source → observation → evidence → structure → validation → project → reproducible output**.
