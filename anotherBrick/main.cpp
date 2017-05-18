/* Nathan Welch
 * Another Brick in the Wall - Kattis Problem
 */

#include <iostream>
using namespace std;

int main() {
  int height, width, numBrick;
  int brickLength;
  int layer = 0;

  cin >> height >> width >> numBrick;

  while(cin >> brickLength) {
    layer += brickLength;
    //if you get to the end of the layer:
    if(layer == width) {
      layer = 0;  //start a new one
      height--;   //and keep track of height
    }
    else if(layer > width) { //if it doesn't fit exactly then quit
      cout << "NO";
      return 0;
    }

    if(height == 0) { //if you build the whole wall with no problems, win
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}