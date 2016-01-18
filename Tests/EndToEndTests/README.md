# End-to-end tests

The CNTK end-to-end tests can be run on Linux and Windows using the python 
script "TestDriver.py" located in <CNTK Repo root>\Tests\EndToEndTests. 
Alternatively they can be run and debugged from Visual Studio. In the following 
we detail:
* How to use the TestDriver.py script.
* Prerequisites to use TestDriver.py on Windows.
* How to run and debug end-to-end tests from Visual studio.

## How to use the TestDriver.py script.

Start a CygWin shell and change directory to the Tests\EndToEndTests folder of 
your local CNTK repository (note: c:\src\cnkt in CygWin is /cygdrive/c/src/cntk/).
Start with one of the following commands to learn the usage and options of the 
TestDriver:

`python TestDriver.py -h`
`python TestDriver.py run -h`
`python TestDriver.py list -h`

To list all available end-to-end tests run

`python TestDriver.py list`

To run a single test, for example Image/QuickE2E, execute

`python TestDriver.py run Image/QuickE2E`

You can add for example '-d gpu' to only run the test using a GPU or '-f debug' 
to  only run the test using the debug build. See `python TestDriver.py run -h` 
for all options.

To run all tests from the nightly builds execute

`python TestDriver.py run -t nightly`

## Prerequisites to use TestDriver.py on Windows.

1) Install the latest version of Python 2.7 (NOT 3.5!) from 
https://www.python.org/downloads/windows/ Accept default installation options.
2) Install CygWin from http://cygwin.com/install.html During installation select 
"Install from Internet" (default selection).
IMPORTANT: At Select Packages screen type "yaml" in the search field and expand 
the Python section. Select "python-yaml: Python Lib YAML bindings" 
(NOT "python3-yaml"). Then finish installation.
3) Make sure you have Microsoft MPI installed (there should be an environment 
variable named MSMPI_BIN)

Note: Some tests require an environment variable named 
CNTK_EXTERNAL_TESTDATA_SOURCE_DIRECTORY pointing to where the data resides. 
If the external data is not available those tests will be skipped.

## How to run and debug end-to-end tests from Visual Studio.

You can generate the Visual Studio debug command arguments using the `-n` options
on the TestDriver for a specific end-to-end test:

`python TestDriver.py run -n Image/QuickE2E`

From the output of the above command you simply copy the 'VS debugging command args' 
to the command arguments of the CNTK project in Visual Studio (Right click on CNTK 
project -> Properties -> Configuration Properties -> Debugging -> Command Arguments). 
Start debugging the CNTK project.
