Copy-pasteable command lines for debugging the Tests\EndToEndTests\Speech tests in VS
=====================================================================================

Note: Below, the current dir is sometimes set to be the data directory. This allows for local paths in data scripts.

--- Speech\QuickE2E:

COMMAND:     currentDirectory=$(SolutionDir)Tests\EndToEndTests\Speech\Data  configFile=$(SolutionDir)Tests\EndToEndTests\Speech\QuickE2E\cntk.config  stderr=$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\QuickE2E\models\cntkSpeech.dnn.log  RunDir=$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\QuickE2E  DataDir=.  DeviceId=auto  makeMode=false

Linux:      bin/cntk  currentDirectory=Tests/EndToEndTests/Speech/Data  configFile=../QuickE2E/cntk.config  stderr=../RunDir/QuickE2E/models/cntkSpeech.dnn.log  RunDir=../RunDir/QuickE2E  DataDir=.  DeviceId=auto  makeMode=false

--- Speech\Simple:

COMMAND:    currentDirectory=$(SolutionDir)Tests\EndToEndTests\Speech\Data  configFile=..\Simple\cntk.config  RunDir=$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\Simple  stderr=../RunDir/Simple/models/cntkSpeech.dnn.log  DataDir=$(SolutionDir)Tests\EndToEndTests\Speech\Data  ConfigDir=$(SolutionDir)Tests\EndToEndTests\Speech\Simple  DeviceId=auto  makeMode=false

--- Speech\LSTM\Truncated:

COMMAND:     currentDirectory=$(SolutionDir)Tests\EndToEndTests\Speech\Data  configFile=$(SolutionDir)Tests\EndToEndTests\Speech\LSTM\cntk.config  stderr=$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\LSTM\Truncated\models\cntkSpeech.dnn.log  RunDir=$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\LSTM\Truncated  NdlDir=$(SolutionDir)Tests\EndToEndTests\Speech\LSTM  DataDir=.  DeviceId=auto  makeMode=false

Linux:      bin/cntk  currentDirectory=Tests/EndToEndTests/Speech/Data  configFile=../LSTM/cntk.config  stderr=../RunDir/LSTM/Truncated/models/cntkSpeech.dnn.log  RunDir=../RunDir/LSTM/Truncated  NdlDir=../LSTM  DataDir=.  DeviceId=auto  makeMode=false

Using full BrainScript configuration

COMMAND:    --cd $(SolutionDir)Tests\EndToEndTests\Speech\Data  -f $(SolutionDir)Tests\EndToEndTests\Speech\LSTM\lstm.bs  -D stderr='$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\LSTM\Truncated\models\cntkSpeech.dnn.log'  -D RunDir='$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\LSTM\Truncated'  -D DataDir='.'  -D DeviceId='auto'  -D makeMode=false

--- Speech\LSTM\FullUtterance:

COMMAND:     currentDirectory=$(SolutionDir)Tests\EndToEndTests\Speech\Data  configFile=$(SolutionDir)Tests\EndToEndTests\Speech\LSTM\cntk.config  stderr=$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\LSTM\FullUtterance\models\cntkSpeech.dnn.log  RunDir=$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\LSTM\FullUtterance  NdlDir=$(SolutionDir)Tests\EndToEndTests\Speech\LSTM  DataDir=.  DeviceId=auto  Truncated=false  speechTrain=[reader=[nbruttsineachrecurrentiter=1]] speechTrain=[SGD=[epochSize=2560]]  speechTrain=[SGD=[maxEpochs=2]]  speechTrain=[SGD=[numMBsToShowResult=1]]  makeMode=false

Using parallel sequences (difference to above: nbruttsineachrecurrentiter=4). Note that this will produce a different result since we are confused about what MB size means:

COMMAND:     currentDirectory=$(SolutionDir)Tests\EndToEndTests\Speech\Data  configFile=$(SolutionDir)Tests\EndToEndTests\Speech\LSTM\cntk.config  stderr=$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\LSTM\FullUtterance\models\cntkSpeech.dnn.log  RunDir=$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\LSTM\FullUtterance  NdlDir=$(SolutionDir)Tests\EndToEndTests\Speech\LSTM  DataDir=.  DeviceId=auto  Truncated=false  speechTrain=[reader=[nbruttsineachrecurrentiter=2]]  speechTrain=[SGD=[epochSize=2560]]  speechTrain=[SGD=[learningRatesPerMB=0.125]]  speechTrain=[SGD=[maxEpochs=2]]  speechTrain=[SGD=[numMBsToShowResult=1]]  makeMode=false  shareNodeValueMatrices=true

Linux:      bin/cntk  currentDirectory=Tests/EndToEndTests/Speech/Data  configFile=../LSTM/cntk.config  stderr=../RunDir/LSTM/Truncated/models/cntkSpeech.dnn.log  RunDir=../RunDir/LSTM/Truncated  NdlDir=../LSTM  DataDir=.  DeviceId=auto  Truncated=false  'speechTrain=[reader=[nbruttsineachrecurrentiter=4]]'  'speechTrain=[SGD=[epochSize=2560]]'  'speechTrain=[SGD=[learningRatesPerMB=0.125]]'  'speechTrain=[SGD=[maxEpochs=2]]'  'speechTrain=[SGD=[numMBsToShowResult=1]]'  makeMode=false

Using full BrainScript configuration

COMMAND:     --cd $(SolutionDir)Tests\EndToEndTests\Speech\Data  -f $(SolutionDir)Tests\EndToEndTests\Speech\LSTM\lstm.bs  -D stderr='$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\LSTM\FullUtterance\models\cntkSpeech.dnn.log'  -D RunDir='$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\LSTM\FullUtterance'  -D NdlDir='$(SolutionDir)Tests\EndToEndTests\Speech\LSTM'  -D DataDir='.'  -D DeviceId='Auto'  -D Truncated=false  -D speechTrain=[reader=[nbruttsineachrecurrentiter=1];SGD=[epochSize=2560;maxEpochs=2;numMBsToShowResult=1]]  -D makeMode=false

--- Speech\DiscriminativePreTraining:  --currently fails with MEL error 'Parameter name could not be resolved 'HL2.y'

COMMAND:     currentDirectory=$(SolutionDir)Tests\EndToEndTests\Speech\Data  configFile=..\DNN\DiscriminativePreTraining\cntk_dpt.config  stderr=$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\DNN\DiscriminativePreTraining\models\cntkSpeech.dnn.log  ConfigDir=$(SolutionDir)Tests\EndToEndTests\Speech\DNN\DiscriminativePreTraining  RunDir=..\RunDir\DNN\DiscriminativePreTraining  DataDir=.  DeviceId=auto  makeMode=false

--- Speech\SequenceTraining:

set CNTK_EXTERNAL_TESTDATA_SOURCE_DIRECTORY=\\storage.ccp.philly.selfhost.corp.microsoft.com\public\CNTKTestData
COMMAND:    currentDirectory=\\storage.ccp.philly.selfhost.corp.microsoft.com\public\CNTKTestData  configFile=$(SolutionDir)Tests\EndToEndTests\Speech\DNN\SequenceTraining\cntk_sequence.config  RunDir=$(SolutionDir)Tests\EndToEndTests\Speech\RunDir\DNN\SequenceTraining  DataDir=.  ConfigDir=$(SolutionDir)Tests\EndToEndTests\Speech\DNN\SequenceTraining  DeviceId=0

--- MNIST:

COMMAND:     currentDirectory=$(SolutionDir)ExampleSetups\Image\MNIST  configFile=02_Conv.config configName=02_Conv

--- Image/QuickE2E:

COMMAND:     configFile=$(SolutionDir)Tests\EndToEndTests\Image\QuickE2E\cntk.config  RunDir=$(SolutionDir)Tests\EndToEndTests\Image\_run  DataDir=$(SolutionDir)Tests\EndToEndTests\Image\Data  ConfigDir=$(SolutionDir)Tests\EndToEndTests\Image\QuickE2E  stderr=$(SolutionDir)Tests\EndToEndTests\RunDir\Image\QuickE2E\models\cntkImage.dnn.log  DeviceId=0  useCuDnn=false   makeMode=false

Simple test
-----------

COMMAND:     currentDirectory=$(SolutionDir)Demos\Simple  configFile=Simple.config  stderr=RunDir\Simple.config.log  RootDir=$(SolutionDir)  DeviceNumber=-1
