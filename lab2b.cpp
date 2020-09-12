//CSCE 1040.307
//Noah Johnson
//lab2b.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "BankAccount.h"

using namespace std;

BankAccount bank[10];


int BankAccount::getBal() {
	return this->balance;
}

void BankAccount::setBal(int value) {
	this->balance = value;
}

void deposit(int num, int value) {
	bank[num].setBal(bank[num].getBal() + value);
}


bool withdraw(int num, int value) {
	if(bank[num].getBal() < value) {
		cout << "Overdraft on account " << num << ". Transaction did not go through."<< endl;
		return false;
	} else
	bank[num].setBal(bank[num].getBal() - value);
	return true;
}

int balance(int num) {
	return bank[num].getBal();
}

void transfer(int num1, int num2, int value) {
	if(withdraw(num1, value))
		deposit(num2, value);
}

int main() {
	char operation[16];
	int acct = 0;
	int acct2 = 0;
	int value = 0;

	while(strcmp(operation, "quit") != 0) {
		cout << "bank>";
		scanf("%s", operation);
		if(strcmp(operation, "deposit") == 0) {
			scanf(" %d %d", &acct, &value);
			deposit(acct, value);
		} else if(strcmp(operation,"withdraw") == 0) {
			scanf(" %d %d", &acct, &value);
			withdraw(acct, value);
		} else if(strcmp(operation, "balance") == 0) {
			scanf(" %d", &acct);
			cout << balance(acct) << endl;
		} else if(strcmp(operation, "transfer") == 0) {
			scanf(" %d %d %d", &acct, &acct2, &value);
			transfer(acct, acct2, value);
		} else if(strcmp(operation, "quit") == 0)
			break;
		else
			cout << "Invalid operation " << operation << endl;

	}
	return 0;
}

