#include <iostream>
#include <sstream>
#include <chrono>
#include <mutex>
#include <thread>
#include <vector>
#include "philosopher.h"

using namespace std;

std::recursive_mutex out_mtx;

void println() {
  std::lock_guard<std::recursive_mutex> lg{out_mtx};
  std::cout << std::endl;
}

template<typename T, typename... Rest>
void println(const T& word, const Rest&... rest) {
  std::lock_guard<std::recursive_mutex> lg{out_mtx};
  std::cout << word << ' ';
  println(rest...);
}


void Philosopher::operator()(){

  stringstream buf;

  while(true) {
    println("Philosopher ", id, " is thinking...");
    this_thread::sleep_for(1s);

    println("Philosopher ", id, " attempts to get left fork");
    left_fork.lock();
    this_thread::sleep_for(5s);

    println("Philosopher ", id, " got left fork. Now he wants the right one...");

    println("Philosopher ", id, " attempts to get right fork");
    right_fork.lock();

    println("Philosopher ", id, " got right fork. Now he is eating...");
    this_thread::sleep_for(5s);

    println("Philosopher ", id, " finished eating");

    println("Philosopher ", id, " released left fork");
    left_fork.unlock();

    println("Philosopher ", id, " released right fork");
    right_fork.unlock();
  }
}
