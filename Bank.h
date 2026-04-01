#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "Client.h"
#include "PartnerAccount.h"

class Bank {
private:
  Client **clients;
  int clientsCount;

  Account **accounts;
  int accountsCount;

public:
  Bank();
  ~Bank();

  Bank(const Bank &) = delete;
  Bank &operator=(const Bank &) = delete;

  Client *GetClient(int c) const;
  Account *GetAccount(int n) const;

  Client *CreateClient(const std::string &name);

  Account *CreateAccount(int c, Client *owner);
  Account *CreateAccount(int c, Client *owner, double ir);
  Account *CreateAccount(int c, Client *owner, Client *partner);
  Account *CreateAccount(int c, Client *owner, Client *partner, double ir);

  bool RemoveAccount(int number);
  bool RemoveClient(int code);

  int GetClientsCount() const;
  int GetAccountsCount() const;

  void AddInterest();

  void PrintClients() const;
  void PrintAccounts() const;
};

#endif