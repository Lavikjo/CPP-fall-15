title: String printer
task_id: M4-STRPRINTER
points: 4
last_modified: 2015-10-08 (link to function call operator)


**Objective:** Operator overloading, resource management, inheritance
and virtual interfaces, exceptions, etc.

**StringPrinter** (defined in *printer.hpp*) is an abstract base class
for printing strings in different styles. There are different classes
that implement the *StringPrinter* interface: **DiagonalPrinter**
(*diagonal_printer.hpp*) outputs text in diagonal format, and
**StandardPrinter** just prints the text normally.

In addition, there is **Printers** container (*printers.hpp*) for
different kind of printers.

Printing is implemented overloading the *function call operator*
(`operator()`). See [this link] for examples how it is used. Again,
see the detailed instructions in the header files.

[this link]: http://www.tutorialspoint.com/cplusplus/function_call_operator_overloading.htm
