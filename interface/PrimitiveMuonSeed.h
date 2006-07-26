#ifndef TrackerSeedGenerator_PrimitiveMuonSeed_H
#define TrackerSeedGenerator_PrimitiveMuonSeed_H

/**  \class PrimitiveMuonSeed
 *
 *   Primitive tracker seed from muon which 
 *   consists of one measurement and a trajectory state
 *
 *   $Date: 2006/07/10 16:30:45 $
 *   $Revision: 1.2 $
 *
 *   \author   N. Neumeister   - Purdue University
 */

#include "DataFormats/TrajectorySeed/interface/TrajectorySeed.h"
#include "DataFormats/TrajectorySeed/interface/BasicTrajectorySeed.h"
#include "TrackingTools/PatternTools/interface/TrajectoryMeasurement.h"
//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

class FreeTrajectoryState;
class TrajectoryMeasurement;
class TransientTrackingRecHit;
//              ---------------------
//              -- Class Interface --
//              ---------------------

class PrimitiveMuonSeed : public BasicTrajectorySeed {

  public:

    /// constructor
    PrimitiveMuonSeed(const PTrajectoryStateOnDet& state,
                      const PropagationDirection& direction,
		      const recHitContainer layerRecHits,
                      const TrajectoryMeasurement& meas);

    /// destructor
    virtual ~PrimitiveMuonSeed() {}

    virtual PropagationDirection direction() const;

    virtual std::vector<TrajectoryMeasurement> measurements() const;

    virtual bool share(const BasicTrajectorySeed&) const;

    virtual BasicTrajectorySeed* clone() const;

    virtual range recHits() const ;

    virtual PTrajectoryStateOnDet startingState() const ;

  private:

    PTrajectoryStateOnDet         theState;
    PropagationDirection          theDirection;  
    TrajectorySeed                theTrajectorySeed;
    TrajectoryMeasurement         theMeasurement;

};

#endif 

