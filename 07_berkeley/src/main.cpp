#include <iostream>
#include <thread>
#include <chrono>
#include "clock.h"
#include "timeutils.h"

using namespace std;

class TimeSlave{
  private:
    string name;
    Clock clock;
  public:
    TimeSlave(string name_, int hours_, int minutes_, int seconds_) : clock(name_ + "_clock", hours_, minutes_, seconds_){
      name = name_;
    }

    void operator()(){
      clock();
    };
};

int main(int argc, char const *argv[]) {
  //thread t1(Clock{"testclock"});
  thread t2(TimeSlave{"testslave", 12, 30, 00});

  //t1.join();
  t2.join();
}
