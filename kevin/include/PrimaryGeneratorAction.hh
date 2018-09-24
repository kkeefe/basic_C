#ifndef __PRIMARY_GENERATOR__
#define __PRIMARY_GENERATOR__

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"
#include "G4Electron.hh"

// create primary generator
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
  PrimaryGeneratorAction();
  ~PrimaryGeneratorAction();
  void GeneratePrimaries(G4Event* event);
  static G4GeneralParticleSource* Gun() {return particleGun;}

private:
  static G4GeneralParticleSource *particleGun;

};

#endif
