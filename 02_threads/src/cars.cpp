#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <signal.h>
#include <random>

using namespace std;
using namespace chrono;

void golf_mk2() {
  int cnt{1};
  std::random_device rd;
  std::mt19937 gen{rd()};
  std::uniform_real_distribution<> dis{1, 10};
  double lap_time;

  while (true) {
    lap_time = dis(gen);
    cout << "Runde" << to_string(cnt) << ": golf mk2" << "\n" << flush;
    this_thread::sleep_for(milliseconds(static_cast<int>(lap_time*1000)));
    cnt++;
  }
}

class Car {
  private:
    string carname;
  public:
    void operator()(){
      int cnt{1};

      std::random_device rd;
      std::mt19937 gen{rd()};
      std::uniform_real_distribution<> dis{1, 10};
      double lap_time;

      while (true) {
        lap_time = dis(gen);
        cout << "Runde" << to_string(cnt) << ": " << this->carname << "\n" << flush;
        this_thread::sleep_for(milliseconds(static_cast<int>(lap_time*1000)));
        cnt++;
      }
    }
    Car(string name){
      this->carname = name;
    }
};

int main(int argc, char const *argv[]) {
  thread t1{golf_mk2};

  Car mercl("C63S Coupe");
  thread t2{ref(mercl)};

  t1.join();
  t2.join();

  return 0;
}
