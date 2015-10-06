title: String printer
task_id: M4-STRPRINTER
points: 4


**Objective:** Operator overloading, resource management, inheritance
and virtual interfaces, exceptions, etc.

**StringPrinter** (defined in *printer.hpp*) is an abstract base class
for printing strings in different styles. There are different classes
that implement the *StringPrinter* interface: **DiagonalPrinter**
(*diagonal_printer.hpp*) outputs text in diagonal format, and
**StandardPrinter** just prints the text normally.

In addition, there is **Printers** container (*printers.hpp*) for
different kind of printers.

Printing is implemented through operator overloading. Again, see the
detailed instructions in the header files.
