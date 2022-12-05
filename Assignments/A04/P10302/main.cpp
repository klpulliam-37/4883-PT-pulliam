/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P10302
*  Title:            Summation of Polynomials
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva P10302 - Summation of Polynomials
*        from Online Judge
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
        main.cpp
*****************************************************************************/
#include <iostream>
#include <math.h>

long long cube(long long num)
{
    return num * num * num;
}

int main() {
  int range = 0;

  while (std::cin >> range) {
    long long sum = 0;
    for (long long i = 1; i <= range; i++) {
      sum += cube(i);
    }
    std::cout << sum << std::endl;
  }
}