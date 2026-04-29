#include <iostream>
#include "Client.h"
#include "Account.h"
#include "CreditAccount.h"
#include "AbstractAccount.h"

using namespace std;

int main()
{
    Client c1("Alfons habrman");

    AbstractAccount *a1 = new Account(1001, &c1);
    AbstractAccount *a2 = new CreditAccount(1002, &c1, 500);

    cout << a1->CanWithdraw(100) << endl;
    cout << a2->CanWithdraw(100) << endl;

    delete a1;
    delete a2;

    return 0;
}
