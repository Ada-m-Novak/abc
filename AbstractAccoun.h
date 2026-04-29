#ifndef ABSTRACTACCOUNT_H
#define ABSTRACTACCOUNT_H

class AbstractAccount
{
public:
    virtual ~AbstractAccount();
    virtual bool CanWithdraw(double a) const = 0;
};

#endif
