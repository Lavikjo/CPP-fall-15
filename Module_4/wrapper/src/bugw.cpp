#include "bugw.hpp"

#include <stdexcept>

Bug::Bug(const std::string &id, const std::string &description, Priority priority) {
	bug_ptr = bug_construct(id.c_str(), description.c_str(), priority);
	if(!bug_ptr) {
		throw std::runtime_error("The bug_construct function failed");
	}
}

Bug::~Bug() {
	bug_destruct(bug_ptr);
}

Bug::Bug(const Bug& other_bug) {
	bug_ptr = bug_copy(other_bug.bug_ptr);
	if(!bug_ptr) {
		throw std::runtime_error("The bug_copy function failed");
	}
}

Bug& Bug::operator=(const Bug& other_bug) {
	
	struct Bug_s* temp = bug_copy(other_bug.bug_ptr);
	if(!temp) {
		throw std::runtime_error("The bug_copy function failed");
	}

	bug_destruct(bug_ptr); 
	this->bug_ptr = temp;
	return *this;
}

std::string Bug::getId() {
	std::string id = bug_get_id(bug_ptr);
	return id;
}

std::string Bug::getDescription() {
	std::string description = bug_get_description(bug_ptr);
	return description;
}

Priority Bug::getPriority() {
	Priority temp = bug_get_priority(bug_ptr);
	return temp;
}

bool Bug::isFixed() {
	bool temp = bug_is_fixed(bug_ptr);
	return temp;
}

void Bug::fix() {
	bug_fix(bug_ptr);
}

struct Bug_s* Bug::getPtr() {
	return bug_ptr;
}

std::ostream& operator<<(std::ostream &os, const Bug& bug) {
	
	bug_print(bug.bug_ptr);
	return os;
}