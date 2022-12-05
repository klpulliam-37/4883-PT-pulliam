/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P11547
*  Title:            Automatic Answer
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva 11547 - Automatic Answer
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
  int cases = 0, value = 0;
  cin >> cases;

  for (int i = 0; i < cases; i++) {
    cin >> value;
    value = ((((((value * 567) / 9) + 7492) * 235) / 47) - 498);
    int digit = (value / 10) % 10;
    cout << abs(digit) << endl;
  }
}