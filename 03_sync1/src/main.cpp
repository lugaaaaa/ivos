#include <iostream>
#include <thread>
#include "account.h"

using namespace std;

int main() {

  /* Punkt 1
  Account test{Account()};
  test.deposit(15);
  cout << test.withdraw(10) << endl;
  cout << test.get_balance() << endl;
  */


  Account test{Account()};
  test.deposit(1);

  thread t1{[&](){
    cout << "Thread 1" << endl;
    cout << test.withdraw(1) << endl;
    cout << test.get_balance() << endl;
  }};

  thread t2{[&](){
    cout << "Thread 2" << endl;
    cout << test.withdraw(1) << endl;
    cout << test.get_balance() << endl;
  }};

  t1.join();
  t2.join();


  return 0;
}
