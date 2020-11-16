#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include "work_packet.h"
#include "work_queue.h"

using namespace std;

WorkPacket WorkQueue::pop() {
  lock_guard<mutex> lock{mtx};
  WorkPacket WorkPacket{this->packets.front()};
  this->packets.pop();
  return WorkPacket;
}

void WorkQueue::push(WorkPacket WorkPacket) {
  lock_guard<mutex> lock{mtx};
  this->packets.push(WorkPacket);
}
