#include "wallet.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Wallet *Wallet::instance = 0;

Wallet *Wallet::getInstance() {
  if (!instance) {
    instance = new Wallet;
  }
  return instance;
}

Wallet::Wallet(): money(0) {}

void Wallet::addMoney(int amt) { money += amt; }
