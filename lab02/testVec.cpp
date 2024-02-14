#include <iostream>
#include "vec.h"
#include "testing.h"
using namespace std;

void testVecCopyConstructor();
void testVecCopyAssignment();

void testVecKrissKross();
void testVecClone();
void testVecTeamWork();
void testVecLeftBehind();

int main() {
  testVecCopyConstructor();
  testVecCopyAssignment();

  // FІXΜЕ: Add 4 more tests
  testVecKrissKross();
  testVecClone();
  testVecTeamWork();
  testVecLeftBehind();

  return 0;
}

void testVecLeftBehind(){
  Vec v1;
  Vec v2;
  v1.push_back(1);
  v2 = v1;
  v1.push_back(0);
  v2.push_back(2);
  v2.push_back(3);
  v2.push_back(4);
  assertTrue(v1.at(0) == 1 &&
             v1.at(1) == 0 &&
             v2.at(0) == 1 &&
             v2.at(1) == 2 &&
             v2.at(2) == 3 &&
             v2.at(3) == 4,
             "Wrong way buddy");
}

void testVecTeamWork(){
  Vec v1;
  Vec v2;
  v1.push_back(1);
  v2 = v1;
  v2.push_back(2);
  v1 = v2;
  v1.push_back(3);
  v2 = v1;
  v2.push_back(4);
  v1 = v2;
  assertTrue(v1.at(0) == 1 &&
             v1.at(1) == 2 &&
             v1.at(2) == 3 &&
             v1.at(3) == 4 &&
             v2.at(0) == 1 &&
             v2.at(1) == 2 &&
             v2.at(2) == 3 &&
             v2.at(3) == 4,
             "We did it!!!");
}

void testVecClone(){
  Vec v1;
  v1.push_back(1);
  v1.push_back(42);
  v1.push_back(17);
  Vec v2;
  v2 = v1;
  assertTrue(v1.at(0) == v2.at(0) &&
             v1.at(1) == v2.at(1) &&
             v1.at(2) == v2.at(2),
             "Wait, if I'm here and you're there then whose... *GULP*");
}


void testVecKrissKross(){
  Vec v1;
  v1.push_back(21);
  v1.push_back(22);
  v1.push_back(31);
  Vec v2;
  v2.push_back(61);
  v2.push_back(52);
  v2.push_back(81);
  Vec temp;
  temp = v1;
  v1 = v2;
  v2 = temp;

  assertTrue(v1.at(0) == 61 &&
             v1.at(1) == 52 &&
             v1.at(2) == 81 &&
             v2.at(0) == 21 &&
             v2.at(1) == 22 &&
             v2.at(2) == 31,
             "KrissKross");
}

void testVecCopyConstructor() {
  Vec v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  Vec v2(v1);
  v1.push_back(4);
  v1.push_back(5);
  v2.push_back(-4);
  v2.push_back(-5);

  assertTrue(v1.at(0) == v2.at(0) &&
             v1.at(1) == v2.at(1) &&
             v1.at(2) == v2.at(2) &&
             v1.at(3) == 4 &&
             v2.at(3) == -4 &&
             v1.at(4) == 5 &&
             v2.at(4) == -5,
             "copy constructor");
}

void testVecCopyAssignment() {
  Vec v1, v2;
  v1.push_back(1);
  v1.push_back(2);
  v2.push_back(3);
  v2.push_back(4);

  v2 = v1;

  v2.push_back(5);
  v1.push_back(3);

  assertTrue(v2.at(0) == 1 &&
             v2.at(1) == 2 &&
             v2.at(2) == 5 &&
             v1.at(0) == 1 &&
             v1.at(1) == 2 &&
             v1.at(2) == 3 &&
             v2.size() == 3 &&
             v1.size() == 3,
             "copy assignment operator");
}
