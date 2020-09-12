#ifndef PLANES_H
#define PLANES_H
class Planes {
	public: Planes();
		
		vector<Plane*> GetPlanes();
	       	void Add(Plane*);
		void Edit(Plane*);

		int Count() { return planes.size(); }

	       	Plane* Search(string);
	       	void Sort();
	       	void Erase(string);

		friend ostream& operator<<(ostream&, Planes&);
	private:vector<Plane*> planes;
};
#endif
