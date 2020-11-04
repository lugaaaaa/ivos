#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <mutex>

class Account {
    private:
        int balance{0};
        std::mutex mtx;
    public:
        Account(int bal) : balance(bal){}
        int get_balance();
        void deposit(int amount);
        bool withdraw(int amount);

};

class Depositer{
    private:
        Account& acc;
        int deposits;
    public:
      Depositer(Account& a, int d) : acc(a), deposits(d){}

        void operator()(){
            for(int i = 0; i < 5; i++){
                acc.deposit(1);
            }
        }
};

#endif
