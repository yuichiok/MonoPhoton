#ifndef TestProcessor_h
#define TestProcessor_h 1

#include "marlin/Processor.h"
#include "lcio.h"
#include <string>

#include "UTIL/LCRelationNavigator.h"

class TFile;
class TTree;
const int NMAX_PFOS   = 500;
const int NMAX_MCPS   = 500;
const int NMAX_CLRS   = 500;

using namespace lcio ;
using namespace marlin ;


/**  Example processor for marlin.
 * 
 *  If compiled with MARLIN_USE_AIDA 
 *  it creates a histogram (cloud) of the MCParticle energies.
 * 
 *  <h4>Input - Prerequisites</h4>
 *  Needs the collection of MCParticles.
 *
 *  <h4>Output</h4> 
 *  A histogram.
 * 
 * @param CollectionName Name of the MCParticle collection
 * 
 * @author F. Gaede, DESY
 * @version $Id: MyProcessor.h,v 1.4 2005-10-11 12:57:39 gaede Exp $ 
 */

class MyProcessor : public Processor {
  
 public:
  
  virtual Processor*  newProcessor() { return new MyProcessor ; }
  
  
  MyProcessor() ;
  
  /** Called at the begin of the job before anything is read.
   * Use to initialize the processor, e.g. book histograms.
   */
  virtual void init() ;
  
  /** Called for every run.
   */
  virtual void processRunHeader( LCRunHeader* run ) ;
  
  /** Called for every event - the working horse.
   */
  virtual void processEvent( LCEvent * evt ) ; 
  
  
  virtual void check( LCEvent * evt ) ; 
  
  
  /** Called after data processing for clean up.
   */
  virtual void end() ;
  
  
 protected:

 /** Prepare NTuple 
  */ 
  void makeNTuple() ;

  /** Input collection name.
   */
  std::string _colMCP ;
  std::string _colPFO ;
  std::string _colMCPFORelation ;
  LCRelationNavigator* _navpfo;

  int _nRun ;
  int _nEvt ;

  TFile* _otfile;
  TTree* _evtdata;

  struct EVTFILLDATA {
    int    evt ;       // event number
    int    npfos ;     // # of PFOs 
    float  pfo_e[NMAX_PFOS];
    float  pfo_px[NMAX_PFOS];
    float  pfo_py[NMAX_PFOS];
    float  pfo_pz[NMAX_PFOS];
    float  pfo_phi[NMAX_PFOS];
    float  pfo_theta[NMAX_PFOS];
    float  pfo_chrg[NMAX_PFOS];
    int    pfo_pdg[NMAX_PFOS];
    int    pfo_ntrk[NMAX_PFOS];
    float  pfo_d0[NMAX_PFOS];
    float  pfo_d0sig[NMAX_PFOS];
    float  pfo_z0[NMAX_PFOS];
    float  pfo_z0sig[NMAX_PFOS];
    float  pfo_trkphi[NMAX_PFOS];
    float  pfo_omega[NMAX_PFOS];
    float  pfo_tanlambda[NMAX_PFOS];
    int    pfo_nclus[NMAX_PFOS]; 
    float  pfo_cal_x[NMAX_PFOS];
    float  pfo_cal_y[NMAX_PFOS];
    float  pfo_cal_z[NMAX_PFOS];
    float  pfo_ecal_e[NMAX_PFOS];
    float  pfo_hcal_e[NMAX_PFOS];
    float  pfo_yoke_e[NMAX_PFOS];
    float  pfo_lcal_e[NMAX_PFOS];
    float  pfo_lhcal_e[NMAX_PFOS];
    float  pfo_bcal_e[NMAX_PFOS];

    // MC Relation 
    int    nmcr[NMAX_PFOS];
    float  mcr_weight[NMAX_PFOS];
    float  mcr_e[NMAX_PFOS];
    float  mcr_px[NMAX_PFOS];
    float  mcr_py[NMAX_PFOS];
    float  mcr_pz[NMAX_PFOS];
    float  mcr_phi[NMAX_PFOS];
    float  mcr_theta[NMAX_PFOS];
    float  mcr_chrg[NMAX_PFOS];
    int    mcr_pdg[NMAX_PFOS];
    int    mcr_genstatus[NMAX_PFOS];
    int    mcr_simstatus[NMAX_PFOS];
    bool   mcr_iscreatedinsim[NMAX_PFOS];

    // MC Info
    int    nmcps ;     // # of MC Particles 
    float  mcp_e[NMAX_MCPS];
    float  mcp_px[NMAX_MCPS];
    float  mcp_py[NMAX_MCPS];
    float  mcp_pz[NMAX_MCPS];
    float  mcp_phi[NMAX_MCPS];
    float  mcp_theta[NMAX_MCPS];
    float  mcp_chrg[NMAX_MCPS];
    int    mcp_pdg[NMAX_MCPS];
    int    mcp_genstatus[NMAX_MCPS];
    int    mcp_simstatus[NMAX_MCPS];
    bool   mcp_iscreatedinsim[NMAX_MCPS];

    int    nclrhits ;    // # of Cal hit clusters;
    float  clr_x[NMAX_CLRS];
    float  clr_y[NMAX_CLRS];
    float  clr_z[NMAX_CLRS];
  };

  EVTFILLDATA _data;

  // output root file name
  std::string _rootfilename;

} ;

#endif



