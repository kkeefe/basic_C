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

#ifndef __SIPM_SENSITIVE_DETECTOR__
#define __SIPM_SENSITIVE_DETECTOR__

#include "G4VSensitiveDetector.hh"
#include "SensDetHit.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4OpticalPhoton.hh"
#include "G4Step.hh"    
#include "G4TouchableHistory.hh"
#include "G4Track.hh"

class G4HCofThisEvent;
class G4TouchableHistory;
class G4Step;

class SensitiveDetector : public G4VSensitiveDetector {

public:

  // Constructor
  SensitiveDetector(const G4String& name);

  // Destructor
  virtual ~SensitiveDetector();
  
  // Methods
  virtual void Initialize(G4HCofThisEvent* hitsCollectionOfThisEvent);
  virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
  virtual void EndOfEvent(G4HCofThisEvent* hitsCollectionOfThisEvent);
  
private:

    SensitiveDetectorHitsCollection* fHitsCollection;
    G4int fHCID;
  
};


#endif
