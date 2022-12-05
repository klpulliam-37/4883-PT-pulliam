/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P11805
*  Title:            Bafana Bafana
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva 11805 - Bafana Bafana
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

  for (int t = 1; t <= cases; t++) {
    int n = 0, k = 0, p = 0;
    cin >> n >> k >> p;
    for (int i = 0; i < p; i++) {
      k++;
    }
    if (k%n == 0) {
      cout << "Case " << t << ": " << n << endl;
    }else{
      cout << "Case " << t << ": " << k%n << endl;
    }
  }
}