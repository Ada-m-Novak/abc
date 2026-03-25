#include "Bank.h"

#include <iostream>

Bank::Bank()
    : clients(nullptr), clientsCount(0), accounts(nullptr), accountsCount(0) {}

Bank::~Bank() {
  for (int i = 0; i < accountsCount; i++) {
    delete accounts[i];
  }
  delete[] accounts;

  for (int i = 0; i < clientsCount; i++) {
    delete clients[i];
  }
  delete[] clients;
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

Client *Bank::CreateClient(const std::string &name) {
  Client **newClients = new Client *[clientsCount + 1];

  for (int i = 0; i < clientsCount; i++) {
    newClients[i] = clients[i];
  }

  newClients[clientsCount] = new Client(name);

  delete[] clients;
  clients = newClients;
  clientsCount++;

  return clients[clientsCount - 1];
}

Account *Bank::CreateAccount(int c, Client *owner) {
  if (owner == nullptr) {
    return nullptr;
  }

  Account **newAccounts = new Account *[accountsCount + 1];

  for (int i = 0; i < accountsCount; i++) {
    newAccounts[i] = accounts[i];
  }

  newAccounts[accountsCount] = new Account(c, owner);

  delete[] accounts;
  accounts = newAccounts;
  accountsCount++;

  return accounts[accountsCount - 1];
}

Account *Bank::CreateAccount(int c, Client *owner, double ir) {
  if (owner == nullptr) {
    return nullptr;
  }

  Account **newAccounts = new Account *[accountsCount + 1];

  for (int i = 0; i < accountsCount; i++) {
    newAccounts[i] = accounts[i];
  }

  newAccounts[accountsCount] = new Account(c, owner, ir);

  delete[] accounts;
  accounts = newAccounts;
  accountsCount++;

  return accounts[accountsCount - 1];
}

Account *Bank::CreateAccount(int c, Client *owner, Client *partner) {
  if (owner == nullptr) {
    return nullptr;
  }

  Account **newAccounts = new Account *[accountsCount + 1];

  for (int i = 0; i < accountsCount; i++) {
    newAccounts[i] = accounts[i];
  }

  newAccounts[accountsCount] = new Account(c, owner, partner);

  delete[] accounts;
  accounts = newAccounts;
  accountsCount++;

  return accounts[accountsCount - 1];
}

Account *Bank::CreateAccount(int c, Client *owner, Client *partner, double ir) {
  if (owner == nullptr) {
    return nullptr;
  }

  Account **newAccounts = new Account *[accountsCount + 1];

  for (int i = 0; i < accountsCount; i++) {
    newAccounts[i] = accounts[i];
  }

  newAccounts[accountsCount] = new Account(c, owner, partner, ir);

  delete[] accounts;
  accounts = newAccounts;
  accountsCount++;

  return accounts[accountsCount - 1];
}

bool Bank::RemoveAccount(int number) {
  int index = -1;

  for (int i = 0; i < accountsCount; i++) {
    if (accounts[i]->GetNumber() == number) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    return false;
  }

  delete accounts[index];

  Account **newAccounts = nullptr;
  if (accountsCount - 1 > 0) {
    newAccounts = new Account *[accountsCount - 1];
  }

  for (int i = 0, j = 0; i < accountsCount; i++) {
    if (i != index) {
      newAccounts[j] = accounts[i];
      j++;
    }
  }

  delete[] accounts;
  accounts = newAccounts;
  accountsCount--;

  return true;
}

bool Bank::RemoveClient(int code) {
  int clientIndex = -1;
  Client *client = nullptr;

  for (int i = 0; i < clientsCount; i++) {
    if (clients[i]->GetCode() == code) {
      clientIndex = i;
      client = clients[i];
      break;
    }
  }

  if (clientIndex == -1) {
    return false;
  }

  for (int i = 0; i < accountsCount;) {
    if (accounts[i]->GetOwner() == client) {
      int number = accounts[i]->GetNumber();
      RemoveAccount(number);
    } else {
      if (accounts[i]->GetPartner() == client) {
        accounts[i]->RemovePartner();
      }
      i++;
    }
  }

  delete clients[clientIndex];

  Client **newClients = nullptr;
  if (clientsCount - 1 > 0) {
    newClients = new Client *[clientsCount - 1];
  }

  for (int i = 0, j = 0; i < clientsCount; i++) {
    if (i != clientIndex) {
      newClients[j] = clients[i];
      j++;
    }
  }

  delete[] clients;
  clients = newClients;
  clientsCount--;

  return true;
}

int Bank::GetClientsCount() const { return clientsCount; }

int Bank::GetAccountsCount() const { return accountsCount; }

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