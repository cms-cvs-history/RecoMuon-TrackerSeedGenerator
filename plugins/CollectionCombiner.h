#ifndef CollectionCombiner_H
#define CollectionCombiner_H

// -*- C++ -*-
//
// Package:    CollectionCombiner
// Class:      CollectionCombiner
// 
/**\class CollectionCombiner CollectionCombiner.cc RecoMuon/CollectionCombiner/src/CollectionCombiner.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Jean-Roch Vlimant
//         Created:  Tue Mar  4 02:08:53 CET 2008
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

//#include "TrackingTools/PatternTools/interface/Trajectory.h"
//#include "DataFormats/MuonSeed/interface/L3MuonTrajectorySeedCollection.h"

template <typename Collection>
class CollectionCombiner : public edm::EDProducer{
public:
  explicit CollectionCombiner(const edm::ParameterSet&);
  ~CollectionCombiner();
  
private:
  virtual void beginJob(const edm::EventSetup&);
  virtual void produce(edm::Event&, const edm::EventSetup&);
  virtual void endJob();
  
  // ----------member data ---------------------------
  std::vector<edm::InputTag> labels;
};

template <typename Collection>
CollectionCombiner<Collection>::CollectionCombiner(const edm::ParameterSet& iConfig){
  labels = iConfig.getParameter<std::vector<edm::InputTag> >("labels");
  produces<Collection>();
}
template <typename Collection>
CollectionCombiner<Collection>::~CollectionCombiner(){}
template <typename Collection>
void CollectionCombiner<Collection>::beginJob(const edm::EventSetup&){}
template <typename Collection>
void CollectionCombiner<Collection>::endJob(){}
template <typename Collection>
void CollectionCombiner<Collection>::produce(edm::Event& iEvent, const edm::EventSetup& es)
{
  uint i=0,i_max=labels.size();
  edm::Handle<Collection> handle;
  std::auto_ptr<Collection> merged(new Collection());
  for (;i!=i_max;++i){
    iEvent.getByLabel(labels[i], handle);
    merged->insert(merged->end(), handle->begin(), handle->end());
  }
  iEvent.put(merged);
}


#endif