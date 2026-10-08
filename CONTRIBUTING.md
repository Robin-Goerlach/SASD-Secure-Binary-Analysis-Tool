# Contributing to SASD Secure Binary Analysis Tool

Thank you for contributing to **SASD Binary Insight**. The project is currently planning/pre-implementation, so contributions must respect unresolved ADRs rather than silently deciding them through code.

## Read first

Read the README, ROADMAP, architecture, Product Requirements, Implementation Specification, ADR index, SECURITY policy and AGENTS rules when using coding agents.

## Principles

Keep V1 read-only; preserve Domain/Core independence from UI; design for large files without full loading; treat input as untrusted; distinguish evidence from heuristics; preserve provenance; prefer small vertical slices; avoid premature dependencies; keep high-risk later modules outside V1.

## Workflow

1. Start from current `main`.
2. Create a focused `feat/...`, `fix/...`, `docs/...` or `test/...` branch.
3. Make one coherent change.
4. Add/update tests and documentation.
5. Run established verification commands once Phase 0 defines them.
6. Review `git diff`, `git diff --check` and status.
7. Push the branch and open a pull request.
8. Address CI/review findings without unrelated cleanup.

Do not normally push directly to `main`.

## Commits and PRs

Prefer small commits such as `feat:`, `fix:`, `test:`, `docs:`, `refactor:`, `build:` and `ci:`.

A PR should state goal, scope/non-scope, architecture/security impact, verification actually run, documentation/ADR changes, dependency/licence changes and known limitations. Never claim tests passed unless they ran.

## Architecture decisions

Durable choices about language/platform, GUI, ByteProvider, project format, format definitions, pattern packs, evidence, reporting, dependencies, disassembly, Vault or device access belong in ADRs. Do not quietly decide an unresolved foundational ADR through implementation.

## Security and fixtures

Parser/input/plugin/Vault/device/write/recovery changes require explicit security review. Never use secrets or confidential/customer binaries as fixtures. Prefer deterministic redistributable/generated fixtures and test chunk boundaries, malformed/truncated input, overflow/bounds and cancellation.

## Dependencies

Document why a new dependency is needed, current licence, platform/maintenance implications and alternatives. External engines should normally sit behind adapters.

## Documentation language

English is the repository default. German companion documentation is maintained where established; normative intent must not diverge.

## Build instructions

The initial C++20/CMake foundation is available locally:

```text
cmake --preset default
cmake --build --preset default
ctest --preset default
```

Use `cmake --preset release` for a release configuration. Other languages may
be added as independent modules; document their toolchain next to the module.

## Conduct

Be professional, technically specific and respectful. Critique designs and evidence rather than people. Security concerns and dissenting architecture reviews are welcome when supported by reproducible reasoning.
