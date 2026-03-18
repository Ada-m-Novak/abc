#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Client.h"

class Account {
private:
  int number;
  double balance;
  double interestRate;
  Client *owner;
  Client *partner;

public:
  Account(int n, int c, Client *o);
  Account(int n, int c, Client *o, double ir);
  Account(int n, int c, Client *o, Client *p);
  Account(int n, int c, Client *o, Client *p, double ir);

  int GetNumber() const;
  double GetBalance() const;
  double GetInterestRate() const;
  Client *GetOwner() const;
  Client *GetPartner() const;

  bool CanWithdraw(double a) const;
  void Deposit(double a);
  bool Withdraw(double a);
  void AddInterest();
};

#endif