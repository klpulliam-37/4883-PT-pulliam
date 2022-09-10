/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P10226
*  Title:            10226 - Hardwood Species
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva Problem 10226 - Hardwood Species
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
#include <iomanip>

using namespace std;

int main() {
  map<string, int> Tree;
  string treeType;
  int cases;
  double total;

  cin >> cases;
  cin.ignore(2);

  cout << fixed;
  cout << setprecision(4);

  // Loop through input and add strings to map
  for (int i = 0; i < cases; i++) {
    // Handles if there is a new case
    while (getline(cin, treeType)) {
      if (treeType == "") {
        for (auto it = Tree.begin(); it != Tree.end(); ++it) {
          cout << it->first << ' ' 
            << double((it->second / total) * 100) << '\n';
        }
        cout << '\n';
        Tree.clear();
        total = 0;
        break;
      }
      // If the tree type isn't in the map
      else if (Tree.find(treeType) == Tree.end()) {
        Tree.insert({treeType, 0});
        Tree[treeType]++;
        total++;
      }else{ // If the tree type is in the map
        Tree[treeType]++;
        total++;
      }
    }
    // Handles last case since getline cancels while loop
    // due to the eof() flag
    if (i == cases - 1){
      if (treeType == "") {
        for (auto it = Tree.begin(); it != Tree.end(); ++it) {
          cout << it->first << ' ' 
            << double((it->second / total) * 100) << '\n';
        }
        Tree.clear();
        total = 0;
        break;
      }
    }
  }
  
  return 0;
}