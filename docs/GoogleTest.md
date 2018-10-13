############ Google test
[1/2 VStudio]
1. clone googletest repo; Open googletest/googletest/msvs/2010/gtest.sln; Target=Release; Build All;
2. In your VStudio project > Open Project (not solution) Setting:
2.1 VC++ Directories> Include Directories: Add "[...]/googletest/googletest/include/" 
2.2 VC++ Directories> Library Directories: Add "[...]/googletest/googletest/msvs/2010/gtest/Win32-Release/" 
2.3 Linker>Input>Additional Dependencies: Add "gtest_main.lib" and "gtest.lib" 
2.4 C/C++>Code Generation>Runtime Library: /MD -> /MT
3. Fixing Integeration with VStudio TestRunner: Extensions > "Google Test Adapter"
[1/2 MacOs]
1. Build gtest for mac: clone googletest repo; cd googletest/googletest; mkdir build; cd build; cmake ../; make;
2. => We will have "googletest/googletest/build/lib/libgtest_main.a" and "[...]/libgtest.a"
3. In your xcode project > Click top-most node of structure in the left panel to see setting > Within the opened setting panel, set the top menubar as "project" (not any specific target. it will change available settings) > Build Setting > Search Paths
3.1 Header Search Path = /Users/emadpres/CodingProjects/libs/googletest/googletest/include
3.2 Library Search Path = /Users/emadpres/CodingProjects/libs/googletest/googletest/build/lib
4. Turn to target's setting > General > Linked Framework and Libraries > Add both "gtest_main.a" and "gtest.a"
5. Fixing Integeration with xCode TestRunner: https://github.com/mattstevens/xcode-googletest
5.1 Clone repo
5.2 In your xCode project:File>Add New Target>macOS Unit Testing Bundle>Set name (Let's say "UT") and language as Objective-C.
	This adds a folder "UT" to proeject structure
5.3 RightClick "UT" folder>Add Files to ...: Select "[...]/xcode-googletest/Bundle/GoogleTests.mm"
5.4 Product > Scheme > "UT" [If after cliking it didn't work, do next line (5.5) and do this again]
5.5 Product > Scheme > Edit Scheme > Executable > [your project name]
5.6 Open your unit testing file, on the Right-side Inspector panel > Target Memebership > Checkmark "UT"
5.7 Open Project Setting > Select "UT"'s setting > Build Phase > Link Binary With Libries: Add "gtest_main.a" and "gtest.a" 
5.8 Product > Test :)

[2/2 Eventually]
Build these two line:
	#include <gtest/gtest.h>
	TEST(aa, bb){ASSERT_TRUE(true);}