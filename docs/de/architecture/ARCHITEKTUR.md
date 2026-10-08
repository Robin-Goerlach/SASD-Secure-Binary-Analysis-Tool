# Architektur – SASD Binary Insight

**Produkt:** SASD Secure Binary Analysis Tool  
**Arbeits-/UI-Name:** SASD Binary Insight  
**Stand:** 2026-10-08  
**Status:** Architektur-Baseline vor Implementierungsbeginn  
**Geltung:** Zielarchitektur. Technologieentscheidungen, die in ADRs als offen markiert sind, werden durch dieses Dokument nicht vorweggenommen.

> **Architekturziel:** Eine sichere, read-only-first und UI-unabhängige Binary-Analysis-Plattform, die große Datenquellen effizient untersucht und aus Bytebefunden reproduzierbares, versionierbares Engineering-Wissen erzeugt.

## 1. Zweck und Architekturtreiber

Dieses Dokument übersetzt Lastenheft, Pflichtenheft und Produktstrategie in eine zusammenhängende technische Zielarchitektur. Es beschreibt Systemgrenzen, Schichten, Komponenten, Datenflüsse, Sicherheitsgrenzen und Erweiterungspunkte. Detailentscheidungen werden über ADRs festgehalten.

Die wichtigsten Architekturtreiber sind:

1. **Read-only first:** Analyse darf die Quelle im Normalbetrieb nicht verändern.
2. **Large-file capable:** Dateien >1 GB dürfen keinen Full-Load in den RAM erfordern.
3. **Core independent from UI:** Desktop-UI, spätere CLI/TUI und Automatisierung verwenden dieselbe fachliche Engine.
4. **Evidence before assumption:** Fakten und Heuristiken sind Teil des Domänenmodells, nicht nur UI-Texte.
5. **Reproduzierbarkeit:** Analysewissen ist ein persistentes, versioniertes Projektartefakt.
6. **Local first:** Kernfunktionen benötigen keinen Cloud-Dienst und keine Telemetrie.
7. **Robustheit:** Unbekannte, beschädigte und trunkierte Eingaben sind normaler Betriebsfall.
8. **Erweiterbarkeit ohne Monolith:** Executable-, Crypto/Vault-, Disk-/Filesystem-, Plugin- und Editierfunktionen bleiben Module mit klaren Grenzen.
9. **Reuse before reinvention:** etablierte Bibliotheken werden evaluiert; Lizenz und Sicherheitsgrenzen bleiben explizit.
10. **Testbarkeit:** Domänenlogik und Analyse-Engines müssen ohne GUI deterministisch testbar sein.

## 2. Architekturprinzipien

### 2.1 Dependency Rule

Abhängigkeiten zeigen grundsätzlich nach innen. UI und Infrastruktur dürfen Application und Domain verwenden; Domain kennt weder GUI-Toolkit noch Dateisystem-API, Datenbank, Netzwerk oder konkrete Drittbibliotheken.

```text
Hosts / Presentation
        ↓
Application
        ↓
Domain / Analysis Model
        ↑
Ports / Interfaces
        ↑
Infrastructure / Adapters
```

Konkrete Provider und externe Engines werden über Interfaces/Ports angebunden. Dadurch bleiben Kernmodelle portabel und testbar.

### 2.2 Analyse und Mutation trennen

V1 kennt keinen allgemeinen Schreibpfad zurück zur Quelle. Spätere Editierfunktionen erhalten eigene Commands, Policies und Provider-Fähigkeiten. Ein read-only `ByteProvider` wird nicht durch einen versteckten Write-Schalter zum Editor.

### 2.3 Streaming statt Vollmaterialisierung

Hashing, Suche, Pattern Scan, String Scan, Entropie und ähnliche Operationen arbeiten über Bereiche/Chunks. Ergebnislisten dürfen ebenfalls inkrementell entstehen.

### 2.4 Explizite Unsicherheit

`Confirmed`, `Strong`, `Probable`, `Heuristic` und `Unknown` sind fachliche Werte. Jede automatisierte Aussage kann Herkunft und Begründung referenzieren.

### 2.5 Kein UI-Domänenmodell

Selection, Scrollposition und Layoutzustand dürfen UI-spezifisch sein; `ByteRange`, Finding, Annotation, ParsedField und ValidationFinding gehören dagegen in Core/Domain. Fachlogik darf nicht in Event-Handlern verschwinden.

## 3. Systemkontext

```text
                        ┌───────────────────────────┐
                        │       Benutzer            │
                        └─────────────┬─────────────┘
                                      │
                         Desktop UI / später CLI/TUI
                                      │
┌─────────────────────────────────────▼────────────────────────────────────┐
│                       SASD Binary Insight                               │
│ Project · Search · Pattern · Format · Validation · Hash · Entropy       │
│ Reporting · später Diff/Executable/Crypto/Disk/Automation               │
└───────────────┬───────────────────────────────┬──────────────────────────┘
                │                               │
       Byte Sources / Files              optionale Engines
                │                               │
      Files, Images, später              Kaitai/Disassembler/
      Device/Vault Streams               libmagic etc. nach ADR
```

Binary Insight besitzt in V1 keine Cloud-Abhängigkeit. SASD Vault bleibt später Eigentümer von Authentifizierung und Schlüsseln; Binary Insight konsumiert nur autorisierte Datenströme.

## 4. Schichtenmodell

### 4.1 Hosts / Presentation

Verantwortung: Darstellung, Benutzereingaben, Navigation, Command-Aufruf, Progress/Cancellation und Accessibility.

Geplante Hosts:
- Desktop Workbench als primärer V1-Host;
- CLI ab V1.1;
- TUI optional;
- automatisierte/headless Hosts später.

Presentation darf keine Binärparser, Hash-Implementierungen oder Dateizugriffslogik enthalten.

### 4.2 Application

Orchestriert Use Cases und Transaktionen auf Analyseebene. Beispiele:
- OpenSource / CloseSource;
- NavigateToRange;
- Search;
- ScanPatterns;
- ExtractStrings;
- CalculateHash;
- AnalyseEntropy;
- ParseFormat;
- Validate;
- Save/OpenProject;
- GenerateReport;
- später Compare.

Application entscheidet über Ablauf, Cancellation, Progress und Zusammenführung von Ergebnissen, nicht über GUI-Darstellung.

### 4.3 Domain / Analysis Model

Technologieunabhängiger Kern:
- `ByteRange`, `Address`, `AddressSpace`;
- `AnalysisFinding`, Evidence/Confidence und Provenance;
- `Bookmark`, `Annotation`;
- `FormatDefinition`, `FieldDefinition`, `ParsedField`;
- `ValidationRule`, `ValidationFinding`;
- `AnalysisProject` und Source Fingerprint;
- Report-Datenmodell.

Invarianten – z. B. gültige Ranges, Severity/Confidence-Werte und Referenzen – werden hier durchgesetzt.

### 4.4 Analysis Services

Fachlich fokussierte, UI-freie Engines:
- `DataDecoder`;
- `SearchEngine`;
- `StringScanner`;
- `PatternEngine` + `PatternRegistry`;
- `FormatParser`;
- `ValidationEngine`;
- `HashService`;
- `EntropyService`;
- später `DiffEngine`.

Sie konsumieren abstrahierten Bytezugriff und produzieren Domänenobjekte.

### 4.5 Infrastructure / Adapters

Enthält konkrete I/O- und Fremdsystemadapter:
- FileByteProvider;
- PageCache;
- Projekt-Serialisierung;
- Rule-/Format-Repository;
- Report Writer;
- später DiskImageProvider, DeviceProvider, VaultProvider;
- Adapter für externe Parser/Disassembler.

## 5. ByteProvider – Fundament der Architektur

Der ByteProvider ist die wichtigste technische Grenze. Er abstrahiert die Quelle als adressierbaren Bytebereich.

Konzeptioneller Vertrag:

```text
ByteProvider
 ├─ Length / AddressSpace
 ├─ Read(offset, destination)
 ├─ ReadRange(range)
 ├─ SourceIdentity / capabilities
 └─ Change/Fingerprint information
```

V1-Anforderungen:
- 64-Bit-fähige Offsets;
- Random Access;
- read-only;
- keine Annahme, dass die gesamte Quelle speicherresident ist;
- definierte Semantik für EOF/Short Read;
- sichere Bounds-Prüfung;
- Cancellation bei höheren Operationen;
- Erkennung relevanter Änderungen der Quelldatei.

Die genaue API, Memory-Mapping-Frage, Cache-Größe und Synchronisationsstrategie werden in ADR-003 entschieden.

## 6. Page-/Chunk- und Cache-Modell

HexView und Analyseoperationen dürfen unterschiedliche Zugriffsmuster besitzen. Deshalb wird der Provider nicht an die Render-Page-Größe gekoppelt.

```text
Source
  │
FileByteProvider
  │
PageCache ─────── configurable bounded memory
  │
ByteProvider abstraction
  ├── HexView visible-window reads
  ├── Search sequential chunks
  ├── Pattern scan sequential chunks + overlap
  ├── Hash sequential chunks
  └── Format parser targeted reads
```

Scanner müssen Pattern über Chunk-Grenzen korrekt erkennen. Cache ist Optimierung, nicht fachliche Wahrheit. Eviction darf Ergebnisse nicht verändern.

## 7. Adressräume und Ranges

V1 beginnt mit File Offset als primärem Adressraum. Das Modell soll spätere Abbildungen erlauben:
- File Offset;
- Virtual Address für PE/ELF/Mach-O;
- Sector/LBA für Datenträger;
- logische/transformierte Streams.

Eine `ByteRange` ist bevorzugt halb-offen `[start, end)`, um Längen- und Grenzberechnungen eindeutig zu halten; die endgültige Festlegung gehört in ADR-003.

Adressraum-Transformationen werden explizit modelliert und nicht als ad-hoc Offset-Arithmetik in UI-Komponenten verteilt.

## 8. Analysepipeline

```text
Byte Source
   ↓
ByteProvider / Cache
   ↓
Observation
   ├─ Search / Strings
   ├─ Pattern recognition
   ├─ Data decoding
   ├─ Entropy / statistics
   └─ Format parsing
   ↓
Evidence + Provenance
   ↓
Structure / Annotation
   ↓
Validation
   ↓
Project
   ↓
Report / später Diff / CLI / Automation
```

Eine Beobachtung wird nicht automatisch zur gesicherten Interpretation. Pattern Engine und Heuristiken erzeugen Findings mit Confidence und Provenance; Validierung kann Evidenz stärken oder Fehler feststellen.

## 9. Evidence- und Provenance-Modell

Ein `AnalysisFinding` soll mindestens enthalten:
- stabile/geeignete Identität;
- Kategorie und Name;
- Beschreibung;
- AddressSpace + ByteRange;
- Confidence;
- Quelle/Rule-ID und Rule-Version;
- optionale Evidenzdetails;
- Erstellungs-/Analysekontext soweit für Reproduzierbarkeit nötig.

Confidence:
- **Confirmed** – durch Definition/Validierung bestätigt;
- **Strong** – sehr starke technische Evidenz;
- **Probable** – plausible Interpretation;
- **Heuristic** – Indikator;
- **Unknown** – keine belastbare Einordnung.

Provenance verhindert, dass ein Ergebnis später ohne Herkunft im Report erscheint.

## 10. Pattern Engine

Die Pattern Engine besteht logisch aus:
1. `PatternRegistry` – geladene, versionierte Regeln;
2. Rule Packs – z. B. Standard, Executable, Archive, Media, SASD;
3. Scanner – chunk-/streamingfähig;
4. Match Normalizer – erzeugt Findings;
5. Overlap Resolver – deterministische Darstellungs-/Prioritätsregeln.

Regeldefinition und Engine bleiben getrennt. Benutzerregeln dürfen ohne Neukompilierung geladen werden. Das konkrete Regeldateiformat wird in ADR-006 entschieden.

## 11. Struktur- und Formatmodell

V1 implementiert bewusst keine universelle Programmiersprache. Das deklarative Modell unterstützt zunächst:
- Name/Offset;
- primitive Typen;
- Länge und Endianness;
- Beschreibung/Enum;
- Fixed/Magic Values;
- einfache Arrays;
- verschachtelte Strukturen;
- einfache Validierungsregeln.

```text
FormatDefinition
  └─ FieldDefinition*
       ↓ parse
ParsedField tree
       ├─ value
       ├─ ByteRange
       ├─ children
       └─ diagnostics
```

Der Parser liest ausschließlich über ByteProvider, prüft Grenzen und liefert Diagnosen statt bei beschädigten Daten abzustürzen. Dynamische Ausdrücke, Bedingungen, Unions, Includes und transformierte Streams folgen später. Kaitai-Kompatibilität/Import wird für V1.5 evaluiert.

## 12. Validierungsarchitektur

Validierung ist von Parsing getrennt. Ein Feld kann erfolgreich gelesen und fachlich trotzdem ungültig sein.

`ValidationFinding` enthält mindestens:
- Severity: Info/Warning/Error;
- Rule/Quelle;
- Nachricht;
- betroffenen ByteRange und optional ParsedField;
- erwarteten/gefundenen Wert, soweit sicher darstellbar.

Validierungsregeln: Magic/Fixed, Wertebereich, Bounds, Referenzen/Offsets und modulare Checksums. Ergebnisse sind in HexView, Structure Inspector und Report dieselben Domänenbefunde.

## 13. Projekt- und Persistenzmodell

Das Projekt ist das zentrale Wissensartefakt, nicht eine Kopie der untersuchten Datei.

Es speichert:
- Quellreferenz und Fingerprint/Hash;
- Bookmarks/Annotationen;
- relevante Findings;
- Format-/Pattern-Referenzen einschließlich Version;
- Analyse-/Navigationskontext soweit sinnvoll;
- Report-Metadaten.

Es speichert **keine** Schlüssel/Passwörter und keine unnötige Kopie sensibler Quelldaten. Beim Öffnen wird die Quelle erneut identifiziert; Abweichungen werden sichtbar gemeldet.

Projektformat und Migration werden in ADR-004 entschieden. Persistenzcode darf nicht in Domain-Objekte mit konkreten JSON/YAML-Abhängigkeiten einsickern.

## 14. Long-running Operations

Hash, Search, String Scan, Pattern Scan, Entropy, Parsing, Validation, Diff und Reporting werden als abbrechbare Jobs/Operationen modelliert.

Jede lange Operation benötigt:
- Cancellation;
- Progress, sofern sinnvoll bestimmbar;
- Fehler-/Diagnosekanal;
- keine Blockierung des UI-Threads;
- deterministische Ergebnissemantik bei erfolgreichem Abschluss;
- klaren Umgang mit Teilresultaten nach Abbruch.

Parallelität ist begrenzt und ressourcenbewusst. Mehr Threads dürfen nicht zu unkontrolliertem RAM-/I/O-Verbrauch führen.

## 15. UI-Architektur

Die Desktop Workbench ist ein Adapter auf Application/Core.

Geplante Bereiche:
- Hex/Text View als zentrale Navigation;
- File Information;
- Pattern Categories;
- Structure Inspector;
- Pattern Details;
- Data Inspector;
- Entropy, Strings, Search Results, später Compare/Statistics/Log.

Panels kommunizieren nicht über gegenseitige direkte Manipulation, sondern über gemeinsamen Selection-/Navigation-Kontext und Application Commands. Ein Klick auf Finding, ParsedField oder Entropy-Bereich navigiert über eine zentrale Range-/Address-Abstraktion.

Farbe ist Zusatzinformation; Selection, Pattern, Validation und Confidence benötigen auch Form/Text/Icon/Label.

## 16. Reporting

Reporting erhält ein neutrales `ReportModel`, nicht direkt UI-Widgets.

```text
Domain/Project
     ↓
Report Builder
     ↓
ReportModel
  ├─ metadata/source fingerprint
  ├─ facts/findings/evidence
  ├─ structures/validation
  ├─ annotations
  └─ controlled excerpts
     ↓
Markdown Writer / HTML Writer / später PDF pipeline
```

So bleiben Inhalt und Ausgabeformat getrennt. Sensible Ausschnitte werden bewusst aufgenommen, nicht automatisch vollständig exportiert.

## 17. Sicherheitsarchitektur und Trust Boundaries

### 17.1 Untrusted Input

Jede analysierte Datei ist potentiell fehlerhaft oder bösartig. Parser und Scanner:
- prüfen Offsets/Längen auf Overflow und Bounds;
- begrenzen Allokationen;
- vertrauen Längenfeldern nicht;
- vermeiden unkontrollierte Rekursion;
- führen keine eingebetteten Skripte aus;
- behandeln Decoder-/Parserfehler als Diagnose.

### 17.2 Lokale Daten

Kein automatischer Upload und keine Telemetriepflicht. Logs enthalten standardmäßig keine kompletten Payloads oder Secrets.

### 17.3 Plugins/Scripting

Nicht V1. Später eigene Trust Boundary mit Permission-Modell, expliziter Aktivierung und getrennten APIs. Öffnen eines Projekts darf nicht implizit fremden Code ausführen.

### 17.4 Vault

Vault besitzt Authentifizierung und Schlüssel. Binary Insight erhält später einen autorisierten Byte-Stream/Provider. Klartext soll möglichst nicht als temporäre Datei materialisiert werden. Secrets gehören nicht ins Projekt.

### 17.5 Devices und Schreiben

Physical Device Provider wird erst vor V3 per ADR spezifiziert und standardmäßig read-only. Controlled Editing ab V4 benötigt Capability-Prüfung, Review before Save, Backup/Copy-on-Write und Audit. Recovery/Repair ist eine weitere Risikoklasse.

## 18. Erweiterungsmodule und Releasegrenzen

```text
Core / V1
├─ ByteProvider + Cache
├─ Search / Strings / DataDecoder
├─ Pattern + Evidence
├─ Format + Validation
├─ Project
├─ Hash / Entropy
└─ Reporting

V1.1 ─ Diff + CLI
V1.2 ─ richer Format Workbench / Structure Diff
V1.5 ─ Kaitai / Extensibility
V2.0 ─ Executable.Pe / Executable.Elf / Disassembly
V2.5 ─ CryptoAnalysis / VaultIntegration
V3.0 ─ DiskImage / Partition / FileSystem
V3.5 ─ Scripting / PluginHost
V4.0 ─ Controlled Editing
V5+  ─ Recovery / Repair
```

Spätere Module dürfen Core nicht rückwirkend von ihren Abhängigkeiten abhängig machen.

## 19. Vorgeschlagene logische Modulstruktur

Die endgültige Sprache/Build-Struktur folgt ADR-001. Technologieunabhängig werden folgende Verantwortungsgrenzen empfohlen:

```text
Sasd.BinaryInsight.Domain
Sasd.BinaryInsight.Application
Sasd.BinaryInsight.Analysis
Sasd.BinaryInsight.Formats
Sasd.BinaryInsight.Projects
Sasd.BinaryInsight.Reporting
Sasd.BinaryInsight.Infrastructure
Sasd.BinaryInsight.Desktop
Sasd.BinaryInsight.Cli              # ab V1.1

optional/later:
Sasd.BinaryInsight.Executables
Sasd.BinaryInsight.Disassembly
Sasd.BinaryInsight.Crypto
Sasd.BinaryInsight.Vault
Sasd.BinaryInsight.Disk
Sasd.BinaryInsight.FileSystems
Sasd.BinaryInsight.Plugins
```

Die Namen sind Architekturvorschläge, keine Entscheidung für C#, C++ oder ein bestimmtes Buildsystem.

## 20. Fehler- und Diagnosemodell

Erwartbare Probleme – EOF, trunkierte Struktur, ungültiger Offset, unbekanntes Encoding, Regelkonflikt – sind strukturierte Diagnosen, keine ungefilterten Exceptions bis zur UI.

Programmierfehler dürfen dagegen nicht still verschluckt werden. Logs sollen technische Diagnose ermöglichen, ohne Quelldaten unnötig offenzulegen.

## 21. Performance- und Ressourcenmodell

V1 muss >1-GB-Dateien ohne Full Load verarbeiten. Architekturmaßnahmen:
- bounded Page Cache;
- virtuelle/visible-range Hex-Darstellung;
- streaming Scanner;
- 64-Bit Offsets;
- keine unbounded Ergebnis-/Preview-Kopien;
- Cancellation;
- Benchmarks mit mindestens 1-GB- und 10-GB-Fixtures.

Optimierung erfolgt anhand reproduzierbarer Benchmarks. Memory Mapping ist Implementierungsoption, kein Architekturzwang.

## 22. Testarchitektur

Testbarkeit wird als Architekturmerkmal behandelt.

### Unit Tests
Range/Address, Decoder, Confidence, Validation, Rule Parsing, Projektmigration.

### Boundary/Property Tests
Page-/Chunk-Grenzen, Integer Overflow, Endianness, Off-by-one, zufällige/trunkierte Eingaben.

### Integration Tests
FileByteProvider + Scanner, Project round-trip, Report generation, Format parse + validation.

### Golden Fixtures
PNG/ZIP, minimale PE/ELF-Dateien, SASD-Testformate, Unicode, Entropieblöcke, beschädigte/trunkierte Varianten.

### Performance Tests
1 GB/10 GB Navigation, Search, Hash, Pattern und Entropy mit definierten Ressourcenmetriken.

### Security Regression
malformed lengths/offsets, Parsergrenzen, Log-/Report-Leakage und später Plugin/Vault/Device-Grenzen.

## 23. Dependency- und Lizenzarchitektur

Funktionale Inspiration und Codeübernahme bleiben getrennt. Bevorzugt werden MIT/BSD/Apache-2.0. LGPL wird integrationsbezogen geprüft; GPL/AGPL wird nicht unreflektiert eingebettet.

Externe Engines werden hinter Adaptern gekapselt. Dadurch bleiben Austauschbarkeit, Tests und Lizenzgrenzen sichtbar. Kandidaten wie Hex-Control, Kaitai, Capstone/Zydis und libmagic werden erst nach ADR/Review festgelegt.

## 24. Deployment und Plattformen

Ziel:
- Linux: V1;
- Windows: V1 oder spätestens V1.1/V1.5;
- macOS: später;
- OpenBSD: perspektivisch Core/CLI.

Core/Application sollen keine unnötigen OS-spezifischen APIs voraussetzen. Plattformadapter kapseln Unterschiede.

## 25. ADR-Grenze

Dieses Dokument definiert Architekturziele, aber ersetzt keine Entscheidungen. Vor Implementierungsbeginn sind insbesondere zu entscheiden:

1. ADR-001 Core-Sprache/Plattform;
2. ADR-002 GUI-Technologie und SASD-UI-Beziehung;
3. ADR-003 ByteProvider/Large-file-Modell;
4. ADR-004 Projektformat;
5. ADR-005 Formatdefinition V1;
6. ADR-006 Pattern-/Rule-Pack-Format;
7. ADR-007 Confidence/Evidence-Modell;
8. ADR-008 Hash-/Checksum-Abstraktion;
9. ADR-009 Reporting-Pipeline;
10. ADR-010 Dependency-/Lizenzpolicy.

ADRs 011–013 werden spätestens vor den zugehörigen späteren Modulen entschieden.

## 26. Architektur-Invarianten

Folgende Regeln dürfen nur durch explizite Architekturentscheidung geändert werden:

- V1 analysiert Quellen read-only.
- Domain hängt nicht von UI ab.
- Langläufer blockieren die UI nicht.
- Große Quellen benötigen keinen Full Load.
- Parser lesen über abstrahierten Bytezugriff und prüfen Bounds.
- Heuristik wird nicht als Fakt ausgegeben.
- Findings besitzen nachvollziehbare Herkunft.
- Projektdateien enthalten keine Secrets.
- Öffnen einer Datei/eines Projekts führt keinen fremden Code automatisch aus.
- Riskante Module werden nicht still in den V1-Core integriert.
- GUI und spätere CLI verwenden dieselben fachlichen Use Cases.

## 27. Definition of Architecture Done für Phase 0

Phase 0 ist architektonisch abgeschlossen, wenn:
- ADR-001 bis ADR-010 entschieden oder bewusst mit dokumentiertem Blocker verschoben sind;
- Projekt-/Modulgrenzen im Build abgebildet sind;
- Dependency Rule durch Referenzen und CI prüfbar ist;
- minimaler read-only FileByteProvider + ByteRange-End-to-End-Slice existiert;
- Cancellation/Progress-Konzept an mindestens einem Langläufer demonstriert ist;
- Test-Fixtures und Performance-Harness existieren;
- Security-/Logging-Baseline dokumentiert ist;
- keine UI-spezifische Abhängigkeit im Domain/Core vorhanden ist.

## 28. Architekturentwicklung

Dieses Dokument ist eine lebende Architektur-Baseline. Änderungen an fundamentalen Entscheidungen erfolgen über ADRs; anschließend wird die Architekturübersicht aktualisiert. Requirements bestimmen **was**, dieses Dokument beschreibt die strukturelle Lösung, ADRs dokumentieren **warum eine konkrete technische Entscheidung getroffen wurde**, und Tests beweisen die Umsetzung.

> **Zielbild:** Binary Insight soll nicht durch die Anzahl seiner Analysefunktionen skalieren, sondern durch stabile Grenzen: Bytequelle → Beobachtung → Evidenz → Struktur → Validierung → Projekt → reproduzierbare Ausgabe.
