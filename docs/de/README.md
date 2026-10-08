# SASD Secure Binary Analysis Tool

[![Lizenz: MIT](https://img.shields.io/badge/Lizenz-MIT-yellow.svg)](../../LICENSE)
![Status](https://img.shields.io/badge/status-Planung%20%2F%20Pre--Implementation-orange)
![Security](https://img.shields.io/badge/security-read--only%20first-blue)
![Dokumentation](https://img.shields.io/badge/docs-DE%20%7C%20EN-informational)

**Sichere, projektorientierte Workbench zur reproduzierbaren Analyse und Dokumentation von Binärdaten.**

> **Projektstatus:** Planung / Pre-Implementation. Dieses README beschreibt die freigegebene Produkt- und Anforderungsrichtung, nicht bereits implementierte Funktionen.

[English (Default)](../../README.md) · **Deutsch**

---

## Warum Binary Insight?

Hex-Editoren können Bytes hervorragend anzeigen. Reverse-Engineering-Suiten können Programme tief analysieren. Formatsprachen können Binärstrukturen beschreiben. In realen Engineering-Aufgaben liegen die gewonnenen Erkenntnisse jedoch häufig verteilt in Notizen, Screenshots, Skripten und Einzelwerkzeugen.

**SASD Binary Insight** soll diese Lücke schließen:

> **Treffer → Bedeutung → Evidenz → Struktur → Annotation → Validierung → Vergleich → Report → Automatisierung**

Die Byteansicht bleibt die überprüfbare Grundlage. Der eigentliche Produktwert entsteht daraus, dass Analysewissen **nachvollziehbar, speicherbar, versionierbar, testbar und wiederverwendbar** wird.

Das Projekt will deshalb nicht einfach HxD, ImHex, 010 Editor oder Ghidra nachbauen. Es kombiniert ausgewählte bewährte Ideen zu einer SASD-orientierten **Binary Knowledge Workbench**.

## Produktziele

Binary Insight soll insbesondere:

- unbekannte und teilweise dokumentierte Binärformate untersuchbar machen;
- große Dateien analysieren, ohne sie vollständig in den RAM zu laden;
- Hex-/Textansicht, Data Inspector, Suche und String-Analyse verbinden;
- Signaturen und Patterns erkennen und ihre Herkunft nachvollziehbar machen;
- **Fakten, starke Indizien und Heuristiken sichtbar unterscheiden**;
- Bookmarks, Annotationen und Strukturwissen als Analyseprojekt erhalten;
- Binärstrukturen deklarativ beschreiben und validieren;
- Hashes, Checksums, Entropie und Byte-Statistiken bereitstellen;
- Ergebnisse in reproduzierbaren Reports dokumentieren;
- langfristig GUI, CLI und kontrollierte Automatisierung auf derselben Analysebasis ermöglichen.

## Was Binary Insight ausdrücklich nicht ist

Zum V1-Ziel gehören **kein** vollständiger Ghidra-/IDA-Ersatz, kein Malware-Labor, Passwort-Cracker, universeller Decryptor, Datenrettungsprogramm oder Cloud-Zwangsdienst.

Schreib-, Patch-, Device- und Recovery-Funktionen werden nicht beiläufig in die Analyse eingebaut. Sie gehören in spätere, ausdrücklich freigegebene Risikoklassen.

## V1 – geplante Secure Binary Analysis Foundation

| Bereich | Geplante Fähigkeit |
|---|---|
| Byte-Zugriff | Read-only, Random Access, große Dateien, Page/Chunk-basiert |
| Hex View | Offset + Hex + Text, synchronisierte Auswahl und Navigation |
| Data Inspector | Integer, Float/Double, Endianness, Strings, Bits, Zeitstempel, UUID |
| Suche | Hex und Text über die gesamte Quelle, Trefferliste, Cancellation |
| Strings | ASCII/UTF-8, konfigurierbare Mindestlänge |
| Pattern Engine | Magic Bytes, feste/maskierte Patterns, Rule Packs, Overlays |
| Evidence | Confirmed, Strong, Probable, Heuristic, Unknown |
| Wissen | Bookmarks, Annotationen, Kategorien und Kommentare |
| Projekte | Quelle/Fingerprint, Befunde, Formatwissen und Analysezustand |
| Strukturen | begrenztes deklaratives V1-Formatmodell + Structure Inspector |
| Validierung | Fixed/Magic, Ranges, Bounds, Referenzen und Checksums |
| Integrität | SHA-256/SHA-512, CRC32; Legacy-Hashes nur gekennzeichnet |
| Analyse | Entropie und Byte Frequency |
| Reporting | Markdown/HTML; PDF über definierten Exportweg |
| Qualität | reproduzierbare Builds, Tests, CI, Robustheits- und Performanceprüfungen |

Die verbindlichen Details stehen im [Lastenheft](requirements/LASTENHEFT.md) und [Pflichtenheft](requirements/PFLICHTENHEFT.md).

## Evidence statt Scheingewissheit

Eine Kernidee des Produkts ist die Trennung zwischen Beobachtung und Schlussfolgerung. Ein validierter Magic-Byte-Treffer kann starke Evidenz liefern; hohe Entropie kann dagegen durch Verschlüsselung, Kompression oder andere Daten entstehen.

Geplant sind die Stufen **Confirmed**, **Strong**, **Probable**, **Heuristic** und **Unknown**. Diese Unterscheidung soll auch in Reports erhalten bleiben.

## Geplante Workbench

~~~text
┌────────────────────────────────────────────────────────────────────┐
│ File / Search / Analysis / Tools                                  │
├───────────────┬───────────────────────────────────┬────────────────┤
│ File Info     │                                   │ Structure      │
│ Patterns      │          Hex / Text View          │ Inspector      │
│ Bookmarks     │                                   │ Pattern Detail │
│               │                                   │ Data Inspector │
├───────────────┴───────────────────────────────────┴────────────────┤
│ Entropy | Strings | Search Results | Compare | Statistics | Log   │
└────────────────────────────────────────────────────────────────────┘
~~~

Die UI ist ein Zielbild. Ein langfristig sichtbarer Arbeitsbereich gehört nicht automatisch zum V1-Umfang.

## Sicherheitsmodell

**Read-only first** ist Produktprinzip und keine bloße UI-Voreinstellung.

- lokale Verarbeitung als Standard;
- keine verpflichtende Telemetrie;
- kein automatischer Upload analysierter Dateien;
- keine automatische Skriptausführung beim Öffnen;
- keine unnötigen sensiblen Payloads in Projekten oder Logs;
- kontrollierte Diagnose fehlerhafter/trunkierter Daten;
- Bounds-Prüfung bei Parsern;
- spätere Vault-Schlüssel bleiben beim SASD Vault;
- spätere physische Datenträger standardmäßig read-only;
- Editing und Recovery nur nach gesonderter Sicherheitsentscheidung.

## Architektur-Richtung

~~~text
Desktop UI / TUI / CLI
        │
Application Services / Commands
        │
Project | Search | Pattern | Format | Diff | Report
        │
Analysis Model / Evidence / Validation
        │
ByteProvider / Address Space / Cache / Transform Streams
        │
File | Disk Image | Device | Vault | Future Sources
~~~

Der Analyse-Core soll nicht von einer bestimmten GUI-Technologie abhängen. GUI und spätere CLI sollen dieselben fachlichen Funktionen verwenden. Langlaufende Operationen müssen Progress/Cancellation unterstützen.

## Plattformstrategie

| Plattform | Ziel |
|---|---|
| Linux | V1 Pflicht |
| Windows | V1 oder spätestens V1.1/V1.5 |
| macOS | später |
| OpenBSD | perspektivisch Core/CLI |

Sprache, GUI-Technologie und konkrete Dependencies werden über die initialen ADRs entschieden.

## Roadmap

| Release | Schwerpunkt |
|---|---|
| Phase 0 | Engineering Foundation, ADRs, Build, Tests, CI |
| V0.1 | ByteProvider, File Provider, Cache, Random Access |
| V1.0 Alpha | stabiler Hex/ASCII Viewer + Inspector |
| V1.0 Beta | Suche, Bookmarks, Annotationen, Projekte, Hashes, Strings |
| V1.0 RC1 | Pattern Engine, Evidence, Strukturmodell, Validierung |
| V1.0 RC2 | Entropie, Statistik, Performance, Reporting, Hardening |
| **V1.0** | **Secure Binary Analysis Foundation** |
| V1.1 | Compare + CLI |
| V1.2 | Format Workbench + Structure Diff |
| V1.5 | Kaitai + Extensibility |
| V2.0 | Executable Insight |
| V2.5 | Secure/Crypto Insight + Vault |
| V3.0 | Disk & Filesystem Insight |
| V3.5 | Automation & Plugins |
| V4.0 | Controlled Editing |
| V5+ | optional Recovery/Repair |

## Forschungsbasis

Betrachtet wurden klassische und moderne Hex-Editoren, Format-/Parser-Werkzeuge, Reverse-Engineering-Plattformen, Diff-Tools, Large-File-Editoren und einbettbare Komponenten. Wichtige Referenzen sind unter anderem 010 Editor, ImHex, Hex Fiend, Synalyze It!, Kaitai Struct, Ghidra, radare2/Rizin/Cutter, rehex, HexWalk, Q22, fhex, wxHexEditor und VBinDiff.

- [Feature- und Marktanalyse](research/FEATURE-ANALYSE.md)
- [Open-Source-Hex-Editor-Katalog](research/OPEN-SOURCE-HEX-EDITOR-KATALOG.md)

## SASD-Integration

- **SASD Optical Media Workbench** – read-only Sektor-/Hex-Erfahrung und mögliche gemeinsame Analysekomponenten;
- **SASD Editor Toolkit/Toolbox** – Navigation, Selection, Commands und spätere Undo/Redo-Konzepte;
- **SASD UI Toolkit / UI Platform** – mögliche UI-Wiederverwendung ohne Core-Kopplung;
- **SASD Desktop Secret Manager / Vault** – spätere kontrollierte Schnittstelle; Schlüsselverwaltung verbleibt beim Vault.

## Repository-Struktur

~~~text
.
├── README.md                     Englisch als Default
├── LICENSE
└── docs/
    ├── README.md
    ├── adr/
    ├── history/
    ├── de/
    │   ├── README.md
    │   ├── requirements/
    │   │   ├── LASTENHEFT.md
    │   │   └── PFLICHTENHEFT.md
    │   ├── strategy/
    │   └── research/
    └── en/
        ├── README.md
        ├── requirements/
        │   ├── REQUIREMENTS.md
        │   └── SPECIFICATION.md
        ├── strategy/
        └── research/
~~~

## Architektur

- [Architekturdokument](architecture/ARCHITEKTUR.md) – Schichten, Komponenten, ByteProvider, Datenflüsse, Sicherheitsgrenzen, Persistenz, Tests und Evolutionspfad.

## Dokumentation

- [Lastenheft](requirements/LASTENHEFT.md) – **was** benötigt wird und **warum**;
- [Pflichtenheft](requirements/PFLICHTENHEFT.md) – **wie** die Anforderungen umgesetzt werden sollen;
- [Produktstrategie](strategy/PRODUKTSTRATEGIE.md);
- [Feature-Analyse](research/FEATURE-ANALYSE.md);
- [Open-Source-Hex-Editor-Katalog](research/OPEN-SOURCE-HEX-EDITOR-KATALOG.md);
- [ADR-Übersicht](../adr/README.md);
- [Dokumentationshistorie](../history/README.md).

## Build und Entwicklung

**Noch nicht verfügbar.** Das Repository befindet sich vor Implementierungsbeginn. Build- oder Run-Befehle wären vor Entscheidung und Umsetzung von Sprache, Buildsystem, GUI-Technologie und initialen Architektur-ADRs irreführend.

Nach Phase 0 wird dieser Abschnitt um reproduzierbare Voraussetzungen, Build-, Test-, Run- und CI-Anweisungen ergänzt.

## Qualitätsanspruch

V1 plant unter anderem Tests für Page-/Chunk-Grenzen und große Offsets, robuste Behandlung beschädigter/trunkierter Daten, definierte Format-Fixtures, reproduzierbare Analyseprojekte, Performance-Fixtures von mindestens 1 GB und 10 GB, reproduzierbare Builds/CI, statische Prüfungen und dokumentierte Dependencies/Lizenzen.

Die konkreten V1-Abnahmekriterien stehen im [Lastenheft](requirements/LASTENHEFT.md#14-abnahmekriterien-für-v1).

## Lizenz und Dependencies

Das Repository steht unter der [MIT License](../../LICENSE).

MIT, BSD und Apache-2.0 werden bei Abhängigkeiten bevorzugt. LGPL benötigt eine bewusste Integrationsprüfung; GPL/AGPL-Komponenten werden nicht ohne explizite Lizenzentscheidung eingebettet.

Zu evaluieren sind insbesondere geeignete Hex-Controls, Kaitai Struct, Capstone/Zydis und libmagic bzw. Alternativen.

## Projektstatus

Der aktuelle Stand ist **Planning / Pre-Implementation**. Die Produkt- und Requirements-Baseline ist vorhanden; vor der Implementierung müssen die initialen Architekturentscheidungen abgeschlossen werden.

Dieses README beschreibt daher das **geplante Produkt**. V1/V2/... sind Zielumfänge und keine Behauptung bereits vorhandener Funktionen.

---

**SASD Binary Insight**  
*A secure, evidence-aware binary analysis workbench that turns byte-level findings into reproducible engineering knowledge.*

## SASD Development Standard

Dieses Projekt orientiert sich am [SASD Development Standard](https://github.com/Robin-Goerlach/SASD-Development-Standard). Dessen **deutsche, genehmigte normative Fassung** ist für die Auslegung der Standardanforderungen maßgeblich; Englisch bleibt lediglich die Standardsprache der Repository-Präsentation. Die Übernahme ist derzeit **teilweise**, keine bestätigte Konformität.

- [Anwendungs- und Lückenanalyse](../SASD-DEVELOPMENT-STANDARD.md)
- [Kompakter Projektbrief](../PROJECT-BRIEF.md)
- [Roadmap](../../ROADMAP.md)
- [Codex-/Agentenregeln](../../AGENTS.md)
