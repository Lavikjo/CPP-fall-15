#include <stdexcept>

#include "softwarew.hpp"

Software::Software(std::string name, int revision) {
	soft_ptr =  software_construct(name.c_str(), revision);
	if(!soft_ptr) {
		throw std::runtime_error("The software_construct function failed");
	}
}

Software::~Software() {
	software_destruct(soft_ptr);
}

Software::Software(const Software& other_sw) {
	soft_ptr = software_copy(other_sw.soft_ptr);
	if(!soft_ptr) {
		throw std::runtime_error("The software_copy function failed");
	}
}

Software& Software::operator=(const Software& other_sw) {
	struct Software_s* temp = software_copy(other_sw.soft_ptr);

	if(!temp) {
		throw std::runtime_error("The software_copy function failed");
	}
	software_destruct(soft_ptr);
	this->soft_ptr = temp;
	return *this;
}

std::string Software::getName() const{
	return software_get_name(soft_ptr);
}

int Software::getRevision() const{
	return software_get_revision(soft_ptr);
}

int Software::numberOfBugs() const {
	return software_number_of_bugs(soft_ptr);
}

void Software::reportBug(Bug& b) {
	struct Bug_s* temp = software_report_bug(soft_ptr, b.getPtr());
	if(!temp) {
		throw std::runtime_error("The software_report_bug function failed");
	}
}

void Software::fixBug(const std::string& id) {
	struct Bug_s* temp = software_fix_bug(soft_ptr, id.c_str());
	if(!temp) {
		throw std::runtime_error("The software_fix_bug function failed");
	}
}

std::ostream& operator<<(std::ostream& os, Software& sw) {
	software_print_bug_report(sw.soft_ptr);
	return os;
}