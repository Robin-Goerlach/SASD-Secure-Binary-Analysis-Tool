# Security Policy — SASD Binary Insight

## Security posture

Binary Insight is designed to inspect **untrusted binary data**. Security is therefore an architecture concern from the beginning. The repository is currently pre-implementation and has no production release.

## Supported versions

Until the first release, only the current development line is relevant. A release support table will be added when releases exist.

## Reporting vulnerabilities

Do **not** publish exploitable details, credentials, keys, private samples or customer data in a public issue. Use GitHub private security reporting for this repository when available. If it is unavailable, contact the repository owner privately through an established trusted channel and do not attach sensitive material publicly.

Useful reports include affected commit/version, component, non-sensitive reproduction, expected/actual behavior, impact and sanitized diagnostics.

## Threat baseline

Every analysed file, image, executable, project-referenced source and later device/Vault stream is untrusted. Primary risks include integer overflow, out-of-bounds access, resource exhaustion, parser complexity/recursion, malformed encodings, crafted rules/formats, unsafe third-party engines and leakage through logs/reports/projects.

### Read-only first

V1 must not modify analysed sources. Future writing/device/recovery capabilities require explicit architecture and security decisions.

### Local first

No mandatory telemetry, cloud account or automatic source upload.

### Code execution

Opening a source or project must not automatically execute embedded/project-provided code. Plugins/scripting are later trust boundaries with explicit permissions.

### Secrets

Projects/logs must not contain passwords, cryptographic keys or unnecessary payload copies. Future Vault integration leaves authentication and key ownership in SASD Vault.

## Secure implementation requirements

When implementation begins:
- validate offset/length arithmetic and overflow;
- enforce bounds before reads;
- distrust embedded sizes/counts/pointers;
- bound allocations/concurrency/recursion;
- diagnose corrupt/truncated input safely;
- support cancellation for expensive analysis;
- avoid sensitive full-payload logging;
- isolate third-party parsers/disassemblers behind reviewed adapters;
- add boundary/property/fuzz-style tests where practical;
- add a regression test for each fixed security defect.

## Dependencies

Dependencies require licence/security review and reproducible resolution where supported. Vulnerability scanning should be added during Phase 0 after the package ecosystem is selected.

## Future trust boundaries

Separate ADR/review is required before disassembly (V2), Vault/secure buffers (V2.5), physical devices (V3), plugins/scripting (V3.5), Controlled Editing (V4) and Recovery/Repair (V5+).

## Security issue handling

A confirmed issue should receive private triage, severity/scope assessment, a minimal non-sensitive regression fixture, a verified fix, supported-version review and coordinated disclosure/release notes when appropriate.

Never weaken a test or suppress a diagnostic merely to hide a security failure.

## Non-goals

The project is not intended for password cracking, credential harvesting, protection bypass, universal decryption, exploit generation or malware deployment.
