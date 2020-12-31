#include <iostream>
#include <thread>
#include <chrono>
#include "clock.h"
#include "timeutils.h"

using namespace std;

int main(int argc, char const *argv[]) {
  thread t1(Clock{"testclock"});
  thread t2(Clock{"testclock", 12, 30, 00});

  t1.join();
  t2.join();
}
