//CSCE 1040.307
//Noah Johnson
//BankAccount.h

class BankAccount {
	public:
		int getBal();
		void setBal(int value);
		BankAccount() { balance = 0; accountNum = 0; }
		BankAccount(int num) { balance = 0; accountNum = num; }
		BankAccount(int num, int bal) { accountNum = num; balance = bal; }
	private:
		int balance;
		int accountNum;
};
