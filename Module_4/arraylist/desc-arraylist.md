title: Arraylist 
task_id: M4-ARRAYLIST
points: 4


**Objective:** Operator overloading, resource management, inheritance
and virtual interfaces, exceptions, etc.

In this exercise you must implement a simple array class with static size. To make the exercise a bit more interesting, you must implement that class so that it conforms to a certain container API.

The class you must implement is called **ArrayList**. The class implements an interface called **List**.
You must also implement the iterator class for **ArrayList** for the return value of **iterator()** member function.
This iterator class must implement the interface defined in class **Iterator**.

The container classes in this API can only store instances of classes which implement the **Object** interface. To prevent object slicing, we must use pointers practically everywhere.

Please look at the main to see how the class is being used.
Implement everything in the header file (*arraylist.hh*).

Notes:

**In this exercise it is forbidden to use any container class in the standard library, such as list and vector!**
Our ArrayList does not support removing and adding elements, so deal with such requests accordingly. Normally exceptions such as UnsupportedOperationException are bad, because they violate Liskov substitution principle. 

We could have used typedefs to hide the fact that Object must be passed by pointer for the API to look even more familiar.

You need to use operators new[] and delete[] to manage the memory of the object array.
This exercise is a bit contrived - we really don't need naked pointers here this much and we really should be using the standard library containers instead. Unfortunately in real life pointer abuse is still common, so you must be able to deal with such code.
