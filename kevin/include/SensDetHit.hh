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

#ifndef __SensDet_HIT__
#define __SensDet_HIT__

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

// class G4AttDef;
// class G4AttValue;

class SensitiveDetectorHit : public G4VHit
{
public:
  SensitiveDetectorHit();
  SensitiveDetectorHit(G4int SensDetID);
  SensitiveDetectorHit(const SensitiveDetectorHit& right);
  virtual ~SensitiveDetectorHit();

  // operators for assignment and equality
  const SensitiveDetectorHit& operator=(const SensitiveDetectorHit &right);
  int operator==(const SensitiveDetectorHit &right) const;

  // allocate/deallocate using G4Allocator
  inline void *operator new(size_t);
  inline void operator delete(void *aHit);

  virtual void Print();

  // ID of the SensitiveDetector this hit was registered in
  void SetSensDetID(G4int z) { fSensDetID = z; }
  G4int GetSensDetID() const { return fSensDetID; }

  // photon energy 
  void SetEnergy(G4double de) { fEnergy = de; }
  G4double GetEnergy() const { return fEnergy; }

  // location in SensitiveDetector
  void SetPos(G4ThreeVector xyz) { fPos = xyz; }
  G4ThreeVector GetPos() const { return fPos; }

  //get the various positions of the three vector for analysis
  G4double Get_X(){return this->fPos.x(); }
  G4double Get_Y(){return this->fPos.y(); }
  G4double Get_Z(){return this->fPos.z(); }  
  
  // time of interaction
  void SetTime(G4double de) { fTime = de; }
  G4double GetTime() const { return fTime; }

  // total track length
  void SetTrackLength(G4double len) {fLength = len; }
  G4double GetTrackLength() const {return fLength; }

  // number of reflections
  void SetReflectionCount(G4int count) {fReflections = count; }
  G4int GetReflectionCount() const {return fReflections; }

  // number of reflections
  void SetTotalInternalReflectionCount(G4int count) {fTotalInternalReflections = count; }
  G4int GetTotalInternalReflectionCount() const {return fTotalInternalReflections; }

private:
  G4int fSensDetID;
  G4double fEnergy;
  G4ThreeVector fPos;
  G4double fTime;
  G4double fLength;
  G4int fReflections;
  G4int fTotalInternalReflections;

};

using SensitiveDetectorHitsCollection = G4THitsCollection<SensitiveDetectorHit>;

extern G4ThreadLocal G4Allocator<SensitiveDetectorHit>* SensitiveDetectorHitAllocator;

inline void* SensitiveDetectorHit::operator new(size_t)
{
  if (!SensitiveDetectorHitAllocator) {
    SensitiveDetectorHitAllocator = new G4Allocator<SensitiveDetectorHit>;
  }
  return (void*)SensitiveDetectorHitAllocator->MallocSingle();
}

inline void SensitiveDetectorHit::operator delete(void* aHit)
{
  SensitiveDetectorHitAllocator->FreeSingle((SensitiveDetectorHit*) aHit);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
