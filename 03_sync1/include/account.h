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
    public:
        Depositer(Account& a) : acc(a){}

        void operator()(){
            for(int i = 0; i < 5; i++){
                acc.deposit(1);
            }
        }
};

#endif
