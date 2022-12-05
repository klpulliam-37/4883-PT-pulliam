/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P10783
*  Title:            Odd Sum
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva 10783 - Odd Sum
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
  int cases;
  int a, b;

  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    int oddSum = 0;
    cin >> a >> b;
    for (int s = a; s <= b; s++) {
      if (s%2 != 0) {
        oddSum += s;
      }
    }
    cout << "Case " << i << ": " << oddSum << endl;
  }
}