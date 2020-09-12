#ifndef FLIGHT_H
#define FLIGHT_H
class Flight {
	public:	Flight(); //Default constructor
		Flight(string, time_t, time_t, vector<CrewMember*>, vector<CrewMember*>, string, string, int, char); //Full constructor
		
		string TailNumber();
		time_t StartTime();
		time_t EndTime();
		vector<CrewMember*> Pilots();
		vector<CrewMember*> Crew();
		string StartPoint();
		string EndPoint();
		int Passengers();
		char Status();

		void SetTailNumber(string);
		void SetStartTime(time_t);
		void SetEndTime(time_t);
		void SetPilots(vector <CrewMember*>);
		void SetCrew(vector <CrewMember*>);
		void SetStartPoint(string);
		void SetEndPoint(string);
		void SetPassengers(int);
		void SetStatus(char);

		bool IsCrew(CrewMember*);

		friend ostream& operator<<(ostream&, Flight&);

	private:string tailNumber;
		time_t startTime;
		time_t endTime;
		vector<CrewMember*> pilots;
		vector<CrewMember*> crew;
		string startPoint;
		string endPoint;
		int passengers;
		char status;
};
#endif
