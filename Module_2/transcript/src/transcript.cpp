#include <list>
#include <utility>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>

#include "transcript.hpp"

void addTranscript(std::list<Transcript>& registry, const Transcript& t) {
	registry.push_back(t);
}

void removeTranscript(std::list<Transcript>& registry, const std::string& id) {
	 auto it = find_if(registry.begin(), registry.end(),
	 	[id](const Transcript& a)
	 	{return a.student_id == id;});
	 	registry.erase(it);
}

std::list<Transcript>::const_iterator findTranscript(const std::list<Transcript>& registry, const std::string& student_id) {
   	auto it = find_if(registry.cbegin(), registry.cend(),
   		[student_id](const Transcript& a)
   		{return a.student_id == student_id;});
    if(it == registry.cend()){
    	return registry.cend();
    } else {
    	return it;
    }
    
}

std::list<std::pair<std::string, size_t>> findCourseResults(const std::list<Transcript>& registry, const std::string& course) {
    std::list<std::pair<std::string, size_t>> results;

	for(auto& it:registry) {
		for(auto& grade : it.grades)
		{
			if(grade.first == course) {
				results.push_back(grade);
			}
		}
	}
	return results;
}

