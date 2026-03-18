#include "Bank.h"

#include <iostream>
#include <string>

int main() {
  Bank bank;

  for (int i = 1; i <= 20; i++) {
    bank.CreateClient(1000 + i, "Klient_" + std::to_string(i));
  }

  for (int i = 1; i <= 10; i++) {
    Client *owner = bank.GetClient(1000 + i);
    bank.CreateAccount(2000 + i, 1000 * i, owner);
  }

  for (int i = 11; i <= 15; i++) {
    Client *owner = bank.GetClient(1000 + i);
    bank.CreateAccount(2000 + i, 2000 * i, owner, 0.03);
  }

  for (int i = 16; i <= 20; i++) {
    Client *owner = bank.GetClient(1000 + i);
    Client *partner = bank.GetClient(1000 + (i - 15));
    bank.CreateAccount(2000 + i, 3000 * i, owner, partner, 0.05);
  }

  bank.PrintClients();
  bank.PrintAccounts();

  std::cout << "=== Operace ===\n";

  Account *a1 = bank.GetAccount(2001);
  if (a1 != nullptr) {
    a1->Deposit(500);
    std::cout << "Na ucet 2001 vlozeno 500, novy zustatek: "
              << a1->GetBalance() << "\n";
  }

  Account *a2 = bank.GetAccount(2002);
  if (a2 != nullptr) {
    bool ok = a2->Withdraw(1500);
    std::cout << "Vyber 1500 z uctu 2002: "
              << (ok ? "uspesny" : "neuspesny")
              << ", zustatek: " << a2->GetBalance() << "\n";
  }

  Account *a3 = bank.GetAccount(2003);
  if (a3 != nullptr) {
    bool ok = a3->Withdraw(100000);
    std::cout << "Vyber 100000 z uctu 2003: "
              << (ok ? "uspesny" : "neuspesny")
              << ", zustatek: " << a3->GetBalance() << "\n";
  }

  std::cout << "\n=== Pripsani uroku ===\n";
  bank.AddInterest();
  bank.PrintAccounts();

  std::cout << "=== Vyhledani ===\n";

  Client *c = bank.GetClient(1005);
  if (c != nullptr) {
    std::cout << "Nalezen klient: " << c->GetName()
              << ", kod: " << c->GetCode() << "\n";
  }

  Account *a = bank.GetAccount(2018);
  if (a != nullptr) {
    std::cout << "Nalezen ucet: " << a->GetNumber()
              << ", vlastnik: " << a->GetOwner()->GetName()
              << ", zustatek: " << a->GetBalance() << "\n";
  }

  return 0;
}