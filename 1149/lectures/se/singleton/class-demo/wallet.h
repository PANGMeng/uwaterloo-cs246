#ifndef __WALLET_H__
#define __WALLET_H__

struct Wallet {

  //will only have one instance of a wallet: declare static
  static Wallet *instance;

  //function for clients to ask for a wallet
  static Wallet *getInstance();

  Wallet(); //ctor

  int money;

  void addMoney(int amt);

};

#endif
