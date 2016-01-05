# Unit tests and end-to-end tests

The unit tests and end-to-end tests provided in this folder are run as part 
of the checkin workflow on the build server. You can run all tests locally 
to verify that your code changes didn't break any test.

If you followed the install instructions and installed Boost on your machine 
you should see the unit tests in the Visual Studio Test Explorer. You can run 
and debug the unit tests from there. We recall the required steps below.

How to run and debug end-to-end tests is described in the README file in the 
EndToEndTests folder.

## Boost Unit tests

We are using the BOOST library (http://www.boost.org/) for unit tests. We are 
probably going to incorporate the BOOST library into CNTK code in the future. 
We are currently using BOOST 1.59. Download and install boost version 1.59 
(you need msvc-12.0 binaries) from here: 
http://sourceforge.net/projects/boost/files/boost-binaries/1.59.0/boost_1_59_0-msvc-12.0-64.exe/download 

Set the environment variable BOOST_INCLUDE PATH to your boost installation, e.g.:

    BOOST_INCLUDE_PATH=c:\local\boost_1_59_0

Set the environment variable BOOST_LIB_PATH to the boost libraries, e.g.:

    BOOST_LIB_PATH=c:\local\boost_1_59_0\lib64-msvc-12.0

To integrate BOOST into the Visual Studio test framework you can install a 
runner for BOOST tests in VS from here: 
https://visualstudiogallery.msdn.microsoft.com/5f4ae1bd-b769-410e-8238-fb30beda987f 

Restart Visual Studio and goto to the 'Test --> Test Settings' menu. There set 
the default processor architecture to x64 and uncheck the option 'Keep Test 
Execution Engine Running'. In the Test Explorer window select Group by Traits 
(next to the search field). After a rebuild you should see all unit tests in 
the Test Explorer. You can run and debug using the the context menu.
