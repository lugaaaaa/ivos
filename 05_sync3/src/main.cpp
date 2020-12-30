#include <thread>
#include <mutex>
#include "philosopher.h"
#include "semaphore.h"
#include "CLI11.hpp"

using namespace std;

int main(int argc, char const *argv[]) {

  mutex right_m;
  mutex left_m;

  Philosopher p1(1, right_m, left_m);
  Philosopher p2(2, right_m, left_m);
  Philosopher p3(3, right_m, left_m);
  Philosopher p4(4, right_m, left_m);

  thread t1(p1);
  thread t2(p2);
  thread t3(p3);
  thread t4(p4);

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  return 0;

}
