#include <string>
#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <numeric>
#include <iterator>
#include <algorithm>

using namespace std;
#include "CrewMember.h"
#include "CrewMembers.h"
#include "Plane.h"
#include "Planes.h"
#include "Flight.h"
#include "Flights.h"

CrewMembers c;
Planes p;
Flights f;

int ReadCrew() {
	ifstream file;
	file.open("crew.dat");
	string name, typeStr;
	int numCrew, id;
	char type, dummy[3];

	file >> numCrew;
	//cout << numCrew << endl;
	file.get();
	for(int i = 0; i < numCrew && i < 100; i++) {
		getline(file, name, '/');
		file >> id;
		file.read(dummy, 3);
		getline(file, typeStr);
		type = typeStr == "Crew" ? 'c' : 'p';
		//cout << "[DEBUG] " << name << " / " << id << " / " << typeStr << ": " << type << endl;
		c.AddCrewMember(new CrewMember(id, name, type));
	}
	return numCrew;
}

int ReadPlanes() {
	ifstream file;
	file.open("planes.dat");
	string make, model, tailNumber;
	int range, seats, minCrew, numPlanes;
	char dummy[6];

	file >> numPlanes;
	file.get();

	for(int i = 0; i < numPlanes && i < 100; i++) {
		getline(file, make, '/'); file.get();
		getline(file, model, '/'); file.get();
		getline(file, tailNumber, '/');
		file.read(dummy, 4);
		file >> seats;
		file.read(dummy, 6);
		file >> range;
		file.read(dummy, 6);
		file >> minCrew;
		//file.get();
		p.Add(new Plane(make, model, tailNumber, seats, range, minCrew));
	}
	return numPlanes;
}

int ReadFlights() {
	ifstream file;
	file.open("flights.dat");
	string tailNumber, startPoint, endPoint;
	vector<CrewMember*> pilots, crew;
	string pilotString, crewString;
	tm startTime, endTime;
	int passengers, flightNum;
	char dummy[16], status;
	//tailNumber/ dd/mm/yy hh:mm - dd/mm/yy hh:mm / Pilot IDs: # # # # / Crew IDs: # # # # # # # # / SSS - EEE / P: # / S: a
	file >> flightNum; file.get();
	for(int x = 0; x < flightNum; x++) {
		pilots.clear();
		crew.clear();
		getline(file, tailNumber, '/');
		file.get();
		string dateTime;
		getline(file, dateTime, '-');
		sscanf(dateTime.c_str(), "%d/%d/%d %d:%d ", &(startTime.tm_mday), &(startTime.tm_mon), &(startTime.tm_year), &(startTime.tm_hour), &(startTime.tm_min));
		getline(file, dateTime, 's');
		sscanf(dateTime.c_str(), " %d/%d/%d %d:%d / Pilot ID", &(endTime.tm_mday), &(endTime.tm_mon), &(endTime.tm_year), &(endTime.tm_hour), &(endTime.tm_min));
		startTime.tm_mon--;
		endTime.tm_mon--;
		startTime.tm_year += 100;
		endTime.tm_year += 100;
		startTime.tm_sec = 0;
		endTime.tm_sec = 0;
		file.read(dummy, 2);
		string next;
		getline(file, next, '/');
		istringstream iss(next);
		vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
		for(auto it = results.begin(); it != results.end(); it++) {
			int pilot;
			sscanf(it->c_str(), "%d", &pilot);
			pilots.push_back(c.Search(pilot));
		}
		file.read(dummy, 11);
		getline(file, next, '/');
		istringstream iss2(next);
		vector<string> results2((istream_iterator<string>(iss2)), istream_iterator<string>());
		for(auto it = results2.begin(); it != results2.end(); it++) {
			int crewman;
			sscanf(it->c_str(), "%d", &crewman);
			crew.push_back(c.Search(crewman));
		}
		file.get();
		getline(file, startPoint, ' ');
		file.get();
		file.get();
		getline(file, endPoint, ' ');
		file.read(dummy, 5);
		file >> passengers;
		file.read(dummy, 8);
		//cout << asctime(&endTime) << endl;;
		f.Add(new Flight(tailNumber, mktime(&startTime), mktime(&endTime), pilots, crew, startPoint, endPoint, passengers, 'a'));
		//cout << *(f.Search(tailNumber, mktime(&startTime)))<< endl;
	}
	return flightNum;
}

int WritePlanes() {
	ofstream file;
	file.open("planes.dat");
	file << p.Count() << endl;
	file << p;
	return p.Count();
}

int WriteCrew() {
	ofstream file;
	file.open("crew.dat");
	file << c.Count() << endl;
	file << c;
	return c.Count();
}

int WriteFlights() {
	ofstream file;
	file.open("flights.dat");
	file << f.Count() << endl;
	file << f;
	return f.Count();
}

time_t stimef(string s);

void FlightMenu() {
	int sel, counter = 0;
	while(sel != 10 && counter < 10) {
		cout << "-----------------Flight Operations------------------" << endl;
		cout << " 1. Add new flight" << endl;
		cout << " 2. Edit existing flight" << endl;
		cout << " 3. Delete existing flight" << endl;
		cout << " 4. Print flights of plane" << endl;
		cout << " 5. Print flights of crew" << endl;
		cout << " 6. Print all flights" << endl;
		cout << " 7. Sort flights" << endl;
		cout << " 8. Update flight statuses" << endl;
		cout << " 9. Delete inactive flights" << endl;
		cout << " 10. Back" << endl;
		cout << " > ";
		cin >> sel; cin.get();
		cout << "----------------------------------------------------" << endl;
		switch(sel) {
			case 1: {
					string startPoint, endPoint, dateTime;
					time_t startTime, endTime;
					vector<CrewMember*> pilots, crew;
					int passengers;
					cout << "Enter start time (DD/MM/YY HH:MM): ";
					getline(cin, dateTime);
					startTime = stimef(dateTime);
					cout << "Enter end time (DD/MM/YY HH:MM): ";
					getline(cin, dateTime);
					endTime = stimef(dateTime);
					cout << "Number of passengers: ";
					cin >> passengers;cin.get();
					cout << "Starting airport (ABC): ";
					getline(cin, startPoint);
					cout << "Ending airport (ABC): ";
					getline(cin, endPoint);
					Plane* plane = f.FindPlane(p, startTime, endTime, passengers);
					for(int i = 0; i < (difftime(endTime, startTime) > 28800 ? 4 : 2); i++)
						pilots.push_back(f.FindCrew(c, startTime, endTime, 'p'));
					for(int i = 0; i < plane->MinCrew() * (difftime(endTime, startTime) > 28800 ? 2 : 1); i++)
						crew.push_back(f.FindCrew(c, startTime, endTime, 'c'));
					f.Add(new Flight(plane->TailNumber(), startTime, endTime, pilots, crew, startPoint, endPoint, passengers, 'a'));
				} break;
			case 2: { cout << "This function was not implemented." << endl;
				} break;
			case 3: { string tailNumber, dateTime; time_t startTime;
					cout << "Tail number to delete: ";
					getline(cin, tailNumber);
					cout << "Starting time (DD/MM/YY HH:MM): ";
					getline(cin, dateTime);
					startTime = stimef(dateTime);
					f.Erase(tailNumber, startTime);
				} break;
			case 4: { string tailNumber;
					cout << "Tail number to print: ";
					getline(cin, tailNumber);
					f.AllOf(p, tailNumber);
				} break;
			case 5: { int id;
					cout << "Crew ID to print: ";
					cin >> id;cin.get();
					f.AllOf(c, id);
				} break;
			case 6: cout << f;
				break;
			case 7: f.Sort();
				break;
			case 8: f.Update();
				break;
			case 9: f.ClearInactive();
				break;
			case 10: return;
			case 11: counter++; break;
		}
	}
}

time_t stimef(string s) {
	tm time;
	sscanf(s.c_str(), "%d/%d/%d %d:%d", &(time.tm_mday), &(time.tm_mon), &(time.tm_year), &(time.tm_hour), &(time.tm_min));
	time.tm_mon--;
	time.tm_year += 100;
	time.tm_sec = 0;
	//cout << asctime(&time);
	return mktime(&time);
}

void CrewMenu() {
	int sel, counter = 0;
	while(sel != 7 && counter < 10) {
		cout << "------------------Crew Operations-------------------" << endl;
		cout << " 1. Add new crew member" << endl;
		cout << " 2. Edit existing crew member" << endl;
		cout << " 3. Delete existing crew member" << endl;
		cout << " 4. Print crew member details" << endl;
		cout << " 5. Print all crew members" << endl;
		cout << " 6. Sort crew members" << endl;
		cout << " 7. Back" << endl;
		cout << " > ";
		cin >> sel;cin.get();
		cout << "----------------------------------------------------" << endl << endl;
		switch(sel) {
			case 1: { int id;
				  string name;
				  char type;
				  cout << "Crew ID: ";
				  cin >> id;cin.get();
				  cout << "Crew name: ";
				  getline(cin, name);
				  cout << "Crew or Pilot (c/p)? ";
				  cin >> type;cin.get();
				  c.AddCrewMember(new CrewMember(id, name, type));
				  cout << "Crew member successfully added." << endl;
				  break; }
			case 2: { int id;
				  string name = "none";
				  char type = 'x';
				  cout << "Crew id to edit: " << endl;
				  cin >> id;cin.get();
				  cout << " 1. Edit name" << endl;
				  cout << " 2. Edit type" << endl;
				  cout << " Choose multiple by typing \"12\"" << endl;
				  cout << " > ";
				  cin >> sel;cin.get();
				  switch(sel) {
					  case 1: cout << "New name: ";
						  getline(cin, name);
						  break;
					  case 2: cout << "New type (c/p): ";
						  cin >> type;cin.get();
						  break;
					  case 12: cout << "New name: ";
						   getline(cin, name);
						   cout << "New type (c/p): ";
						   cin >> type;cin.get();
						   break;
					  default: break;
				  }
				  c.EditCrewMember(new CrewMember(id, name, type));
				  break; }
			case 3: { int id;
				  cout << "Crew ID to delete: ";
				  cin >> id;cin.get();
				  c.EraseCrewMember(id);
				  break; }
			case 4: { int id;
				  cout << "Crew ID to print: ";
				  cin >> id;cin.get();
				  cout << *(c.Search(id));
				  break; }
			case 5: cout << c;
				break;
			case 6: c.Sort();
				break;
			case 7: return;
			default: break;
		}
	}		
}

void PlaneMenu() {
	int sel, counter = 0;
	string tailNumber, make, model;
	int range, seats, minCrew;
	while(sel != 7 && counter < 10) {
		cout << "------------------Plane Operations------------------" << endl;
		cout << " 1. Add plane" << endl;
		cout << " 2. Edit plane" << endl;
		cout << " 3. Delete plane" << endl;
		cout << " 4. Sort planes" << endl;
		cout << " 5. Print individual plane" << endl;
		cout << " 6. Print all planes" << endl;
		cout << " 7. Back" << endl;
		cout << " > ";
		cin >> sel;cin.get();
		cout << "----------------------------------------------------" << endl;
		switch(sel) {
			case 1: { cout << "Plane Make: ";
				getline(cin, make);
				cout << "Plane Model: ";
				getline(cin, model);
				cout << "Tail Number: ";
				getline(cin, tailNumber);
				cout << "Number of seats: ";
				cin >> seats;cin.get();
				cout << "Range: ";
				cin >> range;cin.get();
				cout << "Minimum crew size: ";
				cin >> minCrew;cin.get();
				p.Add(new Plane(make, model, tailNumber, seats, range, minCrew));
				cout << "Airplane added successfully." << endl;
				} break;
			case 2: { cout << "Tail number to edit: ";
				getline(cin, tailNumber);	
				make = "none", model = "none";
				seats = 0, range = 0, minCrew = 0;
				int sels[] = {0, 0, 0, 0, 0, 0, 0};
				while(sels[6] != 1 && sels[5] != 1) {
					cout << " " << (sels[0] == 0 ? "1" : "[1]") << ". Make" << endl;
					cout << " " << (sels[1] == 0 ? "2" : "[2]") << ". Model" << endl;
					cout << " " << (sels[2] == 0 ? "3" : "[3]") << ". Number of seats" << endl;
					cout << " " << (sels[3] == 0 ? "4" : "[4]") << ". Range" << endl;
					cout << " " << (sels[4] == 0 ? "5" : "[5]") << ". Minimum crew size" << endl;
					cout << " 6. Confirm" << endl;
					cout << " 7. Back" << endl;
					cout << " Select one at a time. Press 6 to finalize selection(s)." << endl;
					cout << " > ";
					cin >> sel;cin.get();
					sels[sel-1] = (sels[sel-1] == 0 ? 1 : 0);
					if(sels[5] == 1) { //Finalized
						if(sels[0] == 1) {
							cout << "New make: ";
							getline(cin, make);
						}
						if(sels[1] == 1) {
							cout << "New model: ";
							getline(cin, model);
						}
						if(sels[2] == 1) {
							cout << "New number of seats: ";
							cin >> seats; cin.get();
						}
						if(sels[3] == 1) {
							cout << "New range: ";
							cin >> range; cin.get();
						}
						if(sels[4] == 1) {
							cout << "New minimum crew size: ";
							cin >> minCrew; cin.get();
						}
						cout << tailNumber << endl;
						p.Edit(new Plane(make, model, tailNumber, seats, range, minCrew));
					}

				}
				} break;
			case 3: { cout << "Enter tail number to erase: ";
				getline(cin, tailNumber);
				p.Erase(tailNumber);
				} break;
			case 4: p.Sort();
				break;
			case 5: { cout << "Enter tail number to print: ";
				getline(cin, tailNumber);
				cout << *(p.Search(tailNumber)) << endl;
				} break;
			case 6: cout << p;
				break;
			case 7: return;
			default: counter++;
				 break;
		}
	}
}

void MainMenu() {
	int sel, counter = 0;
	while(sel != 6 && counter < 10) {
		cout << "-----------Welcome to Mean Green Airlines-----------" << endl;
		cout << " 1. Read data from files" << endl;
		cout << " 2. Write data to files" << endl;
		cout << " 3. Crew member operations" << endl;
		cout << " 4. Airplane operations" << endl;
		cout << " 5. Flight operations" << endl;
		cout << " 6. Exit" << endl;
		cout << " > ";
		cin >> sel;
		cout << "----------------------------------------------------" << endl << endl;	
		switch(sel) {
			case 1: cout << ReadCrew() << " crew members have been registered." << endl;
				cout << ReadPlanes()<< " airplanes have been registered." << endl;
				cout << ReadFlights() << " flights have been registered." << endl;
				//cout << f;
				break;
			case 2: cout << WriteCrew() << " crew members have been stored locally." << endl;
				cout << WritePlanes()<< " airplanes have been stored locally." << endl;
				cout << WriteFlights() << " flights have been stored locally." << endl;
				break;
			case 3: CrewMenu();
				break;
			case 4: PlaneMenu();
				break;
			case 5: FlightMenu();
				break;
			case 6: cout << "Exiting..." << endl;
				return;
			default: cout << "Invalid command." << endl;
				 counter++; //Prevents infinite looping
				 break;
		}
		cout << endl;
	}
}

int main() {
	MainMenu();
	return 0;
}
