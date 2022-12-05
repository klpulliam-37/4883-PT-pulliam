/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P10370
*  Title:            Above Average
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva 10370 - Above Average
*        from Online Judge
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
        main.cpp
*****************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int cases = 0;
  cin >> cases;

  for (int i = 0; i < cases; i++) {
    int students = 0;
    cin >> students;
    int grades[students];
    int sum = 0;
    int average = 0;
    float percentage = 0.0;
    
    

    for (int s = 0; s < students; s++) {
      cin >> grades[s];
      sum += grades[s];
    }

    average = sum / students;

    int above = 0;
    for (int s = 0; s < students; s++) {
      if (grades[s] > average) {
        above++;
      }
    }

    percentage = ((float)above / (float)students) * 100;
    cout << fixed << setprecision(3) << percentage << '%' << endl;
  }
}