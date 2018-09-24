#ifndef __PHYSICS_LIST__
#define __PHYSICS_LIST__

#include "G4VUserPhysicsList.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4BosonConstructor.hh"
#include "G4LeptonConstructor.hh"
#include "G4MesonConstructor.hh"
#include "G4Material.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"
#include "G4ProcessManager.hh"
#include "G4EmSaturation.hh"
#include "G4LossTableManager.hh"
#include "G4ComptonScattering.hh"
#include "G4PhotoElectricEffect.hh"
#include "G4GammaConversion.hh"
#include "G4eMultipleScattering.hh"
#include "G4eIonisation.hh"
#include "G4ionIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4hMultipleScattering.hh"
#include "G4hIonisation.hh"
#include "G4OpAbsorption.hh"
#include "G4OpRayleigh.hh"
#include "G4Scintillation.hh"
#include "G4VModularPhysicsList.hh"
#include "G4Cerenkov.hh"
#include "G4ForwardXrayTR.hh"

class PhysicsList : public G4VUserPhysicsList {

public:
    PhysicsList();

    // necessary methods
    virtual void ConstructParticle();
    virtual void ConstructProcess();
    virtual void SetCuts();

    // construct physics processes
    void ConstructOp();
    void ConstructEM();
};


#endif
