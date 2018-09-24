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

// Make this appear first!
#include "G4Timer.hh"

#include "StackingAction.hh"
#include "SteppingAction.hh"
#include "RunAction.hh"
#include "Analysis.hh"
#include <fstream>
#include "G4run.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction(AnalysisManager* analysis)
  : G4UserRunAction(),
    fAnalysisManager(analysis),
    fSumEAbs(0.), fSum2EAbs(0.),
    fSumEGap(0.), fSum2EGap(0.),
    fSumLAbs(0.), fSum2LAbs(0.),
    fSumLGap(0.), fSum2LGap(0.),
    fSumX_pos(0.),fSum2X_pos(0.),
    fSumY_pos(0.),fSum2Y_pos(0.),
    fTimer(0)
{
  // Timer allows tracking of elapsed times while generating events
  fTimer = new G4Timer;

}
RunAction::~RunAction()
{
  delete fTimer;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* aRun)
{
  //inform the runManager to save random number seed
  //G4RunManager::GetRunManager()->SetRandomNumberStore(true);

  //initialize cumulative quantities
  //
  fSumEAbs = fSum2EAbs =fSumEGap = fSum2EGap = 0.;
  fSumLAbs = fSum2LAbs =fSumLGap = fSum2LGap = 0.;
  fSumX_pos = fSum2X_pos = fSumY_pos = fSum2Y_pos = 0.;

  fAnalysisManager->Book();

  // Timer handling
  G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
  fTimer->Start();

}

void RunAction::FillPerEvent(G4double EAbs, G4double EGap,
			     G4double LAbs, G4double LGap,
			     G4double X_pos, G4double Y_pos)
{
  //accumulate statistic
  //
  fSumEAbs += EAbs;  fSum2EAbs += EAbs*EAbs;
  fSumEGap += EGap;  fSum2EGap += EGap*EGap;
  
  fSumLAbs += LAbs;  fSum2LAbs += LAbs*LAbs;
  fSumLGap += LGap;  fSum2LGap += LGap*LGap;

  fSumX_pos += X_pos; fSum2X_pos += X_pos*X_pos;
  fSumY_pos += Y_pos; fSum2Y_pos += Y_pos*Y_pos;
  
}




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* aRun)
{

  G4int NbOfEvents = aRun->GetNumberOfEvent();
  if (NbOfEvents == 0) return;
  
  //compute statistics: mean and rms
  //
  fSumEAbs /= NbOfEvents; fSum2EAbs /= NbOfEvents;
  G4double rmsEAbs = fSum2EAbs - fSumEAbs*fSumEAbs;
  if (rmsEAbs >0.) rmsEAbs = std::sqrt(rmsEAbs); else rmsEAbs = 0.;
  
  fSumEGap /= NbOfEvents; fSum2EGap /= NbOfEvents;
  G4double rmsEGap = fSum2EGap - fSumEGap*fSumEGap;
  if (rmsEGap >0.) rmsEGap = std::sqrt(rmsEGap); else rmsEGap = 0.;
  
  fSumLAbs /= NbOfEvents; fSum2LAbs /= NbOfEvents;
  G4double rmsLAbs = fSum2LAbs - fSumLAbs*fSumLAbs;
  if (rmsLAbs >0.) rmsLAbs = std::sqrt(rmsLAbs); else rmsLAbs = 0.;
  
  fSumLGap /= NbOfEvents; fSum2LGap /= NbOfEvents;
  G4double rmsLGap = fSum2LGap - fSumLGap*fSumLGap;
  if (rmsLGap >0.) rmsLGap = std::sqrt(rmsLGap); else rmsLGap = 0.;


  fSumX_pos /= NbOfEvents; fSum2X_pos /= NbOfEvents;
  G4double rmsX_pos = fSum2X_pos - fSumX_pos*fSumX_pos;
  if (rmsX_pos >0.) rmsX_pos = std::sqrt(rmsX_pos); else rmsX_pos = 0.;
  
  fSumY_pos /= NbOfEvents; fSum2Y_pos /= NbOfEvents;
  G4double rmsY_pos = fSum2Y_pos - fSumY_pos*fSumY_pos;
  if (rmsY_pos >0.) rmsY_pos = std::sqrt(rmsY_pos); else rmsY_pos = 0.;

  
  // //print
  // //energy print
  // G4cout
  //    << "\n--------------------End of Run------------------------------\n"
  //    << "\n mean Energy in Absorber : " << G4BestUnit(fSumEAbs,"Energy")
  //    << " +- "                          << G4BestUnit(rmsEAbs,"Energy")  
  //    << "\n mean Energy in Gap      : " << G4BestUnit(fSumEGap,"Energy")
  //    << " +- "                          << G4BestUnit(rmsEGap,"Energy")
  //    << G4endl;

  // //track length print
  // G4cout
  //    << "\n mean trackLength in Absorber : " << G4BestUnit(fSumLAbs,"Length")
  //    << " +- "                               << G4BestUnit(rmsLAbs,"Length")  
  //    << "\n mean trackLength in Gap      : " << G4BestUnit(fSumLGap,"Length")
  //    << " +- "                               << G4BestUnit(rmsLGap,"Length")
  //    << "\n------------------------------------------------------------\n"
  //    << G4endl;
     
  // //x and y position print
  // G4cout
  //    << "\n mean x position in Absorber : " << G4BestUnit(fSumX_pos,"X_pos")
  //    << " +- "                               << G4BestUnit(rmsX_pos,"X_pos")  
  //    << "\n mean y position in Gap      : " << G4BestUnit(fSumY_pos,"Y_pos")
  //    << " +- "                               << G4BestUnit(rmsY_pos,"Y_pos")
  //    << "\n------------------------------------------------------------\n"
  //    << G4endl;



  //save histograms
  //
  fAnalysisManager->PrintStatistic();
  fAnalysisManager->Save();   

  G4cout << " end of run. " << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

