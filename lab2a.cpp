//CSCE 1040.307
//Noah Johnson
//lab2a.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string operation = "";

	while(operation != "quit") {
		cout << "bank>";
		cin >> operation;
		if(operation == "deposit") {
			cout << "DEPOSIT SELECTED" << endl;
		} else if(operation == "withdraw") {
			cout << "WITHDRAW SELECTED" << endl;
		} else if(operation == "balance") {
			cout << "BALANCE SELECTED" << endl;
		} else if(operation == "quit")
			break;
		else
			cout << "Invalid operation " << operation << "." << endl;

	}
}

