#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "box.h"

void assertTrue(bool b, string description) {
  if (!b) {
    cout << "FAILED: " + description << endl;
  } else {
    cout << "PASSED: " + description << endl;
  }
}

void runBoxTestEmpty();
void runBoxTestSize1();
void runBoxTestSize3();
void runBoxTestSetBoxChar();
void runBoxTestIncDec();

void runBoxSmallBox();
void runBoxBiggieBox();
void runBoxMillenniumBox();
void runBoxScreamingBox();
void runBoxSleepyBox();
void runBoxLastTest();

int main() {
  runBoxTestEmpty();
  runBoxTestSize1();
  runBoxTestSize3();
  runBoxTestSetBoxChar();
  runBoxTestIncDec();

  // FІXΜЕ: implement 6 more tests
  // That is, call assertTrue EXACTLY 6 more times
  runBoxSmallBox();
  runBoxBiggieBox();
  runBoxMillenniumBox();
  runBoxScreamingBox();
  runBoxSleepyBox();
  runBoxLastTest();

  return 0;
}

void runBoxLastTest(){
  Box b(4, '4');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 4 && b.getBoxChar() == '4' && ss.str() == "4444\n4444\n4444\n4444\n", "4X4");
}

void runBoxSleepyBox(){
  Box b(6, 'z');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 6 && b.getBoxChar() == 'z' && ss.str() == "zzzzzz\nzzzzzz\nzzzzzz\nzzzzzz\nzzzzzz\nzzzzzz\n", "zzzzzz");
}

void runBoxScreamingBox(){
  Box b(8, 'A');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 8 && b.getBoxChar() == 'A' && ss.str() == "AAAAAAAA\nAAAAAAAA\nAAAAAAAA\nAAAAAAAA\nAAAAAAAA\nAAAAAAAA\nAAAAAAAA\nAAAAAAAA\n", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
}

void runBoxMillenniumBox(){
  Box b(10, '#');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 10 && b.getBoxChar() == '#' && ss.str() == "##########\n##########\n##########\n##########\n##########\n##########\n##########\n##########\n##########\n##########\n", "No, that's too big");
}

void runBoxBiggieBox(){
  Box b(5, '#');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 5 && b.getBoxChar() == '#' && ss.str() == "#####\n#####\n#####\n#####\n#####\n", "This is a box.");
}

void runBoxSmallBox(){
  Box b(2, '#');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 2 && b.getBoxChar() == '#' && ss.str() == "##\n##\n", "You call that a box?");
}

void runBoxTestEmpty() {
  Box b;
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 0 && b.getBoxChar() == '*' && ss.str() == "",
             "empty box");
}

void runBoxTestSize1() {
  Box b(1, '$');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 1 && b.getBoxChar() == '$' && ss.str() == "$\n",
             "size 1 box");
}

void runBoxTestSize3() {
  Box b(3, '%');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 3 && b.getBoxChar() == '%' &&
                 ss.str() == "%%%\n%%%\n%%%\n",
             "size 3 box");
}

void runBoxTestSetBoxChar() {
  Box b(1, '$');
  b.setBoxChar('%');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 1 && b.getBoxChar() == '%' && ss.str() == "%\n",
             "setBoxChar");
}

void runBoxTestIncDec() {
  Box b(1);
  bool isCorrect = true;
  // try to make the width 3
  b += 2;
  isCorrect = isCorrect && b.getWidth() == 3;
  stringstream ss;
  ss << b;
  isCorrect = isCorrect && ss.str() == "***\n***\n***\n";
  // clear out ss
  ss.str("");
  ss.clear();
  // try to make the width 1 again
  b -= 2;
  isCorrect = isCorrect && b.getWidth() == 1;
  ss << b;
  isCorrect = isCorrect && ss.str() == "*\n";
  assertTrue(isCorrect, "inc/dec");
}

