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
// $Id: NtcSimplePhotoDetectorSD.cc 76474 2013-11-11 10:36:34Z gcosmo $
//
/// \file NtcSimplePhotoDetectorSD.cc
/// \brief Implementation of the NtcSimplePhotoDetectorSD class

#include "SensitiveDetector.hh"
#include "UserTrackInformation.hh"

#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"

#include <sstream>
#include <string>
#include <fstream>

using namespace std;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


SensitiveDetector::SensitiveDetector(const G4String& name)
    :G4VSensitiveDetector(name),
     fHitsCollection(nullptr), fHCID(-1)
{
    collectionName.insert("photonsDetected");
}

SensitiveDetector::~SensitiveDetector()
{}

void SensitiveDetector::Initialize(__attribute__((unused)) G4HCofThisEvent* hitsCollectionOfThisEvent)
{
    // create a new hits collection and store its ID
    fHitsCollection = new SensitiveDetectorHitsCollection(SensitiveDetectorName, collectionName[0]);
    if (fHCID<0) { // not initialized
      //this is the initialization of the Sensitive detector
      fHCID = G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection);
    }

    // add the hit collection to this event
    hitsCollectionOfThisEvent->AddHitsCollection(fHCID, fHitsCollection);

}

G4bool SensitiveDetector::ProcessHits(G4Step* step, __attribute__((unused)) G4TouchableHistory*)
{

    // we only want to process opticalphotons
    if (step->GetTrack()->GetDefinition() != G4OpticalPhoton::OpticalPhotonDefinition())
        return false;

    // get ID of Sensitive Detector that is hit
    const G4VTouchable* touchable = step->GetPreStepPoint()->GetTouchable();
    G4int SensDetID = touchable->GetVolume()->GetCopyNo();

    // get the track
    G4Track* track = step->GetTrack();

    // make sure we only save opticalphotons
    if ((track->GetDynamicParticle()->GetParticleDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()) &&
        (step->GetTotalEnergyDeposit() != 0)) {
            
        // create hit
        SensitiveDetectorHit* hit = new SensitiveDetectorHit(SensDetID);
            
        // hit position
        hit->SetPos(track->GetPosition());

        // photon energy/wavelength
        hit->SetEnergy(step->GetTotalEnergyDeposit());

        // hit time in global time system
        hit->SetTime(track->GetLocalTime());

        // insert total track length
        hit->SetTrackLength(track->GetTrackLength());

        // get track information storage
        UserTrackInformation *trackInformation
            = (UserTrackInformation*)track->GetUserInformation();

        // total number of reflections
        hit->SetReflectionCount(trackInformation->GetReflectionCount());

        // total number of total internal reflections
        hit->SetTotalInternalReflectionCount(trackInformation
                                             ->GetTotalInternalReflectionCount());

        // insert the hit into the hits collection
        fHitsCollection->insert(hit);

    }
    
    return true;
}

void SensitiveDetector::EndOfEvent(__attribute__((unused)) G4HCofThisEvent* eventHC)
{
}
