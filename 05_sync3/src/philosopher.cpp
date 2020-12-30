#include <iostream>
#include <sstream>
#include <chrono>
#include <mutex>
#include <thread>
#include <vector>
#include "philosopher.h"

using namespace std;

mutex out_mtx;

void println(const vector<string>& v){
  lock_guard<mutex> lg{out_mtx};
  for (string s : v){
    cout << s << " ";
  }
  cout << endl;
}


void Philosopher::operator()(){

  stringstream buf;

  while(true) {
    buf << "Philosopher " << id << " is thinking..." << endl;
    cout << buf.str() << endl;
    buf.str("");
    this_thread::sleep_for(1s);

    buf << "Philosopher " << id << " attempts to get left fork" << endl;
    cout << buf.str() << endl;
    buf.str("");

    left_fork.lock();

    buf << "Philosopher " << id << " got left fork. Now he wants the right one..." << endl;
    cout << buf.str() << endl;
    buf.str("");

    buf << "Philosopher " << id << " attempts to get right fork" << endl;
    cout << buf.str() << endl;
    buf.str("");

    right_fork.lock();

    buf << "Philosopher " << id << " got right fork. Now he is eating..." << endl;
    cout << buf.str() << endl;
    buf.str("");

    this_thread::sleep_for(2s);

    buf << "Philosopher " << id << " finished eating" << endl;
    cout << buf.str() << endl;
    buf.str("");

    buf << "Philosopher " << id << " released left fork" << endl;
    cout << buf.str() << endl;
    buf.str("");

    left_fork.unlock();

    buf << "Philosopher " << id << " released right fork" << endl;
    cout << buf.str() << endl;
    buf.str("");

    right_fork.unlock();
  }
}
