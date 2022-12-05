/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P11764
*  Title:            11764 - Jumping Mario
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva Problem 11764 - Jumping Mario
*        from Online Judge
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
        main.cpp
*****************************************************************************/
#include <iostream>

using namespace std;

int main() {
  // read test cases
  int cases, walls, currWall, prevWall, high, low;
  cin >> cases;
  // read number of walls
  for (int i = 0; i < cases; i++) {
    // Reset variables
    high = 0;
    low = 0;
    cin >> walls;
    cin >> prevWall;

    // Loop through number of walls
    for (int j = 0; j < walls - 1; j++) {
      cin >> currWall;
      if (currWall > prevWall) {
        high++;
      }
      else if (currWall < prevWall) {
        low++;
      }
      prevWall = currWall;
    }
    cout << "Case " << i+1 << ": " << high << ' ' << low << endl;
  }
}