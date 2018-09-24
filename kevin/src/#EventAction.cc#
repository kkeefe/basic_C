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
// $Id: B5EventAction.cc 87359 2014-12-01 16:04:27Z gcosmo $
//
/// \file B5EventAction.cc
/// \brief Implementation of the B5EventAction class

#include "RunAction.hh"
#include "EventAction.hh"
#include "Analysis.hh"
#include "SensitiveDetector.hh"
#include "UserEventInformation.hh"
#include "UserTrackInformation.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4EventManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4VHitsCollection.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4TrackStatus.hh"
// for each event,
// photon energy, arrival time, and Sensitive Detector number for each photon
// for each run, total number of generated photons, total number of detected photons

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class AnalysisManager;
class RunAction;

EventAction::EventAction(RunAction* run, AnalysisManager* analysis)
  : G4UserEventAction(),
    fPDHCID(-1), fRunAct(run),fAnalysisManager(analysis),
    fEnergyAbs(0.), fEnergyGap(0.),
    fTrackLAbs(0.), fTrackLGap(0.),
    fPrintModulo(0)                             
{fPrintModulo = 100;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::~EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event* evt) {
  evtNumber = evt->GetEventID();
  // G4String ParticleName = evt->GetDynamicParticle()->
  //                                GetParticleDefinition()->GetParticleName();

  G4cout << "<<< Event  " << evtNumber << " has started." << G4endl;
  //use the track to determine which particle is measured this event.
  if(fPDHCID == -1){
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    fPDHCID = sdManager->GetCollectionID("photonsDetected");
  }
  // initialisation per event
  fEnergyAbs = fEnergyGap = 0.;
  fTrackLAbs = fTrackLGap = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* evt)
{

  evtNumber = evt->GetEventID();
  G4cout << "<<< Event  " << evtNumber << " has ended." << G4endl;

  //SensitiveDetectorHitsCollection = G4THisCollection
  G4HCofThisEvent* HCE = evt->GetHCofThisEvent();

  // //get the hits collectoin
  SensitiveDetectorHitsCollection* HitsCollected = static_cast<SensitiveDetectorHitsCollection*>(HCE->GetHC(fPDHCID));
  
  //here is the place to fill the ntuples
  G4cout << HCE << " G4 HCE of this event " << std::endl;
  if(HCE){
    HitsCollected = (SensitiveDetectorHitsCollection*)(HCE->GetHC(fPDHCID));

    if(HitsCollected){
      G4int n_hits = HitsCollected->entries();
      if(n_hits != 0){
	G4cout << n_hits << " this is the number of hits in this event " << std::endl;
	for(G4int i = 0; i < n_hits; i++){
	  SensitiveDetectorHit* aHit = (*HitsCollected)[i];
	  //CURRENTLY IGNORING PRINT
	  // aHit -> Print();
	  //fill nt
	  fAnalysisManager->FillNtuple(fEnergyAbs, fEnergyGap, fTrackLAbs, fTrackLGap, aHit->Get_X(), aHit->Get_Y());
	}
      }else if (n_hits == 0){
	G4cout << " no hatts " << G4endl;
      }
      
    }
  }

  //accumulates statistic
  fRunAct->FillPerEvent(fEnergyAbs, fEnergyGap, fTrackLAbs, fTrackLGap, HitsCollected->entries(), 5);
  
  //fill histograms
  fAnalysisManager->FillHisto(0, fEnergyAbs);

 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
