#include "testing.h"

using namespace std;

void assertTrue(bool b, string description) {
  if (!b) {
    cout << "FAILED: " << description << endl;
  } else {
    cout << "PASSED: " << description << endl;
  }
}
