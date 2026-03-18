#include "Account.h"

Account::Account(int n, int c, Client *o)
    : number(n),
      balance(c),
      interestRate(0.01),
      owner(o),
      partner(nullptr) {}

Account::Account(int n, int c, Client *o, double ir)
    : number(n), balance(c), interestRate(ir), owner(o), partner(nullptr) {}

Account::Account(int n, int c, Client *o, Client *p)
    : number(n), balance(c), interestRate(0.01), owner(o), partner(p) {}

Account::Account(int n, int c, Client *o, Client *p, double ir)
    : number(n), balance(c), interestRate(ir), owner(o), partner(p) {}

int Account::GetNumber() const { return number; }

double Account::GetBalance() const { return balance; }

double Account::GetInterestRate() const { return interestRate; }

Client *Account::GetOwner() const { return owner; }

Client *Account::GetPartner() const { return partner; }

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