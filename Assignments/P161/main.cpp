/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P161
*  Title:            161 - Traffic Lights
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva Problem 161 - Traffic Lights
*        from Online Judge
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
        main.cpp
*****************************************************************************/
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void runCheck(vector<int> lights, int maxTime);
bool checkSync(vector<int> lights, int itr);

int main() {
  // Set array of lights and get max light time
  vector<int> lights;
  int minTime = 90;
  int light = 0;

  // Main loop for checking multiple scenarios
  int counter = 0;
  while (counter < 2) {
    cin >> light;
    if (light != 0) {
      minTime = (minTime > light) ? light : minTime;
      lights.push_back(light);
      counter = 0;
    } else if (light == 0) {
      counter++;
      if (counter < 2)
        runCheck(lights, minTime);
      minTime = 90;
      lights.clear();
    }
  }

  return 0;
}

/**
 * runCheck
 * 
 * @description: Check all stop lights for current scenario, 
 *               if so, then print the time, otherwise it fails.
 */
void runCheck(vector<int> lights, int minTime) {
  int seconds, minutes, hours;
  bool isSynced = false;

  for (int i = minTime * 2; i <= 18000; i++) {
    isSynced = checkSync(lights, i);
    if (isSynced) {
      seconds = i;
      minutes =  (seconds / 60) % 60;
      hours = seconds / 3600;

      // Prints time
      cout << setfill('0') << setw(2) << int(hours) << ':' << setfill('0')
           << setw(2) << int(minutes) << ':' << setfill('0') << setw(2)
           << int(seconds % 60) << '\n';
      return;
    }
  }

  cout << "Signals fail to synchronise in 5 hours\n";
}

/**
 * checkSync
 * 
 * @description: Checks each individual stoplight for the current
 *               scenario to see if they are all syncronized on green.
 */
bool checkSync(vector<int> lights, int itr) {
  bool isGreen = false;
  for (int i = 0; i < lights.size(); i++) {
    // Run check for isGreen
    isGreen = (itr % (lights[i] * 2)) < (lights[i] - 5);

    // if isGreen is false at any point, early return false
    if (!isGreen) {
      return false;
    }
  }
  return true;
}