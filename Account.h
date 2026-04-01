#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Client.h"

class Account {
protected:
  int number;
  double balance;
  double interestRate;
  Client *owner;

  static int nextNumber;
  static int totalAccounts;

public:
  Account(int c, Client *o);
  Account(int c, Client *o, double ir);
  virtual ~Account();

  int GetNumber() const;
  double GetBalance() const;
  double GetInterestRate() const;
  Client *GetOwner() const;

  virtual Client *GetClient() const;

  bool CanWithdraw(double a) const;
  void Deposit(double a);
  bool Withdraw(double a);
  void AddInterest();

  static int GetTotalAccounts();
};

#endif