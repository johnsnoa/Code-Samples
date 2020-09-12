//Noah Johnson
//CSCE1040.30

#include <stdio.h>
#include <stdlib.h>

struct employee {
	char* name;
	int id;
};

struct customer {
	char* name;
	int id;
	float bal;
};

int main(int argc, char* argv[]) {
	//Variable Declarations
	FILE *fptr;
	employee *employees[50];
	customer *customers[50];
	int numEmployees = 0;
	int numCustomers = 0;
	char operation = ' ';

	//Memory Allocations
	for(int x = 0; x < 50; x++) {
		employees[x] = (employee*) malloc(sizeof(employee));
		employees[x]->name = (char*) malloc(16*sizeof(char));
		customers[x] = (customer*) malloc(sizeof(customer));
		customers[x]->name = (char*) malloc(16*sizeof(char));
	} //Allocates memory for 50 employees and 50 students
	
	//Usage case
	if(argc != 2) {
		printf("Usage: ./lab1assignment.exe [file]\n");
		return 1;
	}
	
	//File Input
	fptr = fopen(argv[1], "r");							// Open file specified by command line argument
	do {
		fscanf(fptr, "%c", (char*) &operation);			// Scans for a character to use for operations
		switch(operation) {
			case 'e': //Employee Case
				fscanf(fptr, "%d ", &numEmployees);
				employees[numEmployees-1]->id = numEmployees;
				fscanf(fptr, "%s ", employees[numEmployees-1]->name);
				break;
			case'c': //Customer Case
				fscanf(fptr, "%d ", &numCustomers);
				customers[numCustomers-1]->id = numCustomers;
				fscanf(fptr, "%s %f ", customers[numCustomers-1]->name, &(customers[numCustomers-1]->bal));
				break;
			case 't':  {//Transaction Case
				int cTrans = 0;
				int eTrans = 0;
				float balChange = 0.0;
				fscanf(fptr,"%d %d %c %f ", &cTrans, &eTrans, (char*) &operation, &(balChange)); //Re-uses operation variable in order to save memory
				switch(operation) { //Arithmetic and Outputs
					case 'w': 
						customers[cTrans-1]->bal -= balChange;
						printf("%16s %16s -$%7.2f $%9.2f\n", customers[cTrans-1]->name, employees[eTrans-1]->name, balChange, customers[cTrans-1]->bal);
						break;
					case 'd': 
						customers[cTrans-1]->bal += balChange;
						printf("%16s %16s +$%7.2f $%9.2f\n", customers[cTrans-1]->name, employees[eTrans-1]->name, balChange, customers[cTrans-1]->bal);
						break;
					}
				} //This code is enclosed in brackets because of the variable initializations above. These variables are declared here for readability purposes. 	
				break;
			default: return 0;
		}
	} while(true);
	
	//Deleting remaining memory that is still allocated
	fclose(fptr);						//Close file
	for(int x = 0; x < 50; x++) {
		free(customers[x]->name);
		free(employees[x]->name);
		free(customers[x]);
		free(employees[x]);
	}
	return 0;
}
