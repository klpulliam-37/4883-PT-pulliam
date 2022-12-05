/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P12550
*  Title:            Language Detection
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva 12550 - Language Detection
*        from Online Judge
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
        main.cpp
*****************************************************************************/
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  string word = "";
  int caseNum = 0;

  map<string,string> languages;
  languages.insert(pair<string,string>("HELLO","ENGLISH"));
  languages.insert(pair<string,string>("HOLA","SPANISH"));
  languages.insert(pair<string,string>("HALLO","GERMAN"));
  languages.insert(pair<string,string>("BONJOUR","FRENCH"));
  languages.insert(pair<string,string>("CIAO","ITALIAN"));
  languages.insert(pair<string,string>("ZDRAVSTVUJTE","RUSSIAN"));
  
  cin >> word;
  while (word != "#") {
    caseNum++;

    auto itr = languages.find(word);

    if (itr == languages.end()) {
      cout << "Case " << caseNum << ": " << "UNKNOWN" << endl;
    }else{
      cout << "Case " << caseNum << ": " << itr->second << endl;
    }
    
    cin >> word;
  }
}