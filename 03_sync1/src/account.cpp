#include <iostream>
#include "account.h"

using namespace std;

int Account::get_balance() {
  return balance;
}

void Account::deposit(int amount) {
  balance += amount;
}

bool Account::withdraw(int amount) {
  if (balance - amount < 0) {
    return false;
  } else if (balance - amount >= 0) {
    balance -= amount;
    return true;
  }
  return 0;
}
