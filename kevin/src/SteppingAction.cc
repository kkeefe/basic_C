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

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "SteppingAction.hh"
#include "EventAction.hh"
#include "UserEventInformation.hh"
#include "UserTrackInformation.hh"

#include "G4Step.hh"
#include "G4Track.hh"
#include "G4OpticalPhoton.hh"
#include "G4OpBoundaryProcess.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

#include "G4SystemOfUnits.hh"
#include <fstream>
#include <iostream>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

SteppingAction::SteppingAction()
  : G4UserSteppingAction(){
  fCerenkovCounter      = 0;
  fEDeposit             = 0;
  fphotoncounter        = 0;
  fEventNumber = -1;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction() { ; }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int count = 0;

void SteppingAction::UserSteppingAction(const G4Step *step)
{

  //use the track to determine which particle is measured this step.
  G4Track* track = step->GetTrack();
  G4String ParticleName = track->GetDynamicParticle()->
                                 GetParticleDefinition()->GetParticleName();

  //what to do if the particle is an optical photon. 
 if (ParticleName == "opticalphoton") {
    fphotoncounter++;
    // G4cout << fphotoncounter << " this is the current photon step count. " << G4endl;
    if (track->GetStep()->GetPostStepPoint()->GetStepStatus()!=fGeomBoundary) {
      return;
    }  
  }

  //define what to do when encountering secondary particles created
  const std::vector<const G4Track*>* secondaries =
                                            step->GetSecondaryInCurrentStep();


  //this counts the cerenkovs produced for each step
  if (secondaries->size()>0) {
     for(unsigned int i=0; i<secondaries->size(); ++i) {
        if (secondaries->at(i)->GetParentID()>0) {
           if(secondaries->at(i)->GetDynamicParticle()->GetParticleDefinition()
               == G4OpticalPhoton::OpticalPhotonDefinition()){
              if (secondaries->at(i)->GetCreatorProcess()->GetProcessName()
               == "Cerenkov")fCerenkovCounter++;
           }
        }
     }
  }
  
}

