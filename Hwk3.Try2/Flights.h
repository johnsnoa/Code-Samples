#ifndef FLIGHTS_H
#define FLIGHTS_H
class Flights {
	public:	Flights();
		
		int Count() { return flights.size(); }

		void Add(Flight*);
		void Edit(string, time_t, Flight);
		void Erase(string, time_t);

		void Sort();
		Flight* Search(string, time_t);

		CrewMember* FindCrew(CrewMembers, time_t, time_t, char);
		Plane* FindPlane(Planes, time_t, time_t, int); //int passengers

		void Update();
		void ClearInactive();

		void AllOf(Planes, string);
		void AllOf(CrewMembers, int);
		friend ostream& operator<<(ostream&, Flights&);
	private:vector<Flight*> flights;
};
#endif
