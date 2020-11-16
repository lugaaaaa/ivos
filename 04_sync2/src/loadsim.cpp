#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include "work_packet.h"
#include "work_queue.h"

using namespace std;
using namespace std::literals;

void worker (int id, WorkQueue& q) {
    while (true) {
      cout << "W" << id << ": Want work packet" << "\n" << flush;
      WorkPacket WorkPacket {q.pop()};
      cout << "W" << id << ": Got work packet " << WorkPacket.getId() << "\n" << flush;
      this_thread::sleep_for(1s);
      cout << "W" << id << ": Processed work packet " << WorkPacket.getId() << "\n" << flush;
    }
}

int main(int argc, char const *argv[]) {
  WorkQueue WorkQueue{};
  int i{1};
  thread t1([&](){worker(1, WorkQueue);});
  thread t2([&](){worker(2, WorkQueue);});
  while (true) {
      WorkPacket WorkPacket(i);
      WorkQueue.push(WorkPacket);
      cout << "B: Submitted work packet " << i << "\n" << flush;
      this_thread::sleep_for(0.5s);
      i++;
  }
}
