# Produktstrategie – SASD Binary Insight

**Stand:** 2026-10-08  
**Herkunft:** konsolidiert aus den strategischen Fragen/Antworten, der Feature-Analyse und den späteren Chatentscheidungen.

## Kernentscheidung

Die relevante Produktfrage lautet nicht „Braucht SASD einen eigenen Hex-Editor?“, sondern:

> **Welche Binärdatenprobleme der SASD-GmbH und ihrer Kunden bleiben trotz vorhandener Werkzeuge schlecht in reproduzierbare Engineering-Prozesse integrierbar?**

Ein klassischer Hex-Editor ist austauschbar. Binary Insight soll aus einer Analyse dagegen ein dauerhaftes, versionierbares Wissensartefakt machen.

## Warum das Produkt existiert

SASD arbeitet bzw. plant Arbeit mit Logs, Datenübertragung, Importformaten, wissenschaftlichen Daten, Embedded/Firmware, Datenträgern, Protokollen und Schulungen. In diesen Fällen reicht es nicht, Bytes zu sehen. Felder müssen benannt, Werte validiert, Versionen verglichen und Erkenntnisse später in Parser, Tests und Dokumentation überführt werden.

## Primärer Nutzer

V1 wird zuerst für SASD selbst gebaut: Entwickler, Administratoren und Trainer, die reale Binärdateien analysieren. Danach folgen technische Nutzer in kleineren Unternehmen, Forschung/Schulung und später autorisierte Security-/Forensik-Szenarien.

## USP

Nicht „besserer Hex-Editor“, sondern **Analysewissen als Produktartefakt**:

- Projekt statt Wegwerf-Session;
- Bedeutung statt bloßer Bytes;
- Evidence/Confidence statt unbelegter Behauptungen;
- Dokumentation statt Screenshots;
- Validierung statt reiner Interpretation;
- CLI/Automatisierung statt GUI-Insel;
- SASD-Integration statt isoliertem Werkzeug.

## Produktgrenzen

V1 ist kein Ghidra-Klon, Malware-Labor, vollständiger Editor, Datenrettungsprogramm oder Cloud-Dienst. Riskante Funktionen werden zeitlich und architektonisch getrennt.

## Standalone und Plattform

Das Produkt muss standalone und lokal nutzbar sein. Intern wird es trotzdem als Plattform aus Core, Projektmodell, Format-/Pattern-Engine, Reporting und UI-Adaptern gebaut. CLI, Plugins und andere Hosts sollen dadurch später ohne Neuschreiben der Analyse möglich sein.

## Automatisierung

V1 entwirft Datenmodelle und Projekte GUI-unabhängig. V1.1 führt die erste CLI ein. Kontrolliertes Scripting und Plugins folgen erst nach einem Berechtigungsmodell.

## Datenmengen

- KB–MB: vollständig komfortabel;
- GB: V1 muss öffnen, navigieren, suchen und analysieren;
- Zehner/Hunderter GB: schrittweise Optimierung ab V2/V3;
- TB: Spezialfall über Streaming/Index-/Provider-Architektur.

## Plattformstrategie

Linux ist strategisch V1-Pflicht. Windows soll V1 oder spätestens V1.1/V1.5 erreichen. macOS folgt später. OpenBSD ist für Core/CLI interessant, sofern Abhängigkeiten dies zulassen.

## Sicherheitsstrategie

- lokale Verarbeitung als Default;
- read-only first;
- keine Telemetriepflicht;
- keine automatische Skriptausführung;
- sensible Nutzdaten nicht ungefragt loggen/exportieren;
- Vault-Schlüssel bleiben im Vault;
- physische Devices explizit und read-only;
- Schreib-/Recovery-Funktionen erst nach eigener Threat-/Safety-Bewertung.

## Business-Entwicklung

Das Produkt darf zunächst internes SASD-Werkzeug sein. Produktreife entsteht durch echte interne Nutzung. Erst danach sollte entschieden werden, ob Community-/Plugin-Ökosystem, kommerzielle Editionen oder Beratungs-/Schulungspakete sinnvoll sind.

## Langfristiges Zielbild

Binary Insight entwickelt sich kontrolliert von der **Secure Binary Analysis Foundation** über Executable-, Crypto/Vault- und Disk/Filesystem-Insight zu einer Automatisierungsplattform. Controlled Editing und Recovery bleiben optionale spätere Risikoklassen.

## Erfolgsmaßstab

Nicht die Anzahl implementierter Features entscheidet, sondern ob SASD bei realen Binärproblemen regelmäßig Binary Insight öffnet, Analysen reproduzierbar wiederverwenden kann und daraus Dokumentation, Tests oder Software ableitet.
