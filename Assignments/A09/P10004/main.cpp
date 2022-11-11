/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P10004
*  Title:            10004 - Bicoloring
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva Problem 10004 - Bicoloring
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
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isBipartiteUtil(vector<vector<int>> G, int src, int colorArr[]);
bool isBipartite(vector<vector<int>> G);

int V;

int main() {
  int E, r, c;
  cin >> V; // Gets algorithm in loop
  while (V != 0) {
    cin >> E;
    vector<vector<int>> G(V, vector<int>(V)); // Sets the size of the matrix
    for (int i = 0; i < E; i++) {             // Creates connections for matrix
      cin >> r;
      cin >> c;
      G[r][c] = 1;
      G[c][r] = 1;
    }

    isBipartite(G) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";

    cin >> V;
  }

  return 0;
}

// This function returns true if
// graph G[V][V] is Bipartite, else false
bool isBipartiteUtil(vector<vector<int>> G, int src, int colorArr[]) {
  colorArr[src] = 1;

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
    if (G[u][u] == 1)
      return false;

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
      else if (G[u][v] && colorArr[v] == colorArr[u])
        return false;
    }
  }

  // If we reach here, then all adjacent vertices can
  // be colored with alternate color
  return true;
}

// Returns true if G[][] is Bipartite, else false
bool isBipartite(vector<vector<int>> G) {
  // Create a color array to store colors assigned to all
  // vertices. Vertex/ number is used as index in this
  // array. The value '-1' of colorArr[i] is used to
  // indicate that no color is assigned to vertex 'i'.
  // The value 1 is used to indicate first color is
  // assigned and value 0 indicates second color is
  // assigned.
  int colorArr[V];
  for (int i = 0; i < V; ++i)
    colorArr[i] = -1;

  // This code is to handle disconnected graph
  for (int i = 0; i < V; i++)
    if (colorArr[i] == -1)
      if (isBipartiteUtil(G, i, colorArr) == false)
        return false;

  return true;
}