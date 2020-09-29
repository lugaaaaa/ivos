#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char const *argv[]) {
  chrono::milliseconds sleeptime(500);

  while(true){
    cout << argv[1] << flush;
    this_thread::sleep_for(sleeptime);
  }


  return 0;
}
