#include <iostream>
#include "Stack.h"
#include "testing.h"
using namespace std;

void testStack1();
void testStack2();
void testStack3();

int main() {
  testStack1();
  testStack2();
  testStack3();
  // FІXΜЕ: add 2 more test cases

  return 0;
}

void testStack3(){
  Stack<int> s;
  bool is_correct = true;

  s.push(42);
  if(s.size() != 1) is_correct = false;
  if(s.peek() != 42) is_correct = false;
  if(s.pop() != 42) is_correct = false;
  if(!s.empty()) is_correct = false;

  assertTrue(is_correct, "Extra Tests");
}

void testStack2(){
  Stack<int> s;
  bool is_correct = true;

  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  if(s.size() != 4) is_correct = false;
  if(s.peek() != 4) is_correct = false;
  s.pop();
  s.pop();
  if(s.pop() != 2) is_correct = false;
  if(s.peek() != 1) is_correct = false;

  assertTrue(is_correct, "testing the functions");
}

void testStack1() {
  Stack<int> s;
  bool is_correct = true;

  if (s.size() != 0) is_correct = false;
  s.push(5);
  s.push(3);
  if (s.size() != 2) is_correct = false;
  if (s.peek() != 3) is_correct = false;
  if (s.size() != 2) is_correct = false;
  if (s.pop() != 3) is_correct = false;
  if (s.peek() != 5) is_correct = false;
  if (s.pop() != 5) is_correct = false;
  if (!s.empty()) is_correct = false;

  assertTrue(is_correct, "general Stack<int> operations");
}
