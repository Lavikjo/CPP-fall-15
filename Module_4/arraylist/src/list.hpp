#ifndef LIST_HH
#define LIST_HH

/* This class iterates over a collection.
   Collection classes return objects which implement this interface.
*/
class Iterator {
public:
  /* Returns true if the iteration has more elements. */
  virtual bool hasNext() const = 0;
  /* Returns the next element in the iteration
     @throws NoSuchElementException - iteration has no more elements */
  virtual Object *next() = 0;
  /* Removes from the underlying collection the last element returned by the
     iterator (optional operation).
     @throws UnsupportedOperationException -
             if remove operation is not supported by this Iterator
  */
  virtual void remove() = 0;
  
  virtual ~Iterator() {}
  
};


// Yes, this should derive from Object if we wanted this class to
// be realistic. However, we don't want to waste time implementing
// toString and equals and other stuff in this exercise.
class List
{
public:
  /* Appends the specified element to the end of this list (optional operation).

  @throws UnsupportedOperationException - if the add method is not supported by this list
  */
  virtual bool add(Object *o) = 0;

  /* Replaces the element at the specified position in this list
     with the specified element (optional operation).
     @param index - index of element to replace
     @param element - element to be stored at the specified position.
     @returns the element previously at the specified position
     @throws UnsupportedOperationException - if the set method is not
             supported by the list
     @throws IndexOutOfBoundsException - if the index is out of range
  */
  virtual Object *set(int index, Object *element) = 0;

  /* Returns the element at the specified position in this list.
   * @throws IndexOutOfBoundsException - if the index is out of range.
   */
  virtual Object *get(int index) = 0;

  /* Returns the number of elements in this list.
   */
  virtual int size() const = 0;
  /* Returns an iterator over the elements in this list in proper sequence */
  virtual Iterator *iterator() = 0;

  /* Returns the index in this list of the first occurence of the specified
     element, or -1 if this list does not contain this element. The
     equality is tested with the equals method.
  */
  virtual int indexOf(Object const *o) const = 0;
  
  virtual ~List() {}
  
};


#endif
