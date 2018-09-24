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
// $Id: AnalysisManager.cc 105493 2017-07-28 09:01:53Z gcosmo $
// GEANT4 tag $Name: geant4-09-04 $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


#include "Analysis.hh"
#include "G4UnitsTable.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

AnalysisManager::AnalysisManager()
:fRootFile(0),fNtuple1(0), fEabs(0.), fEgap(0.) ,fLabs(0.), fLgap(0.)
{

  // histograms
  fHisto = 0;
    
  // ntuple
  fNtuple1 = 0;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

AnalysisManager::~AnalysisManager()
{
  if (fRootFile) delete fRootFile;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void AnalysisManager::Book()
{ 
  // Creating a tree container to handle histograms and ntuples.
  // This tree is associated to an output file.
  //
  G4String fileName = "Analysis.root";
  //recreate option will choose to erase and start fresh at every run. Can choose UPDATE to prevent erasing data
  fRootFile = new TFile(fileName,"RECREATE"); 
  if (! fRootFile) {
    G4cout << " AnalysisManager::Book :" 
           << " problem creating the ROOT TFile "
           << G4endl;
    return;
  }
  
  fHisto = new TH1D("EAbs", "Edep in absorber (MeV)", 100, 0., 800*CLHEP::MeV);

  
  if (! fHisto) G4cout << "\n can't create histo " << G4endl;


  // create 1st ntuple
  fNtuple1 = new TTree("Ntuple1", "Edep");
  fNtuple1->Branch("Eabs", &fEabs, "Eabs/D");
  fNtuple1->Branch("Egap", &fEgap, "Egap/D");
  
  // create 2nd ntuple
  fNtuple2 = new TTree("Ntuple2", "TrackL");
  fNtuple2->Branch("Labs", &fLabs, "Labs/D");
  fNtuple2->Branch("Lgap", &fLgap, "Lgap/D");
  
  // create 3rd ntuple
  fNtuple3 = new TTree("Ntuple3", "Position");
  fNtuple3->Branch("fX_pos", &fX_pos, "X_pos/D");
  fNtuple3->Branch("fY_pos", &fY_pos, "Y_pos/D");
  
  G4cout << "\n----> Output file is open in " << fileName << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void AnalysisManager::Save()
{ 
  if (! fRootFile) return;
  
  fRootFile->Write();       // Writing the histograms to the file
  fRootFile->Close();       // and closing the tree (and the file)
  
  G4cout << "\n----> Histograms and ntuples are saved\n" << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void AnalysisManager::FillHisto(G4int ih, G4double xbin, G4double weight)
{
  //commented out since only want to fill a single histogram
  // if (ih >= kMaxHisto) {
  //   G4cerr << "---> warning from AnalysisManager::FillHisto() : histo " << ih
  //          << " does not exist. (xbin=" << xbin << " weight=" << weight << ")"
  //          << G4endl;
  //   return;
  // }
  //[ih] is the number of the histogram you want to fill
  // if  (fHisto[ih]) { fHisto[ih]->Fill(xbin, weight); }
  if  (fHisto) { fHisto->Fill(xbin, weight); }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void AnalysisManager::Normalize(G4int ih, G4double fac)
{
  //comment out since only want to fill a single histogram
  // if (ih >= kMaxHisto) {
  //   G4cout << "---> warning from AnalysisManager::Normalize() : histo " << ih
  //          << " does not exist. (fac=" << fac << ")" << G4endl;
  //   return;
  // }
  // if (fHisto[ih]) fHisto[ih]->Scale(fac);
  if (fHisto) fHisto->Scale(fac);  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void AnalysisManager::FillNtuple(G4double energyAbs, G4double energyGap,
				 G4double trackLAbs , G4double trackLGap,
				 G4double x_pos, G4double y_pos)
{
  //make sure to define the member variables in the order they're declared in the header file
  fEabs = energyAbs;
  fEgap = energyGap;
  fLabs = trackLAbs;
  fLgap = trackLGap;
  fX_pos = x_pos;
  fY_pos = y_pos;

  //add these values to the ntuple
  if (fNtuple1) fNtuple1->Fill();
  if (fNtuple2) fNtuple2->Fill();  
  if (fNtuple3) fNtuple3->Fill();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void AnalysisManager::PrintStatistic()
{
  G4cout << "\n ----> print histograms statistic \n" << G4endl;

  //deleted the for loop since only want a single hist
  TH1D* h1 = fHisto;
  const G4String name = h1->GetName();  

  G4String unitCategory;
  if (name[0] == 'E' ) unitCategory = "Energy"; 
  if (name[0] == 'L' ) unitCategory = "Length";
  if (name[0] == 'P' ) unitCategory = "Position";

  G4cout << name
	 << ": mean = " << G4BestUnit(h1->GetMean(), unitCategory) 
	 << " rms = " << G4BestUnit(h1->GetRMS(), unitCategory ) 
	 << G4endl;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
