# SASD Secure Binary Analysis Tool

**SASD Binary Insight** is a secure, extensible binary-analysis workbench for developers, researchers, administrators and security professionals.

The project aims beyond a traditional hex editor: byte-level findings should become **evidence-aware, reproducible engineering knowledge** through patterns, structure models, annotations, validation, comparison, reports and later automation.

> Project status: **planning / pre-implementation baseline**. The consolidated specification is dated 2026-10-08. Features described here are planned unless explicitly marked as implemented.

## Documentation

Documentation is maintained in **English and German**.

### English

- [Documentation index](docs/en/README.md)
- [Consolidated specification](docs/en/requirements/SPECIFICATION.md)
- [Product strategy](docs/en/strategy/PRODUCT-STRATEGY.md)
- [Feature analysis](docs/en/research/FEATURE-ANALYSIS.md)
- [Open-source hex editor catalogue](docs/en/research/OPEN-SOURCE-HEX-EDITOR-CATALOG.md)

### Deutsch

- [Dokumentationsübersicht](docs/de/README.md)
- [Konsolidiertes Pflichtenheft](docs/de/requirements/PFLICHTENHEFT.md)
- [Produktstrategie](docs/de/strategy/PRODUKTSTRATEGIE.md)
- [Feature-Analyse](docs/de/research/FEATURE-ANALYSE.md)
- [Open-Source-Hex-Editor-Katalog](docs/de/research/OPEN-SOURCE-HEX-EDITOR-KATALOG.md)

Architecture decisions will be recorded in the [ADR directory](docs/adr/README.md).

## Planned product direction

The V1 foundation is read-only and large-file capable. It combines Hex/ASCII viewing, a Data Inspector, search, bookmarks/annotations, analysis projects, hashing, strings, a Pattern Engine, confidence/evidence classification, a minimal structure model, validation, entropy/statistics and reproducible reporting.

Later releases are planned for executable analysis and disassembly, authorised crypto/Vault insight, disk/filesystem analysis, controlled automation/plugins and—only after a separate safety decision—binary editing and recovery functions.

## Security posture

Binary Insight is **local-first and read-only-first**. It is not intended as a password cracker, universal decryptor, malware deployment tool or one-click disk repair utility. Potentially destructive or sensitive capabilities are separated into later modules with explicit trust boundaries.

## Repository

https://github.com/Robin-Goerlach/SASD-Secure-Binary-Analysis-Tool
