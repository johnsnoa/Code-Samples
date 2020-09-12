#ifndef CREWMEMBER_H
#define CREWMEMBER_H
class CrewMember {
	public:
		CrewMember();
		CrewMember(int, string, char);

		void SetID(int);
		void SetName(string);
		void SetType(char);

		int ID();
		string Name();
		char Type();

		friend ostream& operator<<(ostream&, CrewMember&);
	private:
		int id;
		string name;
		char type;
};
#endif
