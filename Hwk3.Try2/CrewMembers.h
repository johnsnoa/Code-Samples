#ifndef CREWMEMBERS_H
#define CREWMEMBERS_H
class CrewMembers {
	public: CrewMembers();
		
		void AddCrewMember(CrewMember*);
		void EditCrewMember(CrewMember*);
		void EraseCrewMember(int);

		vector<CrewMember*> Pilots();
		vector<CrewMember*> Crew();
		int Count() { return crew.size(); }
		
		CrewMember* Search(int);

		void Sort();

		friend ostream& operator<<(ostream&, CrewMembers&);
	private:
		vector<CrewMember*> crew;

};
#endif
