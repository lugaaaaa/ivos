#include <iostream>
#include <unistd.h>
#include <thread>

using namespace std;

void golf_mk2() {
  int cnt{1};

  while (true) {
    cout << "Runde" << cnt << ": golf mk2" << endl;
    this_thread::sleep_for(1s);
    cnt++;
  }
}

int main(int argc, char const *argv[]) {
  golf_mk2();

  return 0;
}
