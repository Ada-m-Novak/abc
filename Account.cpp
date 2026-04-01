#include "Account.h"

int Account::nextNumber = 2000;
int Account::totalAccounts = 0;

Account::Account(int c, Client *o)
    : number(nextNumber++), balance(c), interestRate(0.01), owner(o) {
  totalAccounts++;
}

Account::Account(int c, Client *o, double ir)
    : number(nextNumber++), balance(c), interestRate(ir), owner(o) {
  totalAccounts++;
}

Account::~Account() { totalAccounts--; }

int Account::GetNumber() const { return number; }

double Account::GetBalance() const { return balance; }

double Account::GetInterestRate() const { return interestRate; }

Client *Account::GetOwner() const { return owner; }

Client *Account::GetClient() const { return nullptr; }

bool Account::CanWithdraw(double a) const { return a >= 0 && balance >= a; }

void Account::Deposit(double a) {
  if (a > 0) {
    balance += a;
  }
}

bool Account::Withdraw(double a) {
  if (!CanWithdraw(a)) {
    return false;
  }

  balance -= a;
  return true;
}

void Account::AddInterest() { balance += balance * interestRate; }

int Account::GetTotalAccounts() { return totalAccounts; }