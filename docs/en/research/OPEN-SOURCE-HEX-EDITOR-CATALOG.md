# Open-Source Hex Editor and Binary-Analysis Catalogue

**Baseline:** 2026-10-08  
**Purpose:** research baseline for SASD Binary Insight. Licence and feature claims must be rechecked against the current upstream before direct code reuse.

## Modern GUI editors and analysis platforms

### ImHex
https://github.com/WerWolv/ImHex

C++ reference for visual binary analysis: Pattern Language, structure interpretation/highlighting, Data Inspector, visualisation, patches and a broad workbench. Primary benchmark for pattern UX.

### rehex
https://github.com/solemnwarning/rehex

Large files, byte-range comments/annotations, binary templates, diff and inline disassembly. Reference for synchronising offsets, annotations, virtual addresses and instructions.

### HexWalk
https://github.com/gcarmix/hexwalk

Qt/C++ with hex view, signature detection, entropy, byte map, hashing and disassembly. Reference for a modular analysis workbench.

### Q22
https://github.com/strobejb/q22

C++/Qt6 with PE/ELF structures, headers/sections, imports/exports/symbols and multi-architecture disassembly. Important for Executable Insight and file-offset ↔ virtual-address mapping.

### fhex
https://github.com/echo-devim/fhex

C++/Qt with configurable coloured pattern rules, labels, diff and optional disassembly/assembly integration. Demonstrates that coloured sequences are useful but not a standalone USP.

### WingHexExplorer2
https://github.com/Wing-summer/WingHexExplorer2

Large modular Qt application. Interesting for plugin/desktop architecture; AGPL requires careful licensing review before integration.

### EUVA
https://github.com/Euva-Project/EUVA

Windows/C#-oriented hex/RE environment with PE focus. Reference for .NET architecture and executable-centred UX.

### Hex Fiend
https://github.com/HexFiend/HexFiend

macOS editor and performance reference. Large files without complete loading; insert/delete/rearrange and templates. Storage model and rendering are particularly relevant to SASD.

### Okteta
https://github.com/KDE/okteta

KDE/Qt hex editor with separated core/GUI libraries and structured data views. Reference for reusable components and library boundaries.

### GHex / libgtkhex
https://github.com/GNOME/ghex

GNOME hex editor with a separate GTK hex component. Reference for Linux/GTK integration.

### BinEd
https://github.com/exbin/bined

Java binary editor and component family. Useful modular architecture reference; Apache-2.0 makes the library side worth evaluation where applicable.

## Classic and specialised GUI editors

- **wxHexEditor** – https://github.com/EUA/wxHexEditor – very large files, raw devices, comparison and low-level access.
- **Bless** – https://github.com/afrantzis/bless – GTK#, tabs, search, undo/redo, classic desktop baseline.
- **wxMEdit** – https://github.com/wxMEdit/wxMEdit – text/column/hex editor, Unicode/encoding.
- **Microhex** – https://github.com/zenwarr/microhex – Python/Qt, configurable data/column views.
- **Frhed** – https://github.com/datadiode/frhed – classic Windows hex editor.
- **chipmunk-sm/HexEditor** – https://github.com/chipmunk-sm/HexEditor – small C++/Qt comparison candidate.
- **Catch22 HexEdit 2.0** – historical reference and predecessor/relative of Q22.
- **Hexplorer** – historical Windows binary-analysis reference; recheck upstream/licence before use.

## Terminal, CLI and binary diff

### GNU poke
https://www.jemarch.net/poke

Programmable binary editor with its own language and reusable format descriptions. Strategic reference for structure models, CLI and expressive power.

### dz6
https://github.com/mentebinaria/dz6

Vim-inspired TUI hex editor with comments, bookmarks, coloured blocks and executable-file support.

### HexPatch
https://github.com/Etto48/HexPatch

Rust TUI for binary patching and machine-code work including disassembly/assembly. Verify current licence before reuse.

### ddhx
https://github.com/dd86k/ddhx

Modern terminal editor with large files, search, bookmarks and Data Inspector. Strong keyboard-first reference.

### Additional terminal/CLI references

- **hecate** – https://github.com/evanmiller/hecate – numeric interpretation alongside bytes.
- **bvi** – https://bvi.sourceforge.net/ – vi-style binary editor.
- **dhex** – https://www.dettus.net/dhex/ – ncurses editor with comparison.
- **Hexer** – https://devel.ringlet.net/editors/hexer/ – lightweight vi-style editor.
- **VBinDiff** – https://github.com/madsen/vbindiff – focused visual binary diff.
- **hexyl** – https://github.com/sharkdp/hexyl – colourised CLI hex dump.
- **xxd, hexdump/hd, od** – classic reproducible CLI dumps.
- **HT Editor / BIEW / BEYE** – historical executable-oriented viewers/editors.

## Embeddable components

### QHexEdit2
https://github.com/Simsys/qhexedit2

Qt5/Qt6 hex widget with undo/redo and QIODevice-backed data. Evaluate before implementing an entire Qt hex control. Verify the current LGPL licensing upstream before integration.

### Parallax QHexEdit
https://github.com/parallaxinc/QHexEdit

Alternative QHexEdit variant and possible Qt evaluation candidate.

### Other components

- **Okteta Libraries** – https://github.com/KDE/okteta – core/GUI libraries.
- **libgtkhex** – https://github.com/GNOME/ghex – GTK hex component.
- **BinEd Library** – https://github.com/exbin/bined-lib-java – Java component.
- **Hex Fiend Framework** – https://github.com/HexFiend/HexFiend – macOS framework and storage reference.
- **VS Code Hex Editor** – https://github.com/microsoft/vscode-hexeditor – MIT, modern editor UX and Data Inspector.

## Adjacent analysis engines

- **Kaitai Struct** – https://github.com/kaitai-io/kaitai_struct – declarative binary formats and parser generation; strategic for V1.5.
- **Binwalk** – https://github.com/ReFirmLabs/binwalk – firmware/container signature analysis.
- **Ghidra** – https://github.com/NationalSecurityAgency/ghidra – disassembly, decompilation, graphs and scripting; benchmark, not a clone target.
- **radare2** – https://github.com/radareorg/radare2 – scriptable low-level/RE framework.
- **Rizin** – https://github.com/rizinorg/rizin – modern RE platform.
- **Cutter** – https://github.com/rizinorg/cutter – Rizin GUI; core/UI separation reference.
- **Capstone** – https://github.com/capstone-engine/capstone – multi-architecture disassembler; primary V2 evaluation candidate.
- **Zydis** – https://github.com/zyantific/zydis – fast x86/x64 decoder.
- **YARA-X** – https://github.com/YARA-X/yara-x – rule-based file identification.
- **file/libmagic** – https://github.com/file/file – mature magic/file-type identification.

## Commercial and source-available benchmarks

- **010 Editor** – https://www.sweetscape.com/010editor/ – Binary Templates, scripting, large files.
- **HxD** – https://mh-nexus.de/en/hxd/ – fast Windows baseline UX.
- **Synalyze It!** – https://www.synalysis.net/ – GUI grammars.
- **Hiew** – https://www.hiew.ru/ – hex/text/disassembler.
- **Hextor** – https://github.com/digitalw0lf/hextor – source-available/freeware; do not assume open source.
- **Hexinator** – commercial grammar/template-oriented editor.
- **WinHex / X-Ways** – forensic disk/filesystem benchmark.
- **IDA** – https://hex-rays.com/ida-pro – industry RE benchmark.
- **Binary Ninja** – https://binary.ninja/ – modern RE platform with API/IL focus.

## SASD conclusions

Hex/ASCII, coloured highlights, entropy, signatures, templates, disassembly, byte diff and a Data Inspector are not unique features.

SASD should adopt: performant ByteProvider, virtual hex rendering, Pattern Registry/rule packs, Data/Structure Inspector, bookmarks/annotations, entropy/byte frequency, binary and later structure diff, declarative formats, Kaitai compatibility, an external disassembler engine, CLI/headless core, project persistence and reporting.

SASD-specific differentiation remains: **Confidence/Evidence**, an analysis record rather than a session, explicit facts-vs-heuristics presentation, versioned/testable format knowledge, a path from analysis into validation/documentation/tests and secure integration with Vault and Optical Media Workbench.

## Evaluation plan

First practical comparison set: **ImHex, rehex, GNU poke, Q22, HexWalk, fhex and Hex Fiend**. Evaluate QHexEdit2 and alternative controls separately.

Shared fixtures: 2 GB file, navigation/search, damaged PNG header, custom SASD format, binary diff, PE/ELF + disassembly, signatures/false positives and annotation persistence.

## Licence rule

Feature ideas may be studied; code reuse is separate. MIT/BSD/Apache are preferred, LGPL reviewed case by case. GPL/AGPL is not embedded casually. The current licence file of the exact upstream is authoritative.
