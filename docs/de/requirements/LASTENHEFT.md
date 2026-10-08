# SASD Secure Binary Analysis Tool
## Lastenheft – Anforderungen aus Auftraggeber-/Nutzersicht

**Produktname:** SASD Secure Binary Analysis Tool  
**Arbeits-/UI-Name:** SASD Binary Insight  
**Stand:** 2026-10-08  
**Status:** Produktanforderungsbaseline  
**Dokumenttyp:** Lastenheft – beschreibt **was** und **warum** benötigt wird; technische Umsetzung und konkrete Architektur sind Gegenstand des Pflichtenhefts und der ADRs.

> **Produktvision:** SASD Binary Insight soll Binärdaten nicht nur anzeigen, sondern nachvollziehbar verständlich machen. Aus Bytefolgen sollen überprüfbare, kommentierbare, validierbare und wiederverwendbare Analyseergebnisse entstehen.

## 1. Ausgangssituation und Motivation

SASD benötigt für Entwicklung, Administration, Schulung, Forschung und spätere Security-/Forensik-Szenarien ein Werkzeug zur Untersuchung unbekannter oder dokumentationsbedürftiger Binärdaten. Klassische Hex-Editoren zeigen Bytes zuverlässig an, bilden aber den vollständigen SASD-Arbeitsprozess nur unzureichend ab.

Typische Aufgaben sind:

- unbekannte oder teilweise dokumentierte Dateiformate untersuchen;
- Header, Kennungen, Felder, Strings, Zahlenwerte und wiederkehrende Muster erkennen;
- Unterschiede zwischen Versionen oder Beispieldateien nachvollziehen;
- Annahmen über Strukturen dokumentieren und später erneut prüfen;
- Prüfsummen, Hashes, statistische Auffälligkeiten und Formatverletzungen feststellen;
- Analysewissen für Dokumentation, Tests, Parser und Softwareentwicklung wiederverwenden;
- große Binärdateien untersuchen, ohne sie vollständig in den Arbeitsspeicher laden zu müssen;
- Analysen lokal und ohne obligatorische Cloud-Dienste durchführen.

Daraus ergibt sich der Bedarf an einer **sicheren, projektorientierten Binary-Analysis-Workbench**, nicht lediglich an einem weiteren allgemeinen Hex-Editor.

## 2. Ziele

### 2.1 Hauptziel

Das Produkt soll eine verlässliche Arbeitsumgebung bereitstellen, in der Binärdaten von den Rohbytes bis zur fachlich beschriebenen Struktur untersucht werden können und die gewonnenen Erkenntnisse reproduzierbar erhalten bleiben.

### 2.2 Teilziele

Das Produkt soll:

1. Binärdateien sicher und zunächst ausschließlich lesend öffnen;
2. auch große Dateien performant navigierbar machen;
3. Bytes parallel in Hex- und Textdarstellung zeigen;
4. ausgewählte Bytes in gebräuchlichen Datentypen interpretieren;
5. Inhalte durchsuchen und gefundene Bereiche direkt ansteuern;
6. bekannte Signaturen, Muster und Strukturen erkennen und verständlich kennzeichnen;
7. zwischen gesicherten Fakten und heuristischen Vermutungen unterscheiden;
8. Analysewissen durch Bookmarks, Annotationen und Strukturdefinitionen festhalten;
9. Dateien und Strukturen validieren;
10. Hashes, Entropie und grundlegende Byte-Statistiken bereitstellen;
11. Analyseergebnisse als Projekt speichern und wieder öffnen;
12. nachvollziehbare Reports erzeugen;
13. langfristig Vergleiche, Automatisierung, Executable-, Crypto/Vault- sowie Datenträgeranalyse ermöglichen;
14. riskante Schreib- und Reparaturfunktionen von der normalen Analyse klar trennen.

## 3. Nichtziele und Abgrenzung

Das Produkt soll in V1 insbesondere **nicht** sein:

- ein vollständiger Ersatz für Ghidra, IDA oder vergleichbare Reverse-Engineering-Suiten;
- ein Malware-Entwicklungs- oder Angriffswerkzeug;
- ein Passwort-Cracker;
- ein universeller Entschlüsseler;
- ein Datenrettungsprogramm;
- ein automatisches Datenträger-Reparaturwerkzeug;
- ein Cloud-Zwangsdienst;
- ein vollwertiger Binäreditor mit unmittelbarem Überschreiben der Originaldatei.

Die Analyse soll Vorrang vor Manipulation haben. Spätere Schreib-, Patch-, Recovery- oder Device-Funktionen benötigen eigene Sicherheitsgrenzen und Freigaben.

## 4. Zielgruppen

### 4.1 Primäre Zielgruppen

Zunächst richtet sich das Produkt an SASD selbst:

- Softwareentwickler;
- System- und Linux/Unix-Administratoren;
- technische Trainer und Lernende;
- Entwickler eigener Datei-, Import- und Protokollformate.

### 4.2 Erweiterte Zielgruppen

Später kommen in Betracht:

- Entwickler und Administratoren kleiner und mittlerer Unternehmen;
- Embedded-/Firmware-Entwickler;
- Forschende und Lehrende;
- Datenmigration und technische Supportteams;
- autorisierte Security- und Forensik-Anwender.

## 5. Typische Nutzungsszenarien

### 5.1 Unbekanntes Dateiformat verstehen

Ein Nutzer öffnet eine Binärdatei, betrachtet Hex- und Textdarstellung, untersucht Werte mit dem Data Inspector, findet Strings und Signaturen, markiert vermutete Felder und entwickelt daraus schrittweise ein dokumentiertes Strukturmodell.

### 5.2 Bekanntes Format prüfen

Eine Datei wird gegen eine bekannte Formatdefinition geprüft. Magic Values, Wertebereiche, Offsets, Längen, Referenzen und Prüfsummen werden kontrolliert. Abweichungen sind nachvollziehbar sichtbar.

### 5.3 Zwei Versionen vergleichen

Zwei Dateien oder später zwei interpretierte Strukturen werden verglichen. Der Nutzer kann Unterschiede lokalisieren und erkennen, welche fachlichen Felder sich verändert haben.

### 5.4 Große Binärdatei untersuchen

Eine Datei im Gigabyte-Bereich wird geöffnet, ohne vollständig in den RAM geladen zu werden. Der Nutzer kann springen, suchen, Hashes berechnen und Analysen abbrechen.

### 5.5 Analyse dokumentieren

Der Nutzer legt Bookmarks, benannte Bereiche, Kommentare und Befunde an. Das Analyseprojekt wird gespeichert und später reproduzierbar wieder geöffnet. Ein Report fasst relevante Fakten und gekennzeichnete Vermutungen zusammen.

### 5.6 Spätere Executable-Analyse

PE-/COFF- und ELF-Dateien sollen mit Headern, Sections/Segments, Imports/Exports, Entry Point und Disassembly untersucht werden können.

### 5.7 Spätere autorisierte Crypto-/Vault-Analyse

Verschlüsselte SASD-Daten sollen über eine kontrollierte Vault-Schnittstelle analysierbar sein, ohne Schlüsselverwaltung in Binary Insight zu duplizieren.

### 5.8 Spätere Datenträgeranalyse

Disk Images und physische Datenträger sollen read-only auf Sektor-, Partitionstabellen- und ausgewählten Dateisystem-Metadatenebenen untersucht werden können.

## 6. Muss-Anforderungen für V1

Die Kennungen **LA-V1-xxx** bilden die fachliche Rückverfolgbarkeit zum späteren Pflichtenheft, zu Tests und Releases.

### 6.1 Datei und Navigation

**LA-V1-001 – Read-only öffnen**  
Das Produkt muss reguläre Binärdateien standardmäßig ausschließlich lesend öffnen können.

**LA-V1-002 – Große Dateien**  
Dateien größer als 1 GB müssen geöffnet und über ihren gesamten Adressraum navigiert werden können, ohne dass die vollständige Datei in den Arbeitsspeicher geladen werden muss.

**LA-V1-003 – Hex-/Textdarstellung**  
Der Nutzer muss Offsets, Hexwerte und eine korrespondierende Textdarstellung gemeinsam sehen können.

**LA-V1-004 – Synchronisierte Auswahl**  
Eine Auswahl muss in Hex- und Textdarstellung denselben Bytebereich repräsentieren.

**LA-V1-005 – Offset-Navigation**  
Der Nutzer muss einen Offset direkt anspringen können.

**LA-V1-006 – Kopieren**  
Ausgewählte Daten müssen mindestens als Hex, Text sowie Offset/Länge kopiert werden können.

**LA-V1-007 – Quelländerung erkennen**  
Wird die analysierte Quelldatei außerhalb des Programms verändert, muss der Nutzer vor einer unbemerkten Weiterarbeit mit veralteten Annahmen geschützt werden.

### 6.2 Dateninterpretation

**LA-V1-010 – Data Inspector**  
Ausgewählte Bytes müssen mindestens als vorzeichenbehaftete und vorzeichenlose 8/16/32/64-Bit-Ganzzahlen, Little/Big Endian, Float/Double, ASCII, UTF-8, UTF-16, Hex und bei geeigneter Länge als Unix-Zeitstempel sowie GUID/UUID interpretierbar sein.

**LA-V1-011 – Bitdarstellung**  
Für geeignete Werte muss eine Bitdarstellung verfügbar sein.

### 6.3 Suche und Strings

**LA-V1-020 – Hexsuche**  
Der Nutzer muss nach Byte-/Hexfolgen suchen können.

**LA-V1-021 – Textsuche**  
Der Nutzer muss nach Text suchen können.

**LA-V1-022 – Gesamte Datei**  
Die Suche muss auch bei großen Dateien den gesamten logischen Inhalt berücksichtigen und darf Treffer an internen Blockgrenzen nicht verlieren.

**LA-V1-023 – Suchergebnisse**  
Treffer müssen mindestens Offset und eine Vorschau enthalten und direkt navigierbar sein.

**LA-V1-024 – Abbruch**  
Lange Suchvorgänge müssen abbrechbar sein.

**LA-V1-025 – Strings**  
Das Produkt muss ASCII- und UTF-8-Strings mit konfigurierbarer Mindestlänge finden können.

### 6.4 Pattern-Erkennung und Evidenz

**LA-V1-030 – Pattern Registry**  
Bekannte Muster und Signaturen müssen zentral verwaltbar und versionierbar sein.

**LA-V1-031 – Erkennungsarten**  
Mindestens Magic Bytes, feste Bytefolgen, maskierte Bytefolgen und geeignete String-/Encoding-Muster müssen unterstützt werden.

**LA-V1-032 – Befundinformationen**  
Ein erkannter Befund muss Name/Kategorie, Beschreibung, Offset, Länge, Evidenz-/Confidence-Stufe und Herkunft der Regel nachvollziehbar machen.

**LA-V1-033 – Visuelle Kennzeichnung**  
Erkannte Bereiche müssen in der Byteansicht eindeutig hervorgehoben und filterbar sein. Farbe allein darf nicht die einzige Information tragen.

**LA-V1-034 – Überlappungen**  
Überlappende Erkennungen müssen deterministisch und für den Nutzer nachvollziehbar behandelt werden.

**LA-V1-035 – Benutzerregeln**  
Eigene Pattern-Regeln sollen ohne Neukompilierung der Anwendung ergänzt werden können.

**LA-V1-036 – Confidence/Evidence**  
Automatische Aussagen müssen mindestens in Confirmed, Strong, Probable, Heuristic und Unknown unterscheidbar sein.

**LA-V1-037 – Keine Scheingewissheit**  
Heuristische Indikatoren dürfen nicht als bewiesene Tatsachen dargestellt werden; insbesondere ist hohe Entropie kein automatischer Beweis für Verschlüsselung.

### 6.5 Bookmarks, Annotationen und Analyseprojekt

**LA-V1-040 – Bookmarks**  
Offsets und Bytebereiche müssen als Bookmarks speicherbar sein.

**LA-V1-041 – Annotationen**  
Bytebereiche müssen benannt, kategorisiert und kommentiert werden können.

**LA-V1-042 – Projektpersistenz**  
Bookmarks, Annotationen, relevante Befunde, verwendete Formatdefinitionen und erforderlicher Analysekontext müssen in einem Projekt gespeichert werden können.

**LA-V1-043 – Reproduzierbares Wiederöffnen**  
Ein gespeichertes Projekt muss später so geöffnet werden können, dass der Nutzer seine Analyse nachvollziehbar fortsetzen kann.

**LA-V1-044 – Quellenbezug**  
Das Projekt muss erkennen können, ob die referenzierte Quelldatei noch zu der gespeicherten Analyse passt.

**LA-V1-045 – Keine unnötigen Secrets**  
Projektdateien dürfen keine Schlüssel, Passwörter oder unnötigen Kopien sensibler Nutzdaten enthalten.

**LA-V1-046 – Versionierbarkeit**  
Das Projektformat soll versioniert, migrationsfähig und soweit sinnvoll für Versionsverwaltung geeignet sein.

### 6.6 Strukturierte Binärformate

**LA-V1-050 – Strukturdefinitionen**  
Nutzer müssen einfache Binärstrukturen deklarativ beschreiben können.

**LA-V1-051 – V1-Strukturelemente**  
Mindestens Namen, Offsets, primitive Typen, Längen, Endianness, Beschreibungen, Enumerationen, Fixed/Magic Values, einfache Arrays und verschachtelte Strukturen müssen darstellbar sein.

**LA-V1-052 – Structure Inspector**  
Interpretierte Felder müssen strukturiert angezeigt und mit dem zugehörigen Bytebereich verknüpft sein.

**LA-V1-053 – Einfache Validierung**  
Formatdefinitionen müssen einfache Validierungsregeln enthalten können.

### 6.7 Validierung

**LA-V1-060 – Formatprüfung**  
Magic/Fixed Values, Wertebereiche, Bounds und Referenzen/Offsets müssen prüfbar sein.

**LA-V1-061 – Prüfsummen**  
Prüfsummen sollen modular in die Validierung eingebunden werden können.

**LA-V1-062 – Schweregrad**  
Validierungsbefunde müssen mindestens als Information, Warnung oder Fehler klassifizierbar sein.

**LA-V1-063 – Befundnavigation**  
Validierungsbefunde müssen zum betroffenen Byte-/Strukturbereich führen.

### 6.8 Hashes, Entropie und Statistik

**LA-V1-070 – Moderne Hashes**  
SHA-256 und SHA-512 müssen für Dateien bzw. relevante Datenbereiche berechnet werden können.

**LA-V1-071 – Legacy-Hashes**  
MD5 und SHA-1 dürfen für Kompatibilität/Identifikation angeboten werden, müssen aber klar als kryptographisch veraltet gekennzeichnet sein.

**LA-V1-072 – CRC32**  
CRC32 soll als modulare Prüfsummenfunktion verfügbar sein.

**LA-V1-073 – Große Datenmengen**  
Hashberechnungen müssen große Dateien verarbeiten können, ohne sie vollständig in RAM zu laden.

**LA-V1-074 – Entropie**  
Das Produkt muss Gesamtentropie und eine positionsbezogene Entropieanalyse über Fenster bereitstellen.

**LA-V1-075 – Navigation aus Analyse**  
Von einer positionsbezogenen Entropieanzeige muss zum entsprechenden Bytebereich navigiert werden können.

**LA-V1-076 – Byte Frequency**  
Eine Häufigkeitsanalyse der Bytewerte muss verfügbar sein.

### 6.9 Reporting

**LA-V1-080 – Analysebericht**  
Der Nutzer muss Ergebnisse als nachvollziehbaren Bericht exportieren können.

**LA-V1-081 – Kernformate**  
Markdown und HTML müssen als Kernformate vorgesehen werden; ein PDF-Export soll über einen definierten Exportweg möglich sein.

**LA-V1-082 – Fakten und Heuristiken**  
Berichte müssen gesicherte Befunde und heuristische Aussagen unterscheidbar darstellen.

**LA-V1-083 – Datenschutz beim Export**  
Der Nutzer muss kontrollieren können, welche sensiblen Inhalte in einen Bericht aufgenommen werden.

## 7. Qualitätsanforderungen

### 7.1 Sicherheit

**LA-Q-001** Lokale Verarbeitung muss der Standard sein.  
**LA-Q-002** Es darf keine verpflichtende Telemetrie oder automatische Dateiübertragung geben.  
**LA-Q-003** Dateien werden in V1 nicht automatisch verändert.  
**LA-Q-004** Beim Öffnen einer Datei dürfen keine eingebetteten Skripte automatisch ausgeführt werden.  
**LA-Q-005** Logs dürfen sensible Payloads nicht ungefragt vollständig aufzeichnen.  
**LA-Q-006** Fehlerhafte oder absichtlich ungewöhnliche Eingabedaten dürfen nicht zu unkontrolliertem Speicherzugriff führen.  
**LA-Q-007** Parser und Strukturinterpretation müssen außerhalb der Quelle liegende Zugriffe zuverlässig erkennen.

### 7.2 Robustheit

**LA-Q-010** Trunkierte, inkonsistente oder unbekannte Dateien dürfen die Anwendung nicht zum Absturz bringen.  
**LA-Q-011** Fehler sollen möglichst am betroffenen Bereich erklärt werden.  
**LA-Q-012** Langlaufende Analysen müssen abbrechbar sein.  
**LA-Q-013** Ein Fehler in einem Analysemodul soll nach Möglichkeit nicht die gesamte Analyse unbrauchbar machen.

### 7.3 Performance und Skalierbarkeit

**LA-Q-020** Die Bedienoberfläche muss beim Navigieren durch große Dateien responsiv bleiben.  
**LA-Q-021** Mindestens 1-GB- und 10-GB-Testdateien sollen für Performanceprüfungen vorgesehen werden.  
**LA-Q-022** Nur für die aktuelle Aufgabe benötigte Daten sollen verarbeitet bzw. dargestellt werden müssen.  
**LA-Q-023** Suche, Hashing, Pattern Scan und Entropieanalyse dürfen nicht von einer vollständigen RAM-Kopie der Quelle abhängen.

### 7.4 Bedienbarkeit und Barrierearmut

**LA-Q-030** Zentrale Funktionen müssen über nachvollziehbare Navigation erreichbar sein.  
**LA-Q-031** HexView, Data Inspector, Structure Inspector, Suchergebnisse und Befunde müssen miteinander navigierbar sein.  
**LA-Q-032** Bedeutung darf nicht ausschließlich durch Farbe vermittelt werden.  
**LA-Q-033** Technische Befunde sollen verständliche Namen und Beschreibungen besitzen.

### 7.5 Portabilität

**LA-Q-040** Linux-Unterstützung ist für V1 erforderlich.  
**LA-Q-041** Windows soll V1 oder spätestens V1.1/V1.5 unterstützen.  
**LA-Q-042** macOS ist eine spätere Zielplattform.  
**LA-Q-043** OpenBSD-Unterstützung für Core/CLI ist perspektivisch erwünscht, soweit Abhängigkeiten dies zulassen.

### 7.6 Wartbarkeit und Wiederverwendbarkeit

**LA-Q-050** Fachliche Analysefunktionen dürfen nicht dauerhaft an eine einzelne GUI-Technologie gebunden sein.  
**LA-Q-051** Format-, Pattern- und Projektwissen muss versionierbar sein.  
**LA-Q-052** Wiederverwendbare vorhandene Bibliotheken sollen vor Eigenimplementierungen geprüft werden.  
**LA-Q-053** Externe Abhängigkeiten und ihre Lizenzen müssen nachvollziehbar dokumentiert werden.

## 8. Soll-Anforderungen nach V1

### 8.1 V1.1 – Compare und CLI

- Byte-Diff mit synchronisierter Navigation und markierten Unterschiedsbereichen;
- erste CLI für wiederholbare Analysen;
- Nutzung derselben Analysefähigkeiten wie die GUI.

### 8.2 V1.2 – Format Workbench

- komfortablere Erstellung und Bearbeitung von Formatdefinitionen;
- dynamische Längen und Bedingungen;
- Unions und Bitfelder;
- berechnete Felder und Includes;
- Structure Diff.

### 8.3 V1.5 – Interoperabilität und Extensibility

- Kaitai-Struct-Import bzw. definierte Kompatibilität;
- Erweiterung der Format-/Analyse-Schnittstellen;
- Vorbereitung kontrollierter Erweiterbarkeit.

## 9. Langfristige Anforderungen

### 9.1 V2 – Executable Insight

Das Produkt soll PE/COFF und ELF, später Mach-O, strukturiert untersuchen können. Gewünscht sind Header, Sections/Segments, Imports/Exports, Symbole soweit verfügbar, Entry Point, File Offset ↔ Virtual Address und Disassembly. Eine bewährte Disassembler-Bibliothek soll gegenüber einer eigenen CPU-Decoder-Implementierung bevorzugt werden.

### 9.2 V2.5 – Secure/Crypto Insight

Für autorisierte Analysen sollen Crypto-Metadaten und eine kontrollierte SASD-Vault-Integration möglich sein. Authentifizierung und Schlüsselverwaltung verbleiben im Vault. Binary Insight soll Schlüssel nicht dauerhaft speichern und entschlüsselte Daten nach Möglichkeit nur so lange wie erforderlich im Speicher halten.

### 9.3 V3 – Disk & Filesystem Insight

RAW/DD/IMG/ISO, Partitionstabellen, Sektornavigation, read-only physische Devices und ausgewählte Dateisystem-Metadaten sollen unterstützt werden. Analyse und Reparatur sind strikt zu trennen.

### 9.4 V3.5 – Automation und Plugins

Scripting, Plugins und Headless-Automatisierung sollen kontrolliert möglich werden. Erweiterungen benötigen ein explizites Berechtigungs- und Vertrauensmodell; das Öffnen einer Datei darf niemals ungefragt Fremdcode aktivieren.

### 9.5 V4 – Controlled Editing

Optional soll später ein bewusst aktivierter Editiermodus mit Undo/Redo, Copy-on-Write, Patch-Dateien, Review before Save, Backup und möglichst sicherem Schreiben entstehen. Die Originaldatei darf nicht beiläufig verändert werden.

### 9.6 V5+ – Recovery/Repair

Recovery- oder Reparaturfunktionen sind optional und gegebenenfalls als eigenes Modul/Produkt zu behandeln. Diagnose, Dry Run, Backup, Auditierbarkeit und kontrollierte Freigabe sind Voraussetzung.

## 10. SASD-Integration

Das Produkt soll Synergien mit bestehenden bzw. geplanten SASD-Projekten ermöglichen, ohne unnötige harte Kopplung:

- **SASD Optical Media Workbench:** read-only Sektor-/Hex-Erfahrung und ggf. gemeinsame Byte-/Analysekomponenten;
- **SASD Editor Toolkit/Toolbox:** Navigation, Selection, Commands und später Undo/Redo;
- **SASD UI Toolkit/UI Platform:** wiederverwendbare UI-Konzepte, sofern der Analyse-Core unabhängig bleibt;
- **SASD Desktop Secret Manager/Vault:** alleinige Verantwortung für Authentifizierung und Schlüsselverwaltung; Binary Insight nutzt später nur eine kontrollierte Schnittstelle.

## 11. Daten und Schutzbedarf

Analysierte Dateien können vertrauliche, personenbezogene, proprietäre oder sicherheitsrelevante Inhalte enthalten. Daraus folgen:

- lokale Verarbeitung als Standard;
- keine automatische Cloud-Übertragung;
- keine unnötige Duplizierung der Quelldaten in Projektdateien;
- kontrollierbarer Reportinhalt;
- keine dauerhafte Speicherung von Vault-Schlüsseln;
- nachvollziehbarer Umgang mit temporären Klartextdaten;
- read-only Zugriff auf physische Datenträger als Standard.

## 12. Lizenz- und Beschaffungsanforderungen

Vor Eigenentwicklung sollen geeignete bestehende Komponenten geprüft werden. Funktionale Inspiration ist von Codeübernahme zu trennen.

Bevorzugt werden Abhängigkeiten mit MIT-, BSD- oder Apache-2.0-Lizenz. LGPL-Komponenten benötigen eine bewusste Prüfung des Integrationsmodells. GPL-/AGPL-Code darf nicht ohne explizite Lizenzentscheidung in eine inkompatibel lizenzierte Anwendung übernommen oder eingebettet werden.

Insbesondere sollen Hex-Controls, Kaitai Struct, Capstone/Zydis und libmagic bzw. geeignete Alternativen evaluiert werden.

## 13. Lieferumfang

### 13.1 V1

Erwartet werden mindestens:

- lauffähige Desktop-Anwendung für die V1-Zielplattform(en);
- dokumentierter Analyse-Core;
- Hex-/Textansicht und Data Inspector;
- Suche und String-Analyse;
- Pattern-/Evidence-Funktionen;
- Bookmarks und Annotationen;
- Analyseprojekt;
- minimales Strukturmodell und Validierung;
- Hash-/Entropie-/Statistikfunktionen;
- Reporting;
- automatisierte Tests;
- reproduzierbarer Build und CI;
- Benutzer- und Entwicklerdokumentation für den erreichten Funktionsumfang;
- dokumentierte Drittanbieterabhängigkeiten und Lizenzen.

### 13.2 Nicht Bestandteil von V1

Byte-Diff/CLI, vollständige Executable-Analyse, Vault-Entschlüsselung, physische Datenträgeranalyse, Plugins/Scripting, Editing und Recovery gehören ausdrücklich nicht zum verbindlichen V1-Lieferumfang, sofern sie nicht durch eine spätere Baseline vorgezogen werden.

## 14. Abnahmekriterien für V1

Die V1-Abnahme ist erfolgreich, wenn mindestens folgende fachliche Nachweise erbracht sind:

1. Eine Datei >1 GB lässt sich öffnen und über den vollständigen Adressraum navigieren, ohne vollständige RAM-Kopie.
2. Definierte Testwerte werden in Little und Big Endian korrekt interpretiert.
3. Hex- und Textsuche finden Treffer auch über interne Block-/Page-Grenzen hinweg.
4. Ein Analyseprojekt mit Bookmarks, Annotationen und Befunden lässt sich speichern und reproduzierbar wieder öffnen.
5. Eine nachträglich veränderte Quelldatei wird als nicht mehr unverändert zur gespeicherten Analyse erkannt.
6. Definierte PNG-, ZIP-, PE- und ELF-Testdateien bzw. deren vereinbarte Signaturen werden erkannt.
7. Ein absichtlich mehrdeutiger Befund wird als Heuristik und nicht als gesicherte Tatsache ausgewiesen.
8. Ein definiertes verschachteltes SASD-Testformat wird korrekt strukturiert dargestellt.
9. Eine beschädigte/trunkierte Testdatei erzeugt einen nachvollziehbaren Validierungsbefund statt eines Absturzes.
10. Hashing und Entropieanalyse arbeiten auch auf großen Testdateien und lassen sich bei langen Vorgängen kontrolliert abbrechen.
11. Ein Report kann die wesentlichen Analyseergebnisse exportieren und Fakten von Heuristiken unterscheiden.
12. Build, automatisierte Tests und vereinbarte statische Prüfungen laufen reproduzierbar in CI.

## 15. Priorisierung

### Muss für V1

Read-only Large-file-Zugriff, Hex/Text, Data Inspector, Suche, Strings, Pattern Engine, Confidence/Evidence, Bookmarks/Annotationen, Analyseprojekt, minimales Strukturmodell, Validierung, Hashing, Entropie/Byte Frequency, Reporting, Robustheit und Tests.

### Soll unmittelbar danach

Byte-Diff, CLI, erweiterte Formatdefinitionen, Structure Diff und Kaitai-Interoperabilität.

### Kann später

Executable Insight, Vault/Crypto Insight, Disk/Filesystem Insight, Plugins/Scripting, Controlled Editing und Recovery/Repair gemäß Roadmap und separater Sicherheitsentscheidung.

## 16. Erfolgskriterien des Produkts

Das Projekt ist fachlich erfolgreich, wenn Binary Insight im realen SASD-Alltag nicht nur als Hexanzeige, sondern als wiederverwendbares Analysewerkzeug eingesetzt wird und mindestens folgende Wirkung erzielt:

- Analysewissen geht zwischen Sitzungen nicht verloren;
- Befunde sind für Dritte nachvollziehbar;
- Vermutungen werden nicht mit Fakten verwechselt;
- Formatwissen kann versioniert und getestet werden;
- Ergebnisse lassen sich in Dokumentation, Tests, Parser oder weitere SASD-Werkzeuge überführen;
- für häufige Binäranalyse-Aufgaben werden weniger isolierte Einzelwerkzeuge und manuelle Notizen benötigt.

## 17. Verhältnis zu Pflichtenheft und ADRs

Dieses Lastenheft definiert die fachlichen Erwartungen aus Auftraggeber-/Nutzersicht. Das [Pflichtenheft](PFLICHTENHEFT.md) beschreibt die daraus abgeleitete technische Lösung und Releaseplanung. Dauerhafte Architekturentscheidungen werden zusätzlich in ADRs dokumentiert.

Bei Änderungen soll die Rückverfolgbarkeit **Lastenheft → Pflichtenheft → ADR/Implementation → Test/Abnahme** erhalten bleiben.
