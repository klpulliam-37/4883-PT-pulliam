/**
 * Kolten Pulliam
 * 4883 - Programming Techniques
 * August 30th, 2022
 */
#include <iostream>

#define endl "\n"

using namespace std;

int main() {
  long int B = 0, A = 0;
  long int result;

  while (cin >> A >> B) {
    cout << abs(A - B) << endl;
  }
  return 0;
}