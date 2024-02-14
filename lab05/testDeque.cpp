#include <iostream>
#include "Deque.h"
#include "testing.h"
using namespace std;

void testDeque1();
void testDeque2();
void testDeque3();

int main() {
  testDeque1();

  // FІXΜЕ: add 2 more test cases
  testDeque2();
  testDeque3();

  return 0;
}

void testDeque3(){
  Deque<int> d;
  bool is_correct = true;

  d.push_back(2);
  d.push_front(1);
  d.push_back(4);
  d.push_front(5);
  d.push_back(3);
  if(d.size() != 5) is_correct = false;
  d.pop_front();
  d.pop_front();
  d.pop_front();
  if(d.peek_back() != 3) is_correct = false;
  if(d.peek_front() != 4) is_correct = false;
  d.pop_back();
  d.pop_back();
  if(!d.empty()) is_correct = false;
  
  assertTrue(is_correct, "more testing");
}

void testDeque2(){
  Deque<int> d;
  bool is_correct = true;

  d.push_front(23);
  d.push_front(34);
  d.push_back(11);
  d.push_front(2);
  if(d.size() != 4) is_correct = false;
  d.pop_back();
  d.pop_back();
  if(d.peek_front() != 2) is_correct = false;
  if(d.peek_back() != 34) is_correct = false;
  
  assertTrue(is_correct, "Just checking the functions");
}

void testDeque1() {
  Deque<int> d;
  bool is_correct = true;

  if (d.size() != 0) is_correct = false;
  d.push_back(5);
  d.push_front(3);
  if (d.size() != 2) is_correct = false;
  if (d.peek_front() != 3) is_correct = false;
  if (d.peek_back() != 5) is_correct = false;
  d.pop_front();
  d.pop_back();
  if (!d.empty()) is_correct = false;

  assertTrue(is_correct, "general Deque<int> operations");
}
