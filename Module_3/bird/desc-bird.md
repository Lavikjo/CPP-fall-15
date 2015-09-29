title: Birds
task_id: M3-BIRD
points: 1


**Objective:** Practice abstract classes and inheritance.

You will need to implement different kinds of birds that all can fly
(expect *const* birds). Birds also speak, but in different languages
specific to the bird type. **Bird** (in *bird.hpp*) is the abstract
base class for birds. You will need to implement **Duck** (and define
it in *duck.hpp*) and **Owl** (and define it in *owl.hpp*). The birds
should be implemented in the respectice *.cpp file named after the
class.

The bird language is simple: duck says "QUACK" and owl says
"WHUU". The speak function should output the name of the bird, colon,
space and followed by one of the above, e.g.:

`Donald: QUACK`
 
In addition, you will need to implement class **Aviary** (in
*aviary.hpp*) that stores the birds.

You will find more instructions in the header files.
