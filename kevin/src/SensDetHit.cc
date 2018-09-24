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

#include "SensDetHit.hh"

#include "G4VVisManager.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4AttDefStore.hh"
#include "G4AttDef.hh"
#include "G4AttValue.hh"
#include "G4UIcommand.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4ThreadLocal G4Allocator<SensitiveDetectorHit>* SensitiveDetectorHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SensitiveDetectorHit::SensitiveDetectorHit()
: G4VHit(), 
  fSensDetID(-1), fEnergy(0.), fPos(0.), fTime(0.),
  fLength(0.), fReflections(0), fTotalInternalReflections(0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SensitiveDetectorHit::SensitiveDetectorHit(G4int cellID)
: G4VHit(), 
  fSensDetID(cellID), fEnergy(0.), fPos(0.), fTime(0.),
  fLength(0.), fReflections(0), fTotalInternalReflections(0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SensitiveDetectorHit::~SensitiveDetectorHit()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SensitiveDetectorHit::SensitiveDetectorHit(const SensitiveDetectorHit &right)
: G4VHit(),
  fSensDetID(right.fSensDetID),
  fEnergy(right.fEnergy),
  fPos(right.fPos),
  fTime(right.fTime),
  fLength(right.fLength),
  fReflections(right.fReflections),
  fTotalInternalReflections(right.fTotalInternalReflections)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

const SensitiveDetectorHit& SensitiveDetectorHit::operator=(const SensitiveDetectorHit
                                                          &right)
{
  fSensDetID = right.fSensDetID;
  fEnergy = right.fEnergy;
  fPos = right.fPos;
  fTime = right.fTime;
  fLength = right.fLength;
  fReflections = right.fReflections;
  fTotalInternalReflections = right.fTotalInternalReflections;
  return *this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int SensitiveDetectorHit::operator==(const SensitiveDetectorHit &right) const
{
  return (fSensDetID==right.fSensDetID);
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SensitiveDetectorHit::Print()
{
  G4cout << "  Sensitive Detector[" << fSensDetID << "] " << fEnergy << " (eV) at time " << fTime << G4endl;
  G4cout << "  Sensitive Detector[" << fSensDetID << "] " << fPos << " (Pos) at time " << fTime << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
