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

  while (true) {
    if (pid == 0) {
      cout << "A" << endl;
      sleep(1);
    }
    else {
      cout << "B" << endl;
      sleep(1);
    }
  }
}
