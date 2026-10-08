# SASD Secure Binary Analysis Tool
## Konsolidiertes Pflichtenheft – Repository-Fassung

**Produktname:** SASD Secure Binary Analysis Tool  
**UI-/Arbeitsname:** SASD Binary Insight  
**Stand:** 2026-10-08  
**Status:** normative Entwicklungsgrundlage vor Implementierungsbeginn

> **Leitsatz:** Wir bauen keinen weiteren Hex-Editor, weil Hex-Editoren fehlen. Wir bauen ein sicheres, projektorientiertes Analysewerkzeug, das Binärdaten erkennt, erklärt, dokumentiert, validiert, vergleicht und als wiederverwendbares Engineering-Wissen verfügbar macht.

## 1. Produktziel

SASD Binary Insight schließt die Lücke zwischen klassischem Hex-Editor, Format-Parser, Reverse-Engineering-Werkzeug und technischer Dokumentation. Die Byteansicht bleibt überprüfbare Grundlage; der eigentliche Produktwert entsteht durch Bedeutung, Evidenz, Projektwissen und Reproduzierbarkeit.

Das Produkt ist **kein** HxD- oder Ghidra-Klon, kein Malware-Labor, Passwort-Cracker, universeller Decryptor oder Cloud-Zwangsdienst.

## 2. Leitprinzipien

1. **Read-only first** – Analyse ist Standard, Schreiben folgt erst nach gesonderter Sicherheitsentscheidung.
2. **Meaning before editing** – Verstehen ist wichtiger als Manipulation.
3. **Evidence before assumption** – bestätigte, starke, wahrscheinliche und heuristische Aussagen werden unterschieden.
4. **Large-file capable by design** – Dateien dürfen nicht vollständig in RAM geladen werden müssen.
5. **Core independent from UI** – dieselbe Engine soll GUI, CLI und spätere Automatisierung bedienen.
6. **Local first** – keine Cloud- oder Telemetriepflicht.
7. **Reproducible analysis** – Erkenntnisse werden als versionierbare Projektartefakte gespeichert.
8. **Security by design** – Crypto, Plugins, Devices und Schreibfunktionen besitzen klare Vertrauensgrenzen.
9. **Reuse before reinvention** – geeignete Bibliotheken werden evaluiert.
10. **No monolith** – Executable-, Crypto-, Disk- und Forensikmodule bleiben vom Core getrennt.

## 3. V1-Benutzeroberfläche

Die langfristige Workbench umfasst:

- HexView mit Offset-, Hex- und Textspalte;
- File Information;
- Pattern Categories;
- Structure Inspector;
- Pattern Details;
- Data Inspector;
- Bottom Workbench mit Entropy, Strings, Search Results, Compare, Statistics und Log.

Farben dürfen nie die einzige Informationsquelle sein. Selection, Pattern und Validierungsstatus müssen visuell unterscheidbar bleiben.

## 4. Funktionale Anforderungen

### 4.1 ByteProvider und große Dateien

- Read-only-Dateizugriff.
- Random Access auf beliebige Bytebereiche.
- Page-/Chunk-basiertes Laden mit Cache.
- keine Kopplung des Analysemodells an eine konkrete OS-Dateiklasse.
- externe Änderungen der Quelle erkennen.
- spätere Provider für Disk Images, Devices und Vault-Streams ermöglichen.

### 4.2 Hex-/Textansicht

- synchronisierte Hex-/Textdarstellung und Selektion;
- Go-to Offset;
- Copy as Hex/Text/Offset+Length;
- Navigation über Offset, Bookmark, Pattern, Strukturfeld und Suchtreffer;
- nur sichtbare Bereiche rendern.

### 4.3 Data Inspector

Mindestens: signed/unsigned 8/16/32/64 Bit, LE/BE, float/double, ASCII, UTF-8, UTF-16, Hex, Bitfelder, Unix Timestamp und GUID/UUID bei passender Länge.

### 4.4 Suche

- Hexfolgen und Text;
- blockweise Suche über große Dateien;
- Ergebnisliste mit Offset und Preview;
- Cancellation;
- später Wildcards, Masken, numerische und strukturbezogene Suche.

### 4.5 Pattern Engine

- versionierte Pattern Registry und Rule Packs;
- Magic Bytes, feste und maskierte Bytefolgen;
- String-/Encoding-Erkennung;
- Treffer mit Kategorie, Name, Beschreibung, Offset, Länge, Confidence und Quelle;
- farbige, filterbare Overlays;
- deterministische Priorität bei Überlappungen;
- benutzerdefinierte Regeln ohne Neukompilierung;
- streamende, abbrechbare Scans.

### 4.6 Confidence / Evidence

Automatische Aussagen werden als **Confirmed**, **Strong**, **Probable**, **Heuristic** oder **Unknown** klassifiziert. Hohe Entropie darf beispielsweise nicht automatisch als Verschlüsselung bezeichnet werden.

### 4.7 Strings, Bookmarks und Annotationen

- ASCII und UTF-8 in V1, UTF-16 später;
- konfigurierbare Mindestlänge;
- Bookmarks an Offset oder Range;
- benannte, kategorisierte und kommentierte Bytebereiche;
- Persistenz im Analyseprojekt;
- Export in Reports.

### 4.8 Analyseprojekt

Projektdateien speichern Quelle/Fingerprint, Bookmarks, Annotationen, verwendete Formatdefinitionen, Analysebefunde und relevante UI-Navigation. Keine unnötigen Kopien sensibler Nutzdaten oder Secrets. Das Format ist versioniert, migrationsfähig und möglichst Git-freundlich.

### 4.9 Strukturmodell

V1 unterstützt ein bewusst begrenztes deklaratives Modell: Name, Offset, primitiver Typ, Länge, Endianness, Beschreibung, Enum, Fixed/Magic, einfache Arrays, Verschachtelung und einfache Validierungsregeln. Später folgen dynamische Längen, Bedingungen, Unions, Bitfelder, berechnete Felder, Includes und transformierte Substreams.

### 4.10 Validierung

Magic/Fixed Values, Wertebereiche, Bounds, Referenzen/Offsets sowie modulare Checksums. Befunde erhalten Info/Warning/Error und werden in HexView und Structure Inspector sichtbar.

### 4.11 Hashing, Entropie und Statistik

SHA-256 und SHA-512; MD5/SHA-1 nur für Kompatibilitäts-/Identifikationszwecke und entsprechend gekennzeichnet; CRC32 modular. Hashing streamend.

Entropie: Gesamtwert, Sliding Window, Navigation vom Graphen zum Bytebereich und Byte-Frequency. Statistik ist Indikator, kein Crypto-Beweis.

### 4.12 Diff und Reporting

V1.1: Byte-Diff mit synchronisierter Navigation und Unterschiedsbereichen. Später Structure Diff.

Reports: Markdown und HTML als Kernformate; PDF über definierten Exportweg. Reports unterscheiden Fakten von Heuristiken und erlauben Kontrolle sensibler Inhalte.

### 4.13 CLI und Automatisierung

GUI und CLI verwenden dieselbe Core-Engine. Geplante Operationen: inspect, hash, scan, analyse, validate, report und diff. Scripting/Plugins folgen erst nach stabilem Core und mit explizitem Permission-Modell.

## 5. Spätere Fachmodule

### V2 – Executable Insight

PE/COFF und ELF zuerst, Mach-O später; Header, Sections/Segments, Imports/Exports, Entry Point und File Offset ↔ Virtual Address. Disassembly über evaluierte Bibliothek wie Capstone/Zydis statt eigener CPU-Decoder-Engine.

### V2.5 – Secure/Crypto Insight

Crypto-Metadaten und SASD-Vault-Integration ausschließlich für autorisierte Analyse. Authentifizierung und Schlüsselverwaltung verbleiben beim Vault. Klartext möglichst nur im Speicher; Projektdateien speichern keine Schlüssel oder Secrets.

### V3 – Disk & Filesystem Insight

RAW/DD/IMG/ISO, MBR/GPT, Sektornavigation, read-only Device Provider und ausgewählte Dateisystem-Metadaten. MBR/GPT-Reparatur gehört nicht in den normalen Analysemodus.

### V4 – Controlled Editing

Erst nach eigener Sicherheitsentscheidung: Edit Mode, Undo/Redo, Copy-on-Write, Patch-Dateien, Review before Save, Backup und möglichst atomisches Schreiben.

### V5+ – Recovery/Repair

Optional bzw. eigenes Produktmodul: Diagnose, Dry Run, verpflichtendes Backup/Audit und kontrollierte Reparatur.

## 6. Architektur

```text
Desktop UI / TUI / CLI
        |
Application Services / Commands
        |
Project | Search | Pattern | Format | Diff | Report
        |
Analysis Model / Evidence / Validation
        |
ByteProvider / Address Space / Cache / Transform Streams
        |
File | Disk Image | Device | Vault | Future Sources
```

Langlaufende Operationen wie Hashing, Suche, Pattern Scan, Entropie, Parsing, Diff und Reporting dürfen die UI nicht blockieren und müssen Progress/Cancellation unterstützen.

## 7. Nichtfunktionale Anforderungen

- Linux ist V1-Pflicht; Windows V1 oder spätestens V1.1/V1.5; macOS später; OpenBSD für Core/CLI perspektivisch erwünscht.
- fehlerhafte oder trunkierte Dateien dürfen nicht zum Crash führen;
- Parser führen Bounds Checks aus;
- keine Telemetrie und kein automatischer Upload per Default;
- keine automatische Skriptausführung beim Öffnen;
- Logs dürfen sensible Payloads nicht ungefragt enthalten;
- Performance-Benchmarks mindestens mit 1 GB und 10 GB Fixtures.

## 8. Roadmap und Releasegrenzen

| Release | Schwerpunkt | grobe kumulative Commits |
|---|---|---:|
| Phase 0 | Engineering Foundation, ADRs, Build, Tests, CI | 10–15 |
| V0.1 | ByteProvider, File Provider, Cache, Random Access | 20–30 |
| **V1.0-alpha** | erster stabiler Hex/ASCII Viewer + Inspector | 35–45 |
| **V1.0-beta** | Suche, Bookmarks, Annotationen, Projekt, Hashes, Strings | 50–65 |
| **V1.0-rc1** | Pattern Engine, Confidence, Strukturmodell, Validierung | 65–85 |
| **V1.0-rc2** | Entropie, Statistik, Performance, Reporting, Härtung | 80–100 |
| **V1.0 FINAL** | sichere, getestete Binary-Analysis-Foundation | **90–115** |
| V1.1 | Compare + CLI | – |
| V1.2 | Format Workbench + Structure Diff | – |
| V1.5 | Kaitai + Extensibility | – |
| V2.0 | Executable Insight | – |
| V2.5 | Secure/Crypto Insight | – |
| V3.0 | Disk & Filesystem Insight | – |
| V3.5 | Automation & Plugins | – |
| V4.0 | Controlled Editing | – |
| V5+ | optional Recovery/Repair | – |

## 9. V1-Abnahme

V1 muss u. a. Dateien >1 GB ohne Full Load öffnen, über die gesamte Datei navigieren, korrekte LE/BE-Interpretation liefern, Page-Grenzen bei Suche berücksichtigen, Projekte reproduzierbar wieder öffnen, Quelldateiänderungen erkennen, definierte PNG/ZIP/PE/ELF-Fixtures erkennen, Heuristiken korrekt kennzeichnen, verschachtelte Testformate parsen, korrupte Daten ohne Crash diagnostizieren und Entropie streamend/abbrechbar berechnen.

Build, Tests und statische Prüfungen müssen reproduzierbar in CI laufen.

## 10. Lizenz- und Dependency-Strategie

Funktionale Inspiration ist strikt von Codeübernahme zu trennen. Bevorzugt werden MIT, BSD und Apache-2.0. LGPL bedarf Prüfung; GPL/AGPL-Komponenten werden nicht unreflektiert eingebettet.

Zu evaluieren sind insbesondere QHexEdit2/alternative Hex-Controls, Capstone, Zydis, Kaitai Struct und libmagic.

## 11. SASD-Integration

- **Optical Media Workbench:** bestehende read-only Sektor-/Hex-Erfahrung nutzen; gemeinsame Komponenten prüfen.
- **Editor Toolkit/Toolbox:** Command-, Navigation-, Selection- und spätere Undo/Redo-Konzepte prüfen.
- **UI Toolkit/UI Platform:** UI-Wiederverwendung prüfen, ohne Core-Kopplung.
- **Desktop Secret Manager/Vault:** Authentifizierung und Keys bleiben dort; Binary Insight konsumiert später eine kontrollierte Schnittstelle.

## 12. Produkt-USP

> **A secure, evidence-aware binary analysis workbench that turns byte-level findings into reproducible engineering knowledge.**

Der USP liegt nicht in einem einzelnen Hex-Feature, sondern in der Kette **Treffer → Bedeutung → Evidenz → Struktur → Annotation → Validierung → Vergleich → Report → Automatisierung**.

**Freigabeempfehlung:** Phase 0 und V0.1 können nach Entscheidung der initialen ADRs gestartet werden.
