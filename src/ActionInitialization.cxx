#include "ActionInitialization.h"
#include "PencilBeamPrimaryGenerator.h"
#include "PencilBeamRunAction.h"

ActionInitialization::ActionInitialization() :
	G4VUserActionInitialization()
{ }

ActionInitialization::~ActionInitialization()
{ }

void ActionInitialization::BuildForMaster() const
{

}

void ActionInitialization::Build() const
{
	SetUserAction(new PencilBeamPrimaryGenerator);
	SetUserAction(new PencilBeamRunAction);	

}
