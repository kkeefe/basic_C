#ifndef __TRACKING_ACTION__
#define __TRACKING_ACTION__

#include "G4UserTrackingAction.hh"
#include "G4TrackingManager.hh"
#include "G4Track.hh"
#include "G4ParticleTypes.hh"

class TrackingAction : public G4UserTrackingAction {

public:

    TrackingAction();
    virtual ~TrackingAction() {};

    virtual void PreUserTrackingAction(const G4Track*);
    virtual void PostUserTrackingAction(const G4Track*);

private:

};

#endif
