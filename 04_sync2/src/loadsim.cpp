#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include "work_packet.h"
#include "work_queue.h"

using namespace std;
using namespace std::literals;

int main(int argc, char const *argv[]) {
  WorkQueue WorkQueue{};
  int i{0};
  while (true) {
      WorkPacket WorkPacket{i};
      WorkQueue.push(WorkPacket);
      cout << "B: Submitted work packet " << i << "\n" << flush;
      this_thread::sleep_for(0.5s);
      i++;
  }
}
