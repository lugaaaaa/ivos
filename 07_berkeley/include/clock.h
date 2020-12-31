#pragma once

#include "timeutils.h"

class Clock{
  private:
    std::string name;
    std::chrono::time_point<std::chrono::system_clock> curr_time = std::chrono::system_clock::now();
  public:
    Clock(std::string _name): name{_name}{};
    Clock(std::string name_, int hours_, int minutes_, int seconds_) {
      name = name_;
      curr_time = set_time(curr_time, hours_, minutes_, seconds_);
    };

    void  operator()();
};
