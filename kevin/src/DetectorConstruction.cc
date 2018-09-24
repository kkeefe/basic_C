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

#include "DetectorConstruction.hh"
#include "SensitiveDetector.hh"

#include "G4Material.hh"
#include "G4Element.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpticalSurface.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4SubtractionSolid.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4PSFlatSurfaceCurrent.hh"
#include "G4SDParticleFilter.hh"
#include "G4SDManager.hh"

#include <sstream>
#include <string>
#include <fstream>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

using namespace CLHEP;
using namespace std;

DetectorConstruction::DetectorConstruction()
  : G4VUserDetectorConstruction()
{
  //the world is a 6x6x6 m cube
  world_x = world_y = world_z = 0.5*m;

  //the Tranloc is .5mm total in xy plane, and 1.5mm in z plane total
  Box_x  = Box_y = .075*mm;
  Box_z  =  0.25*m;

  //define the dimensions of the sensitive detector
  SDet_z = 1*mm;
  //assign the SDet to have the same cross section as the Tranloc
  SDet_y = Box_y;
  SDet_x = Box_x;


  
}

DetectorConstruction::~DetectorConstruction(){;}

// construct the geometry
G4VPhysicalVolume* DetectorConstruction::Construct() {


  // ------------- Materials -------------
  const G4int dim = 500;
  G4double a, z, density;
  G4int nelements;

  G4Element* N = new G4Element("Nitrogen", "N", z=7 , a=14.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8 , a=16.00*g/mole);
  G4Element* H = new G4Element("Hydrogen", "H", z=1 , a=1.01*g/mole);
  G4Element* C = new G4Element("Carbon"  , "C", z=6 , a=12.01*g/mole);
  G4Element *Si = new G4Element("Silicon", "Si", z=14 , a=28.086*g/mole);

  //material #1 - world volume
  G4Material* air = new G4Material("Air", density=1.29*mg/cm3, nelements=2);
  air->AddElement(N, 70.*perCent);
  air->AddElement(O, 30.*perCent);

  //material #2 - sensitive detectors
  G4Material *silicon = new G4Material("Silicon", density=2.32*g/cm3, nelements=1);
  silicon->AddElement(Si,1);

  //material #3 - tranLoc material 
  G4Material *acrylic = new G4Material("Acrylic", density=1.19*g/cm3, nelements=3);
  acrylic->AddElement(C,5);
  acrylic->AddElement(O,2);
  acrylic->AddElement(H,8);

  //material #4 - tranLoc material 
  G4Material *polystyrene = new G4Material("Polystyrene", density=1.05*g/cm3, nelements=2);
  polystyrene->AddElement(C,8);
  polystyrene->AddElement(H,8);
  
  //
  // ------------ Generate & Add Material Properties Table ------------
  //

  //define list of photon energies
  G4double photonEnergy[] =
    { 2.034*eV, 2.068*eV, 2.103*eV, 2.139*eV,
      2.177*eV, 2.216*eV, 2.256*eV, 2.298*eV,
      2.341*eV, 2.386*eV, 2.433*eV, 2.481*eV,
      2.532*eV, 2.585*eV, 2.640*eV, 2.697*eV,
      2.757*eV, 2.820*eV, 2.885*eV, 2.954*eV,
      3.026*eV, 3.102*eV, 3.181*eV, 3.265*eV,
      3.353*eV, 3.446*eV, 3.545*eV, 3.649*eV,
      3.760*eV, 3.877*eV, 4.002*eV, 4.136*eV };

  //define the size of the photon energy array
  const G4int nEntries = sizeof(photonEnergy)/sizeof(G4double);

  G4double *absorptionAir = new G4double[nEntries];    
  G4double *absorptionSi = new G4double[nEntries];
  G4double *absorptionPMMA = new G4double[nEntries];
  G4double *absorptionPS = new G4double[nEntries];
  G4double *rayleigh = new G4double[nEntries];

  //  -------------- define absorption of photons for various materials  --------------
  for(G4int i = 0; i < nEntries; ++i){
    absorptionAir[i] = 100*m; 
    absorptionSi[i] = 10*nm;
    absorptionPMMA[i] = 100*cm;
    absorptionPS[i] = 100*cm;
    rayleigh[i] = 1*km;
  }

  G4double refractiveIndexAir[] =
    { 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00 };

  G4double *refractiveIndexPMMA = new G4double[nEntries];    
  G4double *refractiveIndexPS = new G4double[nEntries];
  // Calculate index of refraction
  // see: http://refractiveindex.info/?shelf=organic&book=poly%28methyl_methacrylate%29&page=Sultanova
  for (G4int i = 0; i < nEntries; ++i) {
    G4double lambda = 1240*eV/photonEnergy[i]*nm/um;
    refractiveIndexPMMA[i] = sqrt(1+1.1819/(1 - 0.011313/pow(lambda,2)));
    refractiveIndexPS[i] = sqrt(1+1.4435/(1 - 0.020216/pow(lambda,2)));
  }

  //  --------------Air material #1 --------------
  G4MaterialPropertiesTable* airTable = new G4MaterialPropertiesTable();
  airTable->AddProperty("RINDEX", photonEnergy, refractiveIndexAir, nEntries)->SetSpline(true);
  airTable->AddProperty("ABSLENGTH", photonEnergy, absorptionAir, nEntries)->SetSpline(true);
  //  airTable->AddProperty("RAYLEIGH", photonEnergy, rayleigh, nEntries)->SetSpline(true);
  G4cout << "Air G4MaterialPropertiesTable" << G4endl;
  airTable->DumpTable();
  air->SetMaterialPropertiesTable(airTable);

  // ------------- Silicon Material #2 --------------(Si)
  G4MaterialPropertiesTable* siliconTable = new G4MaterialPropertiesTable();
  siliconTable->AddProperty("RINDEX",photonEnergy,refractiveIndexAir,nEntries)->SetSpline(true);  //note currently double defininng air refracting index since abs length of Si is 10*nm
  siliconTable->AddProperty("ABSLENGTH",photonEnergy,absorptionSi,nEntries)->SetSpline(true);
  G4cout << "Silicon G4MaterialPropertiesTable" << G4endl;
  siliconTable->DumpTable();
  silicon->SetMaterialPropertiesTable(siliconTable);
  
  //  -------------- Acrylic material #3 --------------(PMMA)
  G4MaterialPropertiesTable* acrylicTable = new G4MaterialPropertiesTable();
  acrylicTable->AddProperty("RINDEX",photonEnergy,refractiveIndexPMMA,nEntries)->SetSpline(true);
  acrylicTable->AddProperty("ABSLENGTH", photonEnergy, absorptionPMMA, nEntries)->SetSpline(true);
  // acrylicTable->AddProperty("RAYLEIGH", photonEnergy, rayleigh, nEntries)->SetSpline(true);
  G4cout << "Acrylic G4MaterialPropertiesTable" << G4endl;
  acrylicTable->DumpTable();
  acrylic->SetMaterialPropertiesTable(acrylicTable);

  // --------------polystyrene material #4 --------------(PS)
  G4MaterialPropertiesTable* polystyreneTable = new G4MaterialPropertiesTable();
  polystyreneTable->AddProperty("RINDEX", photonEnergy, refractiveIndexPS,nEntries)->SetSpline(true);
  polystyreneTable->AddProperty("ABSLENGTH", photonEnergy, absorptionPS, nEntries)->SetSpline(true);
  G4cout << "Polystyrene G4MaterialPropertiesTable" << G4endl;
  polystyreneTable->DumpTable();
  polystyrene->SetMaterialPropertiesTable(polystyreneTable);
   
  //
  // ------------- Volumes --------------

  // The experimental Box (TranLoc material)
  // The World Placement
  //
  
  G4Box *solidWorld = new G4Box("World", world_x , world_y , world_z );
  
  G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, air, "World");
  
  // create physical world
  G4VPhysicalVolume* physWorld = new G4PVPlacement(0,                          // no rotation,
                                                   G4ThreeVector(0, 0, 0),     // location
                                                   logicWorld,                 // logical volume
                                                   "World",                    // name description
                                                   0,                          // no mother volume
                                                   false, 0, true);            // 


  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  //tranLoc placement

  //sensitive detector placement; the number of dimensions is equal to dim squared
  const G4int detectorCount = dim*dim;

  //define the volumes of the Tranloc
  G4Box* SolidTran = new G4Box("TranLoc", Box_x,Box_y,Box_z);
  G4LogicalVolume* LogicTran[detectorCount];
  G4VPhysicalVolume* PhysTran[detectorCount];

  G4Box* SensDetector = new G4Box("SensitiveDetector", dim*SDet_x, dim*SDet_y, SDet_z);  
  G4LogicalVolume* sensDetector_log[2];
  G4VPhysicalVolume* sensDetector_phys[2];
 
  //set the initial counts of detectors and tranCounts
  G4int senscount = 0, tranLocCount = 0;

  //make sure the offsets match the dimensions of the acrylic, and start in the center of the world
  G4double offset_z = 0; 

  //place the 2 sensitive detectors first.
  for(int i = 0; i < 2; ++i){
    	char detName[1024];
	sprintf(detName, "SensitiveDetector%d",senscount);

	//z offset calculation
	if(i == 0){
	  offset_z = -(Box_z + SDet_z);
	}else{
	  offset_z = Box_z + SDet_z;
	}

	//defines a logical volume
	sensDetector_log[i] = new G4LogicalVolume(SensDetector,silicon,detName, 0, 0, 0);
	
	//name the detector, and place it in the physical world;
	sprintf(detName, "Photodetector%d",senscount);
	sensDetector_phys[senscount] =
	  new G4PVPlacement(0, G4ThreeVector(0, 0, offset_z), sensDetector_log[senscount], detName, logicWorld, true, senscount);

	//increase the detector count, after physical placement
	senscount++;
  }

  //x dimension iteration, open outfile.txt to read for string names;
  std::ifstream infile;
  infile.open("outfile500.txt");
  int material_check;
   
  for(G4int x_dim = 0; x_dim < dim; x_dim++){
      
    //x offset calculation, must be redecined when x is changed
    G4double offset_x = (2*x_dim-dim+1)*Box_x;
     
    //y dimension iteration
    for(G4int y_dim = 0; y_dim < dim; y_dim++){

      //y offset calculation, must be changed when x is changed
      G4double offset_y = (2*y_dim-dim+1)*Box_y;
            
      //placement of the TranLoc pieces with the correct x and y offsets
      //define the material type for each piece.
      infile >> material_check;
      if(material_check == 1){
	LogicTran[tranLocCount] = new G4LogicalVolume(SolidTran,acrylic,"TranLoc",0,0,0);
      }else{
	LogicTran[tranLocCount] = new G4LogicalVolume(SolidTran,polystyrene,"TranLoc",0,0,0);

	/*this line is to be commented in out specific specifically to test TranLoc vs pure acrylic*/
	// LogicTran[tranLocCount] = new G4LogicalVolume(SolidTran,acrylic,"TranLoc",0,0,0);	
      }

      PhysTran[tranLocCount] = new G4PVPlacement(0,G4ThreeVector(offset_x,offset_y,0),LogicTran[tranLocCount],"TranLoc",logicWorld,false,0);

      //add a count to the tran locs after placement
      tranLocCount++;
    }
  }

  //close the file reading the material type
  infile.close();
   
  // sensitive detectors ~~~~~~~~~~~~~~~

  //make the newly placed detectors sensitive:
  G4SDManager* SDMan = G4SDManager::GetSDMpointer();
  G4String SDname;

  //must define PhotoDetectorSD!!
  G4VSensitiveDetector *photoDetSD = new SensitiveDetector(SDname="/PhotoDetector");
  SDMan->AddNewDetector(photoDetSD);

  // set every sensDetector_log to a sensitive detector.
  for(auto &c : sensDetector_log){
    c->SetSensitiveDetector(photoDetSD);
  }
  
  //always return physWorld
  return physWorld;
}

void DetectorConstruction::ConstructSDandField() {


}

