#ifndef PLANE_H
#define PLANE_H
class Plane {
	public: Plane();
		Plane(string, string, string, int, int, int);
		string Make();
		string Model();
		string TailNumber();
		int Seats();
		int Range();
		int MinCrew();

		void SetMake(string);
		void SetModel(string);
		void SetTailNumber(string);
		void SetSeats(int);
		void SetRange(int);
		void SetMinCrew(int);

		friend ostream& operator<<(ostream&, Plane&);
	private:string make;
		string model;
		string tailNumber;
		int seats;
		int range;
		int minCrew;
};
#endif
