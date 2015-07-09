#include "DetectorConstruction.h"

//Material manager
#include "G4NistManager.hh"
//Basic Units.
#include "G4SystemOfUnits.hh"

//Basic Volume and Placement
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

//Types of Volumes
#include "G4Box.hh"

//Include necessary scorers
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"

DetectorConstruction::DetectorConstruction() :
	G4VUserDetectorConstruction()
{ }

DetectorConstruction::~DetectorConstruction()
{ }

/**This routine is used to construct the geometry to be simulated. This includes the
 * necessary materials to produce objects.
 */
G4VPhysicalVolume *DetectorConstruction::Construct()
{
	// Option to switch on/off checking of volumes overlaps
	G4bool checkOverlaps = false;

	//--------------Register Materials-------------------------------//
	// Get nist material manager
	G4NistManager* nist = G4NistManager::Instance();
	G4Material* air = nist->FindOrBuildMaterial("G4_AIR");

	// Construct the World
	G4double world_sizeXY = 5*cm;
	G4double world_sizeZ  = 30*cm;

	G4Box* solidWorld =    
		new G4Box("World",                       //its name
				0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);    //its size

	G4LogicalVolume* logicWorld =                         
		new G4LogicalVolume(solidWorld,          //its solid
				air,           //its material
				"World");      //its name

	G4VPhysicalVolume* physWorld = new G4PVPlacement(
			0, 					//no rotation
			G4ThreeVector(),	//at (0,0,0)
			logicWorld,			//contataing logical volume
			"World",				//name
			0,						//no mother volume
			false,				//no boolean operation
			0,						//copy number
			checkOverlaps);	//overlap checking

	//--------------Build the required geometry here-----------------//

	//Return the world
	return physWorld;
}

/**In this routine we construct the Senditive Detector (SD). This is where the scorers are registered.
 */
void DetectorConstruction::ConstructSDandField() 
{
}
