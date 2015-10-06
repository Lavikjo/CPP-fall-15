#include <sstream>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <ctime>

#include "softwarew.hpp"
#include "bugw.hpp"

size_t EXCEPT_B = 0;
size_t EXCEPT_S = 0;

std::vector<Bug> createRandomBugs(size_t howMany) {
    // Arrays containing the possible pseudo random data to generate pseudo random bugs
    static std::vector<std::string> idPrefixes = {"MB-", "NPA-", "NIL-", "AR-"};
    static std::vector<std::string> descriptions = {"Crashes the software during close", "A graphic bug in window manager"};

    // Create a vector of random bugs
    std::vector<Bug> bugs;  

    // Create and array of used postfixes and select an id prefix
    std::vector<size_t> usedPostfixes;
    std::string idPrefix = idPrefixes[rand() % idPrefixes.size()];

    for (size_t i = 0; i < howMany; i++) {
        std::string id = idPrefix;
        size_t postfix = (rand() % 899) + 100;

        while (std::find(usedPostfixes.begin(), usedPostfixes.end(), postfix) != usedPostfixes.end()) {
            postfix = (rand() % 899) + 100;
        }

        // Add to used postfixes
        usedPostfixes.push_back(postfix);

        // Convert the postfix to a string
        std::ostringstream convert;
        convert << postfix;    
        id += convert.str();

        // Construct the bug and append to the vector
        bugs.push_back(Bug(id, descriptions[rand()%descriptions.size()], (Priority)(rand()%5)));
    }

    return bugs;
}


Software createRandomSoftware() {
    std::vector<std::string> names = {"Lindows 7", "New Goblin", "Twittler"};
    Software sw(names[rand()%names.size()], (rand()%1000) + 1);
    return sw;
}


int main() {
    // Seed the random
    srand(time(0));

    std::cout << "*** Creating two random sets of Bugs (non-const and const).." << std::endl;
    std::vector<Bug> bugs = createRandomBugs((rand()%10)+2);
    std::vector<Bug> bugsConst = createRandomBugs((rand()%10)+2);

    std::cout << "*** Testing the getId function.." << std::endl;
    std::cout << "The getId function returned: " << bugsConst[rand()%bugsConst.size()].getId() << std::endl;
    std::cout << "The getId function returned: " << bugs[rand()%bugs.size()].getId() << std::endl;
    std::cout << "The getId function returned: " << bugsConst[rand()%bugsConst.size()].getId() << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing the getDescription function.." << std::endl;
    std::cout << "The getDescription function returned: " << bugsConst[rand()%bugsConst.size()].getDescription() << std::endl;
    std::cout << "The getDescription function returned: " << bugs[rand()%bugs.size()].getDescription() << std::endl;
    std::cout << "The getDescription function returned: " << bugsConst[rand()%bugsConst.size()].getDescription() << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing the getPriority function.." << std::endl;
    std::vector<std::string> priorities = {"Trivial", "Minor", "Major", "Critical", "Blocker"};
    std::cout << "The getPriority function returned: " << priorities[bugsConst[rand()%bugsConst.size()].getPriority()] << std::endl;
    std::cout << "The getPriority function returned: " << priorities[bugs[rand()%bugs.size()].getPriority()] << std::endl;
    std::cout << "The getPriority function returned: " << priorities[bugsConst[rand()%bugsConst.size()].getPriority()] << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing the isFixed function.." << std::endl;
    std::vector<std::string> boolean = {"False", "True"};
    std::cout << "The isFixed function returned: " << boolean[bugsConst[rand()%bugsConst.size()].isFixed()] << std::endl;
    std::cout << "The isFixed function returned: " << boolean[bugs[rand()%bugs.size()].isFixed()] << std::endl;
    std::cout << "The isFixed function returned: " << boolean[bugsConst[rand()%bugsConst.size()].isFixed()] << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing the fix function.." << std::endl;
    for (size_t i = 0; i < 3; i++) {
        size_t idx = rand()%bugs.size();
        bugs[idx].fix();
        std::cout << "The isFixed function now returned: " << bugs[idx].isFixed() << std::endl;
    }
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing the ostream, << -operator overloading.." << std::endl;
    std::cout << bugsConst[rand()%bugsConst.size()];
    std::cout << bugs[rand()%bugs.size()];
    std::cout << bugsConst[rand()%bugsConst.size()];
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing copying through the copy constructor.." << std::endl;
    size_t idx = rand()%bugsConst.size();
    Bug bcopied1 = Bug(bugsConst[idx]);
    std::cout << "Original: " << bugsConst[idx];
    std::cout << "Copied..: " << bcopied1;

    idx = rand()%bugs.size();
    Bug bcopied2 = Bug(bugs[idx]);
    std::cout << "Original: " << bugs[idx];
    std::cout << "Copied..: " << bcopied2;
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing the assignment operator.." << std::endl;
    idx = rand()%bugsConst.size();
    Bug bassigned1 = bugsConst[idx];
    std::cout << "Original: " << bugsConst[idx];
    std::cout << "Assigned: " << bassigned1;

    idx = rand()%bugs.size();
    Bug bassigned2 = bugs[idx];
    std::cout << "Original: " << bugs[idx];
    std::cout << "Assigned: " << bassigned2;

    std::cout << "*** Testing self assigning.." << std::endl;
    idx = rand()%bugs.size();
    bugs[idx] = bugs[idx];
    std::cout << "Self assigned: " << bugs[idx];
    std::cout << "*** END OF READ ***" << std::endl;
    // Test the Bug wrapper exceptions
    EXCEPT_B = 1;
    std::cout << "*** Testing constructor exception handling.." << std::endl;
    try {
        Bug bug1("ID-1337", "Exception handling is cool", BLOCKER);
    }
    catch (const std::runtime_error& e) {
        std::cout << "Constructor exception catched successfully" << std::endl;
    }

    std::cout << "*** Testing copy constructor exception handling.." << std::endl;
    try {
        Bug bug2("ID-7474", "Handle your exceptions gracefully", BLOCKER);
        Bug copy(bug2);
    }
    catch (const std::runtime_error& e) {
        std::cout << "Copy constructor exception catched successfully" << std::endl;
    }

    EXCEPT_B = 0;
    std::cout << "*** Testing the ostream, << -operator exception handling.." << std::endl;
    Bug bug3("ID-1337", "Exception handling is cool", BLOCKER);
    try {
        std::ostringstream out;
        out << bug3;
    }
    catch (const std::runtime_error& e) {
        std::cout << "<< -operator exception handling successful" << std::endl;
    }

    std::cout << "*** Creating two random Softwares (non-const and const).." << std::endl;
    Software sw = createRandomSoftware();
    Software sw2 = createRandomSoftware();
    const Software& swConst = sw2;

    std::cout << "*** Testing the getName function.." << std::endl;
    std::cout << "The getName function returned: " << sw.getName() << std::endl;
    std::cout << "The getName function returned: " << swConst.getName() << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing the getRevision function.." << std::endl;
    std::cout << "The getRevision function returned: " << sw.getRevision() << std::endl;
    std::cout << "The getRevision function returned: " << swConst.getRevision() << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing the reportBug function.." << std::endl;
    std::vector<Bug> bugs1 = createRandomBugs((rand()%10)+3);
    std::vector<Bug> bugs2 = createRandomBugs((rand()%10)+3);

    for (std::vector<Bug>::iterator it = bugs1.begin(); it != bugs1.end(); it++)
        sw.reportBug(*it);
    for (std::vector<Bug>::iterator it = bugs2.begin(); it != bugs2.end(); it++)
        sw2.reportBug(*it);

    std::cout << "*** Testing the numberOfBugs function.." << std::endl;  
    std::cout << "The numberOfBugs function returned: " << sw.numberOfBugs() << std::endl;
    std::cout << "The numberOfBugs function returned: " << swConst.numberOfBugs() << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing the ostream, << -operator overloading.." << std::endl;
    std::cout << sw;
    std::cout << swConst;
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing the fixBug function.." << std::endl;
    size_t fix = rand()%bugs1.size();
    for (size_t i = 0; i < fix; i++)
        sw.fixBug(bugs1[rand()%bugs1.size()].getId());

    fix = rand()%bugs2.size();
    for (size_t i = 0; i < fix; i++)
        sw2.fixBug(bugs2[rand()%bugs2.size()].getId());

    std::cout << "*** Printing the softwares.." << std::endl;
    std::cout << sw;
    std::cout << swConst;
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing copying through the copy constructor.." << std::endl;
    Software copied1 = Software(swConst);
    std::cout << "Original:" << std::endl;
    std::cout << swConst;
    std::cout << "Copied:" << std::endl;
    std::cout << copied1;

    Software copied2 = Software(sw);
    std::cout << "Original:" << std::endl;
    std::cout << sw;
    std::cout << "Copied:" << std::endl;
    std::cout << copied2;
    std::cout << "*** END OF READ ***" << std::endl;

    std::cout << "*** Testing the assignment operator.." << std::endl;
    Software assigned1 = swConst;
    std::cout << "Original:" << std::endl;
    std::cout << swConst;
    std::cout << "Assigned:" << std::endl;
    std::cout << assigned1;

    Software assigned2 = sw;
    std::cout << "Original:" << std::endl;
    std::cout << sw;
    std::cout << "Assigned:" << std::endl;
    std::cout << assigned2;

    std::cout << "*** Testing self assigning.." << std::endl;
    sw = sw;
    std::cout << "Self assigned:" << std::endl;
    std::cout << sw;
    std::cout << "*** END OF READ ***" << std::endl;

    EXCEPT_S = 1;

    std::cout << "*** Testing constructor exception handling.." << std::endl;
    try {
        Software sw1("Handle your exceptions gracefully", 1337);
    }
    catch (const std::runtime_error& e) {
        std::cout << "Constructor exception catched successfully" << std::endl;
    }

    std::cout << "*** Testing copy constructor exception handling.." << std::endl;
    try {
        Software sw2("Remember the copy constructor errors", 990);
        Software copy(sw2);
    }
    catch (const std::runtime_error& e) {
        std::cout << "Copy constructor exception catched successfully" << std::endl;
    }

    EXCEPT_S = 0;
    Software testware("Almost there", 123);
    EXCEPT_S = 1;

    std::cout << "*** Testing reportBug function exception handling.." << std::endl;
    try {
        Bug testbug = Bug("EXCPT-101", "Exception handling bug", BLOCKER);
        testware.reportBug(testbug);
    }
    catch (const std::runtime_error& e) {
        std::cout << "reportBug function exception handling successful" << std::endl;
    }

    std::cout << "*** Testing fixBug function exception handling.." << std::endl;
    try {
        testware.fixBug("EXCPT-202");
    }
    catch (const std::runtime_error& e) {
        std::cout << "fixBug function exception handling succesful" << std::endl;
    }

    std::cout << "*** Testing the ostream, << -operator exception handling.." << std::endl;
    try {
        std::ostringstream out;
        out << testware;
    }
    catch (const std::runtime_error& e) {
        std::cout << "<< -operator exception handling successful" << std::endl;
    }


    std::cout << "*** All done, exiting.." << std::endl;
    return 0;
}
