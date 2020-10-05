#include <iostream>
#include <unistd.h>
#include <thread>

using namespace std;

void golf_mk2() {
  int cnt{1};

  while (true) {
    cout << "Runde" << cnt << ": golf mk2" << endl;
    this_thread::sleep_for(1s);
    cnt++;
  }
}

class Car {
  private:
    string carname;
  public:
    void operator()(){
      int cnt{1};

      while (true) {
        cout << "Runde" << cnt << ":" << this->carname << endl;
        this_thread::sleep_for(1s);
        cnt++;
      }
    }
    Car(string name){
      this->carname = name;
    }
};

int main(int argc, char const *argv[]) {
  /*thread t1{golf_mk2};
  t1.join();

  car Car("Lada");
  thread t2{Car};*/

  Car mercl("C63S Coupe");
  thread t1{ref(mercl)};
  t1.join();

  return 0;
}
