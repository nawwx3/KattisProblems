/*
 * Okviri - Kattis Problem
 *
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  cin >> input;

  //first line
  cout << "..";
  for(int i = 0; i < input.size(); i++) {
    if( (i + 1) % 3 == 0) //if its the third print a wendy frame
      cout << "*";
    else
      cout << "#"; //else print a peter pan frame

    if(i == input.size() - 1)
      cout << "..";  //if its the last one only print 2 dots
    else
      cout << "...";
  }
  cout << endl;

  //second line
  cout << ".";
  for(int i = 0; i < input.size(); i++) {
    if( (i + 1) % 3 == 0) //if its the third print a wendy frame
      cout << "*.*.";
    else
      cout << "#.#."; //else print a peter pan frame
  }
  cout << endl;

  //third line
  cout << "#";
  for(int i = 0; i < input.size(); i++) {
    if( (i + 1) % 3 == 0) //if its the third print a wendy frame
      cout << "*." << input[i] << ".*";
    if( (i + 1) % 3 == 1) //if its the third print a wendy frame
      cout << "." << input[i] << ".#";
    if( (i + 1) % 3 == 2) //if its the third print a wendy frame
      cout << "." << input[i] << ".";
    if(i == input.size() - 1 && (i + 1) % 3 == 2)
      cout << "#";  //if its the last one only print 2 dots

  }
  cout << endl;

  //fourth line
  cout << ".";
  for(int i = 0; i < input.size(); i++) {
    if( (i + 1) % 3 == 0) //if its the third print a wendy frame
      cout << "*.*.";
    else
      cout << "#.#."; //else print a peter pan frame
  }
  cout << endl;

  //fifth line
  cout << "..";
  for(int i = 0; i < input.size(); i++) {
    if( (i + 1) % 3 == 0) //if its the third print a wendy frame
      cout << "*";
    else
      cout << "#"; //else print a peter pan frame

    if(i == input.size() - 1)
      cout << ".." << endl;  //if its the last one only print 2 dots
    else
      cout << "...";
  }

  return 0;
}