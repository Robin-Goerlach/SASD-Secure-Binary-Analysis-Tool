# ADR-001: Core language and platform / Core-Sprache und Plattform

- **Status:** Accepted
- **Date:** 2026-10-08
- **Owners:** SASD
- **Supersedes:** —
- **Superseded by:** —

## English

### Context

Phase 0 needs a reproducible build and test baseline. The core must remain independent from UI frameworks, operating-system file APIs, network services and concrete external engines. The repository should also permit parallel work in other languages without making every language a mandatory dependency of the core.

### Decision drivers

- large-file and low-level byte-analysis suitability;
- portable, deterministic and locally reproducible builds;
- strong tooling for warnings, tests and sanitizers;
- clear separation between the core and future hosts/bindings.

### Considered options

1. C++ core with CMake orchestration.
2. Rust core with a C-compatible boundary.
3. A language-neutral repository with no initial implementation toolchain.

### Decision

The initial analysis core is implemented in **C++20** and built with **CMake 3.25 or newer**. The repository uses a static `sasd_core` target as the first library boundary and CTest for tests. Linux and Windows are initial CI targets; platform-specific APIs remain outside the Domain/Core boundary.

This decision does not require other project components to use C++. Future Python, Rust, C#, or other-language components may be added as independent modules. Integration must use an explicit stable boundary: a versioned C ABI, a process/CLI protocol, or a reviewed native binding. Directly including C++ headers from another language is not a repository-wide contract.

The GUI technology, ByteProvider API, persistence format, external engines and package manager remain separate ADR decisions.

### Consequences

**Positive**

- C++ supports the planned low-level, bounded and large-file-oriented core.
- CMake provides one build entry point across supported hosts and allows separate language subprojects.
- The first CI path is small and dependency-free.
- Other languages can evolve in parallel without being forced into the C++ build.

**Negative / trade-offs**

- C++ toolchains and ABI details require discipline at public boundaries.
- CMake is an additional build language and does not replace language-specific tooling.
- A stable cross-language ABI is deliberately deferred until an actual consumer exists.

**Risks and mitigations**

- Accidental UI/OS coupling: keep core headers under `src/cpp/core` and enforce dependency review.
- ABI drift: expose C ABI or protocol contracts only through a later ADR and version them.
- Toolchain differences: compile with warnings enabled on Linux and Windows in CI.

### Validation

The repository must configure, build and run its CTest suite through `CMakePresets.json`. CI verifies Linux and Windows. The first target is intentionally a minimal smoke contract; the ByteProvider vertical slice will follow ADR-003.

### References

- [Architecture](../en/architecture/ARCHITECTURE.md)
- [Roadmap](../../ROADMAP.md)
- [Contributing](../../CONTRIBUTING.md)

---

## Deutsch

### Kontext

Für Phase 0 werden ein reproduzierbarer Build und eine Testbasis benötigt. Der Core muss unabhängig von UI-Frameworks, Betriebssystem-Datei-APIs, Netzwerkdiensten und konkreten Analyse-Engines bleiben. Gleichzeitig soll parallele Entwicklung in anderen Sprachen möglich sein, ohne jede Sprache zu einer Pflichtabhängigkeit des Cores zu machen.

### Entscheidung

Der initiale Analyse-Core wird in **C++20** implementiert und mit **CMake ab Version 3.20** gebaut. Das Repository verwendet zunächst das statische Ziel `sasd_core` als Bibliotheksgrenze und CTest für Tests. Linux und Windows sind die ersten CI-Ziele; plattformspezifische APIs bleiben außerhalb der Domain/Core-Grenze.

Andere Komponenten müssen nicht C++ verwenden. Zukünftige Python-, Rust-, C#- oder andere Sprachmodule dürfen unabhängig ergänzt werden. Die Integration erfolgt über eine explizite stabile Grenze: versionierte C-ABI, Prozess-/CLI-Protokoll oder ein geprüftes Native-Binding. Das direkte Einbinden von C++-Headern aus einer anderen Sprache ist kein Repository-Vertrag.

GUI-Technologie, ByteProvider-API, Persistenzformat, externe Engines und Paketmanager bleiben eigene ADR-Entscheidungen.

### Konsequenzen und Validierung

Die positiven und negativen Folgen entsprechen dem englischen Abschnitt. Der Build muss über `CMakePresets.json` konfigurieren, bauen und die CTest-Suite ausführen; CI prüft Linux und Windows. Der erste Test ist bewusst ein minimaler Smoke-Test. Der ByteProvider-Vertical-Slice folgt nach ADR-003.

### Referenzen

- [Architektur](../de/architecture/ARCHITEKTUR.md)
- [Roadmap](../../ROADMAP.md)
- [Contributing](../../CONTRIBUTING.md)
