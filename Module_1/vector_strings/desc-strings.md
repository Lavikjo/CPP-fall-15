title: Vector of strings
task_id: M1-STRINGS
points: 1

**Objective:** Practice use of C++ strings, as part of a STL vector.

Implement a program that stores and removes given strings from a
vector, as commanded by the user. You will implement a simple command
line user interface that with the following commands:

  * "ADD": Adds a given string to the vector. The command is followed
    by a newline character, after which user should enter the string
    to be added. The ADD functionality is implemented in function
    `adder`.
  
  * "REMOVE": Removes the last string from the vector. This
    operation is implemented in function `remover`.

  * "PRINT": Outputs all stored strings, each on a separate line
    (e.g., followed by newline character). This operation is
    implemented in function `printer`.

  * "QUIT": that exits the program.

In addition to the above three functions, you need to implement
function `cmdReader` that parses the commands and calls the
appropriate functions. The detailed function interfaces can be found
in file "vector_strings.hpp".
