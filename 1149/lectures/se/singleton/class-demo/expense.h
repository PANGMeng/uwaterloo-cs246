#ifndef __EXPENSE_H__
#define __EXPENSE_H__
#include <string>
#include "wallet.h"

struct Expense {

  //expense description
  const std::string desc;

  //expsense amount
  const int amt;
  
  //access to a wallet
  Wallet *wallet;

  //ctor
  Expense(std::string desc, int amt);
  
  //pay the expense
  void pay();
};

#endif
