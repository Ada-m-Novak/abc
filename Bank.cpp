#include "Bank.h"

#include <iostream>

Bank::Bank()
    : clients(nullptr), clientsCount(0), accounts(nullptr), accountsCount(0) {}

Bank::Bank(int c, int a)
    : clients(nullptr), clientsCount(0), accounts(nullptr), accountsCount(0) {
  if (c > 0) {
    clients = new Client *[c];
    for (int i = 0; i < c; i++) {
      clients[i] = nullptr;
    }
  }

  if (a > 0) {
    accounts = new Account *[a];
    for (int i = 0; i < a; i++) {
      accounts[i] = nullptr;
    }
  }
}

Bank::~Bank() {
  for (int i = 0; i < clientsCount; i++) {
    delete clients[i];
  }
  delete[] clients;

  for (int i = 0; i < accountsCount; i++) {
    delete accounts[i];
  }
  delete[] accounts;
}

Client *Bank::GetClient(int c) const {
  for (int i = 0; i < clientsCount; i++) {
    if (clients[i]->GetCode() == c) {
      return clients[i];
    }
  }
  return nullptr;
}

Account *Bank::GetAccount(int n) const {
  for (int i = 0; i < accountsCount; i++) {
    if (accounts[i]->GetNumber() == n) {
      return accounts[i];
    }
  }
  return nullptr;
}

Client *Bank::CreateClient(int c, const std::string &n) {
  if (GetClient(c) != nullptr) {
    return nullptr;
  }

  Client **newClients = new Client *[clientsCount + 1];

  for (int i = 0; i < clientsCount; i++) {
    newClients[i] = clients[i];
  }

  newClients[clientsCount] = new Client(c, n);

  delete[] clients;
  clients = newClients;
  clientsCount++;

  return clients[clientsCount - 1];
}

Account *Bank::CreateAccount(int n, int c, Client *owner) {
  if (owner == nullptr || GetAccount(n) != nullptr) {
    return nullptr;
  }

  Account **newAccounts = new Account *[accountsCount + 1];

  for (int i = 0; i < accountsCount; i++) {
    newAccounts[i] = accounts[i];
  }

  newAccounts[accountsCount] = new Account(n, c, owner);

  delete[] accounts;
  accounts = newAccounts;
  accountsCount++;

  return accounts[accountsCount - 1];
}

Account *Bank::CreateAccount(int n, int c, Client *owner, double ir) {
  if (owner == nullptr || GetAccount(n) != nullptr) {
    return nullptr;
  }

  Account **newAccounts = new Account *[accountsCount + 1];

  for (int i = 0; i < accountsCount; i++) {
    newAccounts[i] = accounts[i];
  }

  newAccounts[accountsCount] = new Account(n, c, owner, ir);

  delete[] accounts;
  accounts = newAccounts;
  accountsCount++;

  return accounts[accountsCount - 1];
}

Account *Bank::CreateAccount(int n, int c, Client *owner, Client *partner) {
  if (owner == nullptr || GetAccount(n) != nullptr) {
    return nullptr;
  }

  Account **newAccounts = new Account *[accountsCount + 1];

  for (int i = 0; i < accountsCount; i++) {
    newAccounts[i] = accounts[i];
  }

  newAccounts[accountsCount] = new Account(n, c, owner, partner);

  delete[] accounts;
  accounts = newAccounts;
  accountsCount++;

  return accounts[accountsCount - 1];
}

Account *Bank::CreateAccount(
    int n,
    int c,
    Client *owner,
    Client *partner,
    double ir
) {
  if (owner == nullptr || GetAccount(n) != nullptr) {
    return nullptr;
  }

  Account **newAccounts = new Account *[accountsCount + 1];

  for (int i = 0; i < accountsCount; i++) {
    newAccounts[i] = accounts[i];
  }

  newAccounts[accountsCount] = new Account(n, c, owner, partner, ir);

  delete[] accounts;
  accounts = newAccounts;
  accountsCount++;

  return accounts[accountsCount - 1];
}

void Bank::AddInterest() {
  for (int i = 0; i < accountsCount; i++) {
    accounts[i]->AddInterest();
  }
}

void Bank::PrintClients() const {
  std::cout << "=== Klienti ===\n";
  for (int i = 0; i < clientsCount; i++) {
    std::cout << "Kod: " << clients[i]->GetCode()
              << ", jmeno: " << clients[i]->GetName() << "\n";
  }
  std::cout << "\n";
}

void Bank::PrintAccounts() const {
  std::cout << "=== Ucty ===\n";
  for (int i = 0; i < accountsCount; i++) {
    std::cout << "Ucet: " << accounts[i]->GetNumber()
              << ", zustatek: " << accounts[i]->GetBalance()
              << ", urok: " << accounts[i]->GetInterestRate()
              << ", vlastnik: " << accounts[i]->GetOwner()->GetName();

    if (accounts[i]->GetPartner() != nullptr) {
      std::cout << ", partner: " << accounts[i]->GetPartner()->GetName();
    }

    std::cout << "\n";
  }
  std::cout << "\n";
}