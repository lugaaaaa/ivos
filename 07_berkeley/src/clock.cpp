#include <iostream>
#include <thread>
#include <chrono>
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
