//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "PhysicsList.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"

#include "G4PhysicsListHelper.hh"

#include "G4BosonConstructor.hh"
#include "G4LeptonConstructor.hh"
#include "G4MesonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"
#include "G4ShortLivedConstructor.hh"

#include "G4ProcessManager.hh"

#include "G4Cerenkov.hh"
#include "G4Scintillation.hh"
#include "G4OpAbsorption.hh"
#include "G4OpRayleigh.hh"
#include "G4OpMieHG.hh"
#include "G4OpBoundaryProcess.hh"

#include "G4LossTableManager.hh"
#include "G4EmSaturation.hh"

#include "G4HadronElasticProcess.hh"
#include "G4NeutronHPElastic.hh"
#include "G4NeutronHPElasticData.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsList::PhysicsList() : G4VUserPhysicsList() {
}

void PhysicsList::ConstructParticle() {

    // all particles used in the simulation must be constructed here
    G4BosonConstructor bConstructor;
    bConstructor.ConstructParticle();

    G4LeptonConstructor lConstructor;
    lConstructor.ConstructParticle();

    G4IonConstructor iConstructor;
    iConstructor.ConstructParticle();

    G4BaryonConstructor rConstructor;
    rConstructor.ConstructParticle();

    G4MesonConstructor mConstructor;
    mConstructor.ConstructParticle();

    G4Geantino::GeantinoDefinition();
    G4Gamma::GammaDefinition();
    G4OpticalPhoton::OpticalPhotonDefinition();

    G4Positron::PositronDefinition();
    G4Electron::ElectronDefinition();

    G4MuonMinus::MuonMinusDefinition();

   
    G4Proton::ProtonDefinition();
    G4AntiProton::AntiProtonDefinition();

    G4Deuteron::DeuteronDefinition();
    G4Triton::TritonDefinition();
    G4He3::He3Definition();
    G4Alpha::AlphaDefinition();
    G4GenericIon::GenericIonDefinition();
}

void PhysicsList::ConstructProcess() {
  AddTransportation();
  ConstructEM();
  ConstructOp();
}

#include "G4Threading.hh"

// construct optical physics processes
void PhysicsList::ConstructOp() {

  // create Cerenkov process

  G4Cerenkov *cerenkovProcess = new G4Cerenkov("Cerenkov");
  cerenkovProcess->SetMaxNumPhotonsPerStep(20);
  cerenkovProcess->SetMaxBetaChangePerStep(10.0);
  cerenkovProcess->SetTrackSecondariesFirst(true);

  // create boundary process
  G4OpBoundaryProcess *boundaryProcess = new G4OpBoundaryProcess();

  // create scinitillation
  // G4Scintillation *scintProcess = new G4Scintillation("Scintillation");
  // scintProcess->SetScintillationYieldFactor(1.0);
  // scintProcess->SetTrackSecondariesFirst(true);

  // create optical absorption and Rayleigh scattering
  G4OpAbsorption *absProcess = new G4OpAbsorption();
  G4OpRayleigh *rayProcess = new G4OpRayleigh();
  G4OpMieHG* mieHGScatteringProcess = new G4OpMieHG();  

  
    // iterate over particles and apply physics
  GetParticleIterator()->reset();
  while( (*GetParticleIterator())() ) {
    G4ParticleDefinition* particle = GetParticleIterator()->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();

    // add Cerenkov to all applicable particles
    if ( (cerenkovProcess->IsApplicable(*particle) || particleName == "GenericIon") ) {
      // if (particleName == "e-" || particleName == "e+") {
      // 	G4cout << " break " << G4endl;
      // 	break;
      // }
      pmanager->AddProcess(cerenkovProcess);
      pmanager->SetProcessOrdering(cerenkovProcess, idxPostStep);
    }
    // add optical processes to opticalphotons
    if (particleName == "opticalphoton") {
      pmanager->AddDiscreteProcess(boundaryProcess);
      pmanager->AddDiscreteProcess(absProcess);
      pmanager->AddDiscreteProcess(mieHGScatteringProcess);      
      pmanager->AddDiscreteProcess(rayProcess);
    }
  }
}

#include "G4ComptonScattering.hh"
#include "G4GammaConversion.hh"
#include "G4PhotoElectricEffect.hh"

#include "G4eMultipleScattering.hh"
#include "G4MuMultipleScattering.hh"
#include "G4hMultipleScattering.hh"

#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"

#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"

#include "G4hIonisation.hh"

void PhysicsList::ConstructEM() {

  // create EM
  GetParticleIterator()->reset();
  while( (*GetParticleIterator())() ){
    G4ParticleDefinition* particle = GetParticleIterator()->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();

    if (particleName == "gamma") {
      // gamma
      // Construct processes for gamma
#ifdef ALL_PHYSICS
      pmanager->AddDiscreteProcess(new G4GammaConversion());
      pmanager->AddDiscreteProcess(new G4ComptonScattering());
      pmanager->AddDiscreteProcess(new G4PhotoElectricEffect());
#endif

    } else if (particleName == "e-") {
      //electron
      // Construct processes for electron
      // pmanager->AddProcess(new G4eBremsstrahlung(),   -1, 3, 3);
      pmanager->AddProcess(new G4eMultipleScattering(), -1, 1, 1);
      pmanager->AddProcess(new G4eIonisation(),       -1, 2, 2);

    } else if (particleName == "e+") {
      // Construct processes for positron
      pmanager->AddProcess(new G4eMultipleScattering(),-1, 1, 1);
      pmanager->AddProcess(new G4eIonisation(),       -1, 2, 2);
      // pmanager->AddProcess(new G4eBremsstrahlung(),   -1, -1, 3);
      pmanager->AddProcess(new G4eplusAnnihilation(),   0, -1, 4);

    } else if (particleName == "proton" || particleName == "anti_proton") {
      // Construct processes for proton/anti-proton
#ifdef ALL_PHYSICS
      pmanager->AddProcess(new G4hMultipleScattering(),-1, 1, 1);
      pmanager->AddProcess(new G4hIonisation(),       -1, 2, 2);
#endif
    } else if ((particleName == "alpha") &&
	       particle->GetPDGCharge() != 0.0) {
#ifdef ALL_PHYSICS
	pmanager->AddProcess(new G4ionIonisation(), -1, 2, 2);
	pmanager->AddProcess(new G4hMultipleScattering(),-1, 1, 1);
#endif
      } else if( particleName == "mu+" ||
		 particleName == "mu-"    ) {
      //muon
      // Construct processes for muon
      pmanager->AddProcess(new G4MuMultipleScattering(),-1, 1, 1);
      pmanager->AddProcess(new G4MuIonisation(),      -1, 2, 2);
      //      pmanager->AddProcess(new G4MuBremsstrahlung(),  -1, 3, 3);
      pmanager->AddProcess(new G4MuPairProduction(),  -1, 4, 4);
    }
    else if ((particleName == "GenericIon") &&
	     particle->GetPDGCharge() != 0.0)
      {
	pmanager->AddProcess(new G4ionIonisation(), -1, 2, 2);
      }
    else {
      if ((particle->GetPDGCharge() != 0.0) &&
	  (particle->GetParticleName() != "chargedgeantino") &&
	  !particle->IsShortLived()) {
	// all others charged particles except geantino
#ifdef ALL_PHYSICS
	pmanager->AddProcess(new G4hMultipleScattering(),-1,1,1);
	pmanager->AddProcess(new G4hIonisation(),       -1,2,2);
#endif
      }
    }
  }
}

void PhysicsList::SetCuts() {

  SetCutsWithDefault();
}
