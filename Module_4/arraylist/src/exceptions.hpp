#ifndef EXCEPTIONS_HH
#define EXCEPTIONS_HH

struct Exception {};
struct NoSuchElementException : public Exception {};
struct UnsupportedOperationException : public Exception {};
struct IndexOutOfBoundsException : public Exception {};

#endif
