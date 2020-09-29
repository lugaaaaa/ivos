#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <csignal>
#include <sys/wait.h>
#include <cerrno>

using namespace std;

int main(int argc, char const* argv[]) {
  auto pid{fork()};
  chrono::milliseconds sleeptime(500);
  int cnt{0};
  int status;

  if (pid == 0) {
    execl("./charout", "charout", "A", nullptr);
    this_thread::sleep_for(sleeptime);
  }
    else if (pid > 0){
      while (cnt < 6) {
        //execl("./charout", "charout", "B", nullptr);
        cout << "B" << flush;
        this_thread::sleep_for(sleeptime);
        cnt++;
      }
      kill(pid, SIGKILL);
    }


    waitpid(pid, &status, 0);
}
