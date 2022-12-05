/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P12577
*  Title:            Hajj-e-Akbar
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva 12577 - Hajj-e-Akbar
*        from Online Judge
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
        main.cpp
*****************************************************************************/
#include <iostream>
#include <string>

using namespace std;

int main() {
  string word = "";
  int caseNum = 0;

  cin >> word;
  while (word != "*") {
    caseNum++;
    if (word == "Hajj") {
      cout << "Case " << caseNum << ": " << "Hajj-e-Akbar" << endl;
    }
    else if (word == "Umrah") {
      cout << "Case " << caseNum << ": " << "Hajj-e-Asghar" << endl;
    }
    cin >> word;
  }
}