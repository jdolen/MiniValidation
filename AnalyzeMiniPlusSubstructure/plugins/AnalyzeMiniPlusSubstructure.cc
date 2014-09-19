// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"

// TFile
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

// root
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"


//
// class declaration
//

class AnalyzeMiniPlusSubstructure : public edm::EDAnalyzer {
   public:
      explicit AnalyzeMiniPlusSubstructure(const edm::ParameterSet&);
      ~AnalyzeMiniPlusSubstructure();

   private:
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;

      // ----------member data ---------------------------
      edm::EDGetTokenT<reco::VertexCollection> vtxToken_;
      edm::EDGetTokenT<pat::MuonCollection> muonToken_;
      edm::EDGetTokenT<pat::ElectronCollection> electronToken_;
      edm::EDGetTokenT<pat::TauCollection> tauToken_;
      edm::EDGetTokenT<pat::PhotonCollection> photonToken_;
      edm::EDGetTokenT<pat::JetCollection> jetToken_;
      edm::EDGetTokenT<pat::JetCollection> fatjetToken_;
      edm::EDGetTokenT<pat::METCollection> metToken_;
      edm::EDGetTokenT<pat::PackedCandidateCollection> pfToken_;

      // ----------root ---------------------------

      TH1D * NVTX_GOOD            ;  
      TH1D * NVTX_ALL             ;  
      TH1D * RHO                  ;  


      TH1D * MU_PT                ;  
      TH1D * MU_ETA               ;  
      TH1D * MU_PHI               ;  
      TH1D * MU_dzPV              ;  
      TH1D * MU_ISLOOSE           ;  
      TH1D * MU_ISTIGHT           ;  

      TH1D * EL_PT                ;
      TH1D * EL_ETA               ;
      TH1D * EL_PHI               ;
      TH1D * EL_GSF_NLOSTHITS     ;
      TH1D * EL_SCETA             ;
      TH1D * EL_SIETAIETA         ;
      TH1D * EL_full5x5SIETAIETA  ;
      TH1D * EL_PASSCONERSIONVETO ;

      TH1D * PHO_PT               ;
      TH1D * PHO_ETA              ;
      TH1D * PHO_PHI              ;
      TH1D * PHO_CHISOoverPT      ;
      TH1D * PHO_SCETA            ;
      TH1D * PHO_SIETAIETA        ;
      TH1D * PHO_full5x5SIETAIETA ;

      TH1D * TAU_PT               ;  
      TH1D * TAU_PHI              ;  
      TH1D * TAU_ETA              ;  
      TH1D * TAU_DXYSIG           ;  
      TH1D * TAU_TAUID            ;  
      TH1D * TAU_LEADCANDPT       ;  
      TH1D * TAU_LEADCANDPDGID    ;  

      TH1D * AK5PF_PT             ;
      TH1D * AK5PF_PHI            ;
      TH1D * AK5PF_ETA            ;
      TH1D * AK5PF_RAP            ;
      TH1D * AK5PF_MASS           ;
      TH1D * AK5PF_NCONST         ;
      TH1D * AK5PF_AREA           ;
      TH1D * AK5PF_CH_MULT        ;
      TH1D * AK5PF_NE_MULT        ;
      TH1D * AK5PF_CHEF           ;
      TH1D * AK5PF_NHEF           ;
      TH1D * AK5PF_CEEF           ;
      TH1D * AK5PF_NEEF           ;
      TH1D * AK5PF_CMEF           ;
      TH1D * AK5PF_CSV             ; 
      TH1D * AK5PF_ISV             ; 
      TH1D * AK5PF_PUID            ; 


      TH1D * AK5PF_PU_PT              ;
      TH1D * AK5PF_PU_PHI             ;
      TH1D * AK5PF_PU_ETA             ;
      TH1D * AK5PF_PU_RAP             ;
      TH1D * AK5PF_PU_MASS            ;
      TH1D * AK5PF_PU_NCONST          ;
      TH1D * AK5PF_PU_AREA            ;
      TH1D * AK5PF_PU_CH_MULT         ;
      TH1D * AK5PF_PU_NE_MULT         ;
      TH1D * AK5PF_PU_CHEF            ;
      TH1D * AK5PF_PU_NHEF            ;
      TH1D * AK5PF_PU_CEEF            ;
      TH1D * AK5PF_PU_NEEF            ;
      TH1D * AK5PF_PU_CMEF            ;
      TH1D * AK5PF_PU_CSV             ;
      TH1D * AK5PF_PU_ISV             ;
      TH1D * AK5PF_PU_PUID            ;

      TH1D * AK5PF_PUID_PT              ;
      TH1D * AK5PF_PUID_PHI             ;
      TH1D * AK5PF_PUID_ETA             ;
      TH1D * AK5PF_PUID_RAP             ;
      TH1D * AK5PF_PUID_MASS            ;
      TH1D * AK5PF_PUID_NCONST          ;
      TH1D * AK5PF_PUID_AREA            ;
      TH1D * AK5PF_PUID_CH_MULT         ;
      TH1D * AK5PF_PUID_NE_MULT         ;
      TH1D * AK5PF_PUID_CHEF            ;
      TH1D * AK5PF_PUID_NHEF            ;
      TH1D * AK5PF_PUID_CEEF            ;
      TH1D * AK5PF_PUID_NEEF            ;
      TH1D * AK5PF_PUID_CMEF            ;
      TH1D * AK5PF_PUID_CSV             ;
      TH1D * AK5PF_PUID_ISV             ;
      TH1D * AK5PF_PUID_PUID            ;

      TH1D * AK5PF_lowPT_PT           ;
      TH1D * AK5PF_lowPT_PHI          ;
      TH1D * AK5PF_lowPT_ETA          ;
      TH1D * AK5PF_lowPT_RAP          ;
      TH1D * AK5PF_lowPT_MASS         ;
      TH1D * AK5PF_lowPT_NCONST       ;
      TH1D * AK5PF_lowPT_AREA         ;
      TH1D * AK5PF_lowPT_CH_MULT      ;
      TH1D * AK5PF_lowPT_NE_MULT      ;
      TH1D * AK5PF_lowPT_CHEF         ;
      TH1D * AK5PF_lowPT_NHEF         ;
      TH1D * AK5PF_lowPT_CEEF         ;
      TH1D * AK5PF_lowPT_NEEF         ;
      TH1D * AK5PF_lowPT_CMEF         ;
      TH1D * AK5PF_lowPT_CSV          ;
      TH1D * AK5PF_lowPT_ISV          ;
      TH1D * AK5PF_lowPT_PUID         ;
      TH1D * AK5PF_forward_PT         ;
      TH1D * AK5PF_forward_PHI        ;
      TH1D * AK5PF_forward_ETA        ;
      TH1D * AK5PF_forward_RAP        ;
      TH1D * AK5PF_forward_MASS       ;
      TH1D * AK5PF_forward_NCONST     ;
      TH1D * AK5PF_forward_AREA       ;
      TH1D * AK5PF_forward_CH_MULT    ;
      TH1D * AK5PF_forward_NE_MULT    ;
      TH1D * AK5PF_forward_CHEF       ;
      TH1D * AK5PF_forward_NHEF       ;
      TH1D * AK5PF_forward_CEEF       ;
      TH1D * AK5PF_forward_NEEF       ;
      TH1D * AK5PF_forward_CMEF       ;
      TH1D * AK5PF_forward_CSV        ;
      TH1D * AK5PF_forward_ISV        ;
      TH1D * AK5PF_forward_PUID       ;
      TH1D * AK5PF_central_PT         ;
      TH1D * AK5PF_central_PHI        ;
      TH1D * AK5PF_central_ETA        ;
      TH1D * AK5PF_central_RAP        ;
      TH1D * AK5PF_central_MASS       ;
      TH1D * AK5PF_central_NCONST     ;
      TH1D * AK5PF_central_AREA       ;
      TH1D * AK5PF_central_CH_MULT    ;
      TH1D * AK5PF_central_NE_MULT    ;
      TH1D * AK5PF_central_CHEF       ;
      TH1D * AK5PF_central_NHEF       ;
      TH1D * AK5PF_central_CEEF       ;
      TH1D * AK5PF_central_NEEF       ;
      TH1D * AK5PF_central_CMEF       ;
      TH1D * AK5PF_central_CSV        ;
      TH1D * AK5PF_central_ISV        ;
      TH1D * AK5PF_central_PUID       ;
      TH1D * AK5PF_mideta_PT          ;
      TH1D * AK5PF_mideta_PHI         ;
      TH1D * AK5PF_mideta_ETA         ;
      TH1D * AK5PF_mideta_RAP         ;
      TH1D * AK5PF_mideta_MASS        ;
      TH1D * AK5PF_mideta_NCONST      ;
      TH1D * AK5PF_mideta_AREA        ;
      TH1D * AK5PF_mideta_CH_MULT     ;
      TH1D * AK5PF_mideta_NE_MULT     ;
      TH1D * AK5PF_mideta_CHEF        ;
      TH1D * AK5PF_mideta_NHEF        ;
      TH1D * AK5PF_mideta_CEEF        ;
      TH1D * AK5PF_mideta_NEEF        ;
      TH1D * AK5PF_mideta_CMEF        ;
      TH1D * AK5PF_mideta_CSV         ;
      TH1D * AK5PF_mideta_ISV         ;
      TH1D * AK5PF_mideta_PUID        ;
      TH1D * AK5PF_btagCSVM_PT        ;
      TH1D * AK5PF_btagCSVM_PHI       ;
      TH1D * AK5PF_btagCSVM_ETA       ;
      TH1D * AK5PF_btagCSVM_RAP       ;
      TH1D * AK5PF_btagCSVM_MASS      ;
      TH1D * AK5PF_btagCSVM_NCONST    ;
      TH1D * AK5PF_btagCSVM_AREA      ;
      TH1D * AK5PF_btagCSVM_CH_MULT   ;
      TH1D * AK5PF_btagCSVM_NE_MULT   ;
      TH1D * AK5PF_btagCSVM_CHEF      ;
      TH1D * AK5PF_btagCSVM_NHEF      ;
      TH1D * AK5PF_btagCSVM_CEEF      ;
      TH1D * AK5PF_btagCSVM_NEEF      ;
      TH1D * AK5PF_btagCSVM_CMEF      ;
      TH1D * AK5PF_btagCSVM_CSV       ;
      TH1D * AK5PF_btagCSVM_ISV       ;
      TH1D * AK5PF_btagCSVM_PUID      ;

      TH1D * AK5PF_pt30_PT             ; 
      TH1D * AK5PF_pt30_PHI            ; 
      TH1D * AK5PF_pt30_ETA            ; 
      TH1D * AK5PF_pt30_RAP            ; 
      TH1D * AK5PF_pt30_MASS           ; 
      TH1D * AK5PF_pt30_NCONST         ; 
      TH1D * AK5PF_pt30_AREA           ; 
      TH1D * AK5PF_pt30_CH_MULT        ; 
      TH1D * AK5PF_pt30_NE_MULT        ; 
      TH1D * AK5PF_pt30_CHEF           ; 
      TH1D * AK5PF_pt30_NHEF           ; 
      TH1D * AK5PF_pt30_CEEF           ; 
      TH1D * AK5PF_pt30_NEEF           ; 
      TH1D * AK5PF_pt30_CMEF           ; 
      TH1D * AK5PF_pt30_CSV            ; 
      TH1D * AK5PF_pt30_ISV            ; 
      TH1D * AK5PF_pt30_PUID           ; 
      TH1D * AK5PF_pt100_PT            ;  
      TH1D * AK5PF_pt100_PHI           ;  
      TH1D * AK5PF_pt100_ETA           ;  
      TH1D * AK5PF_pt100_RAP           ;  
      TH1D * AK5PF_pt100_MASS          ;  
      TH1D * AK5PF_pt100_NCONST        ;  
      TH1D * AK5PF_pt100_AREA          ;  
      TH1D * AK5PF_pt100_CH_MULT       ;  
      TH1D * AK5PF_pt100_NE_MULT       ;  
      TH1D * AK5PF_pt100_CHEF          ;  
      TH1D * AK5PF_pt100_NHEF          ;  
      TH1D * AK5PF_pt100_CEEF          ;  
      TH1D * AK5PF_pt100_NEEF          ;  
      TH1D * AK5PF_pt100_CMEF          ;  
      TH1D * AK5PF_pt100_CSV           ;  
      TH1D * AK5PF_pt100_ISV           ;  
      TH1D * AK5PF_pt100_PUID          ;  
      TH1D * AK5PF_pt500_PT            ;  
      TH1D * AK5PF_pt500_PHI           ;  
      TH1D * AK5PF_pt500_ETA           ;  
      TH1D * AK5PF_pt500_RAP           ;  
      TH1D * AK5PF_pt500_MASS          ;  
      TH1D * AK5PF_pt500_NCONST        ;  
      TH1D * AK5PF_pt500_AREA          ;  
      TH1D * AK5PF_pt500_CH_MULT       ;  
      TH1D * AK5PF_pt500_NE_MULT       ;  
      TH1D * AK5PF_pt500_CHEF          ;  
      TH1D * AK5PF_pt500_NHEF          ;  
      TH1D * AK5PF_pt500_CEEF          ;  
      TH1D * AK5PF_pt500_NEEF          ;  
      TH1D * AK5PF_pt500_CMEF          ;  
      TH1D * AK5PF_pt500_CSV           ;  
      TH1D * AK5PF_pt500_ISV           ;  
      TH1D * AK5PF_pt500_PUID          ;  
      TH1D * AK5PF_pt30eta2p4_PT       ;  
      TH1D * AK5PF_pt30eta2p4_PHI      ;  
      TH1D * AK5PF_pt30eta2p4_ETA      ;  
      TH1D * AK5PF_pt30eta2p4_RAP      ;  
      TH1D * AK5PF_pt30eta2p4_MASS     ;  
      TH1D * AK5PF_pt30eta2p4_NCONST   ;  
      TH1D * AK5PF_pt30eta2p4_AREA     ;  
      TH1D * AK5PF_pt30eta2p4_CH_MULT  ;  
      TH1D * AK5PF_pt30eta2p4_NE_MULT  ;  
      TH1D * AK5PF_pt30eta2p4_CHEF     ;  
      TH1D * AK5PF_pt30eta2p4_NHEF     ;  
      TH1D * AK5PF_pt30eta2p4_CEEF     ;  
      TH1D * AK5PF_pt30eta2p4_NEEF     ;  
      TH1D * AK5PF_pt30eta2p4_CMEF     ;  
      TH1D * AK5PF_pt30eta2p4_CSV      ;  
      TH1D * AK5PF_pt30eta2p4_ISV      ;  
      TH1D * AK5PF_pt30eta2p4_PUID     ;  

      TH1D * AK8PF_PT             ;
      TH1D * AK8PF_PHI            ;
      TH1D * AK8PF_ETA            ;
      TH1D * AK8PF_RAP            ;
      TH1D * AK8PF_MASS           ;
      TH1D * AK8PF_MASSPRUNED    ;  
      TH1D * AK8PF_MASSTRIMMED   ;  
      TH1D * AK8PF_MASSFILTERED   ;  
      TH1D * AK8PF_MASSTOP       ;  
      TH1D * AK8PF_NCONST       ;
      TH1D * AK8PF_AREA         ;
      TH1D * AK8PF_CH_MULT      ;
      TH1D * AK8PF_NE_MULT      ;
      TH1D * AK8PF_CHEF         ;
      TH1D * AK8PF_NHEF         ;
      TH1D * AK8PF_CEEF         ;
      TH1D * AK8PF_NEEF         ;
      TH1D * AK8PF_CMEF         ;

      TH1D * MET_PT             ;  
      TH1D * MET_PHI            ;  
      TH1D * MET_SUMET          ;  
      TH1D * MET_GENMET         ;  

      TH1D * PF_CHARGE         ;    
      TH1D * PF_PT             ;    
      TH1D * PF_ETA            ;    
      TH1D * PF_PHI            ;    
      TH1D * PF_NEUTRAL_PT     ;         
      TH1D * PF_NEUTRAL_ETA    ;         
      TH1D * PF_NEUTRAL_PHI    ;         
             
      TH1D * PF_CHARGED_PT     ;         
      TH1D * PF_CHARGED_ETA    ;         
      TH1D * PF_CHARGED_PHI    ;         
             
      TH1D * PF_PV_PT          ;      
      TH1D * PF_PV_CHARGE      ;      
      TH1D * PF_PV_ETA         ;      
      TH1D * PF_PV_PHI         ;      
             
      TH1D * PF_PU_PT          ;      
      TH1D * PF_PU_CHARGE      ;      
      TH1D * PF_PU_ETA         ;      
      TH1D * PF_PU_PHI         ;      


      TH1D * PF_MULT                                 ;
      TH1D * PF_MULT_fromPV0                         ;
      TH1D * PF_MULT_fromPV1                         ;
      TH1D * PF_MULT_NEUTRAL                         ;
      TH1D * PF_MULT_CHARGED                         ;
      TH1D * PF_MULT_chargedHadron                   ;
      TH1D * PF_MULT_neutralHadron                   ;
      TH1D * PF_MULT_gamma                           ;
      TH1D * PF_MULT_electron                        ;
      TH1D * PF_MULT_muon                            ;
      TH1D * PF_MULT_forwardHadron                   ;
      TH1D * PF_MULT_forwardEgamma                   ;
      TH1D * PF_MULT_noID                            ;

      TH1D * PF_MULT_pt0p2eta2p5fromPV                ; 
      TH1D * PF_MULT_pt0p2eta2p5fromPV_CHARGED        ; 
      TH1D * PF_MULT_pt0p2eta2p5fromPV_NEUTRAL        ; 
      TH1D * PF_MULT_pt0p2eta2p5fromPV_chargedHadron  ; 
      TH1D * PF_MULT_pt0p2eta2p5fromPV_neutralHadron  ; 
      TH1D * PF_MULT_pt0p2eta2p5fromPV_gamma          ; 
      TH1D * PF_MULT_pt0p2eta2p5fromPV_electron       ; 
      TH1D * PF_MULT_pt0p2eta2p5fromPV_muon           ; 
      TH1D * PF_MULT_pt0p2eta2p5fromPV_forwardHadron  ; 
      TH1D * PF_MULT_pt0p2eta2p5fromPV_forwardEgamma  ; 
      TH1D * PF_MULT_pt0p2eta2p5fromPV_noID           ; 
      TH1D * PF_MULT_pt0p2fromPV                      ; 
      TH1D * PF_MULT_pt0p2fromPV_CHARGED              ; 
      TH1D * PF_MULT_pt0p2fromPV_NEUTRAL              ; 
      TH1D * PF_MULT_pt0p2fromPV_chargedHadron        ; 
      TH1D * PF_MULT_pt0p2fromPV_neutralHadron        ; 
      TH1D * PF_MULT_pt0p2fromPV_gamma                ; 
      TH1D * PF_MULT_pt0p2fromPV_electron             ; 
      TH1D * PF_MULT_pt0p2fromPV_muon                 ; 
      TH1D * PF_MULT_pt0p2fromPV_forwardHadron        ; 
      TH1D * PF_MULT_pt0p2fromPV_forwardEgamma        ; 
      TH1D * PF_MULT_pt0p2fromPV_noID                 ; 
      TH1D * PF_MULT_fromPV                           ; 
      TH1D * PF_MULT_fromPV_CHARGED                   ; 
      TH1D * PF_MULT_fromPV_NEUTRAL                   ; 
      TH1D * PF_MULT_fromPV_chargedHadron             ; 
      TH1D * PF_MULT_fromPV_neutralHadron             ; 
      TH1D * PF_MULT_fromPV_gamma                     ; 
      TH1D * PF_MULT_fromPV_electron                  ; 
      TH1D * PF_MULT_fromPV_muon                      ; 
      TH1D * PF_MULT_fromPV_forwardHadron             ; 
      TH1D * PF_MULT_fromPV_forwardEgamma             ; 
      TH1D * PF_MULT_fromPV_noID                      ; 
      TH1D * PF_MULT_pt2fromPV                        ; 
      TH1D * PF_MULT_pt2fromPV_CHARGED                ; 
      TH1D * PF_MULT_pt2fromPV_NEUTRAL                ; 
      TH1D * PF_MULT_pt2fromPV_chargedHadron          ; 
      TH1D * PF_MULT_pt2fromPV_neutralHadron          ; 
      TH1D * PF_MULT_pt2fromPV_gamma                  ; 
      TH1D * PF_MULT_pt2fromPV_electron               ; 
      TH1D * PF_MULT_pt2fromPV_muon                   ; 
      TH1D * PF_MULT_pt2fromPV_forwardHadron          ; 
      TH1D * PF_MULT_pt2fromPV_forwardEgamma          ; 
      TH1D * PF_MULT_pt2fromPV_noID                   ; 
      
      TH1D * PF_pt0p2eta2p5fromPV1_chargedHadron_PT  ;           
      TH1D * PF_pt0p2eta2p5fromPV1_chargedHadron_ETA ;           
      TH1D * PF_pt0p2eta2p5fromPV1_chargedHadron_PHI ;           
      TH1D * PF_pt0p2eta2p5fromPV1_neutralHadron_PT  ;           
      TH1D * PF_pt0p2eta2p5fromPV1_neutralHadron_ETA ;           
      TH1D * PF_pt0p2eta2p5fromPV1_neutralHadron_PHI ;           
      TH1D * PF_pt0p2eta2p5fromPV1_gamma_PT          ;                 
      TH1D * PF_pt0p2eta2p5fromPV1_gamma_ETA         ;                 
      TH1D * PF_pt0p2eta2p5fromPV1_gamma_PHI         ;                 
      TH1D * PF_pt0p2eta2p5fromPV1_electron_PT       ;                    
      TH1D * PF_pt0p2eta2p5fromPV1_electron_ETA      ;                    
      TH1D * PF_pt0p2eta2p5fromPV1_electron_PHI      ;                    
      TH1D * PF_pt0p2eta2p5fromPV1_muon_PT           ;                
      TH1D * PF_pt0p2eta2p5fromPV1_muon_ETA          ;                
      TH1D * PF_pt0p2eta2p5fromPV1_muon_PHI          ;                
      TH1D * PF_pt0p2eta2p5fromPV1_forwardHadron_PT  ;           
      TH1D * PF_pt0p2eta2p5fromPV1_forwardHadron_ETA ;           
      TH1D * PF_pt0p2eta2p5fromPV1_forwardHadron_PHI ;           
      TH1D * PF_pt0p2eta2p5fromPV1_forwardEgamma_PT  ;           
      TH1D * PF_pt0p2eta2p5fromPV1_forwardEgamma_ETA ;           
      TH1D * PF_pt0p2eta2p5fromPV1_forwardEgamma_PHI ;           
      TH1D * PF_pt0p2eta2p5fromPV1_noID_PT           ;                    
      TH1D * PF_pt0p2eta2p5fromPV1_noID_ETA          ;                    
      TH1D * PF_pt0p2eta2p5fromPV1_noID_PHI          ;                    

      TH1D * PF_pt0p2fromPV1_chargedHadron_PT        ;           
      TH1D * PF_pt0p2fromPV1_chargedHadron_ETA       ;           
      TH1D * PF_pt0p2fromPV1_chargedHadron_PHI       ;           
      TH1D * PF_pt0p2fromPV1_neutralHadron_PT        ;           
      TH1D * PF_pt0p2fromPV1_neutralHadron_ETA       ;           
      TH1D * PF_pt0p2fromPV1_neutralHadron_PHI       ;           
      TH1D * PF_pt0p2fromPV1_gamma_PT                ;                 
      TH1D * PF_pt0p2fromPV1_gamma_ETA               ;                 
      TH1D * PF_pt0p2fromPV1_gamma_PHI               ;                 
      TH1D * PF_pt0p2fromPV1_electron_PT             ;                    
      TH1D * PF_pt0p2fromPV1_electron_ETA            ;                    
      TH1D * PF_pt0p2fromPV1_electron_PHI            ;                    
      TH1D * PF_pt0p2fromPV1_muon_PT                 ;                
      TH1D * PF_pt0p2fromPV1_muon_ETA                ;                
      TH1D * PF_pt0p2fromPV1_muon_PHI                ;                
      TH1D * PF_pt0p2fromPV1_forwardHadron_PT        ;           
      TH1D * PF_pt0p2fromPV1_forwardHadron_ETA       ;           
      TH1D * PF_pt0p2fromPV1_forwardHadron_PHI       ;           
      TH1D * PF_pt0p2fromPV1_forwardEgamma_PT        ;           
      TH1D * PF_pt0p2fromPV1_forwardEgamma_ETA       ;           
      TH1D * PF_pt0p2fromPV1_forwardEgamma_PHI       ;           
      TH1D * PF_pt0p2fromPV1_noID_PT                 ;                    
      TH1D * PF_pt0p2fromPV1_noID_ETA                ;                    
      TH1D * PF_pt0p2fromPV1_noID_PHI                ;                    

      TH1D * PF_pt0p2to2fromPV1_chargedHadron_PT     ;           
      TH1D * PF_pt0p2to2fromPV1_chargedHadron_ETA    ;           
      TH1D * PF_pt0p2to2fromPV1_chargedHadron_PHI    ;           
      TH1D * PF_pt0p2to2fromPV1_neutralHadron_PT     ;           
      TH1D * PF_pt0p2to2fromPV1_neutralHadron_ETA    ;           
      TH1D * PF_pt0p2to2fromPV1_neutralHadron_PHI    ;           
      TH1D * PF_pt0p2to2fromPV1_gamma_PT             ;                 
      TH1D * PF_pt0p2to2fromPV1_gamma_ETA            ;                 
      TH1D * PF_pt0p2to2fromPV1_gamma_PHI            ;                 
      TH1D * PF_pt0p2to2fromPV1_electron_PT          ;                    
      TH1D * PF_pt0p2to2fromPV1_electron_ETA         ;                    
      TH1D * PF_pt0p2to2fromPV1_electron_PHI         ;                    
      TH1D * PF_pt0p2to2fromPV1_muon_PT              ;                
      TH1D * PF_pt0p2to2fromPV1_muon_ETA             ;                
      TH1D * PF_pt0p2to2fromPV1_muon_PHI             ;                
      TH1D * PF_pt0p2to2fromPV1_forwardHadron_PT     ;           
      TH1D * PF_pt0p2to2fromPV1_forwardHadron_ETA    ;           
      TH1D * PF_pt0p2to2fromPV1_forwardHadron_PHI    ;           
      TH1D * PF_pt0p2to2fromPV1_forwardEgamma_PT     ;           
      TH1D * PF_pt0p2to2fromPV1_forwardEgamma_ETA    ;           
      TH1D * PF_pt0p2to2fromPV1_forwardEgamma_PHI    ;           
      TH1D * PF_pt0p2to2fromPV1_noID_PT              ;                    
      TH1D * PF_pt0p2to2fromPV1_noID_ETA             ;                    
      TH1D * PF_pt0p2to2fromPV1_noID_PHI             ;                    


      TH1D * PF_pt0p2eta2p5fromPV0_chargedHadron_PT  ;           
      TH1D * PF_pt0p2eta2p5fromPV0_chargedHadron_ETA ;           
      TH1D * PF_pt0p2eta2p5fromPV0_chargedHadron_PHI ;           
      TH1D * PF_pt0p2eta2p5fromPV0_neutralHadron_PT  ;           
      TH1D * PF_pt0p2eta2p5fromPV0_neutralHadron_ETA ;           
      TH1D * PF_pt0p2eta2p5fromPV0_neutralHadron_PHI ;           
      TH1D * PF_pt0p2eta2p5fromPV0_gamma_PT          ;                 
      TH1D * PF_pt0p2eta2p5fromPV0_gamma_ETA         ;                 
      TH1D * PF_pt0p2eta2p5fromPV0_gamma_PHI         ;                 
      TH1D * PF_pt0p2eta2p5fromPV0_electron_PT       ;                    
      TH1D * PF_pt0p2eta2p5fromPV0_electron_ETA      ;                    
      TH1D * PF_pt0p2eta2p5fromPV0_electron_PHI      ;                    
      TH1D * PF_pt0p2eta2p5fromPV0_muon_PT           ;                
      TH1D * PF_pt0p2eta2p5fromPV0_muon_ETA          ;                
      TH1D * PF_pt0p2eta2p5fromPV0_muon_PHI          ;                
      TH1D * PF_pt0p2eta2p5fromPV0_forwardHadron_PT  ;           
      TH1D * PF_pt0p2eta2p5fromPV0_forwardHadron_ETA ;           
      TH1D * PF_pt0p2eta2p5fromPV0_forwardHadron_PHI ;           
      TH1D * PF_pt0p2eta2p5fromPV0_forwardEgamma_PT  ;           
      TH1D * PF_pt0p2eta2p5fromPV0_forwardEgamma_ETA ;           
      TH1D * PF_pt0p2eta2p5fromPV0_forwardEgamma_PHI ;           
      TH1D * PF_pt0p2eta2p5fromPV0_noID_PT           ;                    
      TH1D * PF_pt0p2eta2p5fromPV0_noID_ETA          ;                    
      TH1D * PF_pt0p2eta2p5fromPV0_noID_PHI          ;                    

      TH1D * PF_pt0p2fromPV0_chargedHadron_PT        ;           
      TH1D * PF_pt0p2fromPV0_chargedHadron_ETA       ;           
      TH1D * PF_pt0p2fromPV0_chargedHadron_PHI       ;           
      TH1D * PF_pt0p2fromPV0_neutralHadron_PT        ;           
      TH1D * PF_pt0p2fromPV0_neutralHadron_ETA       ;           
      TH1D * PF_pt0p2fromPV0_neutralHadron_PHI       ;           
      TH1D * PF_pt0p2fromPV0_gamma_PT                ;                 
      TH1D * PF_pt0p2fromPV0_gamma_ETA               ;                 
      TH1D * PF_pt0p2fromPV0_gamma_PHI               ;                 
      TH1D * PF_pt0p2fromPV0_electron_PT             ;                    
      TH1D * PF_pt0p2fromPV0_electron_ETA            ;                    
      TH1D * PF_pt0p2fromPV0_electron_PHI            ;                    
      TH1D * PF_pt0p2fromPV0_muon_PT                 ;                
      TH1D * PF_pt0p2fromPV0_muon_ETA                ;                
      TH1D * PF_pt0p2fromPV0_muon_PHI                ;                
      TH1D * PF_pt0p2fromPV0_forwardHadron_PT        ;           
      TH1D * PF_pt0p2fromPV0_forwardHadron_ETA       ;           
      TH1D * PF_pt0p2fromPV0_forwardHadron_PHI       ;           
      TH1D * PF_pt0p2fromPV0_forwardEgamma_PT        ;           
      TH1D * PF_pt0p2fromPV0_forwardEgamma_ETA       ;           
      TH1D * PF_pt0p2fromPV0_forwardEgamma_PHI       ;           
      TH1D * PF_pt0p2fromPV0_noID_PT                 ;                    
      TH1D * PF_pt0p2fromPV0_noID_ETA                ;                    
      TH1D * PF_pt0p2fromPV0_noID_PHI                ;      

      TH1D * PFcheck_pt0p2fromPV1_gamma_ETA           ; 
      TH1D * PFcheck_pt0p2fromPV1_electron_ETA        ; 
      TH1D * PFcheck_pt0p2to1p0fromPV1_gamma_ETA      ; 
      TH1D * PFcheck_pt0p2to1p0fromPV1_electron_ETA   ; 
      TH1D * PFcheck_pt1p0to2p0fromPV1_gamma_ETA      ; 
      TH1D * PFcheck_pt1p0to2p0fromPV1_electron_ETA   ; 
      TH1D * PFcheck_pt2p0to5p0fromPV1_gamma_ETA      ; 
      TH1D * PFcheck_pt2p0to5p0fromPV1_electron_ETA   ; 
      TH1D * PFcheck_pt5p0to10p0fromPV1_gamma_ETA     ; 
      TH1D * PFcheck_pt5p0to10p0fromPV1_electron_ETA  ; 
      TH1D * PFcheck_pt10fromPV1_gamma_ETA            ; 
      TH1D * PFcheck_pt10fromPV1_electron_ETA         ;  


        TH1D * AK15FILT_PT                    ; 
      TH1D * AK15FILT_PHI                   ; 
      TH1D * AK15FILT_ETA                   ; 
      TH1D * AK15FILT_RAP                   ; 
      TH1D * AK15FILT_MASS                  ; 
      TH1D * AK15FILT_NCONST                ; 
      TH1D * AK15FILT_BDISC                 ; 
      TH1D * AK15FILT_AREA                  ; 
      TH1D * AK15FILT_NTRACKS               ; 
      TH1D * AK15FILT_FLAVOUR               ; 
      TH1D * AK15FILT_MASS_UNCORR           ; 
      TH1D * AK15FILT_MAXSUBJETBDISC        ; 
      TH1D * AK15FILT_MAXSUBJETBDISCFLAVOUR ; 

       TH1D * CMS_PT                    ; 
      TH1D * CMS_PHI                   ; 
      TH1D * CMS_ETA                   ; 
      TH1D * CMS_RAP                   ; 
      TH1D * CMS_MASS                  ; 
      TH1D * CMS_NCONST                ; 
      TH1D * CMS_BDISC                 ; 
      TH1D * CMS_AREA                  ; 
      TH1D * CMS_NTRACKS               ; 
      TH1D * CMS_FLAVOUR               ; 
      TH1D * CMS_MASS_UNCORR           ; 
      TH1D * CMS_MAXSUBJETBDISC        ; 
      TH1D * CMS_MAXSUBJETBDISCFLAVOUR ; 
      TH1D * CMS_GROOMMASS             ;
      TH1D * CMS_MINMASS               ;

           TH1D * HEP_PT                       ; 
      TH1D * HEP_PHI                      ; 
      TH1D * HEP_ETA                      ; 
      TH1D * HEP_RAP                      ; 
      TH1D * HEP_MASS                     ; 
      TH1D * HEP_NCONST                   ; 
      TH1D * HEP_BDISC                    ; 
      TH1D * HEP_AREA                     ; 
      TH1D * HEP_NTRACKS                  ; 
      TH1D * HEP_FLAVOUR                  ; 
      TH1D * HEP_MASS_UNCORR              ; 
      TH1D * HEP_MAXSUBJETBDISC           ; 
      TH1D * HEP_MAXSUBJETBDISCFLAVOUR    ; 
      TH1D * HEP_M123                     ;
      TH1D * HEP_M12                      ;
      TH1D * HEP_M13                      ;
      TH1D * HEP_M23                      ;
      TH1D * HEP_M23M123                  ;
      TH1D * HEP_ATANM13M12               ;
      TH2F * HEP_ATANM13M12_M23M123       ;




};

AnalyzeMiniPlusSubstructure::AnalyzeMiniPlusSubstructure(const edm::ParameterSet& iConfig):
    vtxToken_(consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vertices"))),
    muonToken_(consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons"))),
    electronToken_(consumes<pat::ElectronCollection>(iConfig.getParameter<edm::InputTag>("electrons"))),
    tauToken_(consumes<pat::TauCollection>(iConfig.getParameter<edm::InputTag>("taus"))),
    photonToken_(consumes<pat::PhotonCollection>(iConfig.getParameter<edm::InputTag>("photons"))),
    jetToken_(consumes<pat::JetCollection>(iConfig.getParameter<edm::InputTag>("jets"))),
    fatjetToken_(consumes<pat::JetCollection>(iConfig.getParameter<edm::InputTag>("fatjets"))),
    metToken_(consumes<pat::METCollection>(iConfig.getParameter<edm::InputTag>("mets"))),
    pfToken_(consumes<pat::PackedCandidateCollection>(iConfig.getParameter<edm::InputTag>("pfCands")))
{

  edm::Service<TFileService> fs;
 
 
 
  NVTX_GOOD             = fs->make<TH1D>("NVTX_GOOD"      ,"", 80,0,80     );
  NVTX_ALL              = fs->make<TH1D>("NVTX_ALL"       ,"", 80,0,80     );
  RHO                   = fs->make<TH1D>("RHO"            ,"", 200,0,100   );

  MU_PT                 = fs->make<TH1D>("MU_PT"      ,"", 200,0,1000   );
  MU_ETA                = fs->make<TH1D>("MU_ETA"     ,"", 100,-4,4  );
  MU_PHI                = fs->make<TH1D>("MU_PHI"     ,"", 100,-3.2,3.2   );
  MU_dzPV               = fs->make<TH1D>("MU_dzPV"    ,"", 100,0,1  );  
  MU_ISLOOSE            = fs->make<TH1D>("MU_ISLOOSE" ,"", 2,0,2  );  
  MU_ISTIGHT            = fs->make<TH1D>("MU_ISTIGHT" ,"", 2,0,2  );  

  EL_PT                 = fs->make<TH1D>("EL_PT"                ,"",200,0,1000   );
  EL_ETA                = fs->make<TH1D>("EL_ETA"               ,"",100,-4,4  );
  EL_PHI                = fs->make<TH1D>("EL_PHI"               ,"",100,-3.2,3.2   );
  EL_GSF_NLOSTHITS      = fs->make<TH1D>("EL_GSF_NLOSTHITS"     ,"",8,0,8  );
  EL_SCETA              = fs->make<TH1D>("EL_SCETA"             ,"",100,-4,4    );
  EL_SIETAIETA          = fs->make<TH1D>("EL_SIETAIETA"         ,"",200,0,0.12 );
  EL_full5x5SIETAIETA   = fs->make<TH1D>("EL_full5x5SIETAIETA"  ,"",200,0,0.12 );
  EL_PASSCONERSIONVETO  = fs->make<TH1D>("EL_PASSCONERSIONVETO"  ,"",2,0,2    );

  PHO_PT                = fs->make<TH1D>("PHO_PT"               ,"",200,0,1000   );
  PHO_ETA               = fs->make<TH1D>("PHO_ETA"              ,"",100,-4,4  );
  PHO_PHI               = fs->make<TH1D>("PHO_PHI"              ,"",100,-3.2,3.2   );
  PHO_CHISOoverPT       = fs->make<TH1D>("PHO_CHISOoverPT"      ,"",100,0,0.4  );
  PHO_SCETA             = fs->make<TH1D>("PHO_SCETA"            ,"",100,-4,4    );
  PHO_SIETAIETA         = fs->make<TH1D>("PHO_SIETAIETA"        ,"",200,0,0.12    );
  PHO_full5x5SIETAIETA  = fs->make<TH1D>("PHO_full5x5SIETAIETA" ,"",200,0,0.12    );

  TAU_PT                = fs->make<TH1D>("TAU_PT"               ,"",200,0,600 ); 
  TAU_PHI               = fs->make<TH1D>("TAU_PHI"              ,"",100,-3.2,3.2  ); 
  TAU_ETA               = fs->make<TH1D>("TAU_ETA"              ,"",100,-4,4  ); 
  TAU_DXYSIG            = fs->make<TH1D>("TAU_DXYSIG"           ,"",100,0,20); 
  TAU_TAUID             = fs->make<TH1D>("TAU_TAUID"            ,"",2,0,2); 
  TAU_LEADCANDPT        = fs->make<TH1D>("TAU_LEADCANDPT"       ,"",200,0,500 ); 
  TAU_LEADCANDPDGID     = fs->make<TH1D>("TAU_LEADCANDPDGID"    ,"",200,-100,100 ); 

  AK5PF_PT              = fs->make<TH1D>("AK5PF_PT"             ,"",500,0,4000   );
  AK5PF_PHI             = fs->make<TH1D>("AK5PF_PHI"            ,"",100,-3.2,3.2 );
  AK5PF_ETA             = fs->make<TH1D>("AK5PF_ETA"            ,"",100,-4,4     );
  AK5PF_RAP             = fs->make<TH1D>("AK5PF_RAP"            ,"",100,-4,4     );
  AK5PF_MASS            = fs->make<TH1D>("AK5PF_MASS"           ,"",100,0,500   );
  AK5PF_NCONST          = fs->make<TH1D>("AK5PF_NCONST"         ,"",1000,0,1000  );
  AK5PF_AREA            = fs->make<TH1D>("AK5PF_AREA"           ,"",100,0,1     );
  AK5PF_CH_MULT         = fs->make<TH1D>("AK5PF_CH_MULT"        ,"",500,0,500   );    
  AK5PF_NE_MULT         = fs->make<TH1D>("AK5PF_NE_MULT"        ,"",500,0,500   );    
  AK5PF_CHEF            = fs->make<TH1D>("AK5PF_CHEF"           ,"",200,0,1     );    
  AK5PF_NHEF            = fs->make<TH1D>("AK5PF_NHEF"           ,"",200,0,1     );    
  AK5PF_CEEF            = fs->make<TH1D>("AK5PF_CEEF"           ,"",200,0,1     );    
  AK5PF_NEEF            = fs->make<TH1D>("AK5PF_NEEF"           ,"",200,0,1     );    
  AK5PF_CMEF            = fs->make<TH1D>("AK5PF_CMEF"           ,"",200,0,1     );
  AK5PF_CSV             = fs->make<TH1D>("AK5PF_CSV"            ,"",100,0,1     );
  AK5PF_ISV             = fs->make<TH1D>("AK5PF_ISV"            ,"",100,0,1     );
  AK5PF_PUID            = fs->make<TH1D>("AK5PF_PUID"           ,"",100,-1,1     );


  AK5PF_PU_PT              = fs->make<TH1D>("AK5PF_PU_PT"             ,"",500,0,4000   );
  AK5PF_PU_PHI             = fs->make<TH1D>("AK5PF_PU_PHI"            ,"",100,-3.2,3.2 );
  AK5PF_PU_ETA             = fs->make<TH1D>("AK5PF_PU_ETA"            ,"",100,-4,4     );
  AK5PF_PU_RAP             = fs->make<TH1D>("AK5PF_PU_RAP"            ,"",100,-4,4     );
  AK5PF_PU_MASS            = fs->make<TH1D>("AK5PF_PU_MASS"           ,"",100,0,500   );
  AK5PF_PU_NCONST          = fs->make<TH1D>("AK5PF_PU_NCONST"         ,"",1000,0,1000  );
  AK5PF_PU_AREA            = fs->make<TH1D>("AK5PF_PU_AREA"           ,"",100,0,1     );
  AK5PF_PU_CH_MULT         = fs->make<TH1D>("AK5PF_PU_CH_MULT"        ,"",500,0,500   );    
  AK5PF_PU_NE_MULT         = fs->make<TH1D>("AK5PF_PU_NE_MULT"        ,"",500,0,500   );    
  AK5PF_PU_CHEF            = fs->make<TH1D>("AK5PF_PU_CHEF"           ,"",200,0,1     );    
  AK5PF_PU_NHEF            = fs->make<TH1D>("AK5PF_PU_NHEF"           ,"",200,0,1     );    
  AK5PF_PU_CEEF            = fs->make<TH1D>("AK5PF_PU_CEEF"           ,"",200,0,1     );    
  AK5PF_PU_NEEF            = fs->make<TH1D>("AK5PF_PU_NEEF"           ,"",200,0,1     );    
  AK5PF_PU_CMEF            = fs->make<TH1D>("AK5PF_PU_CMEF"           ,"",200,0,1     );
  AK5PF_PU_CSV             = fs->make<TH1D>("AK5PF_PU_CSV"            ,"",100,0,1     );
  AK5PF_PU_ISV             = fs->make<TH1D>("AK5PF_PU_ISV"            ,"",100,0,1     );
  AK5PF_PU_PUID            = fs->make<TH1D>("AK5PF_PU_PUID"           ,"",100,-1,1     );


  AK5PF_PUID_PT              = fs->make<TH1D>("AK5PF_PUID_PT"             ,"",500,0,4000   );
  AK5PF_PUID_PHI             = fs->make<TH1D>("AK5PF_PUID_PHI"            ,"",100,-3.2,3.2 );
  AK5PF_PUID_ETA             = fs->make<TH1D>("AK5PF_PUID_ETA"            ,"",100,-4,4     );
  AK5PF_PUID_RAP             = fs->make<TH1D>("AK5PF_PUID_RAP"            ,"",100,-4,4     );
  AK5PF_PUID_MASS            = fs->make<TH1D>("AK5PF_PUID_MASS"           ,"",100,0,500   );
  AK5PF_PUID_NCONST          = fs->make<TH1D>("AK5PF_PUID_NCONST"         ,"",1000,0,1000  );
  AK5PF_PUID_AREA            = fs->make<TH1D>("AK5PF_PUID_AREA"           ,"",100,0,1     );
  AK5PF_PUID_CH_MULT         = fs->make<TH1D>("AK5PF_PUID_CH_MULT"        ,"",500,0,500   );    
  AK5PF_PUID_NE_MULT         = fs->make<TH1D>("AK5PF_PUID_NE_MULT"        ,"",500,0,500   );    
  AK5PF_PUID_CHEF            = fs->make<TH1D>("AK5PF_PUID_CHEF"           ,"",200,0,1     );    
  AK5PF_PUID_NHEF            = fs->make<TH1D>("AK5PF_PUID_NHEF"           ,"",200,0,1     );    
  AK5PF_PUID_CEEF            = fs->make<TH1D>("AK5PF_PUID_CEEF"           ,"",200,0,1     );    
  AK5PF_PUID_NEEF            = fs->make<TH1D>("AK5PF_PUID_NEEF"           ,"",200,0,1     );    
  AK5PF_PUID_CMEF            = fs->make<TH1D>("AK5PF_PUID_CMEF"           ,"",200,0,1     );
  AK5PF_PUID_CSV             = fs->make<TH1D>("AK5PF_PUID_CSV"            ,"",100,0,1     );
  AK5PF_PUID_ISV             = fs->make<TH1D>("AK5PF_PUID_ISV"            ,"",100,0,1     );
  AK5PF_PUID_PUID            = fs->make<TH1D>("AK5PF_PUID_PUID"           ,"",100,-1,1     );


  AK5PF_lowPT_PT              = fs->make<TH1D>("AK5PF_lowPT_PT"             ,"",500,0,4000   );
  AK5PF_lowPT_PHI             = fs->make<TH1D>("AK5PF_lowPT_PHI"            ,"",100,-3.2,3.2 );
  AK5PF_lowPT_ETA             = fs->make<TH1D>("AK5PF_lowPT_ETA"            ,"",100,-4,4     );
  AK5PF_lowPT_RAP             = fs->make<TH1D>("AK5PF_lowPT_RAP"            ,"",100,-4,4     );
  AK5PF_lowPT_MASS            = fs->make<TH1D>("AK5PF_lowPT_MASS"           ,"",100,0,500   );
  AK5PF_lowPT_NCONST          = fs->make<TH1D>("AK5PF_lowPT_NCONST"         ,"",1000,0,1000  );
  AK5PF_lowPT_AREA            = fs->make<TH1D>("AK5PF_lowPT_AREA"           ,"",100,0,1     );
  AK5PF_lowPT_CH_MULT         = fs->make<TH1D>("AK5PF_lowPT_CH_MULT"        ,"",500,0,500   );    
  AK5PF_lowPT_NE_MULT         = fs->make<TH1D>("AK5PF_lowPT_NE_MULT"        ,"",500,0,500   );    
  AK5PF_lowPT_CHEF            = fs->make<TH1D>("AK5PF_lowPT_CHEF"           ,"",200,0,1     );    
  AK5PF_lowPT_NHEF            = fs->make<TH1D>("AK5PF_lowPT_NHEF"           ,"",200,0,1     );    
  AK5PF_lowPT_CEEF            = fs->make<TH1D>("AK5PF_lowPT_CEEF"           ,"",200,0,1     );    
  AK5PF_lowPT_NEEF            = fs->make<TH1D>("AK5PF_lowPT_NEEF"           ,"",200,0,1     );    
  AK5PF_lowPT_CMEF            = fs->make<TH1D>("AK5PF_lowPT_CMEF"           ,"",200,0,1     );
  AK5PF_lowPT_CSV             = fs->make<TH1D>("AK5PF_lowPT_CSV"            ,"",100,0,1     );
  AK5PF_lowPT_ISV             = fs->make<TH1D>("AK5PF_lowPT_ISV"            ,"",100,0,1     );
  AK5PF_lowPT_PUID            = fs->make<TH1D>("AK5PF_lowPT_PUID"           ,"",100,-1,1     );

  AK5PF_pt30_PT              = fs->make<TH1D>("AK5PF_pt30_PT"             ,"",500,0,4000   );
  AK5PF_pt30_PHI             = fs->make<TH1D>("AK5PF_pt30_PHI"            ,"",100,-3.2,3.2 );
  AK5PF_pt30_ETA             = fs->make<TH1D>("AK5PF_pt30_ETA"            ,"",100,-4,4     );
  AK5PF_pt30_RAP             = fs->make<TH1D>("AK5PF_pt30_RAP"            ,"",100,-4,4     );
  AK5PF_pt30_MASS            = fs->make<TH1D>("AK5PF_pt30_MASS"           ,"",100,0,500   );
  AK5PF_pt30_NCONST          = fs->make<TH1D>("AK5PF_pt30_NCONST"         ,"",1000,0,1000  );
  AK5PF_pt30_AREA            = fs->make<TH1D>("AK5PF_pt30_AREA"           ,"",100,0,1     );
  AK5PF_pt30_CH_MULT         = fs->make<TH1D>("AK5PF_pt30_CH_MULT"        ,"",500,0,500   );    
  AK5PF_pt30_NE_MULT         = fs->make<TH1D>("AK5PF_pt30_NE_MULT"        ,"",500,0,500   );    
  AK5PF_pt30_CHEF            = fs->make<TH1D>("AK5PF_pt30_CHEF"           ,"",200,0,1     );    
  AK5PF_pt30_NHEF            = fs->make<TH1D>("AK5PF_pt30_NHEF"           ,"",200,0,1     );    
  AK5PF_pt30_CEEF            = fs->make<TH1D>("AK5PF_pt30_CEEF"           ,"",200,0,1     );    
  AK5PF_pt30_NEEF            = fs->make<TH1D>("AK5PF_pt30_NEEF"           ,"",200,0,1     );    
  AK5PF_pt30_CMEF            = fs->make<TH1D>("AK5PF_pt30_CMEF"           ,"",200,0,1     );
  AK5PF_pt30_CSV             = fs->make<TH1D>("AK5PF_pt30_CSV"            ,"",100,0,1     );
  AK5PF_pt30_ISV             = fs->make<TH1D>("AK5PF_pt30_ISV"            ,"",100,0,1     );
  AK5PF_pt30_PUID            = fs->make<TH1D>("AK5PF_pt30_PUID"           ,"",100,-1,1     );

  AK5PF_pt100_PT              = fs->make<TH1D>("AK5PF_pt100_PT"             ,"",500,0,4000   );
  AK5PF_pt100_PHI             = fs->make<TH1D>("AK5PF_pt100_PHI"            ,"",100,-3.2,3.2 );
  AK5PF_pt100_ETA             = fs->make<TH1D>("AK5PF_pt100_ETA"            ,"",100,-4,4     );
  AK5PF_pt100_RAP             = fs->make<TH1D>("AK5PF_pt100_RAP"            ,"",100,-4,4     );
  AK5PF_pt100_MASS            = fs->make<TH1D>("AK5PF_pt100_MASS"           ,"",100,0,500   );
  AK5PF_pt100_NCONST          = fs->make<TH1D>("AK5PF_pt100_NCONST"         ,"",1000,0,1000  );
  AK5PF_pt100_AREA            = fs->make<TH1D>("AK5PF_pt100_AREA"           ,"",100,0,1     );
  AK5PF_pt100_CH_MULT         = fs->make<TH1D>("AK5PF_pt100_CH_MULT"        ,"",500,0,500   );    
  AK5PF_pt100_NE_MULT         = fs->make<TH1D>("AK5PF_pt100_NE_MULT"        ,"",500,0,500   );    
  AK5PF_pt100_CHEF            = fs->make<TH1D>("AK5PF_pt100_CHEF"           ,"",200,0,1     );    
  AK5PF_pt100_NHEF            = fs->make<TH1D>("AK5PF_pt100_NHEF"           ,"",200,0,1     );    
  AK5PF_pt100_CEEF            = fs->make<TH1D>("AK5PF_pt100_CEEF"           ,"",200,0,1     );    
  AK5PF_pt100_NEEF            = fs->make<TH1D>("AK5PF_pt100_NEEF"           ,"",200,0,1     );    
  AK5PF_pt100_CMEF            = fs->make<TH1D>("AK5PF_pt100_CMEF"           ,"",200,0,1     );
  AK5PF_pt100_CSV             = fs->make<TH1D>("AK5PF_pt100_CSV"            ,"",100,0,1     );
  AK5PF_pt100_ISV             = fs->make<TH1D>("AK5PF_pt100_ISV"            ,"",100,0,1     );
  AK5PF_pt100_PUID            = fs->make<TH1D>("AK5PF_pt100_PUID"           ,"",100,-1,1     );

  AK5PF_pt500_PT              = fs->make<TH1D>("AK5PF_pt500_PT"             ,"",500,0,4000   );
  AK5PF_pt500_PHI             = fs->make<TH1D>("AK5PF_pt500_PHI"            ,"",100,-3.2,3.2 );
  AK5PF_pt500_ETA             = fs->make<TH1D>("AK5PF_pt500_ETA"            ,"",100,-4,4     );
  AK5PF_pt500_RAP             = fs->make<TH1D>("AK5PF_pt500_RAP"            ,"",100,-4,4     );
  AK5PF_pt500_MASS            = fs->make<TH1D>("AK5PF_pt500_MASS"           ,"",100,0,500   );
  AK5PF_pt500_NCONST          = fs->make<TH1D>("AK5PF_pt500_NCONST"         ,"",1000,0,1000  );
  AK5PF_pt500_AREA            = fs->make<TH1D>("AK5PF_pt500_AREA"           ,"",100,0,1     );
  AK5PF_pt500_CH_MULT         = fs->make<TH1D>("AK5PF_pt500_CH_MULT"        ,"",500,0,500   );    
  AK5PF_pt500_NE_MULT         = fs->make<TH1D>("AK5PF_pt500_NE_MULT"        ,"",500,0,500   );    
  AK5PF_pt500_CHEF            = fs->make<TH1D>("AK5PF_pt500_CHEF"           ,"",200,0,1     );    
  AK5PF_pt500_NHEF            = fs->make<TH1D>("AK5PF_pt500_NHEF"           ,"",200,0,1     );    
  AK5PF_pt500_CEEF            = fs->make<TH1D>("AK5PF_pt500_CEEF"           ,"",200,0,1     );    
  AK5PF_pt500_NEEF            = fs->make<TH1D>("AK5PF_pt500_NEEF"           ,"",200,0,1     );    
  AK5PF_pt500_CMEF            = fs->make<TH1D>("AK5PF_pt500_CMEF"           ,"",200,0,1     );
  AK5PF_pt500_CSV             = fs->make<TH1D>("AK5PF_pt500_CSV"            ,"",100,0,1     );
  AK5PF_pt500_ISV             = fs->make<TH1D>("AK5PF_pt500_ISV"            ,"",100,0,1     );
  AK5PF_pt500_PUID            = fs->make<TH1D>("AK5PF_pt500_PUID"           ,"",100,-1,1     );

  AK5PF_pt30eta2p4_PT              = fs->make<TH1D>("AK5PF_pt30eta2p4_PT"             ,"",500,0,4000   );
  AK5PF_pt30eta2p4_PHI             = fs->make<TH1D>("AK5PF_pt30eta2p4_PHI"            ,"",100,-3.2,3.2 );
  AK5PF_pt30eta2p4_ETA             = fs->make<TH1D>("AK5PF_pt30eta2p4_ETA"            ,"",100,-4,4     );
  AK5PF_pt30eta2p4_RAP             = fs->make<TH1D>("AK5PF_pt30eta2p4_RAP"            ,"",100,-4,4     );
  AK5PF_pt30eta2p4_MASS            = fs->make<TH1D>("AK5PF_pt30eta2p4_MASS"           ,"",100,0,500   );
  AK5PF_pt30eta2p4_NCONST          = fs->make<TH1D>("AK5PF_pt30eta2p4_NCONST"         ,"",1000,0,1000  );
  AK5PF_pt30eta2p4_AREA            = fs->make<TH1D>("AK5PF_pt30eta2p4_AREA"           ,"",100,0,1     );
  AK5PF_pt30eta2p4_CH_MULT         = fs->make<TH1D>("AK5PF_pt30eta2p4_CH_MULT"        ,"",500,0,500   );    
  AK5PF_pt30eta2p4_NE_MULT         = fs->make<TH1D>("AK5PF_pt30eta2p4_NE_MULT"        ,"",500,0,500   );    
  AK5PF_pt30eta2p4_CHEF            = fs->make<TH1D>("AK5PF_pt30eta2p4_CHEF"           ,"",200,0,1     );    
  AK5PF_pt30eta2p4_NHEF            = fs->make<TH1D>("AK5PF_pt30eta2p4_NHEF"           ,"",200,0,1     );    
  AK5PF_pt30eta2p4_CEEF            = fs->make<TH1D>("AK5PF_pt30eta2p4_CEEF"           ,"",200,0,1     );    
  AK5PF_pt30eta2p4_NEEF            = fs->make<TH1D>("AK5PF_pt30eta2p4_NEEF"           ,"",200,0,1     );    
  AK5PF_pt30eta2p4_CMEF            = fs->make<TH1D>("AK5PF_pt30eta2p4_CMEF"           ,"",200,0,1     );
  AK5PF_pt30eta2p4_CSV             = fs->make<TH1D>("AK5PF_pt30eta2p4_CSV"            ,"",100,0,1     );
  AK5PF_pt30eta2p4_ISV             = fs->make<TH1D>("AK5PF_pt30eta2p4_ISV"            ,"",100,0,1     );
  AK5PF_pt30eta2p4_PUID            = fs->make<TH1D>("AK5PF_pt30eta2p4_PUID"           ,"",100,-1,1     );




  AK5PF_forward_PT              = fs->make<TH1D>("AK5PF_forward_PT"             ,"",500,0,4000   );
  AK5PF_forward_PHI             = fs->make<TH1D>("AK5PF_forward_PHI"            ,"",100,-3.2,3.2 );
  AK5PF_forward_ETA             = fs->make<TH1D>("AK5PF_forward_ETA"            ,"",100,-4,4     );
  AK5PF_forward_RAP             = fs->make<TH1D>("AK5PF_forward_RAP"            ,"",100,-4,4     );
  AK5PF_forward_MASS            = fs->make<TH1D>("AK5PF_forward_MASS"           ,"",100,0,500   );
  AK5PF_forward_NCONST          = fs->make<TH1D>("AK5PF_forward_NCONST"         ,"",1000,0,1000  );
  AK5PF_forward_AREA            = fs->make<TH1D>("AK5PF_forward_AREA"           ,"",100,0,1     );
  AK5PF_forward_CH_MULT         = fs->make<TH1D>("AK5PF_forward_CH_MULT"        ,"",500,0,500   );    
  AK5PF_forward_NE_MULT         = fs->make<TH1D>("AK5PF_forward_NE_MULT"        ,"",500,0,500   );    
  AK5PF_forward_CHEF            = fs->make<TH1D>("AK5PF_forward_CHEF"           ,"",200,0,1     );    
  AK5PF_forward_NHEF            = fs->make<TH1D>("AK5PF_forward_NHEF"           ,"",200,0,1     );    
  AK5PF_forward_CEEF            = fs->make<TH1D>("AK5PF_forward_CEEF"           ,"",200,0,1     );    
  AK5PF_forward_NEEF            = fs->make<TH1D>("AK5PF_forward_NEEF"           ,"",200,0,1     );    
  AK5PF_forward_CMEF            = fs->make<TH1D>("AK5PF_forward_CMEF"           ,"",200,0,1     );
  AK5PF_forward_CSV             = fs->make<TH1D>("AK5PF_forward_CSV"            ,"",100,0,1     );
  AK5PF_forward_ISV             = fs->make<TH1D>("AK5PF_forward_ISV"            ,"",100,0,1     );
  AK5PF_forward_PUID            = fs->make<TH1D>("AK5PF_forward_PUID"           ,"",100,-1,1     );


  AK5PF_central_PT              = fs->make<TH1D>("AK5PF_central_PT"             ,"",500,0,4000   );
  AK5PF_central_PHI             = fs->make<TH1D>("AK5PF_central_PHI"            ,"",100,-3.2,3.2 );
  AK5PF_central_ETA             = fs->make<TH1D>("AK5PF_central_ETA"            ,"",100,-4,4     );
  AK5PF_central_RAP             = fs->make<TH1D>("AK5PF_central_RAP"            ,"",100,-4,4     );
  AK5PF_central_MASS            = fs->make<TH1D>("AK5PF_central_MASS"           ,"",100,0,500   );
  AK5PF_central_NCONST          = fs->make<TH1D>("AK5PF_central_NCONST"         ,"",1000,0,1000  );
  AK5PF_central_AREA            = fs->make<TH1D>("AK5PF_central_AREA"           ,"",100,0,1     );
  AK5PF_central_CH_MULT         = fs->make<TH1D>("AK5PF_central_CH_MULT"        ,"",500,0,500   );    
  AK5PF_central_NE_MULT         = fs->make<TH1D>("AK5PF_central_NE_MULT"        ,"",500,0,500   );    
  AK5PF_central_CHEF            = fs->make<TH1D>("AK5PF_central_CHEF"           ,"",200,0,1     );    
  AK5PF_central_NHEF            = fs->make<TH1D>("AK5PF_central_NHEF"           ,"",200,0,1     );    
  AK5PF_central_CEEF            = fs->make<TH1D>("AK5PF_central_CEEF"           ,"",200,0,1     );    
  AK5PF_central_NEEF            = fs->make<TH1D>("AK5PF_central_NEEF"           ,"",200,0,1     );    
  AK5PF_central_CMEF            = fs->make<TH1D>("AK5PF_central_CMEF"           ,"",200,0,1     );
  AK5PF_central_CSV             = fs->make<TH1D>("AK5PF_central_CSV"            ,"",100,0,1     );
  AK5PF_central_ISV             = fs->make<TH1D>("AK5PF_central_ISV"            ,"",100,0,1     );
  AK5PF_central_PUID            = fs->make<TH1D>("AK5PF_central_PUID"           ,"",100,-1,1     );


  AK5PF_mideta_PT              = fs->make<TH1D>("AK5PF_mideta_PT"             ,"",500,0,4000   );
  AK5PF_mideta_PHI             = fs->make<TH1D>("AK5PF_mideta_PHI"            ,"",100,-3.2,3.2 );
  AK5PF_mideta_ETA             = fs->make<TH1D>("AK5PF_mideta_ETA"            ,"",100,-4,4     );
  AK5PF_mideta_RAP             = fs->make<TH1D>("AK5PF_mideta_RAP"            ,"",100,-4,4     );
  AK5PF_mideta_MASS            = fs->make<TH1D>("AK5PF_mideta_MASS"           ,"",100,0,500   );
  AK5PF_mideta_NCONST          = fs->make<TH1D>("AK5PF_mideta_NCONST"         ,"",1000,0,1000  );
  AK5PF_mideta_AREA            = fs->make<TH1D>("AK5PF_mideta_AREA"           ,"",100,0,1     );
  AK5PF_mideta_CH_MULT         = fs->make<TH1D>("AK5PF_mideta_CH_MULT"        ,"",500,0,500   );    
  AK5PF_mideta_NE_MULT         = fs->make<TH1D>("AK5PF_mideta_NE_MULT"        ,"",500,0,500   );    
  AK5PF_mideta_CHEF            = fs->make<TH1D>("AK5PF_mideta_CHEF"           ,"",200,0,1     );    
  AK5PF_mideta_NHEF            = fs->make<TH1D>("AK5PF_mideta_NHEF"           ,"",200,0,1     );    
  AK5PF_mideta_CEEF            = fs->make<TH1D>("AK5PF_mideta_CEEF"           ,"",200,0,1     );    
  AK5PF_mideta_NEEF            = fs->make<TH1D>("AK5PF_mideta_NEEF"           ,"",200,0,1     );    
  AK5PF_mideta_CMEF            = fs->make<TH1D>("AK5PF_mideta_CMEF"           ,"",200,0,1     );
  AK5PF_mideta_CSV             = fs->make<TH1D>("AK5PF_mideta_CSV"            ,"",100,0,1     );
  AK5PF_mideta_ISV             = fs->make<TH1D>("AK5PF_mideta_ISV"            ,"",100,0,1     );
  AK5PF_mideta_PUID            = fs->make<TH1D>("AK5PF_mideta_PUID"           ,"",100,-1,1     );


  AK5PF_btagCSVM_PT              = fs->make<TH1D>("AK5PF_btagCSVM_PT"             ,"",500,0,4000   );
  AK5PF_btagCSVM_PHI             = fs->make<TH1D>("AK5PF_btagCSVM_PHI"            ,"",100,-3.2,3.2 );
  AK5PF_btagCSVM_ETA             = fs->make<TH1D>("AK5PF_btagCSVM_ETA"            ,"",100,-4,4     );
  AK5PF_btagCSVM_RAP             = fs->make<TH1D>("AK5PF_btagCSVM_RAP"            ,"",100,-4,4     );
  AK5PF_btagCSVM_MASS            = fs->make<TH1D>("AK5PF_btagCSVM_MASS"           ,"",100,0,500   );
  AK5PF_btagCSVM_NCONST          = fs->make<TH1D>("AK5PF_btagCSVM_NCONST"         ,"",1000,0,1000  );
  AK5PF_btagCSVM_AREA            = fs->make<TH1D>("AK5PF_btagCSVM_AREA"           ,"",100,0,1     );
  AK5PF_btagCSVM_CH_MULT         = fs->make<TH1D>("AK5PF_btagCSVM_CH_MULT"        ,"",500,0,500   );    
  AK5PF_btagCSVM_NE_MULT         = fs->make<TH1D>("AK5PF_btagCSVM_NE_MULT"        ,"",500,0,500   );    
  AK5PF_btagCSVM_CHEF            = fs->make<TH1D>("AK5PF_btagCSVM_CHEF"           ,"",200,0,1     );    
  AK5PF_btagCSVM_NHEF            = fs->make<TH1D>("AK5PF_btagCSVM_NHEF"           ,"",200,0,1     );    
  AK5PF_btagCSVM_CEEF            = fs->make<TH1D>("AK5PF_btagCSVM_CEEF"           ,"",200,0,1     );    
  AK5PF_btagCSVM_NEEF            = fs->make<TH1D>("AK5PF_btagCSVM_NEEF"           ,"",200,0,1     );    
  AK5PF_btagCSVM_CMEF            = fs->make<TH1D>("AK5PF_btagCSVM_CMEF"           ,"",200,0,1     );
  AK5PF_btagCSVM_CSV             = fs->make<TH1D>("AK5PF_btagCSVM_CSV"            ,"",100,0,1     );
  AK5PF_btagCSVM_ISV             = fs->make<TH1D>("AK5PF_btagCSVM_ISV"            ,"",100,0,1     );
  AK5PF_btagCSVM_PUID            = fs->make<TH1D>("AK5PF_btagCSVM_PUID"           ,"",100,-1,1     );



  AK8PF_PT              = fs->make<TH1D>("AK8PF_PT"             ,"",500,0,4000   );
  AK8PF_PHI             = fs->make<TH1D>("AK8PF_PHI"            ,"",100,-3.2,3.2 );
  AK8PF_ETA             = fs->make<TH1D>("AK8PF_ETA"            ,"",100,-4,4     );
  AK8PF_RAP             = fs->make<TH1D>("AK8PF_RAP"            ,"",100,-4,4     );
  AK8PF_MASS            = fs->make<TH1D>("AK8PF_MASS"           ,"",100,0,500   );
  AK8PF_MASSPRUNED      = fs->make<TH1D>("AK8PF_MASSPRUNED"     ,"",100,0,500   );
  AK8PF_MASSTRIMMED     = fs->make<TH1D>("AK8PF_MASSTRIMMED"    ,"",100,0,500   );
  AK8PF_MASSFILTERED    = fs->make<TH1D>("AK8PF_MASSFILTERED"   ,"",100,0,500   );
  AK8PF_MASSTOP         = fs->make<TH1D>("AK8PF_MASSTOP"        ,"",100,0,500   );
  AK8PF_NCONST          = fs->make<TH1D>("AK8PF_NCONST"         ,"",1000,0,1000  );
  AK8PF_AREA            = fs->make<TH1D>("AK8PF_AREA"           ,"",100,0,4     );
  AK8PF_CH_MULT         = fs->make<TH1D>("AK8PF_CH_MULT"        ,"",500,0,500   );    
  AK8PF_NE_MULT         = fs->make<TH1D>("AK8PF_NE_MULT"        ,"",500,0,500   );    
  AK8PF_CHEF            = fs->make<TH1D>("AK8PF_CHEF"           ,"",100,0,1     );    
  AK8PF_NHEF            = fs->make<TH1D>("AK8PF_NHEF"           ,"",100,0,1     );    
  AK8PF_CEEF            = fs->make<TH1D>("AK8PF_CEEF"           ,"",100,0,1     );    
  AK8PF_NEEF            = fs->make<TH1D>("AK8PF_NEEF"           ,"",100,0,1     );    
  AK8PF_CMEF            = fs->make<TH1D>("AK8PF_CMEF"           ,"",100,0,1     );  

  MET_PT                = fs->make<TH1D>("MET_PT"              ,"",100,0,1000  );
  MET_PHI               = fs->make<TH1D>("MET_PHI"             ,"",100,-3.2,3.2);
  MET_SUMET             = fs->make<TH1D>("MET_SUMET"           ,"",200,1000,9000  );
  MET_GENMET            = fs->make<TH1D>("MET_GENMET"          ,"",100,0,1000  );  

  PF_PT                 = fs->make<TH1D>("PF_PT"           ,"", 500,0,1000   );  
  PF_CHARGE             = fs->make<TH1D>("PF_CHARGE"       ,"", 3,-1.5,1.5   );    
  PF_ETA                = fs->make<TH1D>("PF_ETA"          ,"", 100,-4,4     );   
  PF_PHI                = fs->make<TH1D>("PF_PHI"          ,"", 100,-3.2,3.2 );   
  PF_NEUTRAL_PT         = fs->make<TH1D>("PF_NEUTRAL_PT"   ,"", 500,0,1000   );   
  PF_NEUTRAL_ETA        = fs->make<TH1D>("PF_NEUTRAL_ETA"  ,"", 100,-4,4     );   
  PF_NEUTRAL_PHI        = fs->make<TH1D>("PF_NEUTRAL_PHI"  ,"", 100,-3.2,3.2 );   
  PF_CHARGED_PT         = fs->make<TH1D>("PF_CHARGED_PT"   ,"", 500,0,1000   );  
  PF_CHARGED_ETA        = fs->make<TH1D>("PF_CHARGED_ETA"  ,"", 100,-4,4     );  
  PF_CHARGED_PHI        = fs->make<TH1D>("PF_CHARGED_PHI"  ,"", 100,-3.2,3.2 );  
  PF_PV_PT              = fs->make<TH1D>("PF_PV_PT"        ,"", 500,0,1000   ); 
  PF_PV_CHARGE          = fs->make<TH1D>("PF_PV_CHARGE"    ,"", 3,-1.5,1.5   );
  PF_PV_ETA             = fs->make<TH1D>("PF_PV_ETA"       ,"", 100,-4,4     );
  PF_PV_PHI             = fs->make<TH1D>("PF_PV_PHI"       ,"", 100,-3.2,3.2 );
  PF_PU_PT              = fs->make<TH1D>("PF_PU_PT"        ,"", 500,0,1000   );
  PF_PU_CHARGE          = fs->make<TH1D>("PF_PU_CHARGE"    ,"", 3,-1.5,1.5   );
  PF_PU_ETA             = fs->make<TH1D>("PF_PU_ETA"       ,"", 100,-4,4     );
  PF_PU_PHI             = fs->make<TH1D>("PF_PU_PHI"       ,"", 100,-3.2,3.2 );

                               
  PF_MULT                                   = fs->make<TH1D>("PF_MULT"                                 , "", 4000, 0,4000)  ;          
  PF_MULT_fromPV0                           = fs->make<TH1D>("PF_MULT_fromPV0"                         , "", 4000, 0,4000)  ;          
  PF_MULT_fromPV1                           = fs->make<TH1D>("PF_MULT_fromPV1"                         , "", 4000, 0,4000)  ;          
  PF_MULT_NEUTRAL                           = fs->make<TH1D>("PF_MULT_NEUTRAL"                         , "", 4000, 0,4000)  ;          
  PF_MULT_CHARGED                           = fs->make<TH1D>("PF_MULT_CHARGED"                         , "", 4000, 0,4000)  ;          
  PF_MULT_chargedHadron                     = fs->make<TH1D>("PF_MULT_chargedHadron"                   , "", 4000, 0,4000)  ;          
  PF_MULT_neutralHadron                     = fs->make<TH1D>("PF_MULT_neutralHadron"                   , "", 4000, 0,4000)  ;          
  PF_MULT_gamma                             = fs->make<TH1D>("PF_MULT_gamma"                           , "", 4000, 0,4000)  ;          
  PF_MULT_electron                          = fs->make<TH1D>("PF_MULT_electron"                        , "", 4000, 0,4000)  ;          
  PF_MULT_muon                              = fs->make<TH1D>("PF_MULT_muon"                            , "", 4000, 0,4000)  ;          
  PF_MULT_forwardHadron                     = fs->make<TH1D>("PF_MULT_forwardHadron"                   , "", 4000, 0,4000)  ;          
  PF_MULT_forwardEgamma                     = fs->make<TH1D>("PF_MULT_forwardEgamma"                   , "", 4000, 0,4000)  ;          
  PF_MULT_noID                              = fs->make<TH1D>("PF_MULT_noID"                            , "", 4000, 0,4000)  ;   

  PF_MULT_pt0p2eta2p5fromPV                 = fs->make<TH1D>("PF_MULT_pt0p2eta2p5fromPV"              , "", 4000,0,4000);   
  PF_MULT_pt0p2eta2p5fromPV_CHARGED         = fs->make<TH1D>("PF_MULT_pt0p2eta2p5fromPV_CHARGED"      , "", 4000,0,4000);   
  PF_MULT_pt0p2eta2p5fromPV_NEUTRAL         = fs->make<TH1D>("PF_MULT_pt0p2eta2p5fromPV_NEUTRAL"      , "", 4000,0,4000);   
  PF_MULT_pt0p2eta2p5fromPV_chargedHadron   = fs->make<TH1D>("PF_MULT_pt0p2eta2p5fromPV_chargedHadron", "", 4000,0,4000);   
  PF_MULT_pt0p2eta2p5fromPV_neutralHadron   = fs->make<TH1D>("PF_MULT_pt0p2eta2p5fromPV_neutralHadron", "", 4000,0,4000);   
  PF_MULT_pt0p2eta2p5fromPV_gamma           = fs->make<TH1D>("PF_MULT_pt0p2eta2p5fromPV_gamma"        , "", 4000,0,4000);   
  PF_MULT_pt0p2eta2p5fromPV_electron        = fs->make<TH1D>("PF_MULT_pt0p2eta2p5fromPV_electron"     , "", 4000,0,4000);   
  PF_MULT_pt0p2eta2p5fromPV_muon            = fs->make<TH1D>("PF_MULT_pt0p2eta2p5fromPV_muon"         , "", 4000,0,4000);   
  PF_MULT_pt0p2eta2p5fromPV_forwardHadron   = fs->make<TH1D>("PF_MULT_pt0p2eta2p5fromPV_forwardHadron", "", 4000,0,4000);   
  PF_MULT_pt0p2eta2p5fromPV_forwardEgamma   = fs->make<TH1D>("PF_MULT_pt0p2eta2p5fromPV_forwardEgamma", "", 4000,0,4000);   
  PF_MULT_pt0p2eta2p5fromPV_noID            = fs->make<TH1D>("PF_MULT_pt0p2eta2p5fromPV_noID"         , "", 4000,0,4000);   
  PF_MULT_pt0p2fromPV                       = fs->make<TH1D>("PF_MULT_pt0p2fromPV"                    , "", 4000,0,4000);   
  PF_MULT_pt0p2fromPV_CHARGED               = fs->make<TH1D>("PF_MULT_pt0p2fromPV_CHARGED"            , "", 4000,0,4000);   
  PF_MULT_pt0p2fromPV_NEUTRAL               = fs->make<TH1D>("PF_MULT_pt0p2fromPV_NEUTRAL"            , "", 4000,0,4000);   
  PF_MULT_pt0p2fromPV_chargedHadron         = fs->make<TH1D>("PF_MULT_pt0p2fromPV_chargedHadron"      , "", 4000,0,4000);   
  PF_MULT_pt0p2fromPV_neutralHadron         = fs->make<TH1D>("PF_MULT_pt0p2fromPV_neutralHadron"      , "", 4000,0,4000);   
  PF_MULT_pt0p2fromPV_gamma                 = fs->make<TH1D>("PF_MULT_pt0p2fromPV_gamma"              , "", 4000,0,4000);   
  PF_MULT_pt0p2fromPV_electron              = fs->make<TH1D>("PF_MULT_pt0p2fromPV_electron"           , "", 4000,0,4000);   
  PF_MULT_pt0p2fromPV_muon                  = fs->make<TH1D>("PF_MULT_pt0p2fromPV_muon"               , "", 4000,0,4000);   
  PF_MULT_pt0p2fromPV_forwardHadron         = fs->make<TH1D>("PF_MULT_pt0p2fromPV_forwardHadron"      , "", 4000,0,4000);   
  PF_MULT_pt0p2fromPV_forwardEgamma         = fs->make<TH1D>("PF_MULT_pt0p2fromPV_forwardEgamma"      , "", 4000,0,4000);   
  PF_MULT_pt0p2fromPV_noID                  = fs->make<TH1D>("PF_MULT_pt0p2fromPV_noID"               , "", 4000,0,4000);   
  PF_MULT_fromPV                            = fs->make<TH1D>("PF_MULT_fromPV"                         , "", 4000,0,4000);   
  PF_MULT_fromPV_CHARGED                    = fs->make<TH1D>("PF_MULT_fromPV_CHARGED"                 , "", 4000,0,4000);   
  PF_MULT_fromPV_NEUTRAL                    = fs->make<TH1D>("PF_MULT_fromPV_NEUTRAL"                 , "", 4000,0,4000);   
  PF_MULT_fromPV_chargedHadron              = fs->make<TH1D>("PF_MULT_fromPV_chargedHadron"           , "", 4000,0,4000);   
  PF_MULT_fromPV_neutralHadron              = fs->make<TH1D>("PF_MULT_fromPV_neutralHadron"           , "", 4000,0,4000);   
  PF_MULT_fromPV_gamma                      = fs->make<TH1D>("PF_MULT_fromPV_gamma"                   , "", 4000,0,4000);   
  PF_MULT_fromPV_electron                   = fs->make<TH1D>("PF_MULT_fromPV_electron"                , "", 4000,0,4000);   
  PF_MULT_fromPV_muon                       = fs->make<TH1D>("PF_MULT_fromPV_muon"                    , "", 4000,0,4000);   
  PF_MULT_fromPV_forwardHadron              = fs->make<TH1D>("PF_MULT_fromPV_forwardHadron"           , "", 4000,0,4000);   
  PF_MULT_fromPV_forwardEgamma              = fs->make<TH1D>("PF_MULT_fromPV_forwardEgamma"           , "", 4000,0,4000);   
  PF_MULT_fromPV_noID                       = fs->make<TH1D>("PF_MULT_fromPV_noID"                    , "", 4000,0,4000);   
  PF_MULT_pt2fromPV                         = fs->make<TH1D>("PF_MULT_pt2fromPV"                      , "", 4000,0,4000);   
  PF_MULT_pt2fromPV_CHARGED                 = fs->make<TH1D>("PF_MULT_pt2fromPV_CHARGED"              , "", 4000,0,4000);   
  PF_MULT_pt2fromPV_NEUTRAL                 = fs->make<TH1D>("PF_MULT_pt2fromPV_NEUTRAL"              , "", 4000,0,4000);   
  PF_MULT_pt2fromPV_chargedHadron           = fs->make<TH1D>("PF_MULT_pt2fromPV_chargedHadron"        , "", 4000,0,4000);   
  PF_MULT_pt2fromPV_neutralHadron           = fs->make<TH1D>("PF_MULT_pt2fromPV_neutralHadron"        , "", 4000,0,4000);   
  PF_MULT_pt2fromPV_gamma                   = fs->make<TH1D>("PF_MULT_pt2fromPV_gamma"                , "", 4000,0,4000);   
  PF_MULT_pt2fromPV_electron                = fs->make<TH1D>("PF_MULT_pt2fromPV_electron"             , "", 4000,0,4000);   
  PF_MULT_pt2fromPV_muon                    = fs->make<TH1D>("PF_MULT_pt2fromPV_muon"                 , "", 4000,0,4000);   
  PF_MULT_pt2fromPV_forwardHadron           = fs->make<TH1D>("PF_MULT_pt2fromPV_forwardHadron"        , "", 4000,0,4000);   
  PF_MULT_pt2fromPV_forwardEgamma           = fs->make<TH1D>("PF_MULT_pt2fromPV_forwardEgamma"        , "", 4000,0,4000);   
  PF_MULT_pt2fromPV_noID                    = fs->make<TH1D>("PF_MULT_pt2fromPV_noID"                 , "", 4000,0,4000);   
                  


  PF_pt0p2eta2p5fromPV1_chargedHadron_PT    = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_chargedHadron_PT"  , "", 500,0,1000   ) ;        
  PF_pt0p2eta2p5fromPV1_chargedHadron_ETA   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_chargedHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2eta2p5fromPV1_chargedHadron_PHI   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_chargedHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2eta2p5fromPV1_neutralHadron_PT    = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_neutralHadron_PT"  , "", 500,0,1000   ) ;        
  PF_pt0p2eta2p5fromPV1_neutralHadron_ETA   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_neutralHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2eta2p5fromPV1_neutralHadron_PHI   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_neutralHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2eta2p5fromPV1_gamma_PT            = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_gamma_PT"          , "", 500,0,1000   ) ;              
  PF_pt0p2eta2p5fromPV1_gamma_ETA           = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_gamma_ETA"         , "", 100,-4,4     ) ;              
  PF_pt0p2eta2p5fromPV1_gamma_PHI           = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_gamma_PHI"         , "", 100,-3.2,3.2 ) ;              
  PF_pt0p2eta2p5fromPV1_electron_PT         = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_electron_PT"       , "", 500,0,1000   ) ;                 
  PF_pt0p2eta2p5fromPV1_electron_ETA        = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_electron_ETA"      , "", 100,-4,4     ) ;                 
  PF_pt0p2eta2p5fromPV1_electron_PHI        = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_electron_PHI"      , "", 100,-3.2,3.2 ) ;                 
  PF_pt0p2eta2p5fromPV1_muon_PT             = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_muon_PT"           , "", 500,0,1000   ) ;             
  PF_pt0p2eta2p5fromPV1_muon_ETA            = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_muon_ETA"          , "", 100,-4,4     ) ;             
  PF_pt0p2eta2p5fromPV1_muon_PHI            = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_muon_PHI"          , "", 100,-3.2,3.2 ) ;             
  PF_pt0p2eta2p5fromPV1_forwardHadron_PT    = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_forwardHadron_PT " , "", 500,0,1000   ) ;        
  PF_pt0p2eta2p5fromPV1_forwardHadron_ETA   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_forwardHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2eta2p5fromPV1_forwardHadron_PHI   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_forwardHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2eta2p5fromPV1_forwardEgamma_PT    = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_forwardEgamma_PT " , "", 500,0,1000   ) ;        
  PF_pt0p2eta2p5fromPV1_forwardEgamma_ETA   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_forwardEgamma_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2eta2p5fromPV1_forwardEgamma_PHI   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_forwardEgamma_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2eta2p5fromPV1_noID_PT             = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_noID_PT"           , "", 500,0,1000   ) ;                 
  PF_pt0p2eta2p5fromPV1_noID_ETA            = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_noID_ETA"          , "", 100,-4,4     ) ;                 
  PF_pt0p2eta2p5fromPV1_noID_PHI            = fs->make<TH1D>("PF_pt0p2eta2p5fromPV1_noID_PHI"          , "", 100,-3.2,3.2 ) ;
  PF_pt0p2fromPV1_chargedHadron_PT    = fs->make<TH1D>("PF_pt0p2fromPV1_chargedHadron_PT"  , "", 500,0,1000   ) ;        
  PF_pt0p2fromPV1_chargedHadron_ETA   = fs->make<TH1D>("PF_pt0p2fromPV1_chargedHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2fromPV1_chargedHadron_PHI   = fs->make<TH1D>("PF_pt0p2fromPV1_chargedHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2fromPV1_neutralHadron_PT    = fs->make<TH1D>("PF_pt0p2fromPV1_neutralHadron_PT"  , "", 500,0,1000   ) ;        
  PF_pt0p2fromPV1_neutralHadron_ETA   = fs->make<TH1D>("PF_pt0p2fromPV1_neutralHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2fromPV1_neutralHadron_PHI   = fs->make<TH1D>("PF_pt0p2fromPV1_neutralHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2fromPV1_gamma_PT            = fs->make<TH1D>("PF_pt0p2fromPV1_gamma_PT"          , "", 500,0,1000   ) ;              
  PF_pt0p2fromPV1_gamma_ETA           = fs->make<TH1D>("PF_pt0p2fromPV1_gamma_ETA"         , "", 100,-4,4     ) ;              
  PF_pt0p2fromPV1_gamma_PHI           = fs->make<TH1D>("PF_pt0p2fromPV1_gamma_PHI"         , "", 100,-3.2,3.2 ) ;              
  PF_pt0p2fromPV1_electron_PT         = fs->make<TH1D>("PF_pt0p2fromPV1_electron_PT"       , "", 500,0,1000   ) ;                 
  PF_pt0p2fromPV1_electron_ETA        = fs->make<TH1D>("PF_pt0p2fromPV1_electron_ETA"      , "", 100,-4,4     ) ;                 
  PF_pt0p2fromPV1_electron_PHI        = fs->make<TH1D>("PF_pt0p2fromPV1_electron_PHI"      , "", 100,-3.2,3.2 ) ;                 
  PF_pt0p2fromPV1_muon_PT             = fs->make<TH1D>("PF_pt0p2fromPV1_muon_PT"           , "", 500,0,1000   ) ;             
  PF_pt0p2fromPV1_muon_ETA            = fs->make<TH1D>("PF_pt0p2fromPV1_muon_ETA"          , "", 100,-4,4     ) ;             
  PF_pt0p2fromPV1_muon_PHI            = fs->make<TH1D>("PF_pt0p2fromPV1_muon_PHI"          , "", 100,-3.2,3.2 ) ;             
  PF_pt0p2fromPV1_forwardHadron_PT    = fs->make<TH1D>("PF_pt0p2fromPV1_forwardHadron_PT " , "", 500,0,1000   ) ;        
  PF_pt0p2fromPV1_forwardHadron_ETA   = fs->make<TH1D>("PF_pt0p2fromPV1_forwardHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2fromPV1_forwardHadron_PHI   = fs->make<TH1D>("PF_pt0p2fromPV1_forwardHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2fromPV1_forwardEgamma_PT    = fs->make<TH1D>("PF_pt0p2fromPV1_forwardEgamma_PT " , "", 500,0,1000   ) ;        
  PF_pt0p2fromPV1_forwardEgamma_ETA   = fs->make<TH1D>("PF_pt0p2fromPV1_forwardEgamma_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2fromPV1_forwardEgamma_PHI   = fs->make<TH1D>("PF_pt0p2fromPV1_forwardEgamma_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2fromPV1_noID_PT             = fs->make<TH1D>("PF_pt0p2fromPV1_noID_PT"           , "", 500,0,1000   ) ;                 
  PF_pt0p2fromPV1_noID_ETA            = fs->make<TH1D>("PF_pt0p2fromPV1_noID_ETA"          , "", 100,-4,4     ) ;                 
  PF_pt0p2fromPV1_noID_PHI            = fs->make<TH1D>("PF_pt0p2fromPV1_noID_PHI"          , "", 100,-3.2,3.2 ) ;
  PF_pt0p2to2fromPV1_chargedHadron_PT    = fs->make<TH1D>("PF_pt0p2to2fromPV1_chargedHadron_PT"  , "", 500,0,1000   ) ;        
  PF_pt0p2to2fromPV1_chargedHadron_ETA   = fs->make<TH1D>("PF_pt0p2to2fromPV1_chargedHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2to2fromPV1_chargedHadron_PHI   = fs->make<TH1D>("PF_pt0p2to2fromPV1_chargedHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2to2fromPV1_neutralHadron_PT    = fs->make<TH1D>("PF_pt0p2to2fromPV1_neutralHadron_PT"  , "", 500,0,1000   ) ;        
  PF_pt0p2to2fromPV1_neutralHadron_ETA   = fs->make<TH1D>("PF_pt0p2to2fromPV1_neutralHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2to2fromPV1_neutralHadron_PHI   = fs->make<TH1D>("PF_pt0p2to2fromPV1_neutralHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2to2fromPV1_gamma_PT            = fs->make<TH1D>("PF_pt0p2to2fromPV1_gamma_PT"          , "", 500,0,1000   ) ;              
  PF_pt0p2to2fromPV1_gamma_ETA           = fs->make<TH1D>("PF_pt0p2to2fromPV1_gamma_ETA"         , "", 100,-4,4     ) ;              
  PF_pt0p2to2fromPV1_gamma_PHI           = fs->make<TH1D>("PF_pt0p2to2fromPV1_gamma_PHI"         , "", 100,-3.2,3.2 ) ;              
  PF_pt0p2to2fromPV1_electron_PT         = fs->make<TH1D>("PF_pt0p2to2fromPV1_electron_PT"       , "", 500,0,1000   ) ;                 
  PF_pt0p2to2fromPV1_electron_ETA        = fs->make<TH1D>("PF_pt0p2to2fromPV1_electron_ETA"      , "", 100,-4,4     ) ;                 
  PF_pt0p2to2fromPV1_electron_PHI        = fs->make<TH1D>("PF_pt0p2to2fromPV1_electron_PHI"      , "", 100,-3.2,3.2 ) ;                 
  PF_pt0p2to2fromPV1_muon_PT             = fs->make<TH1D>("PF_pt0p2to2fromPV1_muon_PT"           , "", 500,0,1000   ) ;             
  PF_pt0p2to2fromPV1_muon_ETA            = fs->make<TH1D>("PF_pt0p2to2fromPV1_muon_ETA"          , "", 100,-4,4     ) ;             
  PF_pt0p2to2fromPV1_muon_PHI            = fs->make<TH1D>("PF_pt0p2to2fromPV1_muon_PHI"          , "", 100,-3.2,3.2 ) ;             
  PF_pt0p2to2fromPV1_forwardHadron_PT    = fs->make<TH1D>("PF_pt0p2to2fromPV1_forwardHadron_PT " , "", 500,0,1000   ) ;        
  PF_pt0p2to2fromPV1_forwardHadron_ETA   = fs->make<TH1D>("PF_pt0p2to2fromPV1_forwardHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2to2fromPV1_forwardHadron_PHI   = fs->make<TH1D>("PF_pt0p2to2fromPV1_forwardHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2to2fromPV1_forwardEgamma_PT    = fs->make<TH1D>("PF_pt0p2to2fromPV1_forwardEgamma_PT " , "", 500,0,1000   ) ;        
  PF_pt0p2to2fromPV1_forwardEgamma_ETA   = fs->make<TH1D>("PF_pt0p2to2fromPV1_forwardEgamma_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2to2fromPV1_forwardEgamma_PHI   = fs->make<TH1D>("PF_pt0p2to2fromPV1_forwardEgamma_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2to2fromPV1_noID_PT             = fs->make<TH1D>("PF_pt0p2to2fromPV1_noID_PT"           , "", 500,0,1000   ) ;                 
  PF_pt0p2to2fromPV1_noID_ETA            = fs->make<TH1D>("PF_pt0p2to2fromPV1_noID_ETA"          , "", 100,-4,4     ) ;                 
  PF_pt0p2to2fromPV1_noID_PHI            = fs->make<TH1D>("PF_pt0p2to2fromPV1_noID_PHI"          , "", 100,-3.2,3.2 ) ;
  PF_pt0p2eta2p5fromPV0_chargedHadron_PT    = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_chargedHadron_PT"  , "", 500,0,1000   ) ;        
  PF_pt0p2eta2p5fromPV0_chargedHadron_ETA   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_chargedHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2eta2p5fromPV0_chargedHadron_PHI   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_chargedHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2eta2p5fromPV0_neutralHadron_PT    = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_neutralHadron_PT"  , "", 500,0,1000   ) ;        
  PF_pt0p2eta2p5fromPV0_neutralHadron_ETA   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_neutralHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2eta2p5fromPV0_neutralHadron_PHI   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_neutralHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2eta2p5fromPV0_gamma_PT            = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_gamma_PT"          , "", 500,0,1000   ) ;              
  PF_pt0p2eta2p5fromPV0_gamma_ETA           = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_gamma_ETA"         , "", 100,-4,4     ) ;              
  PF_pt0p2eta2p5fromPV0_gamma_PHI           = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_gamma_PHI"         , "", 100,-3.2,3.2 ) ;              
  PF_pt0p2eta2p5fromPV0_electron_PT         = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_electron_PT"       , "", 500,0,1000   ) ;                 
  PF_pt0p2eta2p5fromPV0_electron_ETA        = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_electron_ETA"      , "", 100,-4,4     ) ;                 
  PF_pt0p2eta2p5fromPV0_electron_PHI        = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_electron_PHI"      , "", 100,-3.2,3.2 ) ;                 
  PF_pt0p2eta2p5fromPV0_muon_PT             = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_muon_PT"           , "", 500,0,1000   ) ;             
  PF_pt0p2eta2p5fromPV0_muon_ETA            = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_muon_ETA"          , "", 100,-4,4     ) ;             
  PF_pt0p2eta2p5fromPV0_muon_PHI            = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_muon_PHI"          , "", 100,-3.2,3.2 ) ;             
  PF_pt0p2eta2p5fromPV0_forwardHadron_PT    = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_forwardHadron_PT " , "", 500,0,1000   ) ;        
  PF_pt0p2eta2p5fromPV0_forwardHadron_ETA   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_forwardHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2eta2p5fromPV0_forwardHadron_PHI   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_forwardHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2eta2p5fromPV0_forwardEgamma_PT    = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_forwardEgamma_PT " , "", 500,0,1000   ) ;        
  PF_pt0p2eta2p5fromPV0_forwardEgamma_ETA   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_forwardEgamma_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2eta2p5fromPV0_forwardEgamma_PHI   = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_forwardEgamma_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2eta2p5fromPV0_noID_PT             = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_noID_PT"           , "", 500,0,1000   ) ;                 
  PF_pt0p2eta2p5fromPV0_noID_ETA            = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_noID_ETA"          , "", 100,-4,4     ) ;                 
  PF_pt0p2eta2p5fromPV0_noID_PHI            = fs->make<TH1D>("PF_pt0p2eta2p5fromPV0_noID_PHI"          , "", 100,-3.2,3.2 ) ;
  PF_pt0p2fromPV0_chargedHadron_PT    = fs->make<TH1D>("PF_pt0p2fromPV0_chargedHadron_PT"  , "", 500,0,1000   ) ;        
  PF_pt0p2fromPV0_chargedHadron_ETA   = fs->make<TH1D>("PF_pt0p2fromPV0_chargedHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2fromPV0_chargedHadron_PHI   = fs->make<TH1D>("PF_pt0p2fromPV0_chargedHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2fromPV0_neutralHadron_PT    = fs->make<TH1D>("PF_pt0p2fromPV0_neutralHadron_PT"  , "", 500,0,1000   ) ;        
  PF_pt0p2fromPV0_neutralHadron_ETA   = fs->make<TH1D>("PF_pt0p2fromPV0_neutralHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2fromPV0_neutralHadron_PHI   = fs->make<TH1D>("PF_pt0p2fromPV0_neutralHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2fromPV0_gamma_PT            = fs->make<TH1D>("PF_pt0p2fromPV0_gamma_PT"          , "", 500,0,1000   ) ;              
  PF_pt0p2fromPV0_gamma_ETA           = fs->make<TH1D>("PF_pt0p2fromPV0_gamma_ETA"         , "", 100,-4,4     ) ;              
  PF_pt0p2fromPV0_gamma_PHI           = fs->make<TH1D>("PF_pt0p2fromPV0_gamma_PHI"         , "", 100,-3.2,3.2 ) ;              
  PF_pt0p2fromPV0_electron_PT         = fs->make<TH1D>("PF_pt0p2fromPV0_electron_PT"       , "", 500,0,1000   ) ;                 
  PF_pt0p2fromPV0_electron_ETA        = fs->make<TH1D>("PF_pt0p2fromPV0_electron_ETA"      , "", 100,-4,4     ) ;                 
  PF_pt0p2fromPV0_electron_PHI        = fs->make<TH1D>("PF_pt0p2fromPV0_electron_PHI"      , "", 100,-3.2,3.2 ) ;                 
  PF_pt0p2fromPV0_muon_PT             = fs->make<TH1D>("PF_pt0p2fromPV0_muon_PT"           , "", 500,0,1000   ) ;             
  PF_pt0p2fromPV0_muon_ETA            = fs->make<TH1D>("PF_pt0p2fromPV0_muon_ETA"          , "", 100,-4,4     ) ;             
  PF_pt0p2fromPV0_muon_PHI            = fs->make<TH1D>("PF_pt0p2fromPV0_muon_PHI"          , "", 100,-3.2,3.2 ) ;             
  PF_pt0p2fromPV0_forwardHadron_PT    = fs->make<TH1D>("PF_pt0p2fromPV0_forwardHadron_PT " , "", 500,0,1000   ) ;        
  PF_pt0p2fromPV0_forwardHadron_ETA   = fs->make<TH1D>("PF_pt0p2fromPV0_forwardHadron_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2fromPV0_forwardHadron_PHI   = fs->make<TH1D>("PF_pt0p2fromPV0_forwardHadron_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2fromPV0_forwardEgamma_PT    = fs->make<TH1D>("PF_pt0p2fromPV0_forwardEgamma_PT " , "", 500,0,1000   ) ;        
  PF_pt0p2fromPV0_forwardEgamma_ETA   = fs->make<TH1D>("PF_pt0p2fromPV0_forwardEgamma_ETA" , "", 100,-4,4     ) ;        
  PF_pt0p2fromPV0_forwardEgamma_PHI   = fs->make<TH1D>("PF_pt0p2fromPV0_forwardEgamma_PHI" , "", 100,-3.2,3.2 ) ;        
  PF_pt0p2fromPV0_noID_PT             = fs->make<TH1D>("PF_pt0p2fromPV0_noID_PT"           , "", 500,0,1000   ) ;                 
  PF_pt0p2fromPV0_noID_ETA            = fs->make<TH1D>("PF_pt0p2fromPV0_noID_ETA"          , "", 100,-4,4     ) ;                 
  PF_pt0p2fromPV0_noID_PHI            = fs->make<TH1D>("PF_pt0p2fromPV0_noID_PHI"          , "", 100,-3.2,3.2 ) ;

PFcheck_pt0p2fromPV1_gamma_ETA            = fs->make<TH1D>("PFcheck_pt0p2fromPV1_gamma_ETA"                   , "", 100,-4,4     ) ;            
PFcheck_pt0p2fromPV1_electron_ETA         = fs->make<TH1D>("PFcheck_pt0p2fromPV1_electron_ETA"                , "", 100,-4,4     ) ;                
PFcheck_pt0p2to1p0fromPV1_gamma_ETA       = fs->make<TH1D>("PFcheck_pt0p2to1p0fromPV1_gamma_ETA"              , "", 100,-4,4     ) ;                
PFcheck_pt0p2to1p0fromPV1_electron_ETA    = fs->make<TH1D>("PFcheck_pt0p2to1p0fromPV1_electron_ETA"           , "", 100,-4,4     ) ;                 
PFcheck_pt1p0to2p0fromPV1_gamma_ETA       = fs->make<TH1D>("PFcheck_pt1p0to2p0fromPV1_gamma_ETA"              , "", 100,-4,4     ) ;                
PFcheck_pt1p0to2p0fromPV1_electron_ETA    = fs->make<TH1D>("PFcheck_pt1p0to2p0fromPV1_electron_ETA"           , "", 100,-4,4     ) ;                 
PFcheck_pt2p0to5p0fromPV1_gamma_ETA       = fs->make<TH1D>("PFcheck_pt2p0to5p0fromPV1_gamma_ETA"              , "", 100,-4,4     ) ;                
PFcheck_pt2p0to5p0fromPV1_electron_ETA    = fs->make<TH1D>("PFcheck_pt2p0to5p0fromPV1_electron_ETA"           , "", 100,-4,4     ) ;                 
PFcheck_pt5p0to10p0fromPV1_gamma_ETA      = fs->make<TH1D>("PFcheck_pt5p0to10p0fromPV1_gamma_ETA"             , "", 100,-4,4     ) ;                
PFcheck_pt5p0to10p0fromPV1_electron_ETA   = fs->make<TH1D>("PFcheck_pt5p0to10p0fromPV1_electron_ETA"          , "", 100,-4,4     ) ;                  
PFcheck_pt10fromPV1_gamma_ETA             = fs->make<TH1D>("PFcheck_pt10fromPV1_gamma_ETA"                    , "", 100,-4,4     ) ;            
PFcheck_pt10fromPV1_electron_ETA          = fs->make<TH1D>("PFcheck_pt10fromPV1_electron_ETA"                 , "", 100,-4,4     ) ;               


  AK15FILT_PT                   = fs->make<TH1D>("AK15FILT_PT",                   "",100,0,4000);
  AK15FILT_PHI                  = fs->make<TH1D>("AK15FILT_PHI",                  "",100,-3.2,3.2  );
  AK15FILT_ETA                  = fs->make<TH1D>("AK15FILT_ETA",                  "",100,-4,4  );
  AK15FILT_RAP                  = fs->make<TH1D>("AK15FILT_RAP",                  "",100,-4,4  );
  AK15FILT_MASS                 = fs->make<TH1D>("AK15FILT_MASS",                 "",100,0,400 );
  AK15FILT_NCONST               = fs->make<TH1D>("AK15FILT_NCONST",               "",10,0,10 );
  AK15FILT_BDISC                = fs->make<TH1D>("AK15FILT_BDISC",                "",100,0,1   );
  AK15FILT_AREA                 = fs->make<TH1D>("AK15FILT_AREA",                 "",100,0,10  );
  AK15FILT_NTRACKS              = fs->make<TH1D>("AK15FILT_NTRACKS",              "",200,0,200 );
  AK15FILT_FLAVOUR              = fs->make<TH1D>("AK15FILT_FLAVOUR",              "",24,0,24     );
  AK15FILT_MASS_UNCORR          = fs->make<TH1D>("AK15FILT_MASS_UNCORR",          "",100,0,400 );
  AK15FILT_MAXSUBJETBDISC       = fs->make<TH1D>("AK15FILT_MAXSUBJETBDISC",       "",100,0,1 );
  AK15FILT_MAXSUBJETBDISCFLAVOUR= fs->make<TH1D>("AK15FILT_MAXSUBJETBDISCFLAVOUR","",24,0,24 );

  CMS_PT                     = fs->make<TH1D>("CMS_PT",                   "",100,0,4000   );
  CMS_PHI                    = fs->make<TH1D>("CMS_PHI",                  "",100,-3.2,3.2 );
  CMS_ETA                    = fs->make<TH1D>("CMS_ETA",                  "",100,-4,4     );
  CMS_RAP                    = fs->make<TH1D>("CMS_RAP",                  "",100,-4,4     );
  CMS_MASS                   = fs->make<TH1D>("CMS_MASS",                 "",100,0,500   );
  CMS_NCONST                 = fs->make<TH1D>("CMS_NCONST",               "",1000,0,1000  );
  CMS_BDISC                  = fs->make<TH1D>("CMS_BDISC",                "",100,0,1      );
  CMS_AREA                   = fs->make<TH1D>("CMS_AREA",                 "",100,0,10     );
  CMS_NTRACKS                = fs->make<TH1D>("CMS_NTRACKS",              "",200,0,200    );
  CMS_FLAVOUR                = fs->make<TH1D>("CMS_FLAVOUR",              "",24,0,24      );
  CMS_MASS_UNCORR            = fs->make<TH1D>("CMS_MASS_UNCORR",          "",100,0,500   );
  CMS_MAXSUBJETBDISC         = fs->make<TH1D>("CMS_MAXSUBJETBDISC",       "",100,0,1      );
  CMS_MAXSUBJETBDISCFLAVOUR  = fs->make<TH1D>("CMS_MAXSUBJETBDISCFLAVOUR","",24,0,24 );
  CMS_GROOMMASS              = fs->make<TH1D>("CMS_GROOMMASS",            "",100,0,400    );
  CMS_MINMASS                = fs->make<TH1D>("CMS_MINMASS",              "",100,0,200    );
        

        HEP_PT                      = fs->make<TH1D>("HEP_PT",                   "",100,0,4000   );                              
  HEP_PHI                     = fs->make<TH1D>("HEP_PHI",                  "",100,-3.2,3.2 );                              
  HEP_ETA                     = fs->make<TH1D>("HEP_ETA",                  "",100,-4,4     );                              
  HEP_RAP                     = fs->make<TH1D>("HEP_RAP",                  "",100,-4,4     );                              
  HEP_MASS                    = fs->make<TH1D>("HEP_MASS",                 "",100,0,500   );                              
  HEP_NCONST                  = fs->make<TH1D>("HEP_NCONST",               "",1000,0,1000  );                              
  HEP_BDISC                   = fs->make<TH1D>("HEP_BDISC",                "",100,0,1      );                              
  HEP_AREA                    = fs->make<TH1D>("HEP_AREA",                 "",100,0,10     );                                
  HEP_NTRACKS                 = fs->make<TH1D>("HEP_NTRACKS",              "",200,0,200    );                                
  HEP_FLAVOUR                 = fs->make<TH1D>("HEP_FLAVOUR",              "",24,0,24      );                                
  HEP_MASS_UNCORR             = fs->make<TH1D>("HEP_MASS_UNCORR",          "",100,0,500   );                                
  HEP_MAXSUBJETBDISC          = fs->make<TH1D>("HEP_MAXSUBJETBDISC",       "",100,0,1      );                                
  HEP_MAXSUBJETBDISCFLAVOUR   = fs->make<TH1D>("HEP_MAXSUBJETBDISCFLAVOUR","",100,0,1      );                                
  HEP_M123                    = fs->make<TH1D>("HEP_M123",                 "",100,0,400);                                
  HEP_M12                     = fs->make<TH1D>("HEP_M12",                  "",100,0,200);                                
  HEP_M13                     = fs->make<TH1D>("HEP_M13",                  "",100,0,200);                                
  HEP_M23                     = fs->make<TH1D>("HEP_M23",                  "",100,0,200);                                
  HEP_M23M123                 = fs->make<TH1D>("HEP_M23M123",              "",100,0,2);                                
  HEP_ATANM13M12              = fs->make<TH1D>("HEP_ATANM13M12",           "",100,0,2);                                
  HEP_ATANM13M12_M23M123      = fs->make<TH2F>("HEP_ATANM13M12_M23M123",   "",100,0,2,100,0,2);


}

AnalyzeMiniPlusSubstructure::~AnalyzeMiniPlusSubstructure()
{
}


void
AnalyzeMiniPlusSubstructure::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  bool verbose = false;
  using namespace edm;
  using namespace std;
  using namespace reco;
  //using namespace pat;
  //using namespace fastjet;

  edm::Handle<reco::VertexCollection> vertices;
  iEvent.getByToken(vtxToken_, vertices);
  if (vertices->empty()) return; // skip the event if no PV found
  const reco::Vertex &PV = vertices->front();
  //int size = vertices->size();
  int count_vertex = 0;
  int count_good_vertex = 0;          
  for(reco::VertexCollection::const_iterator v=vertices->begin();v!=vertices->end(); ++v)
  {
      count_vertex++;
      if ( v->ndof() > 4 && fabs(v->z()) < 24 && fabs(v->position().rho()) < 2 ) count_good_vertex++;
  }
  NVTX_GOOD->Fill(count_good_vertex);
  NVTX_ALL->Fill(count_vertex);

  edm::Handle<double> h_rho;
  // iEvent.getByLabel( "fixedGridRhoAll", h_rho );  //ex. kt6PFJets
  iEvent.getByLabel( "fixedGridRhoFastjetAll", h_rho );  //ex. kt6PFJets
  double rho = *h_rho;
  RHO->Fill(rho);

  edm::Handle<pat::MuonCollection> muons;
  iEvent.getByToken(muonToken_, muons);
  for (const pat::Muon &mu : *muons) {
      if (mu.pt() < 5 || !mu.isLooseMuon()) continue;
      MU_PT               ->Fill( mu.pt() );
      MU_ETA              ->Fill( mu.eta() );
      MU_PHI              ->Fill( mu.phi() );
      MU_dzPV              ->Fill( mu.muonBestTrack()->dz(PV.position()) );
      MU_ISLOOSE              ->Fill( mu.isLooseMuon() );
      MU_ISTIGHT              ->Fill(  mu.isTightMuon(PV) );
  }

  edm::Handle<pat::ElectronCollection> electrons;
  iEvent.getByToken(electronToken_, electrons);
  for (const pat::Electron &el : *electrons) {
      if (el.pt() < 5) continue;
      EL_PT               ->Fill( el.pt() );
      EL_ETA              ->Fill( el.eta() );
      EL_PHI              ->Fill( el.phi() );
      EL_GSF_NLOSTHITS    ->Fill( el.gsfTrack()->trackerExpectedHitsInner().numberOfLostHits() );
      EL_SCETA            ->Fill( el.superCluster()->eta() );
      EL_SIETAIETA        ->Fill( el.sigmaIetaIeta() );
      EL_full5x5SIETAIETA ->Fill( el.full5x5_sigmaIetaIeta() );
      EL_PASSCONERSIONVETO->Fill( el.passConversionVeto() );
  }

  edm::Handle<pat::PhotonCollection> photons;
  iEvent.getByToken(photonToken_, photons);
  for (const pat::Photon &pho : *photons) {
      if (pho.pt() < 20 or pho.chargedHadronIso()/pho.pt() > 0.3) continue;
      PHO_PT               ->Fill( pho.pt() );
      PHO_ETA              ->Fill( pho.eta() );
      PHO_PHI              ->Fill( pho.phi() );
      PHO_CHISOoverPT      ->Fill( pho.chargedHadronIso()/pho.pt() );
      PHO_SCETA            ->Fill( pho.superCluster()->eta() );
      PHO_SIETAIETA        ->Fill( pho.sigmaIetaIeta() );
      PHO_full5x5SIETAIETA ->Fill( pho.full5x5_sigmaIetaIeta() );
  }


  edm::Handle<pat::TauCollection> taus;
  iEvent.getByToken(tauToken_, taus);
  for (const pat::Tau &tau : *taus) {
      if (tau.pt() < 15) continue;
    TAU_PT                ->Fill( tau.pt()             );  
    TAU_PHI               ->Fill( tau.phi()            );  
    TAU_ETA               ->Fill( tau.eta()            );  
    TAU_DXYSIG            ->Fill( tau.dxy_Sig()        );  
    TAU_TAUID             ->Fill( tau.tauID("byMediumCombinedIsolationDeltaBetaCorr3Hits")   );  
    TAU_LEADCANDPT        ->Fill( tau.leadCand()->pt()    );  
    TAU_LEADCANDPDGID     ->Fill( tau.leadCand()->pdgId() );  
  }


  edm::Handle<pat::JetCollection> jets;
  iEvent.getByToken(jetToken_, jets);
  for (const pat::Jet &j : *jets) {
      if (j.pt() < 15) continue;
    AK5PF_PT       ->Fill( j.pt()                          ); 
    AK5PF_PHI      ->Fill( j.phi()                         ); 
    AK5PF_ETA      ->Fill( j.eta()                         ); 
    AK5PF_RAP      ->Fill( j.rapidity()                    ); 
    AK5PF_MASS     ->Fill( j.mass()                        ); 
    AK5PF_NCONST   ->Fill( j.numberOfDaughters()           ); 
    AK5PF_AREA     ->Fill( j.jetArea()                     );  
    AK5PF_CH_MULT  ->Fill( j.chargedMultiplicity()         );          
    AK5PF_NE_MULT  ->Fill( j.neutralMultiplicity()         );          
    AK5PF_CHEF     ->Fill( j.chargedHadronEnergyFraction() );  
    AK5PF_NHEF     ->Fill( j.neutralHadronEnergyFraction() );  
    AK5PF_CEEF     ->Fill( j.chargedEmEnergyFraction()     );      
    AK5PF_NEEF     ->Fill( j.neutralEmEnergyFraction()     );      
    AK5PF_CMEF     ->Fill( j.chargedMuEnergyFraction()     );            
    AK5PF_CSV      ->Fill( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags"))              );            
    AK5PF_ISV      ->Fill( std::max(0.f,j.bDiscriminator("combinedInclusiveSecondaryVertexBJetTags"))     );            
    AK5PF_PUID     ->Fill( j.userFloat("pileupJetId:fullDiscriminant")                                    );  

    // Select pileup jets
    if(  j.userFloat("pileupJetId:fullDiscriminant")< -0.6  )   
    {
      AK5PF_PU_PT       ->Fill( j.pt()                          ); 
      AK5PF_PU_PHI      ->Fill( j.phi()                         ); 
      AK5PF_PU_ETA      ->Fill( j.eta()                         ); 
      AK5PF_PU_RAP      ->Fill( j.rapidity()                    ); 
      AK5PF_PU_MASS     ->Fill( j.mass()                        ); 
      AK5PF_PU_NCONST   ->Fill( j.numberOfDaughters()           ); 
      AK5PF_PU_AREA     ->Fill( j.jetArea()                     );  
      AK5PF_PU_CH_MULT  ->Fill( j.chargedMultiplicity()         );          
      AK5PF_PU_NE_MULT  ->Fill( j.neutralMultiplicity()         );          
      AK5PF_PU_CHEF     ->Fill( j.chargedHadronEnergyFraction() );  
      AK5PF_PU_NHEF     ->Fill( j.neutralHadronEnergyFraction() );  
      AK5PF_PU_CEEF     ->Fill( j.chargedEmEnergyFraction()     );      
      AK5PF_PU_NEEF     ->Fill( j.neutralEmEnergyFraction()     );      
      AK5PF_PU_CMEF     ->Fill( j.chargedMuEnergyFraction()     );            
      AK5PF_PU_CSV      ->Fill( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags"))              );            
      AK5PF_PU_ISV      ->Fill( std::max(0.f,j.bDiscriminator("combinedInclusiveSecondaryVertexBJetTags"))     );            
      AK5PF_PU_PUID     ->Fill( j.userFloat("pileupJetId:fullDiscriminant")                                    );  
    }  
    //  select non pileup jets
    if(  j.userFloat("pileupJetId:fullDiscriminant") > 0.2  )   
    {
      AK5PF_PUID_PT       ->Fill( j.pt()                          ); 
      AK5PF_PUID_PHI      ->Fill( j.phi()                         ); 
      AK5PF_PUID_ETA      ->Fill( j.eta()                         ); 
      AK5PF_PUID_RAP      ->Fill( j.rapidity()                    ); 
      AK5PF_PUID_MASS     ->Fill( j.mass()                        ); 
      AK5PF_PUID_NCONST   ->Fill( j.numberOfDaughters()           ); 
      AK5PF_PUID_AREA     ->Fill( j.jetArea()                     );  
      AK5PF_PUID_CH_MULT  ->Fill( j.chargedMultiplicity()         );          
      AK5PF_PUID_NE_MULT  ->Fill( j.neutralMultiplicity()         );          
      AK5PF_PUID_CHEF     ->Fill( j.chargedHadronEnergyFraction() );  
      AK5PF_PUID_NHEF     ->Fill( j.neutralHadronEnergyFraction() );  
      AK5PF_PUID_CEEF     ->Fill( j.chargedEmEnergyFraction()     );      
      AK5PF_PUID_NEEF     ->Fill( j.neutralEmEnergyFraction()     );      
      AK5PF_PUID_CMEF     ->Fill( j.chargedMuEnergyFraction()     );            
      AK5PF_PUID_CSV      ->Fill( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags"))              );            
      AK5PF_PUID_ISV      ->Fill( std::max(0.f,j.bDiscriminator("combinedInclusiveSecondaryVertexBJetTags"))     );            
      AK5PF_PUID_PUID     ->Fill( j.userFloat("pileupJetId:fullDiscriminant")                                    );  
    }  

    // Select low pT jets
    if (j.pt()<40 )
    {
      AK5PF_lowPT_PT       ->Fill( j.pt()                          ); 
      AK5PF_lowPT_PHI      ->Fill( j.phi()                         ); 
      AK5PF_lowPT_ETA      ->Fill( j.eta()                         ); 
      AK5PF_lowPT_RAP      ->Fill( j.rapidity()                    ); 
      AK5PF_lowPT_MASS     ->Fill( j.mass()                        ); 
      AK5PF_lowPT_NCONST   ->Fill( j.numberOfDaughters()           ); 
      AK5PF_lowPT_AREA     ->Fill( j.jetArea()                     );  
      AK5PF_lowPT_CH_MULT  ->Fill( j.chargedMultiplicity()         );          
      AK5PF_lowPT_NE_MULT  ->Fill( j.neutralMultiplicity()         );          
      AK5PF_lowPT_CHEF     ->Fill( j.chargedHadronEnergyFraction() );  
      AK5PF_lowPT_NHEF     ->Fill( j.neutralHadronEnergyFraction() );  
      AK5PF_lowPT_CEEF     ->Fill( j.chargedEmEnergyFraction()     );      
      AK5PF_lowPT_NEEF     ->Fill( j.neutralEmEnergyFraction()     );      
      AK5PF_lowPT_CMEF     ->Fill( j.chargedMuEnergyFraction()     );            
      AK5PF_lowPT_CSV      ->Fill( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags"))              );            
      AK5PF_lowPT_ISV      ->Fill( std::max(0.f,j.bDiscriminator("combinedInclusiveSecondaryVertexBJetTags"))     );            
      AK5PF_lowPT_PUID     ->Fill( j.userFloat("pileupJetId:fullDiscriminant")                                    );  
    }

    // Select low pT jets
    if (j.pt()>30 )
    {
      AK5PF_pt30_PT       ->Fill( j.pt()                          ); 
      AK5PF_pt30_PHI      ->Fill( j.phi()                         ); 
      AK5PF_pt30_ETA      ->Fill( j.eta()                         ); 
      AK5PF_pt30_RAP      ->Fill( j.rapidity()                    ); 
      AK5PF_pt30_MASS     ->Fill( j.mass()                        ); 
      AK5PF_pt30_NCONST   ->Fill( j.numberOfDaughters()           ); 
      AK5PF_pt30_AREA     ->Fill( j.jetArea()                     );  
      AK5PF_pt30_CH_MULT  ->Fill( j.chargedMultiplicity()         );          
      AK5PF_pt30_NE_MULT  ->Fill( j.neutralMultiplicity()         );          
      AK5PF_pt30_CHEF     ->Fill( j.chargedHadronEnergyFraction() );  
      AK5PF_pt30_NHEF     ->Fill( j.neutralHadronEnergyFraction() );  
      AK5PF_pt30_CEEF     ->Fill( j.chargedEmEnergyFraction()     );      
      AK5PF_pt30_NEEF     ->Fill( j.neutralEmEnergyFraction()     );      
      AK5PF_pt30_CMEF     ->Fill( j.chargedMuEnergyFraction()     );            
      AK5PF_pt30_CSV      ->Fill( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags"))              );            
      AK5PF_pt30_ISV      ->Fill( std::max(0.f,j.bDiscriminator("combinedInclusiveSecondaryVertexBJetTags"))     );            
      AK5PF_pt30_PUID     ->Fill( j.userFloat("pileupJetId:fullDiscriminant")                                    );  
    }
    if (j.pt()>100 )
    {
      AK5PF_pt100_PT       ->Fill( j.pt()                          ); 
      AK5PF_pt100_PHI      ->Fill( j.phi()                         ); 
      AK5PF_pt100_ETA      ->Fill( j.eta()                         ); 
      AK5PF_pt100_RAP      ->Fill( j.rapidity()                    ); 
      AK5PF_pt100_MASS     ->Fill( j.mass()                        ); 
      AK5PF_pt100_NCONST   ->Fill( j.numberOfDaughters()           ); 
      AK5PF_pt100_AREA     ->Fill( j.jetArea()                     );  
      AK5PF_pt100_CH_MULT  ->Fill( j.chargedMultiplicity()         );          
      AK5PF_pt100_NE_MULT  ->Fill( j.neutralMultiplicity()         );          
      AK5PF_pt100_CHEF     ->Fill( j.chargedHadronEnergyFraction() );  
      AK5PF_pt100_NHEF     ->Fill( j.neutralHadronEnergyFraction() );  
      AK5PF_pt100_CEEF     ->Fill( j.chargedEmEnergyFraction()     );      
      AK5PF_pt100_NEEF     ->Fill( j.neutralEmEnergyFraction()     );      
      AK5PF_pt100_CMEF     ->Fill( j.chargedMuEnergyFraction()     );            
      AK5PF_pt100_CSV      ->Fill( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags"))              );            
      AK5PF_pt100_ISV      ->Fill( std::max(0.f,j.bDiscriminator("combinedInclusiveSecondaryVertexBJetTags"))     );            
      AK5PF_pt100_PUID     ->Fill( j.userFloat("pileupJetId:fullDiscriminant")                                    );  
    }
        if (j.pt()>100 )
    {
      AK5PF_pt500_PT       ->Fill( j.pt()                          ); 
      AK5PF_pt500_PHI      ->Fill( j.phi()                         ); 
      AK5PF_pt500_ETA      ->Fill( j.eta()                         ); 
      AK5PF_pt500_RAP      ->Fill( j.rapidity()                    ); 
      AK5PF_pt500_MASS     ->Fill( j.mass()                        ); 
      AK5PF_pt500_NCONST   ->Fill( j.numberOfDaughters()           ); 
      AK5PF_pt500_AREA     ->Fill( j.jetArea()                     );  
      AK5PF_pt500_CH_MULT  ->Fill( j.chargedMultiplicity()         );          
      AK5PF_pt500_NE_MULT  ->Fill( j.neutralMultiplicity()         );          
      AK5PF_pt500_CHEF     ->Fill( j.chargedHadronEnergyFraction() );  
      AK5PF_pt500_NHEF     ->Fill( j.neutralHadronEnergyFraction() );  
      AK5PF_pt500_CEEF     ->Fill( j.chargedEmEnergyFraction()     );      
      AK5PF_pt500_NEEF     ->Fill( j.neutralEmEnergyFraction()     );      
      AK5PF_pt500_CMEF     ->Fill( j.chargedMuEnergyFraction()     );            
      AK5PF_pt500_CSV      ->Fill( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags"))              );            
      AK5PF_pt500_ISV      ->Fill( std::max(0.f,j.bDiscriminator("combinedInclusiveSecondaryVertexBJetTags"))     );            
      AK5PF_pt500_PUID     ->Fill( j.userFloat("pileupJetId:fullDiscriminant")                                    );  
    }
    if (j.pt()>30 && fabs(j.eta())<2.4 )
    {
      AK5PF_pt30eta2p4_PT       ->Fill( j.pt()                          ); 
      AK5PF_pt30eta2p4_PHI      ->Fill( j.phi()                         ); 
      AK5PF_pt30eta2p4_ETA      ->Fill( j.eta()                         ); 
      AK5PF_pt30eta2p4_RAP      ->Fill( j.rapidity()                    ); 
      AK5PF_pt30eta2p4_MASS     ->Fill( j.mass()                        ); 
      AK5PF_pt30eta2p4_NCONST   ->Fill( j.numberOfDaughters()           ); 
      AK5PF_pt30eta2p4_AREA     ->Fill( j.jetArea()                     );  
      AK5PF_pt30eta2p4_CH_MULT  ->Fill( j.chargedMultiplicity()         );          
      AK5PF_pt30eta2p4_NE_MULT  ->Fill( j.neutralMultiplicity()         );          
      AK5PF_pt30eta2p4_CHEF     ->Fill( j.chargedHadronEnergyFraction() );  
      AK5PF_pt30eta2p4_NHEF     ->Fill( j.neutralHadronEnergyFraction() );  
      AK5PF_pt30eta2p4_CEEF     ->Fill( j.chargedEmEnergyFraction()     );      
      AK5PF_pt30eta2p4_NEEF     ->Fill( j.neutralEmEnergyFraction()     );      
      AK5PF_pt30eta2p4_CMEF     ->Fill( j.chargedMuEnergyFraction()     );            
      AK5PF_pt30eta2p4_CSV      ->Fill( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags"))              );            
      AK5PF_pt30eta2p4_ISV      ->Fill( std::max(0.f,j.bDiscriminator("combinedInclusiveSecondaryVertexBJetTags"))     );            
      AK5PF_pt30eta2p4_PUID     ->Fill( j.userFloat("pileupJetId:fullDiscriminant")                                    );  
    }
    // Select forward jets 
    if ( fabs( j.eta() )>3.0 &&  fabs( j.eta() )<5.0 )
    {
      AK5PF_forward_PT       ->Fill( j.pt()                          ); 
      AK5PF_forward_PHI      ->Fill( j.phi()                         ); 
      AK5PF_forward_ETA      ->Fill( j.eta()                         ); 
      AK5PF_forward_RAP      ->Fill( j.rapidity()                    ); 
      AK5PF_forward_MASS     ->Fill( j.mass()                        ); 
      AK5PF_forward_NCONST   ->Fill( j.numberOfDaughters()           ); 
      AK5PF_forward_AREA     ->Fill( j.jetArea()                     );  
      AK5PF_forward_CH_MULT  ->Fill( j.chargedMultiplicity()         );          
      AK5PF_forward_NE_MULT  ->Fill( j.neutralMultiplicity()         );          
      AK5PF_forward_CHEF     ->Fill( j.chargedHadronEnergyFraction() );  
      AK5PF_forward_NHEF     ->Fill( j.neutralHadronEnergyFraction() );  
      AK5PF_forward_CEEF     ->Fill( j.chargedEmEnergyFraction()     );      
      AK5PF_forward_NEEF     ->Fill( j.neutralEmEnergyFraction()     );      
      AK5PF_forward_CMEF     ->Fill( j.chargedMuEnergyFraction()     );            
      AK5PF_forward_CSV      ->Fill( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags"))              );            
      AK5PF_forward_ISV      ->Fill( std::max(0.f,j.bDiscriminator("combinedInclusiveSecondaryVertexBJetTags"))     );            
      AK5PF_forward_PUID     ->Fill( j.userFloat("pileupJetId:fullDiscriminant")                                    );  
    }
    // Select central jets 
    if ( fabs( j.eta() )<2.5 )
    {
      AK5PF_central_PT       ->Fill( j.pt()                          ); 
      AK5PF_central_PHI      ->Fill( j.phi()                         ); 
      AK5PF_central_ETA      ->Fill( j.eta()                         ); 
      AK5PF_central_RAP      ->Fill( j.rapidity()                    ); 
      AK5PF_central_MASS     ->Fill( j.mass()                        ); 
      AK5PF_central_NCONST   ->Fill( j.numberOfDaughters()           ); 
      AK5PF_central_AREA     ->Fill( j.jetArea()                     );  
      AK5PF_central_CH_MULT  ->Fill( j.chargedMultiplicity()         );          
      AK5PF_central_NE_MULT  ->Fill( j.neutralMultiplicity()         );          
      AK5PF_central_CHEF     ->Fill( j.chargedHadronEnergyFraction() );  
      AK5PF_central_NHEF     ->Fill( j.neutralHadronEnergyFraction() );  
      AK5PF_central_CEEF     ->Fill( j.chargedEmEnergyFraction()     );      
      AK5PF_central_NEEF     ->Fill( j.neutralEmEnergyFraction()     );      
      AK5PF_central_CMEF     ->Fill( j.chargedMuEnergyFraction()     );            
      AK5PF_central_CSV      ->Fill( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags"))              );            
      AK5PF_central_ISV      ->Fill( std::max(0.f,j.bDiscriminator("combinedInclusiveSecondaryVertexBJetTags"))     );            
      AK5PF_central_PUID     ->Fill( j.userFloat("pileupJetId:fullDiscriminant")                                    );  
    }
    // Select mid jets 
    if ( fabs( j.eta() )>2.5 && fabs( j.eta() )<3.0 )
    {
      AK5PF_mideta_PT       ->Fill( j.pt()                          ); 
      AK5PF_mideta_PHI      ->Fill( j.phi()                         ); 
      AK5PF_mideta_ETA      ->Fill( j.eta()                         ); 
      AK5PF_mideta_RAP      ->Fill( j.rapidity()                    ); 
      AK5PF_mideta_MASS     ->Fill( j.mass()                        ); 
      AK5PF_mideta_NCONST   ->Fill( j.numberOfDaughters()           ); 
      AK5PF_mideta_AREA     ->Fill( j.jetArea()                     );  
      AK5PF_mideta_CH_MULT  ->Fill( j.chargedMultiplicity()         );          
      AK5PF_mideta_NE_MULT  ->Fill( j.neutralMultiplicity()         );          
      AK5PF_mideta_CHEF     ->Fill( j.chargedHadronEnergyFraction() );  
      AK5PF_mideta_NHEF     ->Fill( j.neutralHadronEnergyFraction() );  
      AK5PF_mideta_CEEF     ->Fill( j.chargedEmEnergyFraction()     );      
      AK5PF_mideta_NEEF     ->Fill( j.neutralEmEnergyFraction()     );      
      AK5PF_mideta_CMEF     ->Fill( j.chargedMuEnergyFraction()     );            
      AK5PF_mideta_CSV      ->Fill( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags"))              );            
      AK5PF_mideta_ISV      ->Fill( std::max(0.f,j.bDiscriminator("combinedInclusiveSecondaryVertexBJetTags"))     );            
      AK5PF_mideta_PUID     ->Fill( j.userFloat("pileupJetId:fullDiscriminant")                                    );  
    }
    // Select b-tagged jets
    if ( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags")) >0.667   )
    {
      AK5PF_btagCSVM_PT       ->Fill( j.pt()                          ); 
      AK5PF_btagCSVM_PHI      ->Fill( j.phi()                         ); 
      AK5PF_btagCSVM_ETA      ->Fill( j.eta()                         ); 
      AK5PF_btagCSVM_RAP      ->Fill( j.rapidity()                    ); 
      AK5PF_btagCSVM_MASS     ->Fill( j.mass()                        ); 
      AK5PF_btagCSVM_NCONST   ->Fill( j.numberOfDaughters()           ); 
      AK5PF_btagCSVM_AREA     ->Fill( j.jetArea()                     );  
      AK5PF_btagCSVM_CH_MULT  ->Fill( j.chargedMultiplicity()         );          
      AK5PF_btagCSVM_NE_MULT  ->Fill( j.neutralMultiplicity()         );          
      AK5PF_btagCSVM_CHEF     ->Fill( j.chargedHadronEnergyFraction() );  
      AK5PF_btagCSVM_NHEF     ->Fill( j.neutralHadronEnergyFraction() );  
      AK5PF_btagCSVM_CEEF     ->Fill( j.chargedEmEnergyFraction()     );      
      AK5PF_btagCSVM_NEEF     ->Fill( j.neutralEmEnergyFraction()     );      
      AK5PF_btagCSVM_CMEF     ->Fill( j.chargedMuEnergyFraction()     );            
      AK5PF_btagCSVM_CSV      ->Fill( std::max(0.f,j.bDiscriminator("combinedSecondaryVertexBJetTags"))              );            
      AK5PF_btagCSVM_ISV      ->Fill( std::max(0.f,j.bDiscriminator("combinedInclusiveSecondaryVertexBJetTags"))     );            
      AK5PF_btagCSVM_PUID     ->Fill( j.userFloat("pileupJetId:fullDiscriminant")                                    );  
    }

  }


  edm::Handle<pat::JetCollection> fatjets;
  iEvent.getByToken(fatjetToken_, fatjets);
  for (const pat::Jet &j : *fatjets) {
    AK8PF_PT       ->Fill( j.pt()                                                  ); 
    AK8PF_PHI      ->Fill( j.phi()                                                 ); 
    AK8PF_ETA      ->Fill( j.eta()                                                 ); 
    AK8PF_RAP      ->Fill( j.rapidity()                                            ); 
    AK8PF_MASS     ->Fill( j.mass()                                                ); 
    AK8PF_MASSPRUNED     ->Fill( j.userFloat("ak8PFJetsCHSPrunedLinks")            ); 
    AK8PF_MASSTRIMMED    ->Fill( j.userFloat("ak8PFJetsCHSTrimmedLinks")           ); 
    AK8PF_MASSFILTERED   ->Fill( j.userFloat("ak8PFJetsCHSFilteredLinks")          );
    AK8PF_MASSTOP        ->Fill( j.userFloat("cmsTopTagPFJetsCHSLinksAK8")         );
    AK8PF_NCONST   ->Fill( j.numberOfDaughters()                                   ); 
    AK8PF_AREA     ->Fill( j.jetArea()                                             );  
    AK8PF_CH_MULT  ->Fill( j.chargedMultiplicity()                                 );          
    AK8PF_NE_MULT  ->Fill( j.neutralMultiplicity()                                 );          
    AK8PF_CHEF     ->Fill( j.chargedHadronEnergyFraction()                         );  
    AK8PF_NHEF     ->Fill( j.neutralHadronEnergyFraction()                         );  
    AK8PF_CEEF     ->Fill( j.chargedEmEnergyFraction()                             );      
    AK8PF_NEEF     ->Fill( j.neutralEmEnergyFraction()                             );      
    AK8PF_CMEF     ->Fill( j.chargedMuEnergyFraction()                             );  
  }

  edm::Handle<pat::METCollection> mets;
  iEvent.getByToken(metToken_, mets);
  const pat::MET &met = mets->front();
  MET_PT        ->Fill( met.pt()             );  
  MET_PHI       ->Fill( met.phi()            );  
  MET_SUMET     ->Fill( met.sumEt()          );  
  MET_GENMET    ->Fill( met.genMET()->pt()   );  

  edm::Handle<pat::PackedCandidateCollection> pfs;
  iEvent.getByToken(pfToken_, pfs);
  
  int count        = 0;
  int count_pos   = 0;
  int count_zero   = 0;
  int count_neg   = 0;

  int count_h         = 0;
  int count_h0        = 0;
  int count_gamma     = 0;
  int count_e         = 0;
  int count_mu        = 0;
  int count_h_HF      = 0;
  int count_egamma_HF = 0;
  int count_X         = 0;

  int count_fromPV0   = 0;
  int count_fromPV1   = 0;
  int count_fromPV2   = 0;
  int count_fromPV3   = 0;
  int count_notFromPV = 0;


  int count_pt0p2eta2p5fromPV           =0;
  int count_pt0p2eta2p5fromPV_pos       =0;
  int count_pt0p2eta2p5fromPV_zero      =0;
  int count_pt0p2eta2p5fromPV_neg       =0;
  int count_pt0p2eta2p5fromPV_h         =0;
  int count_pt0p2eta2p5fromPV_h0        =0;
  int count_pt0p2eta2p5fromPV_gamma     =0;
  int count_pt0p2eta2p5fromPV_e         =0;
  int count_pt0p2eta2p5fromPV_mu        =0;
  int count_pt0p2eta2p5fromPV_h_HF      =0;
  int count_pt0p2eta2p5fromPV_egamma_HF =0;
  int count_pt0p2eta2p5fromPV_X         =0;

  int count_pt0p2fromPV                 =0;
  int count_pt0p2fromPV_pos             =0;
  int count_pt0p2fromPV_zero            =0;
  int count_pt0p2fromPV_neg             =0;
  int count_pt0p2fromPV_h               =0;
  int count_pt0p2fromPV_h0              =0;
  int count_pt0p2fromPV_gamma           =0;
  int count_pt0p2fromPV_e               =0;
  int count_pt0p2fromPV_mu              =0;
  int count_pt0p2fromPV_h_HF            =0;
  int count_pt0p2fromPV_egamma_HF       =0;
  int count_pt0p2fromPV_X               =0;

  int count_fromPV                      =0;
  int count_fromPV_pos                  =0;
  int count_fromPV_zero                 =0;
  int count_fromPV_neg                  =0;
  int count_fromPV_h                    =0;
  int count_fromPV_h0                   =0;
  int count_fromPV_gamma                =0;
  int count_fromPV_e                    =0;
  int count_fromPV_mu                   =0;
  int count_fromPV_h_HF                 =0;
  int count_fromPV_egamma_HF            =0;
  int count_fromPV_X                    =0;

  int count_pt2fromPV                   =0;
  int count_pt2fromPV_pos               =0;
  int count_pt2fromPV_zero              =0;
  int count_pt2fromPV_neg               =0;
  int count_pt2fromPV_h                 =0;
  int count_pt2fromPV_h0                =0;
  int count_pt2fromPV_gamma             =0;
  int count_pt2fromPV_e                 =0;
  int count_pt2fromPV_mu                =0;
  int count_pt2fromPV_h_HF              =0;
  int count_pt2fromPV_egamma_HF         =0;
  int count_pt2fromPV_X                 =0;

  for (unsigned int i = 0, n = pfs->size(); i < n; ++i) {
    const pat::PackedCandidate &pf = (*pfs)[i];

    count      ++;  
    if (pf.charge() == 1 ) count_pos ++ ;  
    if (pf.charge() == 0 ) count_zero ++ ;  
    if (pf.charge() == -1) count_neg ++ ;  

    if     ( fabs(pf.pdgId())== 211 ){ count_h         ++ ;  } // cout<<" charged hadron"<<endl;  }                       
    else if( fabs(pf.pdgId())== 130 ){ count_h0        ++ ;  } // cout<<" neutral hadron"<<endl;  }                       
    else if( fabs(pf.pdgId())== 22  ){ count_gamma     ++ ;  } // cout<<" gamma"<<endl;           }              
    else if( fabs(pf.pdgId())== 11  ){ count_e         ++ ;  } // cout<<" e"<<endl;               }          
    else if( fabs(pf.pdgId())== 13  ){ count_mu        ++ ;  } // cout<<" mu"<<endl;              }           
    else if( fabs(pf.pdgId())== 1   ){ count_h_HF      ++ ;  } // cout<<" h_HF"<<endl;            }             
    else if( fabs(pf.pdgId())== 2   ){ count_egamma_HF ++ ;  } // cout<<" egamma_HF"<<endl;       }                  
    else                             { count_X         ++ ;  } // cout<<" something else"<<endl;  }

    if ( pf.fromPV()==0 ) count_fromPV0 ++ ;
    if ( pf.fromPV()>=1 ) count_fromPV1 ++ ;
    if ( pf.fromPV()>=2 ) count_fromPV2 ++ ;
    if ( pf.fromPV()>=3 ) count_fromPV3 ++ ;


    if ( pf.pt() >0.2 && fabs( pf.eta() ) < 2.5 && pf.fromPV()>=1 )
    {
                                         count_pt0p2eta2p5fromPV         ++;  
      if (pf.charge() == 1 )             count_pt0p2eta2p5fromPV_pos     ++ ;  
      if (pf.charge() == 0 )             count_pt0p2eta2p5fromPV_zero    ++ ;  
      if (pf.charge() == -1)             count_pt0p2eta2p5fromPV_neg     ++ ;  

      if     ( fabs(pf.pdgId())== 211 ){ count_pt0p2eta2p5fromPV_h         ++ ;  } // cout<<" charged hadron"<<endl;  }                       
      else if( fabs(pf.pdgId())== 130 ){ count_pt0p2eta2p5fromPV_h0        ++ ;  } // cout<<" neutral hadron"<<endl;  }                       
      else if( fabs(pf.pdgId())== 22  ){ count_pt0p2eta2p5fromPV_gamma     ++ ;  } // cout<<" gamma"<<endl;           }              
      else if( fabs(pf.pdgId())== 11  ){ count_pt0p2eta2p5fromPV_e         ++ ;  } // cout<<" e"<<endl;               }          
      else if( fabs(pf.pdgId())== 13  ){ count_pt0p2eta2p5fromPV_mu        ++ ;  } // cout<<" mu"<<endl;              }           
      else if( fabs(pf.pdgId())== 1   ){ count_pt0p2eta2p5fromPV_h_HF      ++ ;  } // cout<<" h_HF"<<endl;            }             
      else if( fabs(pf.pdgId())== 2   ){ count_pt0p2eta2p5fromPV_egamma_HF ++ ;  } // cout<<" egamma_HF"<<endl;       }                  
      else                             { count_pt0p2eta2p5fromPV_X         ++ ;  } // cout<<" something else"<<endl;  }
    }
    if ( pf.pt() >0.2 && pf.fromPV()>=1 )
    {
                             count_pt0p2fromPV      ++;  
      if (pf.charge() == 1 ) count_pt0p2fromPV_pos ++ ;  
      if (pf.charge() == 0 ) count_pt0p2fromPV_zero ++ ;  
      if (pf.charge() == -1) count_pt0p2fromPV_neg ++ ;  

      if     ( fabs(pf.pdgId())== 211 ){ count_pt0p2fromPV_h         ++ ;  } // cout<<" charged hadron"<<endl;  }                       
      else if( fabs(pf.pdgId())== 130 ){ count_pt0p2fromPV_h0        ++ ;  } // cout<<" neutral hadron"<<endl;  }                       
      else if( fabs(pf.pdgId())== 22  ){ count_pt0p2fromPV_gamma     ++ ;  } // cout<<" gamma"<<endl;           }              
      else if( fabs(pf.pdgId())== 11  ){ count_pt0p2fromPV_e         ++ ;  } // cout<<" e"<<endl;               }          
      else if( fabs(pf.pdgId())== 13  ){ count_pt0p2fromPV_mu        ++ ;  } // cout<<" mu"<<endl;              }           
      else if( fabs(pf.pdgId())== 1   ){ count_pt0p2fromPV_h_HF      ++ ;  } // cout<<" h_HF"<<endl;            }             
      else if( fabs(pf.pdgId())== 2   ){ count_pt0p2fromPV_egamma_HF ++ ;  } // cout<<" egamma_HF"<<endl;       }                  
      else                             { count_pt0p2fromPV_X         ++ ;  } // cout<<" something else"<<endl;  }
    }
    if ( pf.fromPV()>=1 )
    {
                             count_fromPV      ++;  
      if (pf.charge() == 1 ) count_fromPV_pos ++ ;  
      if (pf.charge() == 0 ) count_fromPV_zero ++ ;  
      if (pf.charge() == -1) count_fromPV_neg ++ ;  

      if     ( fabs(pf.pdgId())== 211 ){ count_fromPV_h         ++ ;  } // cout<<" charged hadron"<<endl;  }                       
      else if( fabs(pf.pdgId())== 130 ){ count_fromPV_h0        ++ ;  } // cout<<" neutral hadron"<<endl;  }                       
      else if( fabs(pf.pdgId())== 22  ){ count_fromPV_gamma     ++ ;  } // cout<<" gamma"<<endl;           }              
      else if( fabs(pf.pdgId())== 11  ){ count_fromPV_e         ++ ;  } // cout<<" e"<<endl;               }          
      else if( fabs(pf.pdgId())== 13  ){ count_fromPV_mu        ++ ;  } // cout<<" mu"<<endl;              }           
      else if( fabs(pf.pdgId())== 1   ){ count_fromPV_h_HF      ++ ;  } // cout<<" h_HF"<<endl;            }             
      else if( fabs(pf.pdgId())== 2   ){ count_fromPV_egamma_HF ++ ;  } // cout<<" egamma_HF"<<endl;       }                  
      else                             { count_fromPV_X         ++ ;  } // cout<<" something else"<<endl;  }
    }
    if ( pf.pt() >2 && pf.fromPV()>=1 )
    {
                             count_pt2fromPV      ++;  
      if (pf.charge() == 1 ) count_pt2fromPV_pos ++ ;  
      if (pf.charge() == 0 ) count_pt2fromPV_zero ++ ;  
      if (pf.charge() == -1) count_pt2fromPV_neg ++ ;  

      if     ( fabs(pf.pdgId())== 211 ){ count_pt2fromPV_h         ++ ;  } // cout<<" charged hadron"<<endl;  }                       
      else if( fabs(pf.pdgId())== 130 ){ count_pt2fromPV_h0        ++ ;  } // cout<<" neutral hadron"<<endl;  }                       
      else if( fabs(pf.pdgId())== 22  ){ count_pt2fromPV_gamma     ++ ;  } // cout<<" gamma"<<endl;           }              
      else if( fabs(pf.pdgId())== 11  ){ count_pt2fromPV_e         ++ ;  } // cout<<" e"<<endl;               }          
      else if( fabs(pf.pdgId())== 13  ){ count_pt2fromPV_mu        ++ ;  } // cout<<" mu"<<endl;              }           
      else if( fabs(pf.pdgId())== 1   ){ count_pt2fromPV_h_HF      ++ ;  } // cout<<" h_HF"<<endl;            }             
      else if( fabs(pf.pdgId())== 2   ){ count_pt2fromPV_egamma_HF ++ ;  } // cout<<" egamma_HF"<<endl;       }                  
      else                             { count_pt2fromPV_X         ++ ;  } // cout<<" something else"<<endl;  }
    }


    if ( pf.fromPV()==0 && pf.fromPV()!=1 && pf.fromPV()!=1 && pf.fromPV()!=1  ) count_notFromPV ++ ;

    // FromPV
    if ( pf.pt() >0.2 && fabs( pf.eta() ) < 2.5 && pf.fromPV()>=1 )
    {
      if ( fabs(pf.pdgId())== 211 )   //charged hadrons
      {
        PF_pt0p2eta2p5fromPV1_chargedHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV1_chargedHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV1_chargedHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 130 )  //neutral hadrons
      {
        PF_pt0p2eta2p5fromPV1_neutralHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV1_neutralHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV1_neutralHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 22 )  //gamma
      {
        PF_pt0p2eta2p5fromPV1_gamma_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV1_gamma_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV1_gamma_PHI    ->Fill(pf.phi() ); 
      }
      else if ( fabs(pf.pdgId())== 11 )  //e
      {
        PF_pt0p2eta2p5fromPV1_electron_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV1_electron_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV1_electron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 13 )  //mu
      {
        PF_pt0p2eta2p5fromPV1_muon_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV1_muon_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV1_muon_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 1 )  
      {
        PF_pt0p2eta2p5fromPV1_forwardHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV1_forwardHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV1_forwardHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 2)   
      {
        PF_pt0p2eta2p5fromPV1_forwardEgamma_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV1_forwardEgamma_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV1_forwardEgamma_PHI    ->Fill(pf.phi() );      
      }      
      else  
      {
        PF_pt0p2eta2p5fromPV1_noID_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV1_noID_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV1_noID_PHI    ->Fill(pf.phi() );      
      }
    }
    if ( pf.pt() >0.2 && pf.fromPV()>=1 )
    {
      if ( fabs(pf.pdgId())== 211 )  //charged hadrons
      {
        PF_pt0p2fromPV1_chargedHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV1_chargedHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV1_chargedHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 130)   //neutral hadrons
      {
        PF_pt0p2fromPV1_neutralHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV1_neutralHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV1_neutralHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 22)   //gamma
      {
        PF_pt0p2fromPV1_gamma_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV1_gamma_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV1_gamma_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 11)   //e
      {
        PF_pt0p2fromPV1_electron_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV1_electron_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV1_electron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 13)   //e
      {
        PF_pt0p2fromPV1_muon_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV1_muon_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV1_muon_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 1)   
      {
        PF_pt0p2fromPV1_forwardHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV1_forwardHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV1_forwardHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 2)   
      {
        PF_pt0p2fromPV1_forwardEgamma_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV1_forwardEgamma_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV1_forwardEgamma_PHI    ->Fill(pf.phi() );      
      }      
      else  
      {
        PF_pt0p2fromPV1_noID_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV1_noID_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV1_noID_PHI    ->Fill(pf.phi() );      
      }
    }
    if ( pf.pt() >0.2 && pf.pt() <2 && pf.fromPV()>=1 )
    {
      if ( fabs(pf.pdgId())== 211 )  //charged hadrons
      {
        PF_pt0p2to2fromPV1_chargedHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2to2fromPV1_chargedHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2to2fromPV1_chargedHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 130 )  //neutral hadrons
      {
        PF_pt0p2to2fromPV1_neutralHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2to2fromPV1_neutralHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2to2fromPV1_neutralHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 22 )  //gamma
      {
        PF_pt0p2to2fromPV1_gamma_PT     ->Fill(pf.pt() );
        PF_pt0p2to2fromPV1_gamma_ETA    ->Fill(pf.eta() );
        PF_pt0p2to2fromPV1_gamma_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 11 )  //e
      {
        PF_pt0p2to2fromPV1_electron_PT     ->Fill(pf.pt() );
        PF_pt0p2to2fromPV1_electron_ETA    ->Fill(pf.eta() );
        PF_pt0p2to2fromPV1_electron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 13 )  //e
      {
        PF_pt0p2to2fromPV1_muon_PT     ->Fill(pf.pt() );
        PF_pt0p2to2fromPV1_muon_ETA    ->Fill(pf.eta() );
        PF_pt0p2to2fromPV1_muon_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 1 )  
      {
        PF_pt0p2to2fromPV1_forwardHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2to2fromPV1_forwardHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2to2fromPV1_forwardHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 2  ) 
      {
        PF_pt0p2to2fromPV1_forwardEgamma_PT     ->Fill(pf.pt() );
        PF_pt0p2to2fromPV1_forwardEgamma_ETA    ->Fill(pf.eta() );
        PF_pt0p2to2fromPV1_forwardEgamma_PHI    ->Fill(pf.phi() );      
      }      
      else  
      {
        PF_pt0p2to2fromPV1_noID_PT     ->Fill(pf.pt() );
        PF_pt0p2to2fromPV1_noID_ETA    ->Fill(pf.eta() );
        PF_pt0p2to2fromPV1_noID_PHI    ->Fill(pf.phi() );      
      }
    }

    //NotFromPV
    if ( pf.pt() >0.2 && fabs( pf.eta() ) < 2.5 && pf.fromPV()==0 )
    {
      if ( fabs(pf.pdgId())== 211 )  //charged hadrons
      {
        PF_pt0p2eta2p5fromPV0_chargedHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV0_chargedHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV0_chargedHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 130 )  //neutral hadrons
      {
        PF_pt0p2eta2p5fromPV0_neutralHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV0_neutralHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV0_neutralHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 22 )  //gamma
      {
        PF_pt0p2eta2p5fromPV0_gamma_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV0_gamma_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV0_gamma_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 11 )  //e
      {
        PF_pt0p2eta2p5fromPV0_electron_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV0_electron_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV0_electron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 13 )  //e
      {
        PF_pt0p2eta2p5fromPV0_muon_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV0_muon_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV0_muon_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 1 )  
      {
        PF_pt0p2eta2p5fromPV0_forwardHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV0_forwardHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV0_forwardHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 2 )  
      {
        PF_pt0p2eta2p5fromPV0_forwardEgamma_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV0_forwardEgamma_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV0_forwardEgamma_PHI    ->Fill(pf.phi() );      
      }      
      else  
      {
        PF_pt0p2eta2p5fromPV0_noID_PT     ->Fill(pf.pt() );
        PF_pt0p2eta2p5fromPV0_noID_ETA    ->Fill(pf.eta() );
        PF_pt0p2eta2p5fromPV0_noID_PHI    ->Fill(pf.phi() );      
      }
    }
    if ( pf.pt() >0.2 && pf.fromPV()==0  )
    {
      if ( fabs(pf.pdgId())== 211  )  //charged hadrons
      {
        PF_pt0p2fromPV0_chargedHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV0_chargedHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV0_chargedHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 130 )  //neutral hadrons
      {
        PF_pt0p2fromPV0_neutralHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV0_neutralHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV0_neutralHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 22 )  //gamma
      {
        PF_pt0p2fromPV0_gamma_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV0_gamma_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV0_gamma_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 11 )  //e
      {
        PF_pt0p2fromPV0_electron_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV0_electron_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV0_electron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 13 )  //e
      {
        PF_pt0p2fromPV0_muon_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV0_muon_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV0_muon_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 1 )  
      {
        PF_pt0p2fromPV0_forwardHadron_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV0_forwardHadron_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV0_forwardHadron_PHI    ->Fill(pf.phi() );      
      }
      else if ( fabs(pf.pdgId())== 2  ) 
      {
        PF_pt0p2fromPV0_forwardEgamma_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV0_forwardEgamma_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV0_forwardEgamma_PHI    ->Fill(pf.phi() );      
      }      
      else  
      {
        PF_pt0p2fromPV0_noID_PT     ->Fill(pf.pt() );
        PF_pt0p2fromPV0_noID_ETA    ->Fill(pf.eta() );
        PF_pt0p2fromPV0_noID_PHI    ->Fill(pf.phi() );      
      }
    }


        if(  pf.pt() > 0.2 && pf.fromPV()>=1  ) 
        {
           if (fabs(pf.pdgId())== 22) PFcheck_pt0p2fromPV1_gamma_ETA    ->Fill(pf.eta() );
           if (fabs(pf.pdgId())== 11) PFcheck_pt0p2fromPV1_electron_ETA    ->Fill(pf.eta() );
        } 
        if(  pf.pt() > 0.2 && pf.pt() < 1.0  && pf.fromPV()>=1  ) 
        {
           if (fabs(pf.pdgId())== 22) PFcheck_pt0p2to1p0fromPV1_gamma_ETA    ->Fill(pf.eta() );
           if (fabs(pf.pdgId())== 11) PFcheck_pt0p2to1p0fromPV1_electron_ETA    ->Fill(pf.eta() );
        } 
        if(  pf.pt() > 1.0 && pf.pt() < 2.0  && pf.fromPV()>=1  ) 
        {
           if (fabs(pf.pdgId())== 22) PFcheck_pt1p0to2p0fromPV1_gamma_ETA    ->Fill(pf.eta() );
           if (fabs(pf.pdgId())== 11) PFcheck_pt1p0to2p0fromPV1_electron_ETA    ->Fill(pf.eta() );
        } 
        if(  pf.pt() > 2.0 && pf.pt() < 5.0  && pf.fromPV()>=1  ) 
        {
           if (fabs(pf.pdgId())== 22) PFcheck_pt2p0to5p0fromPV1_gamma_ETA    ->Fill(pf.eta() );
           if (fabs(pf.pdgId())== 11) PFcheck_pt2p0to5p0fromPV1_electron_ETA    ->Fill(pf.eta() );
        } 
        if(  pf.pt() > 5.0 && pf.pt() < 10.0  && pf.fromPV()>=1  ) 
        {
           if (fabs(pf.pdgId())== 22) PFcheck_pt5p0to10p0fromPV1_gamma_ETA    ->Fill(pf.eta() );
           if (fabs(pf.pdgId())== 11) PFcheck_pt5p0to10p0fromPV1_electron_ETA    ->Fill(pf.eta() );
        } 
        if(  pf.pt() > 10.0 && pf.fromPV()>=1  ) 
        {
           if (fabs(pf.pdgId())== 22) PFcheck_pt10fromPV1_gamma_ETA    ->Fill(pf.eta() );
           if (fabs(pf.pdgId())== 11) PFcheck_pt10fromPV1_electron_ETA    ->Fill(pf.eta() );
        } 


    //cout<<"chargedHadronMultiplicity "<<pf.chargedHadronMultiplicity() <<endl;
    PF_CHARGE ->Fill(pf.charge() );
    PF_PT     ->Fill(pf.pt() );
    PF_ETA    ->Fill(pf.eta() );
    PF_PHI    ->Fill(pf.phi() );
    if (pf.charge() == 0) { 
      PF_NEUTRAL_PT  ->Fill(pf.pt() ); 
      PF_NEUTRAL_ETA ->Fill(pf.eta() );
      PF_NEUTRAL_PHI ->Fill(pf.phi() );
    }
    if (pf.charge() != 0) { 
      PF_CHARGED_PT  ->Fill(pf.pt() ); 
      PF_CHARGED_ETA ->Fill(pf.eta() );
      PF_CHARGED_PHI ->Fill(pf.phi() );
    }
    if (pf.fromPV() >= 1){
      PF_PV_PT ->Fill(pf.pt() );
      PF_PV_CHARGE->Fill(pf.charge() );
      PF_PV_ETA ->Fill(pf.eta() );
      PF_PV_PHI ->Fill(pf.phi() );
    }
    if (pf.fromPV() ==0 ){
      PF_PU_PT ->Fill(pf.pt() );
      PF_PU_CHARGE->Fill(pf.charge() );
      PF_PU_ETA ->Fill(pf.eta() );
      PF_PU_PHI ->Fill(pf.phi() );
    }


  }

  PF_MULT                 ->Fill( count );
  PF_MULT_fromPV0         ->Fill( count_fromPV0 );
  PF_MULT_fromPV1         ->Fill( count_fromPV1 );
  PF_MULT_NEUTRAL         ->Fill( count_zero );
  PF_MULT_CHARGED         ->Fill( count_pos+count_neg  );
  PF_MULT_chargedHadron   ->Fill( count_h        );
  PF_MULT_neutralHadron   ->Fill( count_h0       );
  PF_MULT_gamma           ->Fill( count_gamma    );
  PF_MULT_electron        ->Fill( count_e        );
  PF_MULT_muon            ->Fill( count_mu       );
  PF_MULT_forwardHadron   ->Fill( count_h_HF     );
  PF_MULT_forwardEgamma   ->Fill( count_egamma_HF);
  PF_MULT_noID            ->Fill( count_X        );



PF_MULT_pt0p2eta2p5fromPV                ->Fill(  count_pt0p2eta2p5fromPV                                     );      
PF_MULT_pt0p2eta2p5fromPV_CHARGED        ->Fill(  count_pt0p2eta2p5fromPV_pos + count_pt0p2eta2p5fromPV_neg   );                                   
PF_MULT_pt0p2eta2p5fromPV_NEUTRAL        ->Fill(  count_pt0p2eta2p5fromPV_zero                                );      
PF_MULT_pt0p2eta2p5fromPV_chargedHadron  ->Fill(  count_pt0p2eta2p5fromPV_h                                   );      
PF_MULT_pt0p2eta2p5fromPV_neutralHadron  ->Fill(  count_pt0p2eta2p5fromPV_h0                                  );      
PF_MULT_pt0p2eta2p5fromPV_gamma          ->Fill(  count_pt0p2eta2p5fromPV_gamma                               );      
PF_MULT_pt0p2eta2p5fromPV_electron       ->Fill(  count_pt0p2eta2p5fromPV_e                                   );                                           
PF_MULT_pt0p2eta2p5fromPV_muon           ->Fill(  count_pt0p2eta2p5fromPV_mu                                  );         
PF_MULT_pt0p2eta2p5fromPV_forwardHadron  ->Fill(  count_pt0p2eta2p5fromPV_h_HF                                );         
PF_MULT_pt0p2eta2p5fromPV_forwardEgamma  ->Fill(  count_pt0p2eta2p5fromPV_egamma_HF                            );         
PF_MULT_pt0p2eta2p5fromPV_noID           ->Fill(  count_pt0p2eta2p5fromPV_X                                   );     

PF_MULT_pt0p2fromPV                         ->Fill(  count_pt0p2fromPV                                     );      
PF_MULT_pt0p2fromPV_CHARGED                 ->Fill(  count_pt0p2fromPV_pos + count_pt0p2eta2p5fromPV_neg   );                                   
PF_MULT_pt0p2fromPV_NEUTRAL                 ->Fill(  count_pt0p2fromPV_zero                                );      
PF_MULT_pt0p2fromPV_chargedHadron           ->Fill(  count_pt0p2fromPV_h                                   );      
PF_MULT_pt0p2fromPV_neutralHadron           ->Fill(  count_pt0p2fromPV_h0                                  );      
PF_MULT_pt0p2fromPV_gamma                   ->Fill(  count_pt0p2fromPV_gamma                               );      
PF_MULT_pt0p2fromPV_electron                ->Fill(  count_pt0p2fromPV_e                                   );                                           
PF_MULT_pt0p2fromPV_muon                    ->Fill(  count_pt0p2fromPV_mu                                  );         
PF_MULT_pt0p2fromPV_forwardHadron           ->Fill(  count_pt0p2fromPV_h_HF                                );         
PF_MULT_pt0p2fromPV_forwardEgamma           ->Fill(  count_pt0p2fromPV_egamma_HF                            );         
PF_MULT_pt0p2fromPV_noID                    ->Fill(  count_pt0p2fromPV_X                                   );     

PF_MULT_fromPV                              ->Fill(  count_fromPV                                     );      
PF_MULT_fromPV_CHARGED                      ->Fill(  count_fromPV_pos + count_pt0p2eta2p5fromPV_neg   );                                   
PF_MULT_fromPV_NEUTRAL                      ->Fill(  count_fromPV_zero                                );      
PF_MULT_fromPV_chargedHadron                ->Fill(  count_fromPV_h                                   );      
PF_MULT_fromPV_neutralHadron                ->Fill(  count_fromPV_h0                                  );      
PF_MULT_fromPV_gamma                        ->Fill(  count_fromPV_gamma                               );      
PF_MULT_fromPV_electron                     ->Fill(  count_fromPV_e                                   );                                           
PF_MULT_fromPV_muon                         ->Fill(  count_fromPV_mu                                  );         
PF_MULT_fromPV_forwardHadron                ->Fill(  count_fromPV_h_HF                                );         
PF_MULT_fromPV_forwardEgamma                ->Fill(  count_fromPV_egamma_HF                            );         
PF_MULT_fromPV_noID                         ->Fill(  count_fromPV_X                                   );     

PF_MULT_pt2fromPV                         ->Fill(  count_pt2fromPV                                     );      
PF_MULT_pt2fromPV_CHARGED                 ->Fill(  count_pt2fromPV_pos + count_pt0p2eta2p5fromPV_neg   );                                   
PF_MULT_pt2fromPV_NEUTRAL                 ->Fill(  count_pt2fromPV_zero                                );      
PF_MULT_pt2fromPV_chargedHadron           ->Fill(  count_pt2fromPV_h                                   );      
PF_MULT_pt2fromPV_neutralHadron           ->Fill(  count_pt2fromPV_h0                                  );      
PF_MULT_pt2fromPV_gamma                   ->Fill(  count_pt2fromPV_gamma                               );      
PF_MULT_pt2fromPV_electron                ->Fill(  count_pt2fromPV_e                                   );                                           
PF_MULT_pt2fromPV_muon                    ->Fill(  count_pt2fromPV_mu                                  );         
PF_MULT_pt2fromPV_forwardHadron           ->Fill(  count_pt2fromPV_h_HF                                );         
PF_MULT_pt2fromPV_forwardEgamma           ->Fill(  count_pt2fromPV_egamma_HF                            );         
PF_MULT_pt2fromPV_noID                    ->Fill(  count_pt2fromPV_X                                   );     

         
         // AK15 filtered
  edm::Handle<std::vector<pat::Jet> > AK15JETSFILTERED;
  iEvent.getByLabel( "patJetsAK15CHSfilteredPacked", AK15JETSFILTERED );
  edm::Handle<std::vector<pat::Jet> > ak15filtsubjets;
  iEvent.getByLabel( "patJetsAK15CHSfilteredSubjets", ak15filtsubjets );

  int count_AK15JETSFILTERED =0;
  for ( std::vector<pat::Jet>::const_iterator jetBegin = AK15JETSFILTERED->begin(), jetEnd = AK15JETSFILTERED->end(), ijet = jetBegin; ijet != jetEnd; ++ijet ) 
  {
    if (count_AK15JETSFILTERED >2 ) break;
    count_AK15JETSFILTERED++;
    double pt            = ijet->pt();
    if (pt<200) continue;
    double phi           = ijet->phi();
    double eta           = ijet->eta();
    double rapidity      = ijet->rapidity();
    double mass          = ijet->mass();
    int    nconst      = ijet->numberOfDaughters();
    double bdisc         = ijet->bDiscriminator("combinedSecondaryVertexBJetTags");
    double area          = ijet->jetArea();
    double ntracks       = ijet->associatedTracks().size();
    double flavour       = abs(ijet->partonFlavour());

    reco::Candidate::LorentzVector uncorrJet = ijet->correctedP4(0);
    double massuncorr = uncorrJet.mass();
     
    if (verbose) cout<<"Filt "<<count_AK15JETSFILTERED<<"  pt "<<pt<<" mass "<<mass<<" nconst "<<nconst<<" ntracks "<<ntracks<<" bdisc "<<bdisc<< " area "<<area<<endl;

    double maxbdisc = -20;
    double maxbdiscpartonflavour = -999;
    for (int i = 0; i < nconst; i++ ) {
      reco::Candidate const * subjet =  ijet->daughter(i);
      pat::Jet const * patsubjet = dynamic_cast<pat::Jet const *>(subjet);
      double sbdisc = patsubjet->bDiscriminator("combinedSecondaryVertexBJetTags");
      double spartonflavour = abs(patsubjet->partonFlavour());
      if (sbdisc  > maxbdisc ) {maxbdisc = sbdisc; maxbdiscpartonflavour =spartonflavour; }
      if (verbose) cout<<"  subjet pt "<<patsubjet->pt()<<"  mass "<<patsubjet->mass()<<"  bdisc "<<patsubjet->bDiscriminator("combinedSecondaryVertexBJetTags") <<" area "<< patsubjet->jetArea() <<endl;
    }


    AK15FILT_PT                    ->Fill( pt);              
    AK15FILT_PHI                   ->Fill( phi);              
    AK15FILT_ETA                   ->Fill( eta);              
    AK15FILT_RAP                   ->Fill( rapidity);              
    AK15FILT_MASS                  ->Fill( mass);              
    AK15FILT_NCONST                ->Fill( nconst);              
    AK15FILT_BDISC                 ->Fill( bdisc);              
    AK15FILT_AREA                  ->Fill( area);              
    AK15FILT_NTRACKS               ->Fill( ntracks);              
    AK15FILT_FLAVOUR               ->Fill( flavour);              
    AK15FILT_MASS_UNCORR           ->Fill( massuncorr);
    AK15FILT_MAXSUBJETBDISC        ->Fill( maxbdisc);
    AK15FILT_MAXSUBJETBDISCFLAVOUR ->Fill( maxbdiscpartonflavour);

  }    


    edm::Handle<std::vector<pat::Jet> > CMSTTJETS;
    iEvent.getByLabel( "patJetsCMSTopTagCHSPacked", CMSTTJETS );
    int count_CMSTTJETS=0;
    for ( std::vector<pat::Jet>::const_iterator jetBegin = CMSTTJETS->begin(), jetEnd = CMSTTJETS->end(), ijet = jetBegin; ijet != jetEnd; ++ijet ) 
    {
      if (count_CMSTTJETS >2 ) break;
      double pt            = ijet->pt();
      count_CMSTTJETS++;
      if (pt<400) continue;
      double phi           = ijet->phi();
      double eta           = ijet->eta();
      double rapidity      = ijet->rapidity();
      double mass          = ijet->mass();
      int    nconst        = ijet->numberOfDaughters();
      double bdisc         = ijet->bDiscriminator("combinedSecondaryVertexBJetTags");
      double area          = ijet->jetArea();
      double ntracks       = ijet->associatedTracks().size();
      double flavour       = abs(ijet->partonFlavour());

      reco::Candidate::LorentzVector uncorrJet = ijet->correctedP4(0);
      double massuncorr = uncorrJet.mass();


      double minmass   = -1;
      double maxbdisc  = -20;
      double maxbdiscpartonflavour = -999;
      math::XYZTLorentzVector SumSubjets;

      if (nconst>=3){
        reco::Candidate const * c0 =  ijet->daughter(0);
        reco::Candidate const * c1 =  ijet->daughter(1);
        reco::Candidate const * c2 =  ijet->daughter(2);

        pat::Jet const * subjet0 = dynamic_cast<pat::Jet const *>(c0);
        pat::Jet const * subjet1 = dynamic_cast<pat::Jet const *>(c1);
        pat::Jet const * subjet2 = dynamic_cast<pat::Jet const *>(c2);

        math::XYZTLorentzVector Pair01(subjet0->p4()+subjet1->p4());
        math::XYZTLorentzVector Pair02(subjet0->p4()+subjet2->p4());
        math::XYZTLorentzVector Pair12(subjet1->p4()+subjet2->p4());

        double min3 = std::min(Pair01.mass(), Pair02.mass() );
        minmass = std::min(min3, Pair12.mass() );             
      }

      if (verbose) cout<<"CMS "<<count_CMSTTJETS<<"  pt "<<pt<<" mass "<<mass<<" nconst "<<nconst<<" ntracks "<<ntracks<<" bdisc "<<bdisc<< " area "<<area<<" minmass "<<minmass<<endl;
      
      for (int i = 0; i < nconst; i++ ) {
        reco::Candidate const * subjet =  ijet->daughter(i);
        pat::Jet const * patsubjet = dynamic_cast<pat::Jet const *>(subjet);        
        double sbdisc = patsubjet->bDiscriminator("combinedSecondaryVertexBJetTags");
        double spartonflavour = abs(patsubjet->partonFlavour());
        if (sbdisc  > maxbdisc ) {maxbdisc = sbdisc; maxbdiscpartonflavour =spartonflavour; }
        SumSubjets+=patsubjet->p4();
        if (verbose) cout<<"  subjet pt "<<patsubjet->pt()<<"  mass "<<patsubjet->mass()<<"  bdisc "<<patsubjet->bDiscriminator("combinedSecondaryVertexBJetTags") <<" area "<< patsubjet->jetArea() <<endl;
      }
      double groommass = SumSubjets.mass();
      if (verbose)cout<<" groommass"<<groommass<<" maxbdisc "<<maxbdisc<<endl;


      CMS_PT                    ->Fill( pt);              
      CMS_PHI                   ->Fill( phi);              
      CMS_ETA                   ->Fill( eta);              
      CMS_RAP                   ->Fill( rapidity);              
      CMS_MASS                  ->Fill( mass);              
      CMS_NCONST                ->Fill( nconst);              
      CMS_BDISC                 ->Fill( bdisc);              
      CMS_AREA                  ->Fill( area);              
      CMS_NTRACKS               ->Fill( ntracks);              
      CMS_FLAVOUR               ->Fill( flavour);              
      CMS_MASS_UNCORR           ->Fill( massuncorr);
      CMS_MAXSUBJETBDISC        ->Fill( maxbdisc);
      CMS_MAXSUBJETBDISCFLAVOUR ->Fill( maxbdiscpartonflavour);
      CMS_GROOMMASS             ->Fill( groommass);      
      CMS_MINMASS               ->Fill( minmass);      

    }



    edm::Handle<std::vector<pat::Jet> > HEPTTJETS;
    iEvent.getByLabel( "patJetsHEPTopTagCHSPacked", HEPTTJETS );
    int count_HEPTTJETS=0;
    for ( std::vector<pat::Jet>::const_iterator jetBegin = HEPTTJETS->begin(), jetEnd = HEPTTJETS->end(), ijet = jetBegin; ijet != jetEnd; ++ijet ) 
    {
      if (count_HEPTTJETS >2 ) break;
      double pt            = ijet->pt();
      count_HEPTTJETS++;
      if (pt<200) continue;
      double phi           = ijet->phi();
      double eta           = ijet->eta();
      double rapidity      = ijet->rapidity();
      double mass          = ijet->mass();
      int    nconst        = ijet->numberOfDaughters();
      double bdisc         = ijet->bDiscriminator("combinedSecondaryVertexBJetTags");
      double area          = ijet->jetArea();
      double ntracks       = ijet->associatedTracks().size();
      double flavour       = abs(ijet->partonFlavour());

      reco::Candidate::LorentzVector uncorrJet = ijet->correctedP4(0);
      double massuncorr = uncorrJet.mass();

      if (verbose) cout<<"HEP "<<count_HEPTTJETS<<"  pt "<<pt<<" mass "<<mass<<" nconst "<<nconst<<" ntracks "<<ntracks<<" bdisc "<<bdisc<< " area "<<area<<endl;
      double maxbdisc=-20;
      double maxbdiscpartonflavour = -999;
      for (int i = 0; i < nconst; i++ ) {
        reco::Candidate const * subjet =  ijet->daughter(i);
        pat::Jet const * patsubjet = dynamic_cast<pat::Jet const *>(subjet);
        double sbdisc = patsubjet->bDiscriminator("combinedSecondaryVertexBJetTags");
        double spartonflavour = abs(patsubjet->partonFlavour());
        if (sbdisc  > maxbdisc ) {maxbdisc = sbdisc; maxbdiscpartonflavour =spartonflavour; }
        if (verbose) cout<<"  subjet pt "<<patsubjet->pt()<<"  mass "<<patsubjet->mass()<<"  bdisc "<<patsubjet->bDiscriminator("combinedSecondaryVertexBJetTags") <<" area "<< patsubjet->jetArea() <<endl;
      }
 

      if (nconst>=3){
        reco::Candidate const * c0 =  ijet->daughter(0);
        reco::Candidate const * c1 =  ijet->daughter(1);
        reco::Candidate const * c2 =  ijet->daughter(2);

        pat::Jet const * subjet0 = dynamic_cast<pat::Jet const *>(c0);
        pat::Jet const * subjet1 = dynamic_cast<pat::Jet const *>(c1);
        pat::Jet const * subjet2 = dynamic_cast<pat::Jet const *>(c2);

        math::XYZTLorentzVector Trip012(subjet0->p4()+subjet1->p4()+subjet2->p4());
        math::XYZTLorentzVector Pair01( subjet0->p4()+subjet1->p4() );
        math::XYZTLorentzVector Pair02( subjet0->p4()+subjet2->p4() );
        math::XYZTLorentzVector Pair12( subjet1->p4()+subjet2->p4() );

        double M12M012 = -1;
        double AtanM02M01 = -1;
        if ( Trip012.mass()!=0 ) M12M012     =  Pair12.mass() / Trip012.mass();
        if ( Pair01.mass()!=0 )  AtanM02M01  = atan( Pair02.mass() / Pair01.mass() ) ; 
        if (verbose) cout<<" Trip012 "<<Trip012.mass()<<" M12M012 "<<M12M012<<" AtanM02M01 "<<AtanM02M01<<endl;


        HEP_PT                    ->Fill( pt);                                
        HEP_PHI                   ->Fill( phi);                               
        HEP_ETA                   ->Fill( eta);                               
        HEP_RAP                   ->Fill( rapidity);                           
        HEP_MASS                  ->Fill( mass);                                                   
        HEP_NCONST                ->Fill( nconst);                                                   
        HEP_BDISC                 ->Fill( bdisc);                                      
        HEP_AREA                  ->Fill( area);                                      
        HEP_NTRACKS               ->Fill( ntracks);                                      
        HEP_FLAVOUR               ->Fill( flavour);                                      
        HEP_MASS_UNCORR           ->Fill( massuncorr);                        
        HEP_MAXSUBJETBDISC        ->Fill( maxbdisc);                        
        HEP_MAXSUBJETBDISCFLAVOUR ->Fill( maxbdiscpartonflavour);                        
        HEP_M123                  ->Fill( Trip012.mass());                         
        HEP_M12                   ->Fill( Pair01.mass());                         
        HEP_M13                   ->Fill( Pair02.mass());                         
        HEP_M23                   ->Fill( Pair12.mass());                         
        HEP_M23M123               ->Fill( M12M012);                         
        HEP_ATANM13M12            ->Fill( AtanM02M01);                         
        HEP_ATANM13M12_M23M123    ->Fill( AtanM02M01,M12M012);                        




      }
      if (verbose) cout<<"last line of hep loop"<<endl;

    }

}

//define this as a plug-in
DEFINE_FWK_MODULE(AnalyzeMiniPlusSubstructure);
