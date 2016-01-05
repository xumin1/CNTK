# End-to-end tests

The CNTK end-to-end tests can be run on Linux and Windows using the python 
script "TestDriver.py" located in <CNTK Repo root>\Tests\EndToEndTests. 
Alternatively they can be run and debugged from Visual Studio. In the following 
we detail:
* How to use the TestDriver.py script.
* Prerequisites to use TestDriver.py on Windows.
* How to run and debug end-to-end tests from Visual studio.

## How to use the TestDriver.py script.

TODO: Usage and Options

## Prerequisites to use TestDriver.py on Windows.

1) Install the latest version of Python 2.7 (NOT 3.5!) from 
https://www.python.org/downloads/windows/
Accept default installation options.
2) Install CygWin from http://cygwin.com/install.html
During installation select "Install from Internet" (default selection)
IMPORTANT! At Select Packages screen type "yaml" to search field and expand 
the Python section. Select "python-yaml: Python Lib YAML bindings" 
(NOT "python3-yaml"). Then finish installation.
3) Make sure you have Microsoft MPI installed (there should be an environment 
variable named MSMPI_BIN)
4) Run CygWin
5) In CygWin shell change directory to the Tests\EndToEndTests folder of your 
local CNTK repository (note: c:\src\cnkt in CygWin is /cygdrive/c/src/cntk/).

Note: Some tests require an environment variable named 
CNTK_EXTERNAL_TESTDATA_SOURCE_DIRECTORY pointing to where the data resides. 
If the external data is not available those tests will be skipped.

## How to run and debug end-to-end tests from Visual Studio.

TODO: -n example + point to file
