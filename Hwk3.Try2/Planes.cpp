#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#include "Plane.h"
#include "Planes.h"

Planes::Planes() {}

void Planes::Add(Plane* p) {
	for(auto it = planes.begin(); it != planes.end(); it++)
		if((*it)->TailNumber() == p->TailNumber()) {
			cout << "[WARNING] A plane with that tail number already exists. The existing plane has been written over." << endl;
			(*it) = p;
			return;
		}
	planes.push_back(p);
}

vector<Plane*> Planes::GetPlanes() { return planes; }

void Planes::Edit(Plane* p) {
	Plane* toEdit = Search(p->TailNumber());
	if(p->Make() != "none")	toEdit->SetMake(p->Make());
	if(p->Model() != "none")toEdit->SetModel(p->Model());
	if(p->Seats() != 0) 	toEdit->SetSeats(p->Seats());
	if(p->Range() != 0)	toEdit->SetRange(p->Range());
	if(p->MinCrew() != 0) 	toEdit->SetMinCrew(p->MinCrew());
}

void Planes::Erase(string tailNumber) {
	for(auto it = planes.begin(); it != planes.end(); it++)
		if((*it)->TailNumber() == tailNumber) {
			planes.erase(it);
			return;
		}
	cout << "[WARNING] That plane could not be found. No action was taken." << endl;
}

bool CompareTN(Plane* a, Plane* b) {
	return a->TailNumber() < b->TailNumber();
}

void Planes::Sort() {
	sort(planes.begin(), planes.end(), CompareTN);
}

Plane* Planes::Search(string tailNumber) {
	for(auto it = planes.begin(); it != planes.end(); it++)
		if((*it)->TailNumber() == tailNumber)
			return *it;
	cout << "[WARNING] That plane could not be found. A default plane has been returned instead." << endl;
	return new Plane("none", "none", "none", 0, 0, 0);
}

ostream& operator<<(ostream& os, Planes& p) {
	for(auto it = p.planes.begin(); it != p.planes.end(); it++)
		os << **it;
	os << endl;
	return os;
}
