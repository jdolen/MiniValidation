import FWCore.ParameterSet.Config as cms

###############################################
useMiniAOD = True

# AOD
pfcandidates          = 'particleFlow'
chsstring             = 'pfNoPileUpJME'
genjetparticles       = 'genParticles'
importantgenparticles = 'genParticles'
tracks                = 'generalTracks'
vertices              = 'offlinePrimaryVertices'
mergedvertices        = 'inclusiveMergedVertices' 
mergedvertices2       = '' 
primaryvertices       = 'offlinePrimaryVertices'

#miniAOD
if useMiniAOD:
  pfcandidates          = 'packedPFCandidates'
  genjetparticles       = 'packedGenParticles'
  importantgenparticles = 'prunedGenParticles'
  tracks                = 'unpackedTracksAndVertices'
  vertices              = 'unpackedTracksAndVertices'
  mergedvertices        = 'unpackedTracksAndVertices'
  mergedvertices2       = 'secondary'
  primaryvertices       = 'offlineSlimmedPrimaryVertices'


print 'useMiniAOD = '+str(useMiniAOD)
print ' pfcandidates          = '+pfcandidates         
print ' genjetparticles       = '+genjetparticles      
print ' importantgenparticles = '+importantgenparticles
print ' tracks                = '+tracks               
print ' vertices              = '+vertices             
print ' mergedvertices        = '+mergedvertices       
print ' mergedvertices2       = '+mergedvertices2      
print ' primaryvertices       = '+primaryvertices 


###############################################
# SETUP
process = cms.Process("USER")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(False) , allowUnscheduled = cms.untracked.bool(True) )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )


###############################################
# SOURCE
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/02ACCAE2-FB26-E411-AC80-002590D0B05A.root',    
      'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/02DB51E6-F626-E411-8D5F-E0CB4E19F976.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/04AF8C44-BF26-E411-9C02-00259073E4A0.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/061877C0-F726-E411-BFC7-20CF3019DF0C.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/0637BBBE-0427-E411-89BD-00259073E324.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/0A30732D-FA26-E411-9A59-E0CB4E29C4FD.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/0AE5CE9D-0527-E411-B309-00259073E3FC.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/0AFC9C56-F426-E411-9086-0025907B4EF2.root',	
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/0C1B4731-FE26-E411-A4F4-0025907B502A.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/0E06D103-E726-E411-8618-00259073E398.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/10AA277D-D526-E411-8D3A-485B39800BB9.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/1229DF06-FF26-E411-80D7-002590D0B002.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/126DAE5B-CE26-E411-9A74-00259073E504.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/14640CFC-F426-E411-B282-20CF3027A5F3.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/16A2E42A-E526-E411-A593-002590D0B0B4.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/16A46FEC-DC26-E411-B56C-525400A40E5C.root',
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/16B88970-0227-E411-9785-002590D0AFD8.root', 
      #'root://cmsxrootd-site.fnal.gov//store/mc/Spring14miniaod/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU40bx25_POSTLS170_V7-v2/00000/00800BE3-E826-E411-AD01-20CF3019DEE9.root'
  )
)

###############################################
# ANA
process.demo = cms.EDAnalyzer("AnalyzeMiniPlusSubstructure",
    vertices = cms.InputTag("offlineSlimmedPrimaryVertices"),
    muons = cms.InputTag("slimmedMuons"),
    electrons = cms.InputTag("slimmedElectrons"),
    taus = cms.InputTag("slimmedTaus"),
    photons = cms.InputTag("slimmedPhotons"),
    jets = cms.InputTag("slimmedJets"),
    fatjets = cms.InputTag("slimmedJetsAK8"),
    mets = cms.InputTag("slimmedMETs"),
    pfCands = cms.InputTag("packedPFCandidates"),
)

process.TFileService = cms.Service("TFileService",
      fileName = cms.string("histos_TTJets_premix_mini_PU40bx25_file2.root"),
      closeFileFast = cms.untracked.bool(True)
  )

###############################################
# RECO AND GEN SETUP
process.load('PhysicsTools.PatAlgos.producersLayer1.patCandidates_cff')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.Geometry_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'START70_V6::All'

process.load('RecoJets.Configuration.RecoPFJets_cff')
process.load('RecoJets.Configuration.RecoGenJets_cff')
#process.fixedGridRhoFastjetAll.pfCandidatesTag = pfcandidates
process.fixedGridRhoFastjetAll.pfCandidatesTag = 'packedPFCandidates'
process.fixedGridRhoAll.pfCandidatesTag        = 'packedPFCandidates'
# process.fixedGridRhoAll.pfCandidatesTag = .InputTag("packedPFCandidates")
# process.fixedGridRhoFastjetAll = fixedGridRhoFastjetAll.clone( pfCandidatesTag = cms.InputTag("packedPFCandidates"))
# process.fixedGridRhoAll = fixedGridRhoAll.clone( pfCandidatesTag = cms.InputTag("packedPFCandidates"))


from RecoJets.JetProducers.SubJetParameters_cfi import SubJetParameters
from RecoJets.JetProducers.PFJetParameters_cfi import *
from RecoJets.JetProducers.CaloJetParameters_cfi import *
from RecoJets.JetProducers.AnomalousCellParameters_cfi import *
from RecoJets.JetProducers.CATopJetParameters_cfi import *
from RecoJets.JetProducers.GenJetParameters_cfi import *
from RecoJets.JetProducers.caTopTaggers_cff import *


###############################################
# GEN JETS


from RecoJets.JetProducers.ca4GenJets_cfi import ca4GenJets
from RecoJets.JetProducers.ak5GenJets_cfi import ak5GenJets

process.ak3GenJets = ak5GenJets.clone( rParam = cms.double(0.3),
                                           src = cms.InputTag(genjetparticles))


process.ak15GenJets = ak5GenJets.clone( rParam = cms.double(1.5),
                                           src = cms.InputTag(genjetparticles))

process.ak15GenJetsFiltered = ak5GenJets.clone(
  rParam = cms.double(1.5),
  src = cms.InputTag(genjetparticles),
  useFiltering = cms.bool(True),
  nFilt = cms.int32(3),
  rFilt = cms.double(0.3),
  writeCompound = cms.bool(True),
  jetCollInstanceName=cms.string("SubJets")
  )


process.cmsTopTagGEN = cms.EDProducer(
    "CATopJetProducer",
    GenJetParameters.clone(src = cms.InputTag(genjetparticles),
                           doAreaFastjet = cms.bool(False),
                           doRhoFastjet = cms.bool(False)),
    AnomalousCellParameters,
    CATopJetParameters,
    jetAlgorithm = cms.string("CambridgeAachen"),
    rParam = cms.double(0.8),
    writeCompound = cms.bool(True)
    )

process.hepTopTagGEN = process.cmsTopTagGEN.clone(
    rParam = cms.double(1.5),
    tagAlgo = cms.int32(2), #2=fastjet heptt
    muCut = cms.double(0.8),
    maxSubjetMass = cms.double(30.0),
    useSubjetMass = cms.bool(False),
)

###############################################
# RECO JETS



process.chs = cms.EDFilter("CandPtrSelector", src = cms.InputTag("packedPFCandidates"), cut = cms.string("fromPV>=1"))
chsstring = 'chs'

# process.ak4PFJets.src = pfcandidates
# process.ak15PFJets = process.ak4PFJets.clone(rParam = 1.5,  doAreaFastjet = True)
# process.ak15CHSJets = process.ak15PFJets.clone(src = chsstring)

process.load('RecoJets.JetProducers.ak4PFJetsFiltered_cfi')
process.ak15CHSJetsFiltered = process.ak4PFJetsFiltered.clone(rParam=1.5,  doAreaFastjet = True, src = chsstring)



# CATopJet PF Jets with adjacency 
#process.cmsTopTagCHS = cmsTopTagPFJetsCHS.clone()
process.cmsTopTagCHS = cms.EDProducer(
    "CATopJetProducer",
    PFJetParameters.clone( src = cms.InputTag(chsstring),
                           doAreaFastjet = cms.bool(True),
                           doRhoFastjet = cms.bool(False),
                           jetPtMin = cms.double(100.0)
                           ),
    AnomalousCellParameters,
    CATopJetParameters.clone( jetCollInstanceName = cms.string("SubJets"), 
                              verbose = cms.bool(False),
                              algorithm = cms.int32(1),                 # 0 = KT, 1 = CA, 2 = anti-KT
                              tagAlgo = cms.int32(0),                   #0=legacy top
                              useAdjacency = cms.int32(2),              # modified adjacency
                              centralEtaCut = cms.double(2.5),          # eta for defining "central" jets
                              sumEtBins = cms.vdouble(0,1600,2600),     # sumEt bins over which cuts vary. vector={bin 0 lower bound, bin 1 lower bound, ...}
                              rBins = cms.vdouble(0.8,0.8,0.8),         # Jet distance paramter R. R values depend on sumEt bins.
                              ptFracBins = cms.vdouble(0.05,0.05,0.05), # minimum fraction of central jet pt for subjets (deltap)
                              deltarBins = cms.vdouble(0.19,0.19,0.19), # Applicable only if useAdjacency=1. deltar adjacency values for each sumEtBin
                              nCellBins = cms.vdouble(1.9,1.9,1.9), 
                            ),
    jetAlgorithm = cms.string("CambridgeAachen"),
    rParam = cms.double(0.8),
    writeCompound = cms.bool(True)
    )

process.cmsTopTagFJCHS = process.cmsTopTagCHS.clone(
    tagAlgo = cms.int32(1), # 1=fastjet cmstagger
    ptFrac = cms.double(0.05),
    rFrac = cms.double(0.4),
    adjacencyParam = cms.double(0.0004),
)

process.hepTopTagCHS = process.cmsTopTagCHS.clone(
    rParam = cms.double(1.5),
    tagAlgo = cms.int32(2), #2=fastjet heptt
    muCut = cms.double(0.8),
    maxSubjetMass = cms.double(30.0),
    useSubjetMass = cms.bool(False),
)




process.CATopTagInfos = cms.EDProducer("CATopJetTagger",
                                    src = cms.InputTag("cmsTopTagCHS"),
                                    TopMass = cms.double(171),
                                    TopMassMin = cms.double(0.),
                                    TopMassMax = cms.double(250.),
                                    WMass = cms.double(80.4),
                                    WMassMin = cms.double(0.0),
                                    WMassMax = cms.double(200.0),
                                    MinMassMin = cms.double(0.0),
                                    MinMassMax = cms.double(200.0),
                                    verbose = cms.bool(False)
                                    )

process.cmsTopTagFJCHSTagInfos = process.CATopTagInfos.clone(
  src = cms.InputTag("cmsTopTagFJCHS")
)

process.hepTopTagCHSTagInfos = process.CATopTagInfos.clone(
  src = cms.InputTag("hepTopTagCHS")
)


###############################################
# PAT JETS

from PhysicsTools.PatAlgos.tools.jetTools import *

process.load('RecoBTag.Configuration.RecoBTag_cff')
process.load('RecoJets.Configuration.RecoJetAssociations_cff')
process.load('PhysicsTools.PatAlgos.slimming.unpackedTracksAndVertices_cfi')

# fix JTA (see https://github.com/cms-sw/cmssw/tree/CMSSW_7_0_X/RecoJets/JetAssociationProducers/python)
process.ak5JetTracksAssociatorAtVertexPF.jets = cms.InputTag("ak4PFJets")
process.ak5JetTracksAssociatorAtVertexPF.tracks = cms.InputTag(tracks)
process.impactParameterTagInfos.primaryVertex = cms.InputTag(vertices)
process.inclusiveSecondaryVertexFinderTagInfos.extSVCollection = cms.InputTag(mergedvertices,mergedvertices2,"")
process.combinedSecondaryVertex.trackMultiplicityMin = 1


#AK15CHS Filt
addJetCollection(
    process,
    labelName = 'AK15CHSfiltered',
    jetSource = cms.InputTag('ak15CHSJetsFiltered'),
    jetCorrections = ('AK7PFchs', cms.vstring(['L1FastJet', 'L2Relative', 'L3Absolute']), 'None'),
    trackSource = cms.InputTag(tracks),
    pvSource = cms.InputTag(vertices),
    btagDiscriminators = ['combinedSecondaryVertexBJetTags'],
    )

process.patJetPartonMatchAK15CHSfiltered.matched=importantgenparticles
process.patJetCorrFactorsAK15CHSfiltered.primaryVertices = primaryvertices
process.patJetGenJetMatchAK15CHSfiltered.matched = 'ak15GenJetsFiltered'#'slimmedGenJets'
process.patJetPartonMatchAK15CHSfiltered.matched = importantgenparticles
process.jetTracksAssociatorAtVertexAK15CHSfiltered=process.ak5JetTracksAssociatorAtVertexPF.clone(jets = cms.InputTag('ak15CHSJetsFiltered'), coneSize = 1.5)
process.secondaryVertexTagInfosAK15CHSfiltered.trackSelection.jetDeltaRMax = cms.double(1.5) # default is 0.3
process.secondaryVertexTagInfosAK15CHSfiltered.vertexCuts.maxDeltaRToJetAxis = cms.double(1.5) # default is 0.5
process.combinedSecondaryVertexAK15CHSfiltered= process.combinedSecondaryVertex.clone()
process.combinedSecondaryVertexAK15CHSfiltered.trackSelection.jetDeltaRMax = cms.double(1.5)
process.combinedSecondaryVertexAK15CHSfiltered.trackPseudoSelection.jetDeltaRMax = cms.double(1.5)
process.combinedSecondaryVertexBJetTagsAK15CHSfiltered.jetTagComputer = cms.string('combinedSecondaryVertexAK15CHSfiltered')

process.patJetCorrFactorsAK15CHSfiltered.rho = 'fixedGridRhoFastjetAll'


addJetCollection(
    process,
    labelName = 'AK15CHSfilteredSubjets',
    jetSource = cms.InputTag('ak15CHSJetsFiltered','SubJets'),
    jetCorrections = ('AK7PFchs', cms.vstring(['L1FastJet', 'L2Relative', 'L3Absolute']), 'None'),
    trackSource = cms.InputTag(tracks),
    pvSource = cms.InputTag(vertices),
    btagDiscriminators = ['combinedSecondaryVertexBJetTags'],
    getJetMCFlavour = False,
    )
process.patJetPartonMatchAK15CHSfilteredSubjets.matched=importantgenparticles
process.patJetCorrFactorsAK15CHSfilteredSubjets.primaryVertices = primaryvertices
process.patJetGenJetMatchAK15CHSfilteredSubjets.matched = 'ak3GenJets'#slimmedGenJets'
process.patJetPartonMatchAK15CHSfilteredSubjets.matched = importantgenparticles
process.patJetCorrFactorsAK15CHSfiltered.rho = 'fixedGridRhoFastjetAll'

process.patJetsAK15CHSfilteredPacked = cms.EDProducer("BoostedJetMerger",
    jetSrc=cms.InputTag("patJetsAK15CHSfiltered" ),
    subjetSrc=cms.InputTag("patJetsAK15CHSfilteredSubjets")
      )



# patJetsCMSTopTagCHS
addJetCollection(
    process,
    labelName = 'CMSTopTagCHS',
    jetSource = cms.InputTag('cmsTopTagCHS'),
    jetCorrections = ('AK7PFchs', cms.vstring(['L1FastJet', 'L2Relative', 'L3Absolute']), 'None'),
    trackSource = cms.InputTag(tracks),
    pvSource = cms.InputTag(vertices),
    btagDiscriminators = ['combinedSecondaryVertexBJetTags'],
        # btagInfos = [
        # 'CATopTagInfos'
        #  ]   
    )
process.patJetPartonMatchCMSTopTagCHS.matched=importantgenparticles
process.patJetCorrFactorsCMSTopTagCHS.primaryVertices = primaryvertices
process.patJetGenJetMatchCMSTopTagCHS.matched = 'ca8GenJetsPruned'#'slimmedGenJets'
process.patJetPartonMatchCMSTopTagCHS.matched = importantgenparticles
process.jetTracksAssociatorAtVertexCMSTopTagCHS=process.ak5JetTracksAssociatorAtVertexPF.clone(jets = cms.InputTag('cmsTopTagCHS'), coneSize = 0.8)
process.secondaryVertexTagInfosCMSTopTagCHS.trackSelection.jetDeltaRMax = cms.double(0.8) # default is 0.3
process.secondaryVertexTagInfosCMSTopTagCHS.vertexCuts.maxDeltaRToJetAxis = cms.double(0.8) # default is 0.5
process.combinedSecondaryVertexCMSTopTagCHS= process.combinedSecondaryVertex.clone()
process.combinedSecondaryVertexCMSTopTagCHS.trackSelection.jetDeltaRMax = cms.double(0.8)
process.combinedSecondaryVertexCMSTopTagCHS.trackPseudoSelection.jetDeltaRMax = cms.double(0.8)
process.combinedSecondaryVertexBJetTagsCMSTopTagCHS.jetTagComputer = cms.string('combinedSecondaryVertexCMSTopTagCHS')
process.patJetsCMSTopTagCHS.addTagInfos = True
process.patJetsCMSTopTagCHS.tagInfoSources = cms.VInputTag(
    cms.InputTag('CATopTagInfos')
    )

addJetCollection(
    process,
    labelName = 'CMSTopTagCHSSubjets',
    jetSource = cms.InputTag('cmsTopTagCHS','SubJets'),
    jetCorrections = ('AK7PFchs', cms.vstring(['L1FastJet', 'L2Relative', 'L3Absolute']), 'None'),
    trackSource = cms.InputTag(tracks),
    pvSource = cms.InputTag(vertices),
    btagDiscriminators = ['combinedSecondaryVertexBJetTags'],
    getJetMCFlavour = False,
    )
process.patJetPartonMatchCMSTopTagCHSSubjets.matched=importantgenparticles
process.patJetCorrFactorsCMSTopTagCHSSubjets.primaryVertices = primaryvertices
process.patJetGenJetMatchCMSTopTagCHSSubjets.matched = 'cmsTopTagGENSubJets'#slimmedGenJets'
process.patJetPartonMatchCMSTopTagCHSSubjets.matched = importantgenparticles

process.patJetsCMSTopTagCHSPacked = cms.EDProducer("BoostedJetMerger",
    jetSrc=cms.InputTag("patJetsCMSTopTagCHS" ),
    subjetSrc=cms.InputTag("patJetsCMSTopTagCHSSubjets")
      )



# patJetsHEPTopTagCHS
addJetCollection(
    process,
    labelName = 'HEPTopTagCHS',
    jetSource = cms.InputTag('hepTopTagCHS'),
    jetCorrections = ('AK7PFchs', cms.vstring(['L1FastJet', 'L2Relative', 'L3Absolute']), 'None'),
    trackSource = cms.InputTag(tracks),
    pvSource = cms.InputTag(vertices),
    btagDiscriminators = ['combinedSecondaryVertexBJetTags'],
    )
process.patJetPartonMatchHEPTopTagCHS.matched=importantgenparticles
process.patJetCorrFactorsHEPTopTagCHS.primaryVertices = primaryvertices
process.patJetGenJetMatchHEPTopTagCHS.matched = 'ca8GenJetsPruned'#'slimmedGenJets'
process.patJetPartonMatchHEPTopTagCHS.matched = importantgenparticles
process.jetTracksAssociatorAtVertexHEPTopTagCHS=process.ak5JetTracksAssociatorAtVertexPF.clone(jets = cms.InputTag('hepTopTagCHS'), coneSize = 1.5)
process.secondaryVertexTagInfosHEPTopTagCHS.trackSelection.jetDeltaRMax = cms.double(1.5) # default is 0.3
process.secondaryVertexTagInfosHEPTopTagCHS.vertexCuts.maxDeltaRToJetAxis = cms.double(1.5) # default is 0.5
process.combinedSecondaryVertexHEPTopTagCHS= process.combinedSecondaryVertex.clone()
process.combinedSecondaryVertexHEPTopTagCHS.trackSelection.jetDeltaRMax = cms.double(1.5)
process.combinedSecondaryVertexHEPTopTagCHS.trackPseudoSelection.jetDeltaRMax = cms.double(1.5)
process.combinedSecondaryVertexBJetTagsHEPTopTagCHS.jetTagComputer = cms.string('combinedSecondaryVertexHEPTopTagCHS')
process.patJetsHEPTopTagCHS.addTagInfos = True
process.patJetsHEPTopTagCHS.tagInfoSources = cms.VInputTag(
    cms.InputTag('hepTopTagCHSTagInfos')
    )

addJetCollection(
    process,
    labelName = 'HEPTopTagCHSSubjets',
    jetSource = cms.InputTag('hepTopTagCHS','SubJets'),
    jetCorrections = ('AK7PFchs', cms.vstring(['L1FastJet', 'L2Relative', 'L3Absolute']), 'None'),
    trackSource = cms.InputTag(tracks),
    pvSource = cms.InputTag(vertices),
    btagDiscriminators = ['combinedSecondaryVertexBJetTags'],
    getJetMCFlavour = False,
    )
process.patJetPartonMatchHEPTopTagCHSSubjets.matched=importantgenparticles
process.patJetCorrFactorsHEPTopTagCHSSubjets.primaryVertices = primaryvertices
process.patJetGenJetMatchHEPTopTagCHSSubjets.matched = 'ak3GenJets'#slimmedGenJets'
process.patJetPartonMatchHEPTopTagCHSSubjets.matched = importantgenparticles

process.patJetsHEPTopTagCHSPacked = cms.EDProducer("BoostedJetMerger",
    jetSrc=cms.InputTag("patJetsHEPTopTagCHS" ),
    subjetSrc=cms.InputTag("patJetsHEPTopTagCHSSubjets")
      )


###############################################
# Modifify all

for jetcoll in (process.patJetsAK15CHSfiltered,
                process.patJetsAK15CHSfilteredSubjets,
                process.patJetsCMSTopTagCHS,
                process.patJetsCMSTopTagCHSSubjets,
                process.patJetsHEPTopTagCHS,
                process.patJetsHEPTopTagCHSSubjets
                ) :
        jetcoll.embedGenJetMatch = False
        jetcoll.getJetMCFlavour = False
        jetcoll.addGenPartonMatch = False

###############################################

process.content = cms.EDAnalyzer("EventContentAnalyzer")


process.p = cms.Path(
  #process.fixedGridRhoFastjetAll
  process.ak15GenJetsFiltered
  *process.ak15CHSJetsFiltered
  *process.cmsTopTagCHS
  *process.hepTopTagCHS
  *process.CATopTagInfos
  *process.hepTopTagCHSTagInfos
  *process.patJetsAK15CHSfiltered
  *process.patJetsAK15CHSfilteredSubjets
  *process.patJetsAK15CHSfilteredPacked
  *process.patJetsCMSTopTagCHS
  *process.patJetsCMSTopTagCHSSubjets
  *process.patJetsCMSTopTagCHSPacked
  *process.patJetsHEPTopTagCHS
  *process.patJetsHEPTopTagCHSSubjets
  *process.patJetsHEPTopTagCHSPacked
  # *process.content
  *process.demo
  )
