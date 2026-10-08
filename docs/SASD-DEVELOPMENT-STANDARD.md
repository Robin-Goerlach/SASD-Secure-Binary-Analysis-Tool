# SASD Development Standard — Adoption and Gap Assessment

**Status:** provisional adoption plan; not a conformity certificate  
**Assessed:** 2026-10-08  
**Upstream:** [SASD Development Standard](https://github.com/Robin-Goerlach/SASD-Development-Standard)

## Authority and scope

The upstream SASD Development Standard is currently a **Version 1.0 Specification Candidate**, not a released stable 1.0. Its approved normative baseline is **German**. Its Quick Start, templates, checklists, prompts and tooling are supporting materials, not independently binding requirements. This repository's English-default presentation does not override upstream German normative authority.

Adoption means identifying applicable upstream requirements and recording evidence; it does **not** mean copying all upstream files, declaring conformity based on documentation presence, or making upstream Python validators a runtime dependency.

Upstream entry points:
- [Quick Start](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/QUICKSTART.md)
- [Project classification](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/30-processes/PROJECT-CLASSIFICATION.md)
- [New project process](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/30-processes/NEW-PROJECT.md)
- [Core Standard](https://github.com/Robin-Goerlach/SASD-Development-Standard/tree/main/docs/10-core-standard)
- [Normative language](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/40-governance/NORMATIVE-LANGUAGE.md)
- [Content architecture](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/00-foundation/CONTENT-ARCHITECTURE.md)
- [Solo Developer Guide](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/10-core-standard/SOLO-DEVELOPER-GUIDE.md)

## Provisional project classification

| Dimension | Current assessment | Evidence / unresolved work |
|---|---|---|
| Lifecycle | Long-lived open-source desktop analysis product | Requirements, architecture and roadmap |
| Size | **Provisional Medium** (modular core, GUI, later CLI/integrations) | Confirm through upstream classification criteria |
| Quality level | **Provisional Recommended** for Phase 0; target **Production** before distributing a security-sensitive V1 | Must be formally classified and approved |
| Profiles | Core; Desktop **candidate**; .NET **conditional** on ADR-001 | Only apply approved, relevant profiles |
| Risks | Untrusted binary inputs, parser bounds, large-file resource use, sensitive local data, later plugins/devices/Vault | Threat analysis and release evidence required |
| Responsible role | Repository owner / SASD | Formal project classification approval outstanding |

These are *project-specific proposals*, not classifications already approved under the upstream process. Team size alone must not determine quality level.

## Evidence and gaps

| SASD adoption area | Present evidence | Remaining gap | Priority |
|---|---|---|---|
| Project brief and purpose | README, product strategy, Lastenheft, [project brief](PROJECT-BRIEF.md) | Review and approve existing brief; confirm owner, assumptions and success criteria | Phase 0 |
| Classification | This provisional table | Verify upstream criteria, formally approve size/quality/profiles/risks | Phase 0 blocker |
| Requirements and acceptance | DE/EN requirements and specification | Traceability and review of requirement IDs and acceptance evidence | Phase 0/V1 |
| Architecture and decisions | DE/EN architecture, ADR index/template | Accept ADR-001–010; record tradeoffs and review | Phase 0 blocker |
| Repository/process | AGENTS, CONTRIBUTING, ROADMAP | Establish reproducible toolchain and PR checks | Phase 0 |
| Build/test/CI | Planned in ROADMAP | Real commands, CI and exact-commit test evidence do not yet exist | Phase 0 blocker |
| Security/privacy | SECURITY and architecture baseline | Threat model, dependency checks and concrete security tests | Phase 0/V1 |
| Quality gates | Definition of Done in AGENTS/architecture | Evidence record and repeatable release gate | Phase 0/V1 |
| Release/maintenance | CHANGELOG, PROJECT-STATUS | Versioning, release record, support policy and archival procedure before release | Before V1 |
| Standard version tracking | This document | Pin reviewed upstream commit/version and reassess on material changes | Phase 0 |
| Standard tooling | Not adopted | Evaluate optional validators/checklists after toolchain decisions; equivalent evidence allowed | Optional |

**Current conclusion:** documentation alignment is **partial**, and formal SASD Development Standard conformity has **not** been demonstrated. No implementation/build/CI evidence is available yet.

## Additional process controls reconciled from parallel documentation branch

The parallel standard-alignment review identified further items that are retained here rather than replacing the already merged project brief and assessment:

- **Version and scope:** record the reviewed upstream Standard commit, the applicable approved German normative sections, and their individual statuses; a specification candidate is not a stable 1.0 release.
- **Quality classification:** review size, quality level, risks and applicable Core/Desktop/technology profiles independently. Record accountable approval, a next review date and a temporally separated self-review when maintained solo.
- **AI-assisted development:** map AGENTS.md permissions, human review, verification and evidence to applicable normative AI-related controls rather than assuming AGENTS.md alone proves compliance.
- **Readiness gate:** capture a dated Phase-0 readiness decision with unresolved blockers, accepted residual risks, responsible owner and next verifiable milestone.
- **Release readiness:** document release/rollback, maintenance, support and data-storage/backup expectations proportionately before distribution.
- **Traceability:** map each applicable normative requirement to evidence, an outstanding task, a justified non-applicability decision or an approved exception. Keep exceptions distinct from recommendations not followed.
- **Security:** explicitly assess untrusted parser input, local privacy and any later physical-device, plugin or Vault boundaries; unknown risk is not automatically low risk.

Upstream supporting references include [Quality Levels](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/10-core-standard/QUALITY-LEVELS.md) and [Exceptions](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/40-governance/EXCEPTIONS.md). Supporting templates, including project classification and project brief templates, may help collect evidence but do not replace approval.

## Minimal adoption sequence

1. Complete a concise [Project Brief](PROJECT-BRIEF.md).
2. Classify project size, quality level, risks and applicable profiles using the upstream normative process; record approval.
3. Record the exact upstream baseline commit reviewed (avoid treating moving `main` as a frozen normative version).
4. Complete foundational ADRs and establish a real build/test/CI baseline.
5. Map applicable upstream requirements to repository evidence; mark fulfilled, pending, not applicable with reason, or exception requiring approval.
6. Capture actual exact-commit test/security/performance evidence before changing the project status or claiming compliance.
7. Reassess classification when adding plugins, physical-device access, editing, recovery, or distribution changes.

## Language and precedence

English is the default *presentation language* in this repository. For interpretation of upstream normative SASD requirements, the **German authoritative original** governs. Local bilingual product requirements must remain consistent, and differences should be resolved explicitly rather than silently overwritten.

An upstream SASD requirement is not automatically an implementation feature requirement: apply only the appropriate quality level and profile. Templates and checklists can assist without introducing new normative obligations.

## Change control

Track deviations with rationale, impact, responsible decision and review date. A `MUSS` deviation follows upstream exception governance; a `SOLLTE` deviation requires rationale where relevant. Do not mark a requirement `Not Applicable` without its triggering-condition justification in a formal assessment.

The adoption plan should remain proportionate: **complexity available, not imposed**.
