#include <string>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
#include "CrewMember.h"
#include "Plane.h"
#include "Flight.h"

Flight::Flight() {
	this->tailNumber = "none";
	this->startTime = 0;
	this->endTime = 0;
	this->startPoint = "none";
	this->endPoint = "none";
	this->passengers = 0;
	this->status = 'x';
}

Flight::Flight(string tailNumber, time_t startTime, time_t endTime, vector<CrewMember*> pilots, vector<CrewMember*> crew, string startPoint, string endPoint, int passengers, char status) {
	this->tailNumber = tailNumber;
	this->startTime = startTime;
	this->endTime = endTime;
	this->pilots = pilots;
	this->crew = crew;
	this->startPoint = startPoint;
	this->endPoint = endPoint;
	this->passengers = passengers;
	this->status = status;
}

string Flight::TailNumber() 	    { return this->tailNumber; }
time_t Flight::StartTime()  	    { return this->startTime;  }
time_t Flight::EndTime() 	    { return this->endTime;    }
vector<CrewMember*> Flight::Pilots() { return this->pilots;     }
vector<CrewMember*> Flight::Crew()   { return this->crew;       }
string Flight::StartPoint()	    { return this->startPoint; }
string Flight::EndPoint()	    { return this->endPoint;   }
int Flight::Passengers()	    { return this->passengers; }
char Flight::Status()		    { return this->status;     }

void Flight::SetTailNumber(string tailNumber) 	  { this->tailNumber = tailNumber; }
void Flight::SetStartTime(time_t startTime)   	  { this->startTime = startTime;   }
void Flight::SetEndTime(time_t endTime)	     	  { this->endTime = endTime;	   }
void Flight::SetPilots(vector<CrewMember*> pilots){ this->pilots = pilots;   	   }
void Flight::SetCrew(vector<CrewMember*> crew)	  { this->crew = crew;		   }
void Flight::SetStartPoint(string startPoint)	  { this->startPoint = startPoint; }
void Flight::SetEndPoint(string endPoint)	  { this->endPoint = endPoint;     }
void Flight::SetPassengers(int passengers)	  { this->passengers = passengers; }
void Flight::SetStatus(char status)		  { this->status = status;	   }

ostream& operator<<(ostream& os, Flight& f) {
	char *startCStr, *endCStr;
	startCStr = (char*) malloc(15*sizeof(char));
	endCStr = (char*) malloc(15*sizeof(char));
	strftime(startCStr, 15*sizeof(char), "%D %H:%M", localtime(&(f.startTime)));
	strftime(endCStr, 15*sizeof(char), "%D %H:%M", localtime(&(f.endTime)));
	//cout << ctime(&(f.endTime)) << endl;
	string sTStr = startCStr;
	string eTStr = endCStr;
	os << f.tailNumber << " / " << sTStr << " - " << eTStr << " / Pilot IDs: ";
	for(auto it = f.pilots.begin(); it != f.pilots.end(); it++)
		os << (*it)->ID() << " ";
	os << "/ Crew IDs: ";
	for(auto it = f.crew.begin(); it != f.crew.end(); it++)
		os << (*it)->ID() << " ";
	os << "/ " << f.startPoint << " - " << f.endPoint << " / P: " << f.passengers << " / S: " << (f.status == 'a' ? "Active" : (f.status == 'c' ? "Complete" : "Cancelled")) << endl;
	free(startCStr);
	free(endCStr);
	return os;
}

bool Flight::IsCrew(CrewMember* c) {
	for(auto it = crew.begin(); it != crew.end(); it++)
		if((*it) == c) return true;
	for(auto it = pilots.begin(); it != pilots.end(); it++)
		if((*it) == c) return true;
	return false;
}
