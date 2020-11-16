#pragma once

#include <iostream>
#include <queue>
#include <mutex>
#include "work_packet.h"
#include <condition_variable>

class WorkQueue {
    private:
      std::queue<WorkPacket> WorkPackets{};
      std::mutex mtx;
      std::condition_variable not_empty;
      std::condition_variable is_full;

    public:
      WorkPacket pop();
      void push(WorkPacket WorkPacket);

};
