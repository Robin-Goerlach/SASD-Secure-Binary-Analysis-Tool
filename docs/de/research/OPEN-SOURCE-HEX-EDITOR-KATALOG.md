# Open-Source-Hex-Editor- und Binäranalyse-Katalog

**Stand:** 2026-10-08  
**Zweck:** Research-Baseline für SASD Binary Insight. Lizenz- und Funktionsangaben müssen vor direkter Codeübernahme erneut anhand des aktuellen Upstreams geprüft werden.

## Moderne GUI-Editoren und Analyseplattformen

### ImHex
https://github.com/WerWolv/ImHex

C++-Referenz für visuelle Binäranalyse: Pattern Language, Strukturinterpretation und Hervorhebung, Data Inspector, Visualisierung, Patches und Analyse-Workspace. Wichtigste Benchmark für Pattern-UX.

### rehex
https://github.com/solemnwarning/rehex

Große Dateien, Kommentare/Annotationen auf Bytebereichen, Binärtemplates, Diff und Inline-Disassembly. Referenz für die Synchronisierung von Byteoffset, Annotation, virtueller Adresse und Maschinenbefehlen.

### HexWalk
https://github.com/gcarmix/hexwalk

Qt/C++ mit Hexansicht, Signaturerkennung, Entropie, Byte Map, Hashing und Disassembly. Referenz für eine modulare Analyse-Workbench.

### Q22
https://github.com/strobejb/q22

C++/Qt6 mit PE-/ELF-Strukturen, Header/Sections, Imports/Exports/Symbolen und Multi-Architecture-Disassembly. Wichtig für Executable Insight und File Offset ↔ Virtual Address.

### fhex
https://github.com/echo-devim/fhex

C++/Qt mit konfigurierbaren farbigen Pattern-Regeln, Labels, Diff sowie optionaler Disassembly/Assembly-Anbindung. Zeigt, dass farbige Sequenzen nützlich, aber kein eigenständiger USP sind.

### WingHexExplorer2
https://github.com/Wing-summer/WingHexExplorer2

Umfangreiche modulare Qt-Anwendung. Interessant für Plugin-/Desktop-Architektur; AGPL vor Integration sorgfältig prüfen.

### EUVA
https://github.com/Euva-Project/EUVA

Windows-/C#-orientierte Hex-/RE-Umgebung mit PE-Fokus. Referenz für .NET-Architektur und executable-zentrierte UX.

### Hex Fiend
https://github.com/HexFiend/HexFiend

macOS-Editor und Performance-Referenz. Große Dateien ohne vollständiges Laden; Insert/Delete/Rearrange und Templates. Dateimodell und Rendering sind für SASD besonders interessant.

### Okteta
https://github.com/KDE/okteta

KDE/Qt-Hexeditor mit getrennten Core-/GUI-Bibliotheken und strukturierten Datenansichten. Referenz für wiederverwendbare Komponenten und Bibliotheksgrenzen.

### GHex / libgtkhex
https://github.com/GNOME/ghex

GNOME-Hexeditor mit separater GTK-Hex-Komponente. Referenz für Linux-/GTK-Integration.

### BinEd
https://github.com/exbin/bined

Java-Binäreditor und Komponentenfamilie. Interessant als modulare Architektur; Apache-2.0 macht die Bibliotheksseite grundsätzlich prüfenswert.

## Klassische und spezialisierte GUI-Editoren

- **wxHexEditor** – https://github.com/EUA/wxHexEditor – sehr große Dateien, Rohdatenträger, Vergleich und Low-Level-Zugriff.
- **Bless** – https://github.com/afrantzis/bless – GTK#, Tabs, Suche, Undo/Redo, klassische Desktop-Basis.
- **wxMEdit** – https://github.com/wxMEdit/wxMEdit – Text-/Spalten-/Hexeditor, Unicode/Encoding.
- **Microhex** – https://github.com/zenwarr/microhex – Python/Qt, konfigurierbare Daten-/Spaltenansichten.
- **Frhed** – https://github.com/datadiode/frhed – klassischer Windows-Hexeditor.
- **chipmunk-sm/HexEditor** – https://github.com/chipmunk-sm/HexEditor – kleiner C++/Qt-Vergleichskandidat.
- **Catch22 HexEdit 2.0** – historische Referenz und Vorgänger/Verwandter von Q22.
- **Hexplorer** – historische Windows-Binäranalyse-Referenz; Upstream/Lizenz vor Nutzung neu prüfen.

## Terminal, CLI und Binary Diff

### GNU poke
https://www.jemarch.net/poke

Programmierbarer Binäreditor mit eigener Sprache und wiederverwendbaren Formatbeschreibungen. Strategische Referenz für Strukturmodelle, CLI und Ausdrucksstärke.

### dz6
https://github.com/mentebinaria/dz6

Vim-inspirierter TUI-Hexeditor mit Kommentaren, Bookmarks, farbigen Blöcken und Programmdatei-Unterstützung.

### HexPatch
https://github.com/Etto48/HexPatch

Rust-TUI für Binärpatching und Maschinencode-nahe Arbeit einschließlich Disassembly/Assembly. Aktuelle Lizenz vor Übernahme prüfen.

### ddhx
https://github.com/dd86k/ddhx

Moderner Terminaleditor mit großen Dateien, Suche, Bookmarks und Data Inspector. Gute keyboard-first Referenz.

### Weitere Terminal-/CLI-Referenzen

- **hecate** – https://github.com/evanmiller/hecate – numerische Interpretation direkt bei den Bytes.
- **bvi** – https://bvi.sourceforge.net/ – vi-artiger Binäreditor.
- **dhex** – https://www.dettus.net/dhex/ – ncurses-Editor mit Vergleich.
- **Hexer** – https://devel.ringlet.net/editors/hexer/ – schlanker vi-artiger Editor.
- **VBinDiff** – https://github.com/madsen/vbindiff – fokussierter visueller Binary Diff.
- **hexyl** – https://github.com/sharkdp/hexyl – farbiger CLI-Hexdump.
- **xxd, hexdump/hd, od** – klassische reproduzierbare CLI-Dumps.
- **HT Editor / BIEW / BEYE** – historische executable-nahe Viewer/Editoren.

## Einbettbare Komponenten

### QHexEdit2
https://github.com/Simsys/qhexedit2

Qt5/Qt6-Hex-Widget mit Undo/Redo und QIODevice-basierter Datenquelle. Vor Eigenentwicklung eines Qt-Hex-Controls evaluieren. LGPL-Angabe vor Integration am aktuellen Upstream verifizieren.

### Parallax QHexEdit
https://github.com/parallaxinc/QHexEdit

Alternative QHexEdit-Variante und möglicher Qt-Evaluationskandidat.

### Weitere Komponenten

- **Okteta Libraries** – https://github.com/KDE/okteta – Core-/GUI-Bibliotheken.
- **libgtkhex** – https://github.com/GNOME/ghex – GTK-Hexkomponente.
- **BinEd Library** – https://github.com/exbin/bined-lib-java – Java-Komponente.
- **Hex Fiend Framework** – https://github.com/HexFiend/HexFiend – macOS-Framework und Storage-Referenz.
- **VS Code Hex Editor** – https://github.com/microsoft/vscode-hexeditor – MIT, moderne Editor-UX und Data Inspector.

## Verwandte Analyse-Engines

- **Kaitai Struct** – https://github.com/kaitai-io/kaitai_struct – deklarative Binärformate und Parsergenerierung; strategisch für V1.5.
- **Binwalk** – https://github.com/ReFirmLabs/binwalk – Firmware-/Container-Signaturanalyse.
- **Ghidra** – https://github.com/NationalSecurityAgency/ghidra – Disassembly, Decompilation, Graphen, Scripting; Benchmark, kein Nachbauziel.
- **radare2** – https://github.com/radareorg/radare2 – skriptbares Low-Level-/RE-Framework.
- **Rizin** – https://github.com/rizinorg/rizin – moderne RE-Plattform.
- **Cutter** – https://github.com/rizinorg/cutter – GUI auf Rizin-Basis; Core/UI-Trennung.
- **Capstone** – https://github.com/capstone-engine/capstone – Multi-Architecture-Disassembler; primärer V2-Evaluationskandidat.
- **Zydis** – https://github.com/zyantific/zydis – schneller x86/x64-Decoder.
- **YARA-X** – https://github.com/YARA-X/yara-x – regelbasierte Dateierkennung.
- **file/libmagic** – https://github.com/file/file – bewährte Magic-/Dateityperkennung.

## Kommerzielle und Source-Available Benchmarks

- **010 Editor** – https://www.sweetscape.com/010editor/ – Binary Templates, Scripting, große Dateien.
- **HxD** – https://mh-nexus.de/en/hxd/ – schnelle Windows-Basis-UX.
- **Synalyze It!** – https://www.synalysis.net/ – GUI-Grammars.
- **Hiew** – https://www.hiew.ru/ – Hex/Text/Disassembler.
- **Hextor** – https://github.com/digitalw0lf/hextor – Source-Available/Freeware, nicht automatisch Open Source.
- **Hexinator** – Grammar-/Template-orientierter kommerzieller Editor.
- **WinHex / X-Ways** – forensische Disk-/Filesystem-Referenz.
- **IDA** – https://hex-rays.com/ida-pro – Industriereferenz für RE.
- **Binary Ninja** – https://binary.ninja/ – moderne RE-Plattform mit API-/IL-Fokus.

## SASD-Ableitungen

Hex/ASCII, farbige Markierungen, Entropie, Signaturen, Templates, Disassembly, Byte-Diff und Data Inspector sind keine Alleinstellungsmerkmale.

SASD sollte übernehmen: performanter ByteProvider, virtuelle Hexdarstellung, Pattern Registry/Rule Packs, Data/Structure Inspector, Bookmarks/Annotationen, Entropie/Byte Frequency, Binary und später Structure Diff, deklarative Formate, Kaitai-Kompatibilität, externe Disassembler-Engine, CLI/Headless-Core, Projektpersistenz und Reporting.

SASD-spezifisch bleiben: **Confidence/Evidence**, Analyseakte statt Session, klare Trennung von Fakten und Heuristiken, versionierbares/testbares Formatwissen, Übergang von Analyse zu Validierung/Dokumentation/Tests sowie sichere Integration in Vault und Optical Media Workbench.

## Evaluationsplan

Praktisch zuerst vergleichen: **ImHex, rehex, GNU poke, Q22, HexWalk, fhex und Hex Fiend**. QHexEdit2 und alternative Controls separat.

Gemeinsame Fixtures: 2-GB-Datei, Navigation/Suche, beschädigter PNG-Header, SASD-Testformat, Binary Diff, PE/ELF + Disassembly, Signaturen/False Positives und Persistenz von Annotationen.

## Lizenzregel

Funktionsideen dürfen untersucht werden; Codeübernahme ist separat. MIT/BSD/Apache werden bevorzugt, LGPL fallbezogen geprüft. GPL/AGPL wird nicht unreflektiert eingebettet. Maßgeblich ist immer die aktuelle Lizenzdatei des konkreten Upstreams.
