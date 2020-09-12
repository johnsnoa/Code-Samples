all: Main.o Flights.o Flight.o CrewMembers.o CrewMember.o Planes.o Plane.o
	g++ -o a.out Main.o Flights.o Flight.o CrewMembers.o CrewMember.o Planes.o Plane.o
Main.o: Main.cpp Flight.h Flights.h CrewMember.h CrewMembers.h Plane.h Planes.h
	g++ -c Main.cpp
Flights.o: Flights.cpp Flights.h Flight.h CrewMembers.h CrewMember.h Planes.h Plane.h
	g++ -c Flights.cpp
Flight.o: Flight.cpp Flight.h CrewMember.h
	g++ -c Flight.cpp
Planes.o: Planes.cpp Plane.h Planes.h
	g++ -c Planes.cpp
Plane.o: Plane.cpp Plane.h
	g++ -c Plane.cpp
CrewMember.o: CrewMember.cpp CrewMember.h
	g++ -c CrewMember.cpp
CrewMembers.o: CrewMembers.cpp CrewMembers.h CrewMember.h
	g++ -c CrewMembers.cpp
clean:
	rm *.o test	
