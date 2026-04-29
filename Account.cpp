#include "Account.h"

int Account::totalAccounts = 0;

Account::Account(int c, Client *o)
{
    number = c;
    owner = o;
    balance = 0;
    interestRate = 0;
    totalAccounts++;
}

Account::Account(int c, Client *o, double ir)
{
    number = c;
    owner = o;
    balance = 0;
    interestRate = ir;
    totalAccounts++;
}

Account::~Account()
{
    totalAccounts--;
}

int Account::GetNumber() const
{
    return number;
}

Client *Account::GetOwner() const
{
    return owner;
}

double Account::GetBalance() const
{
    return balance;
}

double Account::GetInterestRate() const
{
    return interestRate;
}

void Account::Deposit(double a)
{
    if (a > 0)
        balance += a;
}

bool Account::Withdraw(double a)
{
    if (CanWithdraw(a))
    {
        balance -= a;
        return true;
    }
    return false;
}

bool Account::CanWithdraw(double a) const
{
    return a >= 0 && balance >= a;
}

Client *Account::GetClient() const
{
    return nullptr;
}
