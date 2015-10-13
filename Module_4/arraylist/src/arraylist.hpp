
#ifndef ARRAYLIST_HH
#define ARRAYLIST_HH

#include <algorithm>

#include "object.hpp"
#include "exceptions.hpp"
#include "list.hpp"


class ArrayListIterator : public Iterator {
public:

	ArrayListIterator(Object **o, int s) {
		ptr = o;
		size = s;
		pos = 0;
	}

	bool hasNext() const {
		if(!*(ptr + pos + 1)) {
			return false;
		} else {
			return true;
		}
	}
	/* Returns the next element in the iteration
	@throws NoSuchElementException - iteration has no more elements */
	Object* next() {
		if(hasNext()) {
			if(pos < size) {
			pos++;
			}
			return *(ptr + pos - 1);
		} else {
			throw NoSuchElementException();
		}
	}
	/* Removes from the underlying collection the last element returned by the
	iterator (optional operation).
	@throws UnsupportedOperationException -
	if remove operation is not supported by this Iterator
	*/
  	void remove() {
  		if(!ptr) {
  			throw UnsupportedOperationException();
  		} else {
  			delete *ptr;
  		} 
  	}
  
  	~ArrayListIterator() {}

private:
	Object **ptr;
	int size;
	int pos;	

};
  
class ArrayList : public List {
public:


	ArrayList(int s = 0) :siz(s) {
		obj_ptr = new Object*[s + 1];
		for(int i = 0; i < (s + 1); i++) {
			obj_ptr[i] = NULL;
		}
	}

	~ArrayList() {
		/*
		delete [] obj_ptr;
		delete obj_ptr;
		*/
	}

	bool add(Object *o) {
		if(!o) {}
	throw UnsupportedOperationException();
	}

	Object* set(int index, Object *element) {
		if(index > siz) {
			throw IndexOutOfBoundsException();
		} else {
			Object* temp = obj_ptr[index];
			//delete obj_ptr[index];
			obj_ptr[index] = element; 
			return temp;
		}
	}

	Object* get(int index) {
		if(index > siz) {
			throw IndexOutOfBoundsException();
		}
		return obj_ptr[index];
	}

	int size() const {
		return siz;
	}

	Iterator* iterator() {
		return new ArrayListIterator(obj_ptr, siz);

	}

	int indexOf(Object const *o) const {
		for(int i = 0; i < siz;i++) {
			if(obj_ptr[i]->equals(o)) {
				return i;
			}
		}
		return -1;
	}


private:
	int siz;
	Object **obj_ptr;
};

#endif
