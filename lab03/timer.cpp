#include "timer.h"

#include <iostream>
using namespace std;

Timer::Timer(std::string description): description(description) {}

void Timer::start() {
  // FІXΜЕ: set begin appropriately
  clock_t begin = clock();
}

void Timer::stop() {
  // FІXΜЕ: set end appropriately
  clock_t end = clock();
}

double Timer::getSecondsElapsed() const {
  // FІXΜЕ: calculate the number of seconds between start() and stop()
  double secondsPassed = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
  return secondsPassed; // might need to return 0
}

void Timer::printData() const {
  cout << description << ": " << getSecondsElapsed() << " seconds" << endl;
}
