#include <thread>
#include <mutex>
#include "philosopher.h"
#include "semaphore.h"
#include "CLI11.hpp"

using namespace std;

int main(int argc, char const *argv[]) {

  mutex right_m;
  mutex left_m;
  Semaphore* sem = new Semaphore{4};

  Philosopher p1(1, right_m, left_m);
  Philosopher p2(2, right_m, left_m);
  Philosopher p3(3, right_m, left_m);
  Philosopher p4(4, right_m, left_m);
  Philosopher p5(5, right_m, left_m);
  Philosopher p6(6, right_m, left_m);

  thread t1(p1, sem);
  thread t2(p2, sem);
  thread t3(p3, sem);
  thread t4(p4, sem);
  thread t5(p5, sem);
  thread t6(p6, sem);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();

  return 0;

}
