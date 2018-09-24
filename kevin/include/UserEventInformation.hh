#ifndef __USER_EVENT_INFORMATION__
#define __USER_EVENT_INFORMATION__

#include "G4VUserEventInformation.hh"
#include "G4ThreeVector.hh"

class UserEventInformation : public G4VUserEventInformation
{
  public:

    UserEventInformation();
    virtual ~UserEventInformation();

    inline virtual void Print() const{};

    // non-boundary absorption
    void IncAbsorption(){fAbsorptionCount++;}
    G4int GetAbsorptionCount()const {return fAbsorptionCount;}

    // boundary absorption
    void IncBoundaryAbsorption(){fBoundaryAbsorptionCount++;}
    G4int GetBoundaryAbsorptionCount() const {return fBoundaryAbsorptionCount;}


  private:

    G4int fAbsorptionCount;
    G4int fBoundaryAbsorptionCount;

};

#endif
