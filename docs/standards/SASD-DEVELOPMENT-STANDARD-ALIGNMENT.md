# SASD Development Standard — Adoption and Gap Assessment

**Assessment date:** 2026-10-08  
**Status:** Initial, evidence-based assessment; **not a compliance certificate**  
**Product:** SASD Secure Binary Analysis Tool / Binary Insight  
**Standard source:** [SASD Development Standard](https://github.com/Robin-Goerlach/SASD-Development-Standard)

## Authority and version

The SASD Development Standard repository describes its current state as a **Version 1.0 Specification Candidate**, with Approved German normative baselines (Foundation/Governance 0.8.0 and Core/C#/.NET/Desktop/processes 0.9.0), but no published stable 1.0.0 release and practical pilot validation still pending. This project must not claim formal Version 1.0 conformity.

The **German normative text is authoritative** in the Standard. This English project guide is an informative mapping and does not supersede the Standard's requirements, applicability rules, profiles, exceptions or approval process.

Standard entry points:
- [Quick Start](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/QUICKSTART.md)
- [Project Classification (SASD-PROC-002)](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/30-processes/PROJECT-CLASSIFICATION.md)
- [New Project (SASD-PROC-001)](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/30-processes/NEW-PROJECT.md)
- [Core Standard](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/10-core-standard/README.md)
- [Quality Levels](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/10-core-standard/QUALITY-LEVELS.md)
- [Solo Developer Guide](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/10-core-standard/SOLO-DEVELOPER-GUIDE.md)
- [Normative Language](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/40-governance/NORMATIVE-LANGUAGE.md)
- [Exceptions](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/docs/40-governance/EXCEPTIONS.md)

## Initial classification — proposed, not approved

| Dimension | Proposed assessment | Evidence / next action |
|---|---|---|
| Product lifetime | Long-term maintained product | Strategy and ROADMAP; owner to confirm |
| Structural size | **Medium (provisional)** | Multiple planned components and integrations; re-evaluate before Phase 0 gate and later major scope changes |
| Quality level | **Recommended (provisional)** | Long-lived public software; evaluate Production where untrusted input, sensitive data, device access or distribution risks justify stronger controls |
| Profiles | **Core applies**; Desktop expected; C#/.NET **conditional** | ADR-001/002 have not yet chosen the implementation stack |
| Risk | Elevated untrusted-input/parser risk; future Vault/device/write boundaries | SECURITY.md, architecture; formal classification needed |
| Responsible role | Repository owner / maintainer (to confirm) | Record accountable approval and a temporally separated solo self-review |
| Next reassessment | Before Phase 0 implementation readiness and before material scope/risk change | Document review date and outcome |

**This is a proposal only.** Under SASD-PROC-002, size, quality level, risk and profiles must be assessed separately, reviewed and approved. Unknown facts must not be treated as low risk.

## Standard alignment matrix

| Standard area | Existing project evidence | Gap / next action |
|---|---|---|
| Project brief and goals | README, strategy, requirements | Create concise project brief with accountable owner and explicit assumptions |
| Classification | Provisional table above | Complete approved classification using Standard template; determine conditional profiles and quality level |
| Requirements and acceptance | Bilingual Lastenheft/Pflichtenheft | Build requirement → implementation → test traceability; record unresolved conflicts |
| Architecture and ADRs | DE/EN architecture; ADR index/template | Accept foundational ADRs; verify system context, external dependencies and risk boundaries |
| Repository/Git | README, AGENTS, CONTRIBUTING, PR workflow | Verify branch protection/CI policy against Standard; record deviations |
| Quality/testing | ROADMAP tests and fixtures planned | Implement build/test/static checks, deterministic fixtures and executed evidence |
| Security/privacy | SECURITY.md, read-only architecture | Complete threat/risk assessment and controls before untrusted/sensitive runtime processing |
| AI-assisted development | AGENTS.md | Map human approval, agent permissions, verification and evidence to applicable AI requirements |
| Releases/maintenance | ROADMAP, CHANGELOG, PROJECT-STATUS | Establish release/rollback/support/maintenance procedure before distribution |
| New-project readiness | Phase-0 exit described | Create a dated, reviewed initialization/readiness record; distinguish blockers from accepted residual risk |

The presence of documents is **not** proof that normative requirements are satisfied. Actual conformity must be evaluated requirement by requirement, including applicable quality levels, profiles, evidence, exclusions and approved exceptions.

## Required Phase-0 adoption tasks

- [ ] Produce a concise [project brief](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/templates/documents/PROJECT-BRIEF-TEMPLATE.md).
- [ ] Complete and approve [project classification](https://github.com/Robin-Goerlach/SASD-Development-Standard/blob/main/templates/documents/PROJECT-CLASSIFICATION-TEMPLATE.md).
- [ ] Confirm Core + applicable technology profiles **after** ADR-001/002.
- [ ] Record the relevant Standard baseline commit/version and assessment date.
- [ ] Identify applicable normative requirements and map each to evidence, gap, Not Applicable reason or approved exception.
- [ ] Complete security/risk assessment appropriate to untrusted binary input.
- [ ] Reconcile requirements and create traceability to tests.
- [ ] Document build/test/toolchain and capture actual CI evidence once implementation begins.
- [ ] Document release, maintenance, support and data-storage/backup expectations proportionally.
- [ ] Perform a temporally separated self-review for the solo maintainer.
- [ ] Complete a documented Phase-0 **Readiness Gate** before regular implementation, with named blockers and the next verifiable milestone.

## Process rules

**Progressive disclosure:** use the Standard's Quick Start and applicable Core/process/profile documents; do not copy the Standard's complete documentation tree into this product repository. Complexity available, not imposed.

**Standard versus tooling:** Standard requirements and evidence are authoritative; its Python validators, templates, prompts and CI are supporting mechanisms, not mandatory runtime dependencies unless a specific normative requirement says otherwise. Equivalent verifiable project-appropriate mechanisms may be used where permitted.

**Normative language:** project-level notes must not silently invent new SASD MUST requirements. Where a binding Standard requirement is cited, preserve its ID, triggering condition, applicable quality level and German authoritative wording.

**Deviation handling:** record justified Not Applicable decisions, recommendations not followed and formal exceptions separately. A draft classification or unchecked task does not count as approval.

**Evidence discipline:** use exact commits, test results and review records; do not equate planned CI or an existing Markdown file with executed validation.

## Related project documents

- [Product README](../../README.md)
- [Roadmap](../../ROADMAP.md)
- [Project status](../../PROJECT-STATUS.md)
- [Agent operating contract](../../AGENTS.md)
- [Security](../../SECURITY.md)
- [Architecture](../en/architecture/ARCHITECTURE.md)
- [German architecture](../de/architecture/ARCHITEKTUR.md)
