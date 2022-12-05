/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P11777
*  Title:            Automate the Grades
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva 11777 - Automate the Grades
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
  int cases = 0;

  cin >> cases;

  for (int i = 1; i <= cases; i++) {
    int test1 = 0, test2 = 0, finalTest = 0, attendance = 0;
    int classTests[3] = {0, 0, 0};
    int index1;
    
    int best1 = -1, best2 = -1;
    cin >> test1 >> test2 >> finalTest >> attendance;
    for (int t = 0; t < 3; t++) {
      cin >> classTests[t];
    }
    
    for (int t = 0; t < 3; t++) {
      if (classTests[t] >= best1) {
        best1 = classTests[t];
        index1 = t;
      }
    }

    for (int t = 0; t < 3; t++) {
      if (t != index1) {
        if (classTests[t] >= best2) {
          best2 = classTests[t];
        }
      }
    }

    int grade = test1 + test2 + finalTest + attendance + (best1 + best2)/2;
    if (grade >= 90) {
      cout << "Case " << i << ": " << 'A' << endl;
    }
    else if (grade >= 80 && grade < 90) {
      cout << "Case " << i << ": " << 'B' << endl;
    }
    else if (grade >= 70 && grade < 80) {
      cout << "Case " << i << ": " << 'C' << endl;
    }
    else if (grade >= 60 && grade < 70) {
      cout << "Case " << i << ": " << 'D' << endl;
    }
    else if (grade < 60) {
      cout << "Case " << i << ": " << 'F' << endl;
    }
  }
}