/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P11080
*  Title:            11080 - Place the Guards
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva Problem 11080 - Place the Guards
*        from Online Judge
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
        main.cpp
*****************************************************************************/

// Credit to https://www.geeksforgeeks.org/bipartite-graph/
// for the bipartite algorithm.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;

void ProcessInput();
int isBipartiteUtil(vector<vector<int>> G, int src, int colorArr[]);
int isBipartite(vector<vector<int>> G);
void PrintMatrix(vector<vector<int>> G);

int main() {
  ProcessInput();
}

void ProcessInput() {
  int cases, r, c, result;

  cin >> cases;
  for (int i = 0; i < cases; i++) {
    cin >> V >> E;
    
    vector<vector<int>> G(V, vector<int>(V));
    for (int j = 0; j < E; j++) {
      cin >> r;
      cin >> c;
      G[r][c] = 1;
      G[c][r] = 1;
    }

    result = isBipartite(G);
    cout << result << endl;
  }
}

// This function returns true if
// graph G[V][V] is Bipartite, else false
int isBipartiteUtil(vector<vector<int>> G, int src, int colorArr[]) {
  colorArr[src] = 1;
  int counter = 0;
  int firstColor = 0;
  int secondColor = 0;

  // Create a queue (FIFO) of vertex numbers a
  // nd enqueue source vertex for BFS traversal
  queue<int> q;
  q.push(src);

  // Run while there are vertices in queue (Similar to
  // BFS)
  while (!q.empty()) {    
    // Dequeue a vertex from queue ( Refer
    // http://goo.gl/35oz8 )
    int u = q.front();
    q.pop();

    // Return false if there is a self-loop
    if (G[u][u] == 1) {
      // cout << "self-loop\n";
      return -1;
    }

    // Find all non-colored adjacent vertices
    for (int v = 0; v < V; ++v) {
      // An edge from u to v exists and
      // destination v is not colored
      if (G[u][v] && colorArr[v] == -1) {
        // Assign alternate color to this
        // adjacent v of u
        colorArr[v] = 1 - colorArr[u];
        q.push(v);
      }

      // An edge from u to v exists and destination
      // v is colored with same color as u
      else if (G[u][v] && colorArr[v] == colorArr[u]){
        // cout << "not bipartite\n";
        return -1;
      }
    }
    
    // Keep track of our guard number counts
    if (colorArr[u] == 1) {
      firstColor++;
    }
    counter++;
  }

  // If we reach here, then all adjacent vertices can
  // be colored with alternate color

  // Check for minimum number of guards based on color array
  secondColor = counter - firstColor;
  if (counter == 1) {
    return counter;
  }
  else if (firstColor > secondColor) {
    return secondColor;
  }
  return firstColor;
}

// Returns true if G[][] is Bipartite, else false
int isBipartite(vector<vector<int>> G) {
  int result = 0;
  int count = 0;
  
  // Create a color array to store colors assigned to all
  // vertices. Vertex/ number is used as index in this
  // array. The value '-1' of colorArr[i] is used to
  // indicate that no color is assigned to vertex 'i'.
  // The value 1 is used to indicate first color is
  // assigned and value 0 indicates second color is
  // assigned.
  int colorArr[V];
  for (int i = 0; i < V; ++i) {
    colorArr[i] = -1;
  }
  
  // This code is to handle disconnected graph
  for (int i = 0; i < V; i++) {
    if (colorArr[i] == -1) {
      result = isBipartiteUtil(G, i, colorArr);
      // accumulate sums of guards
      // for disconnected graphs
      if (result == -1) {
        return -1;
      }else{
        count += result;
      }
    }
  }
  return count;
}

void PrintMatrix(vector<vector<int>> G) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      cout << G[i][j] << ' ';
    }
    cout << endl;
  }
}