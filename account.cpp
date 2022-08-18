//
// Created by Dan on 17/08/2022.
//

#include "account.h"
#include <string>


account::account(const std::string& nameIn, double initialValue)
{
    acc_balance = initialValue;
    name = nameIn;
}

account::account(){acc_balance= 0;name="";}

void account::deposit(double amount)
{
    acc_balance += amount;
}

void account::withdraw(double amount)
{
    acc_balance -= amount;
}

double account::balance() const
{
    return acc_balance;
}

bool account::has_funds() const
{
    if (acc_balance > 0.0) {return true;} else {return false;}
}

std::string account::get_name() const{
    return name;
}