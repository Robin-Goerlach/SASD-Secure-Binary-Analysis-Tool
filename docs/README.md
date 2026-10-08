# SASD Secure Binary Analysis Tool – Documentation

This directory is the documentation entry point for **SASD Secure Binary Analysis Tool / SASD Binary Insight**.

The structure follows established SASD repository conventions: language-specific product documentation is separated from architecture decision records, while requirements, research and strategy remain clearly distinguishable.

## Requirements model

The documentation deliberately distinguishes the German engineering concepts **Lastenheft** and **Pflichtenheft**:

- **Lastenheft / Product Requirements:** customer/user perspective – what is required and why.
- **Pflichtenheft / Implementation Specification:** derived technical solution – how the requirements are intended to be fulfilled.

The 2026-10-08 requirements/specification pair forms the current product baseline. Requirement IDs are intended to support traceability into implementation, tests and acceptance.

## English

- [Product requirements](en/requirements/REQUIREMENTS.md)
- [Implementation specification](en/requirements/SPECIFICATION.md)
- [Product strategy](en/strategy/PRODUCT-STRATEGY.md)
- [Feature and market analysis](en/research/FEATURE-ANALYSIS.md)
- [Open-source hex editor and binary-analysis catalogue](en/research/OPEN-SOURCE-HEX-EDITOR-CATALOG.md)
- [Documentation index](en/README.md)

## Deutsch

- [Lastenheft](de/requirements/LASTENHEFT.md)
- [Pflichtenheft](de/requirements/PFLICHTENHEFT.md)
- [Produktstrategie](de/strategy/PRODUKTSTRATEGIE.md)
- [Feature- und Marktanalyse](de/research/FEATURE-ANALYSE.md)
- [Open-Source-Hex-Editor- und Binäranalyse-Katalog](de/research/OPEN-SOURCE-HEX-EDITOR-KATALOG.md)
- [Dokumentationsübersicht](de/README.md)

## Architecture

- [English architecture](en/architecture/ARCHITECTURE.md)
- [Detailed German architecture](de/architecture/ARCHITEKTUR.md)

## Architecture Decision Records

- [ADR index](adr/README.md)

ADRs are intended to be bilingual in a single file so architectural rationale cannot silently diverge between German and English.

## Documentation policy

German and English documents describe the same technical intent. They do not have to be literal sentence-by-sentence translations, but requirements, release assignments, security boundaries and architectural decisions must remain equivalent.

Research documents are evidence and decision support. The requirements/specification pair defines the maintained product baseline unless superseded by a later approved baseline or ADR.

## Repository governance

- [Project status](../PROJECT-STATUS.md)
- [Roadmap](../ROADMAP.md)
- [Contributing](../CONTRIBUTING.md)
- [Security policy](../SECURITY.md)
- [Changelog](../CHANGELOG.md)
- [Agent operating contract](../AGENTS.md)

## SASD Development Standard

- [Adoption and gap assessment](SASD-DEVELOPMENT-STANDARD.md)
- [Project brief](PROJECT-BRIEF.md)
- [Upstream SASD Development Standard](https://github.com/Robin-Goerlach/SASD-Development-Standard)
