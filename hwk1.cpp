// Noah Johnson
// CSCE 1040.003

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "student.h"
#include "bubble.h"

struct classStats {
	float mean;
	float min;
	float max;
	float median;
	char *name;
};
int main(int argc, char* argv[])
{
	//Declarations & Memory Allocation
	FILE *fptr;
	classStats *stats = (classStats*) malloc(sizeof(classStats));
	stats->name = (char*) malloc(8*sizeof(char));
	student *students[19];
	for(int x = 0; x < 19; x++) {
		students[x] = (student*) malloc(sizeof(student));
		students[x]->first = (char*) malloc(12*sizeof(char));
		students[x]->last = (char*) malloc(12*sizeof(char));
	} //Initializes 19 students with empty memory for pointers
	
	//Usage test
	if(argc < 2) {
		std::cout << "Usage: ./hwk1.exe file\n";
		return 1;
	}

	//File Input
	fptr = fopen(argv[1], "r");
	fscanf(fptr, "%s", stats->name);
	for(int x = 0; x < 19; x++) {
		fscanf(fptr, "%s %s %d %d %d ", students[x]->first, students[x]->last, &(students[x]->exam1), &(students[x]->exam2), &(students[x]->exam3));
	}

	//Arithmetic Block
	//Average for each student
	for(int x = 0; x < 19; x++) {
		students[x]->mean = (students[x]->exam1 + students[x]->exam2 + students[x]->exam3 )/3.00;
		stats->mean += students[x]->mean;
	}

	bubble(students, 19);
	stats->median = students[9]->mean; 	// (18/0)/2 = 9
	stats->mean /= 19.00;			//Total number of students from sum of all students
	stats->min = students[0]->mean; 	//Post-sort
	stats->max = students[18]->mean;	//Post-sort

	//Output Block
	printf("123456789012345678901234567890123456789012345678901234567890\n");
	printf("%s MEAN:  %.2f MIN:  %.2f MAX:  %.2f MEDIAN:  %.2f\n", stats->name , stats->mean, stats->min, stats->max, stats->median);
	for(int x = 0; x < 19; x++) {
		printf("%12s %12s %7.2f\n", students[x]->first, students[x]->last, students[x]->mean);
	}
	
	//Memory Clean-up
	free(stats);
	for(int x = 0; x < 19; x++) {
		free(students[x]->first);
		free(students[x]->last);
		free(students[x]);
	}	
  return 0;
}
