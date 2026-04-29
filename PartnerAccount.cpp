#include "CreditAccount.h"

CreditAccount::CreditAccount(int c, Client *o, double cr)
    : Account(c, o)
{
    credit = cr;
}

CreditAccount::CreditAccount(int c, Client *o, double ir, double cr)
    : Account(c, o, ir)
{
    credit = cr;
}

double CreditAccount::GetCredit() const
{
    return credit;
}

bool CreditAccount::CanWithdraw(double a) const
{
    return a >= 0 && balance + credit >= a;
}
