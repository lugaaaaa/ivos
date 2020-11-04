#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <mutex>

class Account {
    private:
        int balance{0};
        std::mutex mtx;
    public:
        int get_balance();
        void deposit(int amount);
        bool withdraw(int amount);

};

class Depositor {

};

#endif
