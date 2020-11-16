#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <random>
#include "work_packet.h"
#include "work_queue.h"

using namespace std;
using namespace std::literals;

void worker (int id, WorkQueue& q) {
    while (true) {
      std::random_device rd;
      std::mt19937 gen{rd()};
      std::uniform_real_distribution<> dis{0, 1};
      double rand{dis(gen)};
      std::chrono::duration<double> duration(rand);
      cout << "W" << id << ": Want work packet" << "\n" << flush;
      WorkPacket WorkPacket {q.pop()};
      cout << "W" << id << ": Got work packet " << WorkPacket.getId() << "\n" << flush;
      std::this_thread::sleep_for(std::chrono::duration_cast<std::chrono::milliseconds>(duration));
      cout << "W" << id << ": Processed work packet " << WorkPacket.getId() << "\n" << flush;
    }
}

int main(int argc, char const *argv[]) {
  WorkQueue WorkQueue{};
  int i{1};
  thread t1([&](){worker(1, WorkQueue);});
  thread t2([&](){worker(2, WorkQueue);});
  thread t3([&](){worker(3, WorkQueue);});
  while (true) {
      WorkPacket WorkPacket(i);
      WorkQueue.push(WorkPacket);
      cout << "B: Submitted work packet " << i << "\n" << flush;
      std::random_device rd;
      std::mt19937 gen{rd()};
      std::uniform_real_distribution<> dis{0, 1};
      double rand{dis(gen)};
      std::chrono::duration<double> duration(rand);
      std::this_thread::sleep_for(std::chrono::duration_cast<std::chrono::milliseconds>(duration));
      i++;
  }
  t1.join();
  t2.join();
  t3.join();
}
