#include <iostream>
#include <thread>
#include <chrono>
#include "clock.h"
#include "timeutils.h"

using namespace std;

int main(int argc, char const *argv[]) {
  thread t1(Clock{"testclock"});
  t1.join();
}
