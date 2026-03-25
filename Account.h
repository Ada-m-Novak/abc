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

  static int nextNumber;
  static int totalAccounts;

public:
  Account(int c, Client *o);
  Account(int c, Client *o, double ir);
  Account(int c, Client *o, Client *p);
  Account(int c, Client *o, Client *p, double ir);
  ~Account();

  int GetNumber() const;
  double GetBalance() const;
  double GetInterestRate() const;
  Client *GetOwner() const;
  Client *GetPartner() const;

  bool CanWithdraw(double a) const;
  void Deposit(double a);
  bool Withdraw(double a);
  void AddInterest();

  void RemovePartner();

  static int GetTotalAccounts();
};

#endif