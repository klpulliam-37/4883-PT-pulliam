/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P10443
*  Title:            10443 - Rock, Scissors, Paper
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva Problem 10443 - Rock, Scissors, Paper
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
#include <vector>

using namespace std;

vector<vector<char>> IterateDays(vector<vector<char>> T);
char Winner(char atk, char def);
bool NeighborExists(int r, int c);

int cases = 0, rows = 0, columns = 0, days = 0;

map<char, char> winMap = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};

int main() {
  char lifeform = '\0';

  cin >> cases;
  for (int i = 0; i < cases; i++) {
    cin >> rows >> columns >> days;
    vector<vector<char>> T(rows, vector<char>(columns));
    if (rows == 0 && columns == 0) {
      cout << endl;
      continue;
    } else if (rows == 1 && columns == 1) {
      cin >> lifeform;
      cout << lifeform << endl << endl;
      continue;
    } else {
      for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
          cin >> lifeform;
          T[r][c] = lifeform;
        }
      }
    }

    T = IterateDays(T);
    // Prints matrix after the war
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < columns; c++) {
        cout << T[r][c];
      }
      cout << endl;
    }
    if (i != (cases - 1)) {
      cout << endl;
    }
  }
}

vector<vector<char>> IterateDays(vector<vector<char>> T) {
  // int counter = 0;
  vector<vector<char>> newT(rows, vector<char>(columns));
  // Iterates each day of battle
  for (int d = 0; d < days; d++) {
    // Checks each node in matrix
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < columns; c++) {
        // Check bottom neighbor
        if (NeighborExists(r + 1, c)) {
          newT[r][c] = Winner(T[r + 1][c], T[r][c]);
          // Prevents re-evaluation over winner
          if (newT[r][c] != T[r][c]) {
            continue;
          }
        }
        // Check top neighbor
        if (NeighborExists(r - 1, c)) {
          newT[r][c] = Winner(T[r - 1][c], T[r][c]);
          // Prevents re-evaluation over winner
          if (newT[r][c] != T[r][c]) {
            continue;
          }
        }
        // Check right neighbor
        if (NeighborExists(r, c + 1)) {
          newT[r][c] = Winner(T[r][c + 1], T[r][c]);
          // Prevents re-evaluation over winner
          if (newT[r][c] != T[r][c]) {
            continue;
          }
        }
        // Check left neighbor
        if (NeighborExists(r, c - 1)) {
          newT[r][c] = Winner(T[r][c - 1], T[r][c]);
          // Prevents re-evaluation over winner
          if (newT[r][c] != T[r][c]) {
            continue;
          }
        }
        // counter++;
      }
    }
    T = newT;
  }

  return newT;
}

char Winner(char atk, char def) {
  if (atk == winMap[def]) {
    return atk;
  }
  return def;
}

bool NeighborExists(int r, int c) {
  if (r >= 0 && r < rows && c >= 0 && c < columns) {
    return true;
  }
  return false;
}