#include <string>
#include <iostream>

using namespace std;
#include "CrewMember.h"

//Constructors
CrewMember::CrewMember() {
	id = 0;
	name = "none";
	type = 'x';
}

/**
 * Ranges
 * ID > 0, unique identifier
 * Name = Any string
 * Type = 'c' for crew, 'p' for pilot. 'x' is a placeholder.
 */
CrewMember::CrewMember(int id, string name, char type) {
	this->id = id;
	this->name = name;
	this->type = type;
}


//Mutators
void CrewMember::SetID(int id) {
	this->id = id;
}

void CrewMember::SetName(string name) {
	this->name = name;
}

void CrewMember::SetType(char type) {
	this->type = type;
}


//Accessors
int CrewMember::ID() {
	return this->id;
}

string CrewMember::Name() {
	return this->name;
}

char CrewMember::Type() {
	return this->type;
}


//Print method
ostream& operator<<(ostream& os, CrewMember& c) {
	os << c.name << " / " << c.id << " / " << (c.type == 'c' ? "Crew" : "Pilot") << endl;
	return os;
}
