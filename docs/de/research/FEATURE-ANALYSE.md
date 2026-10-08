# Feature- und Marktanalyse

Dieses Dokument ist die repository-taugliche Fassung der ersten Feature-Analyse und wird durch den ausführlicheren [Open-Source-Hex-Editor-Katalog](OPEN-SOURCE-HEX-EDITOR-KATALOG.md) ergänzt.

## Bewertete Werkzeugklassen

- klassische Hex-/Binäreditoren;
- template-/grammar-getriebene Editoren;
- deklarative Formatsprachen und Parsergeneratoren;
- Reverse-Engineering-Suiten;
- Binary-Diff-Werkzeuge;
- große Datei-/Datenträgereditoren;
- CLI/TUI-Werkzeuge;
- einbettbare Hex-Komponenten.

## Zentrale Referenzen

| Werkzeug | Stärke | SASD-Lernpunkt |
|---|---|---|
| 010 Editor | Binary Templates, Scripting, große Dateien | strukturierte Interpretation |
| ImHex | Pattern Language, Visualisierung, moderne Analyse-UX | Pattern + Workbench |
| Hex Fiend | große Dateien, effizientes Dateimodell | Performance |
| Synalyze It! | GUI-Grammars | visuelles Formatmodell |
| Kaitai Struct | deklarative Formate, Parsergenerierung | Formatwissen als Code |
| Ghidra | RE-Projektmodell, Disassembly/Decompilation | Analyseartefakte |
| radare2/Rizin/Cutter | CLI/API/Pipelines | Automatisierung |
| rehex | Annotationen, Templates, Diff, Disassembly | integrierte Navigation |
| HexWalk | Signaturen, Entropie, Byte Map | Analysevisualisierung |
| Q22 | PE/ELF + Disassembly | Executable Insight |
| fhex | konfigurierbare Farbregeln | Pattern Overlays |
| wxHexEditor | große Dateien, Rohdatenträger | Device-/Large-file-Modell |
| VBinDiff | fokussierter Binary Diff | einfache Compare-UX |

## Wiederkehrende Feature-Cluster

### Hex-Editor-Basis

Hex/Text, Offsets, Suche, Auswahl, Copy/Paste, Bookmarks, Hashes und Data Inspector sind Pflichtfunktionen, aber keine ausreichende Differenzierung.

### Strukturierte Interpretation

Templates, Grammars und Pattern-Sprachen verwandeln Rohbytes in benannte Felder, Arrays und Strukturen. SASD startet in V1 bewusst mit einem begrenzten deklarativen Modell und erweitert es schrittweise.

### Analyseartefakte

Professionelle Analyse benötigt Formatdefinitionen, Annotationen, Testdateien, erwartete Ergebnisse, Reports und Versionierung. Das ist ein Kern des SASD-Ansatzes.

### Diff auf mehreren Ebenen

Byte-Diff ist nützlich; Structure Diff ist strategisch wertvoller: Feldname, alter/neuer Wert, hinzugefügt/entfernt/geändert und Validierungsfolgen.

### Automatisierung

CLI/API/Batch machen die Engine für CI, Importprüfungen, Migration, Support und Schulung wiederverwendbar.

### Lern- und Dokumentationsfähigkeit

Erklärungen, Confidence, kommentierte Formatdefinitionen und Reports sind wichtige SASD-Differenzierungsmerkmale.

## Für V1 übernommene Ideen

- read-only Large-file-Provider;
- Hex/ASCII + Data Inspector;
- Bookmarks/Annotationen;
- Pattern Engine und farbige Kategorien;
- Confidence/Evidence;
- minimales Strukturmodell;
- Validierung;
- Hashing;
- Strings;
- Entropie/Byte Frequency;
- Projektdatei;
- Markdown/HTML-Reporting.

## Bewusst später

- Byte/Structure Diff und CLI: V1.1;
- komplexeres Formatmodell: V1.2;
- Kaitai: V1.5;
- PE/ELF/Disassembly: V2;
- Crypto/Vault: V2.5;
- Disk/Filesystem: V3;
- Scripting/Plugins: V3.5;
- Editing: V4;
- Recovery/Repair: V5+.

## Hauptrisiken

- Scope-Explosion durch gleichzeitiges Nachbauen von ImHex, 010 Editor und Ghidra;
- zu frühes Schreiben auf Dateien/Devices;
- zu komplexe eigene Template-Sprache;
- ungeeignetes Dateimodell für große Dateien;
- unklare Zielgruppe;
- Lizenzprobleme durch direkte Übernahme von GPL/AGPL-Code;
- falsche Sicherheit durch heuristische Befunde.

## Schlussfolgerung

Die Recherche rechtfertigt kein weiteres generisches Hex-Editor-Projekt. Sie rechtfertigt jedoch eine **sichere, evidence-aware Binary Knowledge Workbench**, wenn SASD vorhandene Basistechnik wiederverwendet und sich auf reproduzierbare Analyse, Dokumentation, Validierung und Integration konzentriert.
