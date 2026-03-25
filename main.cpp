#include "Bank.h"

#include <iostream>
#include <string>

int main() {
  Bank bank1;
  Bank bank2;

  for (int i = 1; i <= 20; i++) {
    bank1.CreateClient("Klient_A_" + std::to_string(i));
  }

  for (int i = 1; i <= 10; i++) {
    bank2.CreateClient("Klient_B_" + std::to_string(i));
  }

  std::cout << "=== Pocty klientu ===\n";
  std::cout << "Bank1: " << bank1.GetClientsCount() << "\n";
  std::cout << "Bank2: " << bank2.GetClientsCount() << "\n";
  std::cout << "Celkove ve vsech bankach: " << Client::GetTotalClients()
            << "\n\n";

  for (int i = 1000; i < 1010; i++) {
    Client *owner = bank1.GetClient(i);
    bank1.CreateAccount(1000 * (i - 999), owner);
  }

  for (int i = 1010; i < 1015; i++) {
    Client *owner = bank1.GetClient(i);
    bank1.CreateAccount(2000 * (i - 1009), owner, 0.03);
  }

  for (int i = 1015; i < 1020; i++) {
    Client *owner = bank1.GetClient(i);
    Client *partner = bank1.GetClient(1000 + (i - 1015));
    bank1.CreateAccount(3000 * (i - 1014), owner, partner, 0.05);
  }

  std::cout << "=== Pocty uctu ===\n";
  std::cout << "Bank1: " << bank1.GetAccountsCount() << "\n";
  std::cout << "Bank2: " << bank2.GetAccountsCount() << "\n";
  std::cout << "Celkove ve vsech bankach: " << Account::GetTotalAccounts()
            << "\n\n";

  bank1.PrintClients();
  bank1.PrintAccounts();

  std::cout << "=== Operace ===\n";

  Account *a1 = bank1.GetAccount(2000);
  if (a1 != nullptr) {
    a1->Deposit(500);
    std::cout << "Na ucet " << a1->GetNumber()
              << " vlozeno 500, novy zustatek: " << a1->GetBalance() << "\n";
  }

  Account *a2 = bank1.GetAccount(2001);
  if (a2 != nullptr) {
    bool ok = a2->Withdraw(1500);
    std::cout << "Vyber 1500 z uctu " << a2->GetNumber() << ": "
              << (ok ? "uspesny" : "neuspesny")
              << ", zustatek: " << a2->GetBalance() << "\n";
  }

  Account *a3 = bank1.GetAccount(2002);
  if (a3 != nullptr) {
    bool ok = a3->Withdraw(100000);
    std::cout << "Vyber 100000 z uctu " << a3->GetNumber() << ": "
              << (ok ? "uspesny" : "neuspesny")
              << ", zustatek: " << a3->GetBalance() << "\n";
  }

  std::cout << "\n=== Pripsani uroku ===\n";
  bank1.AddInterest();
  bank1.PrintAccounts();

  std::cout << "=== Mazani uctu ===\n";
  bool removedAccount = bank1.RemoveAccount(2002);
  std::cout << "Smazani uctu 2002: "
            << (removedAccount ? "uspesne" : "neuspesne") << "\n";
  std::cout << "Bank1 ma ted uctu: " << bank1.GetAccountsCount() << "\n";
  std::cout << "Celkove uctu ve vsech bankach: "
            << Account::GetTotalAccounts() << "\n\n";

  std::cout << "=== Mazani klienta ===\n";
  bool removedClient = bank1.RemoveClient(1000);
  std::cout << "Smazani klienta 1000: "
            << (removedClient ? "uspesne" : "neuspesne") << "\n\n";

  std::cout << "Bank1 ma ted klientu: " << bank1.GetClientsCount() << "\n";
  std::cout << "Bank1 ma ted uctu: " << bank1.GetAccountsCount() << "\n";
  std::cout << "Celkove klientu ve vsech bankach: "
            << Client::GetTotalClients() << "\n";
  std::cout << "Celkove uctu ve vsech bankach: "
            << Account::GetTotalAccounts() << "\n\n";

  bank1.PrintClients();
  bank1.PrintAccounts();

  std::cout << "=== Kontrola generovani novych cisel ===\n";
  Client *newClient = bank1.CreateClient("Novy_klient");
  if (newClient != nullptr) {
    std::cout << "Novy klient dostal kod: " << newClient->GetCode() << "\n";
  }

  Account *newAccount = bank1.CreateAccount(9999, newClient);
  if (newAccount != nullptr) {
    std::cout << "Novy ucet dostal cislo: " << newAccount->GetNumber() << "\n";
  }

  std::cout << "\nSmazane kody a cisla se znovu nepouzivaji.\n";

  return 0;
}