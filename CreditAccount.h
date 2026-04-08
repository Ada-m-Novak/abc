#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "Account.h"

class CreditAccount : public Account {
private:
  double credit;

public:
  CreditAccount(int c, Client *o, double cr);
  CreditAccount(int c, Client *o, double ir, double cr);

  double GetCredit() const;
  bool CanWithdraw(double a) const override;
};

#endif