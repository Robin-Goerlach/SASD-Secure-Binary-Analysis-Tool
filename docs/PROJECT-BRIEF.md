# Project Brief — SASD Secure Binary Analysis Tool

**Status:** Proposed; pending owner review and formal SASD project classification  
**Date:** 2026-10-08  
**Project owner:** SASD / repository maintainer  
**Lifecycle:** intended long-lived open-source product

## Problem

Binary-data investigations commonly fragment knowledge between hex editors, parsers, scripts, screenshots and notes. Existing tools provide powerful individual capabilities, but a persistent, evidence-aware and reproducible engineering analysis workflow is the target gap.

## Objective and value

Deliver a secure, local-first workbench that turns byte observations into structured findings, validation, annotations and reproducible reports. Support reuse of analysis knowledge across projects and, later, GUI/CLI/automation.

## Target users

Developers analysing binary formats, researchers, administrators and authorized security professionals; initially SASD's own workflows.

## V1 scope

Read-only large-file access; Hex/Text and Data Inspector; search/strings; bookmarks, annotations and projects; patterns with confidence/provenance; minimal structure model/validation; hashes, entropy/statistics; Markdown/HTML reporting.

## Explicit non-goals

General editing, physical-device writes, partition repair, debugger/decompiler, generic plugins/scripting, password cracking, universal decryption, cloud requirement and production malware tooling.

## Constraints and risks

Untrusted input; safe bounds and overflow; bounded memory; no automatic code execution; local privacy; no secrets in project files; licensing of third-party libraries; cross-platform decisions unresolved until ADRs.

## Success and acceptance

The V1 acceptance criteria in the [Product Requirements](en/requirements/REQUIREMENTS.md) and [Implementation Specification](en/requirements/SPECIFICATION.md) govern verification. Key proof includes >1GB without full loading, correct cross-page operations, deterministic fixtures, project persistence, evidence-aware findings, reproducible reports and no unprompted network upload.

## Open decisions

ADR-001–010; formal SASD size/quality/profile classification; approved toolchain and GUI; exact upstream SASD standard baseline; test/CI/release evidence.

## Next milestone

Phase 0: accepted foundation decisions, reproducible build/test/CI, fixtures, performance/security baseline and smallest read-only ByteProvider slice.

## Governance

See [SASD Standard adoption assessment](SASD-DEVELOPMENT-STANDARD.md), [Roadmap](../ROADMAP.md) and [Project Status](../PROJECT-STATUS.md). This brief is intentionally compact and does not duplicate the full Lastenheft.
