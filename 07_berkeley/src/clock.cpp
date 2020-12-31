#include <iostream>
#include <thread>
#include <chrono>
#include <tuple>
#include "clock.h"
#include "timeutils.h"

using namespace std;

void Clock::operator()(){
  while(true){
    cout << name << ": " << curr_time << endl;
    this_thread::sleep_for(1s);
    curr_time += 1s;
  }
}

void Clock::set_time(int hours, int minutes, int seconds){
  curr_time = clock_functions::set_time(curr_time, hours, minutes, seconds);
};

tuple<int, int, int> Clock::get_time(){
  return clock_functions::get_time(curr_time);
};
