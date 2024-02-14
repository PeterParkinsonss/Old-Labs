#include <cstdlib>  // for exit
#include <fstream>  // for ifstream
#include <string>   // for getline, stoi
#include <iomanip>  // for setw and setfill
#include <iostream> // lol you know what this is for
#include "vec.h"
using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " order_file.csv" << endl;
    exit(1);
  }

  ifstream ifs(argv[1]);
  Vec prices;

  string currentLine;
  while (getline(ifs, currentLine)) {
    // FІXΜЕ: add the price from the current line into the prices Vec
    int comma = currentLine.find(",");
    string numStart = currentLine.substr(comma + 1);
    int price = stoi(numStart);
    prices.push_back(price);
    // Hint: use find, substr, and stoi to extract the prices
  }
    cout << setprecision(2) << fixed;
    double total = 0;

    prices.sort();
    for(int i = 0; i < prices.size(); i++){
      double item = prices.at(i);
      item = item / 100;
      total = item + total;
      cout << "$" << item << endl;
    }

    cout << "------" << endl;
    cout << "$" << total << endl;
  // FІXΜЕ: print the *sorted* prices, a line with exactly 6 '-'s, and
  // finally the total. Prices should be displayed with dollar signs
  // and cents.

  // Hint: when printing out prices, use setw(2) and setfill('0') to
  // guarantee you output the cents correctly

  return 0;
}
