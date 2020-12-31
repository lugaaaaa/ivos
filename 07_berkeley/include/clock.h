#pragma once

class Clock{
  private:
    std::string name;
    std::chrono::time_point<std::chrono::system_clock> curr_time = std::chrono::system_clock::now();
  public:
    Clock(std::string _name): name{_name}{};
    void  operator()();
};
