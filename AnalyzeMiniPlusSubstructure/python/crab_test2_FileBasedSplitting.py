from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'TTJets_PU40bx25_ClassicMixing_50files_test2'

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ana_crab.py'
config.JobType.allowNonProductionCMSSW = False
config.JobType.outputFiles = ['out.root']

config.section_("Data")
config.Data.inputDataset = '/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/Spring14miniaod-PU40bx25_POSTLS170_V5-v2/MINIAODSIM'
config.Data.dbsUrl = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.totalUnits = 50
config.Data.publication = True
config.Data.publishDbsUrl = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter/'
config.Data.publishDataName = 'Spring14miniaod-PU40bx25_POSTLS170_V5-v2_ANA'
#config.Data.outlfn = '/store/user/lpccsa14/'                                                                                                                                                              
config.Data.ignoreLocality = False

config.section_("Site")
config.Site.storageSite = 'T3_US_FNALLPC'
