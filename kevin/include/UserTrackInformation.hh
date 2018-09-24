#ifndef __USER_TRACK_INFORMATION__
#define __USER_TRACK_INFORMATION__

#include "G4VUserTrackInformation.hh"

enum TrackStatus { active=1, hitSiPM=2, absorbed=4, boundaryAbsorbed=8,
                   inactive=14};

/*TrackStatus:
  active: still being tracked
  hitSiPM: stopped by being detected in a SiPM
  absorbed: stopped by being absorbed with G4OpAbsorbtion
  boundaryAbsorbed: stopped by being aborbed with G4OpAbsorbtion at a boundary
  inactive: track is stopped for some reason
   -This is the sum of all stopped flags so can be used to remove stopped flags
 
*/

class UserTrackInformation : public G4VUserTrackInformation
{
  public:

    UserTrackInformation();
    virtual ~UserTrackInformation();

    //Sets the track status to s (does not check validity of flags)
    void SetTrackStatusFlags(int s){fStatus=s;}
    //Does a smart add of track status flags (disabling old flags that conflict)
    //If s conflicts with itself it will not be detected
    void AddTrackStatusFlag(int s);
    int GetTrackStatus()const {return fStatus;}

    // number of non-total reflections by track
    void IncReflections(){fReflections++;}
    G4int GetReflectionCount()const {return fReflections;}

    // number of total internal reflections by track
    void IncTotalInternalReflections(){fTotalInternalReflections++;}
    G4int GetTotalInternalReflectionCount()const {return fTotalInternalReflections;}

    inline virtual void Print() const{};

  private:

    int fStatus;
    G4int fReflections;
    G4int fTotalInternalReflections;
};

#endif
