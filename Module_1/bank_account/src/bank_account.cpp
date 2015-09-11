#include "bank_account.hpp"

#include <iostream>


BankAccount::BankAccount(std::string const& o, std::string const& accnumber, double bal) {
	owner = o;
	accountNumber = accnumber;
	balance = bal;
}
std::string BankAccount::getOwner() const {
	return owner;
}

std::string BankAccount::getNumber() const {
	return accountNumber;
}

double BankAccount::getBalance() const {
	return balance;
}

void BankAccount::deposit(double amount) {
	balance += amount;
}

bool BankAccount::withdraw(double amount) {
	if(amount <= balance) {
		balance -= amount;
		return true;
	} else {
		return false;
	}
}

void BankAccount::print() const {
	std::cout << "Account num: " << accountNumber << ", owned by: " << owner << ", balance: " << balance << " eur." << std::endl;
}

bool transfer(BankAccount& sourceAccount, BankAccount& targetAccount, double amount) {
	// if money can be withdraw, do it and return true
	if(sourceAccount.withdraw(amount)) {

		targetAccount.deposit(amount);
		return true;

	} else {
		return false;
	}
}