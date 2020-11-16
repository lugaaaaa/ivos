#pragma once

#include <iostream>
#include <queue>
#include <mutex>
#include "work_packt.h"
#include <condition_variable>

class WorkQueue {
    private:
      std::queue<WorkPacket> WorkPackets{};
      std::mutex mtx;
    public:
      WorkPacket pop();
      void push(WorkPacket WorkPacket);
      
};
