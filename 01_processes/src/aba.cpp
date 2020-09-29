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
  } else if (pid > 0) {
      auto pid2{fork()};
      if (pid2 == 0){
        execl("./charout", "charout", "B", nullptr);
      }else if (pid2 > 0) {
        while (cnt < 6) {
          this_thread::sleep_for(sleeptime);
          cnt++;
        }
        kill(pid, SIGKILL);
        kill(pid2, SIGKILL);
        waitpid(pid, &status, 0);
        waitpid(pid2, &status, 0);
      }
  }

}
