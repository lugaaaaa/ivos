#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <csignal>
#include <thread>
#include <sys/wait.h>
#include <iostream>
#include <sstream>
#include <random>
#include<bits/stdc++.h>
#include<vector>
#include "CLI11.hpp"
#include "InfInt.h"
#include "calc_factors.h"
#include <future>

using namespace std;

string check(const string& s){
    std::size_t found = s.find_first_not_of("0123456789");
    if (found != string::npos){
         throw CLI::ValidationError(s +" contains not numeric character");
    }else
    {
        return "";
    }
}

int main(int argc, char const *argv[]) {
  CLI::App app("Factor numbers");
  vector<string> list;
  app.add_option("number", list, "numbers to factor")
    ->required()
    ->check(check);

  bool async{false};
  app.add_flag("-a, --async", async, "async");
  
  CLI11_PARSE(app, argc, argv);

  try{
        app.parse(argc, argv);
        vector<InfInt> newList;
        for(size_t i = 0; i<list.size(); i++){
          InfInt list_item = list[i];
          newList.push_back(list_item);
          cout << list_item << "\n" << flush;
        }

    }catch (const CLI::ParseError &e) {
        return app.exit(e);
    }

}
