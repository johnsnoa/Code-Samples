#include <iostream>
#include <string>

using namespace std;
#include "Plane.h"

Plane::Plane() {
	make = "none";
	model = "none";
	tailNumber = "none";
	seats = 0;
	range = 0;
	minCrew = 0;
}

Plane::Plane(string make, string model, string tailNumber, int seats, int range, int minCrew) {
	this->make = make;
	this->model = model;
	this->tailNumber = tailNumber;
	this->seats = seats;
	this->range = range;
	this->minCrew = minCrew;
}

string Plane::Make()       { return make;       }
string Plane::Model()      { return model;      }
string Plane::TailNumber() { return tailNumber; }
int    Plane::Seats()      { return seats;      }
int    Plane::Range()      { return range;      }
int    Plane::MinCrew()    { return minCrew;    }

void Plane::SetMake(string make) 	     { this->make = make; 	      }
void Plane::SetModel(string model) 	     { this->model = model; 	      }
void Plane::SetTailNumber(string tailNumber) { this->tailNumber = tailNumber; }
void Plane::SetSeats(int seats) 	     { this->seats = seats; 	      }
void Plane::SetRange(int range) 	     { this->range = range; 	      }
void Plane::SetMinCrew(int minCrew) 	     { this->minCrew = minCrew;       }

ostream& operator<<(ostream& os, Plane& p) {
	os << p.make << "/ " << p.model << "/ " << p.tailNumber << "/ S: " << p.seats << " / R: " << p.range << " / C: " << p.minCrew;
	return os;
}
