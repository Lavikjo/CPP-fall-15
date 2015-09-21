#include <list>
#include <utility>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>

#include "transcript.hpp"

void addTranscript(std::list<Transcript>& registry, const Transcript& t) {
}

void removeTranscript(std::list<Transcript>& registry, const std::string& student_id) {
}

std::list<Transcript>::const_iterator findTranscript(const std::list<Transcript>& registry, const std::string& student_id) {
    return registry.begin(); // replace this
}

std::list<std::pair<std::string, size_t>> findCourseResults(const std::list<Transcript>& registry, const std::string& course) {
    return registry.front().grades; // replace this
}

