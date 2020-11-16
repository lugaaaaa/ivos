#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include "work_packet.h"
#include "work_queue.h"

using namespace std;

WorkPacket WorkQueue::pop() {
  unique_lock<mutex> lock{mtx};
  not_empty.wait(lock, [this]{return WorkPackets.size();});
  WorkPacket WorkPacket{this->WorkPackets.front()};
  this->WorkPackets.pop();
  is_full.notify_one();
  return WorkPacket;
}

void WorkQueue::push(WorkPacket WorkPacket) {
  unique_lock<mutex> lock{mtx};
  is_full.wait(lock, [this]{return(WorkPackets.size() <= this->size);});
  this->WorkPackets.push(WorkPacket);
  not_empty.notify_one();
}
