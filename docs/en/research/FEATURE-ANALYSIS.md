# Feature and Market Analysis

This is the repository-oriented edition of the initial feature analysis. It is complemented by the more extensive [Open-Source Hex Editor Catalogue](OPEN-SOURCE-HEX-EDITOR-CATALOG.md).

## Tool classes reviewed

- classic hex/binary editors;
- template/grammar-driven editors;
- declarative binary-format languages and parser generators;
- reverse-engineering suites;
- binary-diff tools;
- large-file/raw-device editors;
- CLI/TUI tools;
- embeddable hex components.

## Key references

| Tool | Strength | SASD lesson |
|---|---|---|
| 010 Editor | Binary Templates, scripting, large files | structured interpretation |
| ImHex | Pattern Language, visualisation, modern analysis UX | pattern + workbench |
| Hex Fiend | large files, efficient file model | performance |
| Synalyze It! | GUI grammars | visual format modelling |
| Kaitai Struct | declarative formats, parser generation | format knowledge as code |
| Ghidra | RE project model, disassembly/decompilation | analysis artifacts |
| radare2/Rizin/Cutter | CLI/API/pipelines | automation |
| rehex | annotations, templates, diff, disassembly | integrated navigation |
| HexWalk | signatures, entropy, byte map | analysis visualisation |
| Q22 | PE/ELF + disassembly | Executable Insight |
| fhex | configurable colour rules | pattern overlays |
| wxHexEditor | large files, raw devices | device/large-file model |
| VBinDiff | focused binary diff | simple compare UX |

## Recurring feature clusters

### Hex-editor baseline

Hex/text, offsets, search, selection, copy/paste, bookmarks, hashes and a data inspector are expected features but not sufficient differentiation.

### Structured interpretation

Templates, grammars and pattern languages turn raw bytes into named fields, arrays and structures. SASD deliberately starts V1 with a limited declarative model and expands it incrementally.

### Analysis artifacts

Professional analysis needs format definitions, annotations, test files, expected results, reports and version history. This is central to the SASD approach.

### Diff at multiple levels

Byte diff is useful; structure diff is strategically stronger: field name, old/new value, added/removed/changed and validation consequences.

### Automation

CLI/API/batch operation makes the engine reusable in CI, import validation, migration, support and training.

### Learning and documentation

Explanations, confidence, annotated format definitions and reports are important SASD differentiators.

## Ideas adopted for V1

- read-only large-file provider;
- Hex/ASCII + Data Inspector;
- bookmarks/annotations;
- Pattern Engine and coloured categories;
- Confidence/Evidence;
- minimal structure model;
- validation;
- hashing;
- strings;
- entropy/byte frequency;
- project file;
- Markdown/HTML reporting.

## Deliberately later

- byte/structure diff and CLI: V1.1;
- richer format model: V1.2;
- Kaitai: V1.5;
- PE/ELF/disassembly: V2;
- Crypto/Vault: V2.5;
- Disk/Filesystem: V3;
- scripting/plugins: V3.5;
- editing: V4;
- recovery/repair: V5+.

## Main risks

Scope explosion from attempting to reproduce ImHex, 010 Editor and Ghidra at once; premature file/device writes; an overly complex home-grown template language; a file model that does not scale; unclear target users; licensing mistakes from direct GPL/AGPL reuse; and false certainty from heuristic findings.

## Conclusion

The research does not justify another generic hex editor. It does support a **secure, evidence-aware Binary Knowledge Workbench** if SASD reuses suitable foundations and concentrates on reproducible analysis, documentation, validation and integration.
