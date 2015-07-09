/**
 *
 */

#ifndef DETECTORCONSTRUCTION_H
#define DETECTORCONSTRUCTION_H

#include "G4VUserDetectorConstruction.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{
	private:
		
	public:
		DetectorConstruction();
		virtual ~DetectorConstruction();
		
		virtual G4VPhysicalVolume* Construct();
		virtual void ConstructSDandField();
	
};

#endif
