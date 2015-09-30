title: Bug tracker
task_id: M4-WRAPPER
points: 4
last_modified: 2015-10-09 (Clarification about strings used in exceptions)


**Objective:** Practice resource management and exceptions, and
porting a C program to C++

*bug.c*, *bug.h*, *software.c* and *software.h* implement a small bug
 tracking system that you need to convert to C++, by implementing
 **Bug** class and **Software** class. Follow the detailed
 instructions in the header files (**softwarew.hpp** and
 **bugw.hpp**). Your C++ implementation should call the corresponding
 functions in the C implementation (hence the task name).

**Note:** In error conditions you are required to throw an exception (read
header files). The exceptions you throw can contain informative messages about the
error. These messages can be anything, however an exception thrown from Software::fixBug
*must* contain message: "The software_fix_bug function failed"

**Note:** test_source.cpp updated on 2015-10-09
