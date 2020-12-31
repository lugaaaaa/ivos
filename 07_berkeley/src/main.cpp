#include <iostream>
#include <thread>
#include <chrono>
#include "clock.h"
#include "timeutils.h"
#include "pipe.h"
#include "println.h"

using namespace std;

recursive_mutex out_mtx;

class Channel{
  private:
    Pipe<long> p1;
    Pipe<long> p2;
  public:
    Pipe<long>& get_pipe1(){
      return p1;
    }

    Pipe<long>& get_pipe2(){
      return p2;
    }
};

class TimeSlave{
  private:
    string name;
    Clock clock;
    Channel channel;
  public:
    TimeSlave(string name_, int hours_, int minutes_, int seconds_) : clock(name_ + "_clock", hours_, minutes_, seconds_){
      name = name_;
    }

    void operator()(){
      clock();
    };

    Channel* get_channel(){
      return &channel;
    }
};

class TimeMaster{
  private:
    string name;
    Clock clock;
    Channel* channel1;
    Channel* channel2;
  public:
    TimeMaster(string name_, int hours_, int minutes_, int seconds_) : clock(name_ + "_clock", hours_, minutes_, seconds_){
      name = name_;
    }

    void operator()(){
      clock();
    };

    void set_Channel1(Channel* channel) {
      channel1 = channel;
    }

    void set_Channel2(Channel* channel) {
      channel2 = channel;
    }
};

int main(int argc, char const *argv[]) {
  //thread t1(Clock{"testclock"});
  TimeSlave slave1("slave1", 12, 30, 00);
  TimeSlave slave2("slave2", 12, 30, 00);
  TimeMaster master1("master1", 12, 30, 00);

  thread s1(ref(slave1));
  thread s2(ref(slave2));
  thread m1(master1);

  //t1.join();
  s1.join();
  s2.join();
  m1.join();
}
