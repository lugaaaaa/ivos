#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <signal.h>
#include <sys/wait.h>
#include <cerrno>

using namespace std;

int main(int argc, char const* argv[]) {
  auto pid{fork()};
  chrono::milliseconds sleeptime(500);

  while (true) {
    if (pid == 0) {
      cout << "A" << endl;
      this_thread::sleep_for(sleeptime);
    }
    else {
      cout << "B" << endl;
      this_thread::sleep_for(sleeptime);
    }
  }
}
