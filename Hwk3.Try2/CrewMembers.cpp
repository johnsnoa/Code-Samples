#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#include "CrewMember.h"
#include "CrewMembers.h"

//Constructor
CrewMembers::CrewMembers() {}

//Accessors
vector<CrewMember*> CrewMembers::Pilots() {
	vector<CrewMember*> pilots;
	for(auto it = crew.begin(); it != crew.end(); it++)
		if((*it)->Type() == 'p') pilots.push_back(*it);
	return pilots;
}

vector<CrewMember*> CrewMembers::Crew() {
	vector<CrewMember*> c;
	for(auto it = crew.begin(); it != crew.end(); it++)
		if((*it)->Type() == 'c') c.push_back(*it);
	return c;
}

//Mutator
void CrewMembers::AddCrewMember(CrewMember* c) {
	for(auto it = crew.begin(); it != crew.end(); it++)
		if((*it)->ID() == c->ID()) {
			cout << "[WARNING] This ID is already taken. The old crew member (" << **it << ") has been written over." << endl;
			//crew.erase(it);
			//crew.push_back(&c);
			*it = c;
		}
	crew.push_back(c);
}

void CrewMembers::EditCrewMember(CrewMember* c) {
	CrewMember* toEdit = Search(c->ID());
	if(c->Name() != "none") toEdit->SetName(c->Name());
	if(c->Type() != 'x') toEdit->SetType(c->Type());
}

void CrewMembers::EraseCrewMember(int id) {
	for(auto it = crew.begin(); it != crew.end(); it++)
		if((*it)->ID() == id) {
			crew.erase(it);
			return;
		}
	cout << "That crew member could not be found. No action was taken." << endl;
	
}

//Helpers
bool CompareIDs(CrewMember* a, CrewMember* b) {
	return a->ID() < b->ID();
}

void CrewMembers::Sort() {
	sort(crew.begin(), crew.end(), CompareIDs);
}


//Searches
CrewMember* CrewMembers::Search(int id) {
	for(auto it = crew.begin(); it != crew.end(); it++)
		if((*it)->ID() == id) return *it;
	cout << "[WARNING] That crew member could not be found. A default Crew Member has been returned instead." << endl;
	return new CrewMember(0, "none", 'x');
}

ostream& operator<<(ostream& os, CrewMembers& c) {
	for(auto it = c.crew.begin(); it != c.crew.end(); it++)
		os << **it;
	return os;
}
