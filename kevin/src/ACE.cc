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
//

#include "ACE.hh"

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif


using namespace CLHEP;

int main(int argc, char **argv) {

    // construct the default run manager
    G4RunManager *runManager = new G4RunManager;

    // // we must IMMEDIATELY construct the scoring manager
    // G4ScoringManager *scoringManager = G4ScoringManager::GetScoringManager();
    // (void)scoringManager;

    // generate geometry
    DetectorConstruction* detector = new DetectorConstruction;
    runManager->SetUserInitialization(detector);

    // create physics list
    runManager->SetUserInitialization(new PhysicsList);

    // set action generator
    runManager->SetUserInitialization(new ActionInitialization);

    // initialize the Geant4 kernel
    runManager->Initialize();

    // create vis manager
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    // get pointer to UI manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    // read a macro and execute it
    if (argc != 1) { //read a macro file of commands
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UImanager->ApplyCommand(command+fileName);
    }
    else { // we wish to run interactively
      UImanager->ApplyCommand("/control/macroPath ../macros");
      G4UIExecutive* ui = new G4UIExecutive(argc, argv);
      ui->SessionStart();
      delete ui;
    }

    // cleanup
    delete runManager;
    delete visManager;
    
    return 0;
}
