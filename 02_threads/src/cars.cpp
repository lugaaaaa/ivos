#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <signal.h>
#include <random>
#include <iomanip>
#include <sstream>

using namespace std;
using namespace chrono;

void golf_mk2(double& totaltime) {
  int cnt{1};
  double lap_time;

  std::random_device rd;
  std::mt19937 gen{rd()};
  std::uniform_real_distribution<> dis{1, 10};
  ostringstream buf;

  while (cnt <= 10) {
    lap_time = dis(gen);
    buf << "Runde" << to_string(cnt) << ": Golf MK2" << ": " << setprecision(3) << lap_time << "\n" << flush;
    cout << buf.str();
    buf.str("");
    this_thread::sleep_for(milliseconds(static_cast<int>(lap_time*1000)));
    totaltime += lap_time;
    cnt++;
  }
}

class Car {
  private:
    string carname;
    double totaltime;
  public:
    void operator()(){
      int cnt{1};
      double lap_time;

      std::random_device rd;
      std::mt19937 gen{rd()};
      std::uniform_real_distribution<> dis{1, 10};
      ostringstream buf;

      while (cnt <= 10) {
        lap_time = dis(gen);
        totaltime += lap_time;
        buf << "Runde" << to_string(cnt) << ": " << carname << ": " << setprecision(3) << lap_time << "\n" << flush;
        cout << buf.str();
        buf.str("");
        this_thread::sleep_for(milliseconds(static_cast<int>(lap_time*1000)));
        cnt++;
      }
    }
    Car(string name){
      this->carname = name;
    }

    double get_total_time(){
      return this->totaltime;
    }

    string get_car_name(){
      return this->carname;
    }
};

int main(int argc, char const *argv[]) {
  double totaltime;
  thread t1{golf_mk2, ref(totaltime)};

  Car mercl("C63S Coupe");
  thread t2{ref(mercl)};

  t1.join();
  t2.join();

  if (totaltime < mercl.get_total_time()) {
    cout << "Sieger ist: Golf MK2 mit " << totaltime << "s" << endl;
    cout << "Verlierer ist: " << mercl.get_car_name() << " mit " << mercl.get_total_time() << " s" << endl;
  } else {
    cout << "Sieger ist: " << mercl.get_car_name() << " mit " << mercl.get_total_time() << " s" << endl;
    cout << "Verlierer ist: Golf MK2 mit " << totaltime << "s" << endl;
  }

  return 0;
}
