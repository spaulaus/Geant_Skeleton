#include "AngleScorer.h"

#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"
#include "G4Step.hh"

AngleScorer::AngleScorer(G4String name, G4int depth) :
	G4VPrimitiveScorer(name, depth),
	fHCID(-1)
{

}

G4bool AngleScorer::ProcessHits(G4Step* step, G4TouchableHistory*)
{
	if(step->GetPostStepPoint()->GetStepStatus() == fGeomBoundary) {
		G4int index = GetIndex(step);
		G4double value = step->GetTrack()->GetMomentum().theta();
		fEvtMap->add(index,value);
	}

	return true;
}

void AngleScorer::Initialize(G4HCofThisEvent* HCE)
{
  fEvtMap = new G4THitsMap<G4double>(detector->GetName(), GetName());
  if ( fHCID < 0 ) fHCID = GetCollectionID(0);
  HCE->AddHitsCollection(fHCID, (G4VHitsCollection*)fEvtMap);
}

void AngleScorer::EndOfEvent(G4HCofThisEvent*)
{

}
