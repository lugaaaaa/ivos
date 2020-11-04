#include <iostream>
#include <thread>
#include <mutex>
#include "account.h"

using namespace std;

int Account::get_balance() {
  return balance;
}

void Account::deposit(int amount) {
  unique_lock <mutex> lock{mtx};

  balance += amount;
}

bool Account::withdraw(int amount) {
  lock_guard <mutex> lock{mtx};

  if (balance - amount < 0) {
    return false;
  } else if (balance - amount >= 0) {
    this_thread::yield();
    balance -= amount;
    return true;
  }
  return 0;
}
