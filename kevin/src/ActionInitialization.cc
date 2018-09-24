#include "EventAction.hh"
#include "Analysis.hh"
#include "PrimaryGeneratorAction.hh"
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"
#include "StackingAction.hh"

ActionInitialization::ActionInitialization() : G4VUserActionInitialization()
{}

ActionInitialization::~ActionInitialization()
{}


void ActionInitialization::BuildForMaster() const
{
  AnalysisManager* analysis = new AnalysisManager();
  SetUserAction(new RunAction(analysis));
}

void ActionInitialization::Build() const
{

  AnalysisManager* analysis = new AnalysisManager();

  SetUserAction(new PrimaryGeneratorAction());
  
  RunAction* runAction = new RunAction(analysis);
  SetUserAction(runAction);

  EventAction* eventAction = new EventAction(runAction, analysis);
  SetUserAction(eventAction);
  
  SteppingAction* steppingAction = new SteppingAction();
  SetUserAction(steppingAction);
  
  SetUserAction(new TrackingAction);
  
  SetUserAction(new StackingAction);
  
}
