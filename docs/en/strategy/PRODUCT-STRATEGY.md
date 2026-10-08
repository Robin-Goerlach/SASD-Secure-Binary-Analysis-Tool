# Product Strategy – SASD Binary Insight

**Baseline:** 2026-10-08  
**Origin:** consolidated from the strategic Q&A, feature analysis and later product decisions.

## Core decision

The relevant question is not “Does SASD need its own hex editor?” but:

> **Which binary-data problems faced by SASD and its customers remain poorly integrated into reproducible engineering workflows despite the existing tools?**

A classic hex editor is interchangeable. Binary Insight should turn analysis into durable, versioned engineering knowledge.

## Why the product exists

SASD works, or expects to work, with logs, data transfer, import formats, scientific data, embedded/firmware, storage media, protocols and training material. Seeing bytes is not enough: fields need names, values need validation, versions need comparison and findings need a path into parsers, tests and documentation.

## Primary user

V1 is built for SASD itself first: developers, administrators and trainers analysing real binary data. Later audiences include technical users in smaller companies, research/training and authorised security/forensic scenarios.

## Differentiation

Not a “better hex editor”, but **analysis knowledge as a product artifact**:

- project rather than disposable session;
- meaning rather than bytes alone;
- evidence/confidence rather than unsupported claims;
- documentation rather than screenshots;
- validation rather than interpretation alone;
- CLI/automation rather than a GUI island;
- SASD integration rather than an isolated tool.

## Product boundaries

V1 is not a Ghidra clone, malware laboratory, complete binary editor, recovery suite or cloud service. Risky capabilities are separated in both architecture and roadmap.

## Standalone product and platform architecture

The application must work locally and standalone. Internally it is designed as a platform composed of core, project model, format/pattern engines, reporting and UI adapters. This allows later CLI, plugins and additional hosts without rewriting analysis logic.

## Automation

V1 keeps data models and projects independent of the GUI. V1.1 introduces the first CLI. Controlled scripting and plugins come only after a permission model exists.

## Data scale

- KB–MB: fully comfortable;
- GB: V1 must open, navigate, search and analyse;
- tens/hundreds of GB: progressive optimisation in V2/V3;
- TB: specialist case using streaming/index/provider architecture.

## Platform strategy

Linux is strategically required for V1. Windows should arrive in V1 or at the latest V1.1/V1.5. macOS follows later. OpenBSD is desirable for Core/CLI where dependencies permit.

## Security strategy

- local processing by default;
- read-only first;
- no mandatory telemetry;
- no automatic script execution;
- sensitive payloads are not silently logged or exported;
- Vault keys remain owned by the Vault;
- physical-device access is explicit and read-only;
- write/recovery features require their own threat/safety assessment.

## Business development

The tool may start as an internal SASD product. Real internal use is the route to product maturity. Only afterwards should SASD decide on a community/plugin ecosystem, commercial editions or consulting/training packages.

## Long-term direction

Binary Insight grows deliberately from the **Secure Binary Analysis Foundation** through Executable, Crypto/Vault and Disk/Filesystem Insight into an automation platform. Controlled Editing and Recovery remain optional later risk classes.

## Success criterion

Success is not the number of implemented features. It is whether SASD repeatedly chooses Binary Insight for real binary-analysis work, can reproduce previous analyses and can turn findings into documentation, tests or software.
