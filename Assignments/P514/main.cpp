/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P514
*  Title:            514 - Rails
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva Problem 514 - Rails
*        from Online Judge
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
        main.cpp
*****************************************************************************/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void checkConfig(queue<int> &que, queue<int> &output, stack<int> &stack);
void setQueue(queue<int> &que, int config);
void resetQueue(queue<int> &que);
void clearStack(stack<int> &stack);
void printQueue(queue<int> que);
void printStack(stack<int> stack);

int main() {
  queue<int> que;
  queue<int> output;
  stack<int> stack;
  int config = 0;
  int val = 0;

  cin >> config;
  while (config != 0) {
    setQueue(que, config);
    cin >> val;

    if (val != 0) {
      output.push(val);
      checkConfig(que, output, stack);
    }else{
      cout << endl;
      cin >> config;
    }
  }

  return 0;
}

/**
 * checkConfig
 * 
 * @description: Runs the main algorithm on stack and queue's to calculate
 *               if it is possible to rearrange the train carts in the 
 *               specified order.
 */
void checkConfig(queue<int> &que, queue<int> &output, stack<int> &stack) {
  int val = 0;
  
  for (int i = 0; i < que.size() - 1; i++) {
    cin >> val;
    output.push(val);
  }
  
  while (!output.empty()){
    if (!que.empty()) {
      if (que.front() != output.front()) {
        if (!stack.empty()) {
          if (stack.top() != output.front()) {
            stack.push(que.front());
            que.pop(); 
          }else{
            stack.pop();
            output.pop();
          }
        }else{
          stack.push(que.front());
          que.pop();
        }
      }else{
        que.pop();
        output.pop();
      }
    }else{
      if (stack.top() != output.front()) {
        cout << "No\n";
        break;
      }else{
        stack.pop();
        output.pop();
      }
    }
  }
  if (output.empty()) {
    cout << "Yes\n";
  }
  resetQueue(que);
  resetQueue(output);
  clearStack(stack);
}

/**
 * setQueue
 * 
 * @description: Sets the queue containing the ascending order of 
 *               train carts.
 */
void setQueue(queue<int> &que, int config) {
  resetQueue(que);
  for (int i = 1; i <= config; i++) {
    que.push(i);
  }
}

/**
 * resetQueue
 * 
 * @description: Essentially empties the the queue.
 */
void resetQueue(queue<int> &que) {
  queue<int> empty;
  que.swap(empty);
}

/**
 * clearStack
 * 
 * @description: Empties the stack
 */
void clearStack(stack<int> &stack) {
  while (!stack.empty()) {
    stack.pop();
  }
}


// For debugging purposes
void printQueue(queue<int> que) {
  while (!que.empty()) {
    cout << que.front() << ' ';
    que.pop();
  }
  cout << endl;
}

// For Debugging purposes
void printStack(stack<int> stack) {
  while (!stack.empty()) {
    cout << stack.top() << ' '; 
    stack.pop();
  }
  cout << endl;
}