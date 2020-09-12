#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;
#include "CrewMember.h"
#include "Plane.h"
#include "CrewMembers.h"
#include "Planes.h"
#include "Flight.h"
#include "Flights.h"

Flights::Flights(){}

void Flights::Add(Flight* f) {
	for(auto it = flights.begin(); it != flights.end(); it++) 
		if((*it)->TailNumber() == f->TailNumber() && (*it)->StartTime() == f->StartTime()) {
			cout << "[WARNING] A flight with that tail number and start time already exists. The existing flight has been written over." << endl;
			*it =  f;
		}
	flights.push_back(f);
}

void Flights::Edit(string tN, time_t sT, Flight f) {
	Flight* toEdit = Search(tN, sT);
	if(f.TailNumber() != "none")	   toEdit->SetTailNumber(f.TailNumber());
	if(f.StartTime() != 0) 		   toEdit->SetStartTime(f.StartTime());
	if(f.EndTime() != 0)   		   toEdit->SetEndTime(f.EndTime());
	if(f.Pilots() != toEdit->Pilots()) toEdit->SetPilots(f.Pilots()); //Fill f.Pilots() with toEdit.Pilots() if not editing pilots
	if(f.Crew() != toEdit->Crew())     toEdit->SetCrew(f.Crew());
	if(f.StartPoint() != "none")	   toEdit->SetStartPoint(f.StartPoint());
	if(f.EndPoint() != "none")	   toEdit->SetEndPoint(f.EndPoint());
	if(f.Passengers() != 0)		   toEdit->SetPassengers(f.Passengers());
	if(f.Status() != 'x')		   toEdit->SetStatus(f.Status());
}

void Flights::Erase(string tailNumber, time_t startTime) {
	for(auto it = flights.begin(); it != flights.end(); it++)
		if((*it)->TailNumber() == tailNumber && (*it)->StartTime() == startTime) {
			flights.erase(it);
			return;
		}
	cout << "[WARNING] That flight could not be found. No action was taken." << endl;
}

bool CompareFlights(Flight* a, Flight* b) {
	return a->StartTime() < b->StartTime();
}

void Flights::Sort() {
	auto start = flights.begin();
	for(auto it = flights.begin(); it != flights.end(); it++)
		if((*it)->TailNumber() != (*start)->TailNumber()) {
			sort(start, --it, CompareFlights);
			start = ++it;
		}
}

Flight* Flights::Search(string tailNumber, time_t startTime) {
	for(auto it = flights.begin(); it != flights.end(); it++)
		if((*it)->TailNumber() == tailNumber && (*it)->StartTime() == startTime)
			return *it;
	cout << "[WARNING] That flight could not be found. A default flight has been returned instead." << endl;
	return new Flight();
}


CrewMember* Flights::FindCrew(CrewMembers c, time_t startTime, time_t endTime, char type) {
	vector<CrewMember*> crew = (type == 'c' ? c.Crew() : c.Pilots());
	bool available;
	for(auto it = crew.begin(); it != crew.end(); it++) {
		available = true;
		for(auto fit = flights.begin(); fit != flights.end(); fit++)
			if((*fit)->IsCrew(*it) && 
					!(endTime < (*fit)->StartTime() || startTime > (*fit)->EndTime()))
				available = false;	
		if(available) return *it;
	}
	cout << "[WARNING] Could not find a valid " << (type == 'c' ? "crew member" : "pilot") << ". Therefore, the creation of this flight has been terminated. Please choose a different time or register more crew members and retry." << endl;
	return new CrewMember();
}

Plane* Flights::FindPlane(Planes p, time_t startTime, time_t endTime, int passengers) {
	vector<Plane*> planes = p.GetPlanes();
	bool available;
	for(auto it = planes.begin(); it != planes.end(); it++) {
		available = (*it)->Seats() >= passengers;
		for(auto fit = flights.begin(); fit != flights.end(); fit++)
			if((*fit)->TailNumber() == (*it)->TailNumber() &&
					!(endTime < (*fit)->StartTime() || startTime > (*fit)->EndTime()))
				available = false;
		if(available) return *it;
	}
	cout << "[WARNING] Could not find a valid plane. Therefore, the creation of this flight as been terminated. Please choose a different time or register more airplanes and try again." << endl;
	return new Plane();
}

void Flights::Update() {
	for(auto it = flights.begin(); it != flights.end(); it++)
		if((*it)->EndTime() < time(NULL)) (*it)->SetStatus('c');
}

void Flights::ClearInactive() {
	for(auto it = flights.begin(); it != flights.end(); it++)
		if((*it)->Status() != 'a') flights.erase(it);
}

ostream& operator<<(ostream& os, Flights& f) {
	for(auto it = f.flights.begin(); it != f.flights.end(); it++)
		os << **it;
	return os;
}

void Flights::AllOf(Planes p, string tailNumber) {
	for(auto it = flights.begin(); it != flights.end(); it++)
		if((*it)->TailNumber() == tailNumber)
			cout << **it; 
}

void Flights::AllOf(CrewMembers c, int id) {
	for(auto it = flights.begin(); it != flights.end(); it++)
		if((find((*it)->Crew().begin(), (*it)->Crew().end(), c.Search(id)) != (*it)->Crew().end()) || (find((*it)->Pilots().begin(), (*it)->Pilots().end(), c.Search(id)) != (*it)->Pilots().end()))
			cout << **it;
}
