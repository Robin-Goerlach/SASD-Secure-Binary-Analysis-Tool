# Architecture Decision Records / Architekturentscheidungen

This directory records durable architectural decisions for SASD Binary Insight.

## Planned initial ADRs

1. Core language and platform / Programmiersprache und Core-Plattform
2. GUI technology and relationship to SASD UI Toolkit/UI Platform
3. ByteProvider and large-file model
4. Project file format
5. V1 format-definition representation
6. Pattern registry and rule-pack format
7. Confidence/evidence model
8. Hash/checksum abstraction
9. Reporting pipeline
10. Dependency and licence policy
11. Disassembler library before V2
12. Secure buffer / Vault boundary before V2.5
13. Disk/device provider before V3

## Accepted decisions

- [ADR-001: Core language and platform](ADR-001-core-language-and-platform.md)

ADRs should contain both English and German sections in the same file. This mirrors the approach used by other SASD repositories and prevents architectural rationale from drifting between translations.

No item in this list is considered decided merely because it is listed here.

## Creating an ADR

Use [TEMPLATE.md](TEMPLATE.md). Keep English and German sections in the same ADR. Once an ADR is Accepted, preserve its historical rationale; supersede it with a new ADR rather than silently rewriting the decision.
