#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "Client.h"

class Bank {
private:
  Client **clients;
  int clientsCount;

  Account **accounts;
  int accountsCount;

public:
  Bank();
  Bank(int c, int a);
  ~Bank();

  Bank(const Bank &) = delete;
  Bank &operator=(const Bank &) = delete;

  Client *GetClient(int c) const;
  Account *GetAccount(int n) const;

  Client *CreateClient(int c, const std::string &n);

  Account *CreateAccount(int n, int c, Client *owner);
  Account *CreateAccount(int n, int c, Client *owner, double ir);
  Account *CreateAccount(int n, int c, Client *owner, Client *partner);
  Account *CreateAccount(
      int n,
      int c,
      Client *owner,
      Client *partner,
      double ir//av
  );

  void AddInterest();

  void PrintClients() const;
  void PrintAccounts() const;
};

#endif