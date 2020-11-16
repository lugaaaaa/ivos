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
      std::size_t size;
      std::condition_variable not_empty;
      std::condition_variable is_full;

    public:
      WorkQueue(size_t s){
          if (s <= 0){
              this->size = 1;
          } else {
              this->size = s; 
          }
      }
      WorkPacket pop();
      void push(WorkPacket WorkPacket);

};
