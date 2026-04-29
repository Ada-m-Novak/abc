#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "AbstractAccount.h"
#include "Client.h"

class Account : public AbstractAccount
{
protected:
    int number;
    Client *owner;
    double balance;
    double interestRate;
    static int totalAccounts;

public:
    Account(int c, Client *o);
    Account(int c, Client *o, double ir);
    virtual ~Account();

    int GetNumber() const;
    Client *GetOwner() const;
    double GetBalance() const;
    double GetInterestRate() const;

    void Deposit(double a);
    bool Withdraw(double a);
    virtual bool CanWithdraw(double a) const override;
    virtual Client *GetClient() const;
};

#endif
