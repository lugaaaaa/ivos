#pragma once

#include <mutex>
#include <vector>

class Philosopher{
    private:
        int id;
        std::mutex& left_fork;
        std::mutex& right_fork;
        
    public:
        Philosopher(int philosoph, std::mutex& fork_left, std::mutex& fork_right):
            id(philosoph), left_fork(fork_left), right_fork(fork_right) {};
        void operator()();
};
