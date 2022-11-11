/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P929
*  Title:            929 - Number Maze
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva Problem 929 - Number Maze
*        from Online Judge
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
        main.cpp
*****************************************************************************/

// Credit to: 
// https://www.geeksforgeeks.org/shortest-path-in-a-directed-graph-by-dijkstras-algorithm/
// for shortest path algorithm

// C++ implementation to find the
// shortest path in a directed
// graph from source vertex to
// the destination vertex
 
#include <bits/stdc++.h>
#define infi 1000000000
using namespace std;

// Number of vertices in the graph
int V = 0, rows = 0, columns = 0;
 
// Class of the node
class Node {
public:
    int vertexNumber;
 
    // Adjacency list that shows the
    // vertexNumber of child vertex
    // and the weight of the edge
    vector<pair<int, int> > children;
    Node(int vertexNumber)
    {
        this->vertexNumber = vertexNumber;
    }
 
    // Function to add the child for
    // the given node
    void add_child(int vNumber, int length)
    {
        pair<int, int> p;
        p.first = vNumber;
        p.second = length;
        children.push_back(p);
    }
};
 
// Function to find the distance of
// the node from the given source
// vertex to the destination vertex
vector<int> dijkstraDist(
    vector<Node*> g,
    int s, vector<int>& path)
{
    // Stores distance of each
    // vertex from source vertex
    vector<int> dist(g.size());
 
    // Boolean array that shows
    // whether the vertex 'i'
    // is visited or not
    bool visited[g.size()];
    for (int i = 0; i < g.size(); i++) {
        visited[i] = false;
        path[i] = -1;
        dist[i] = infi;
    }
    dist[s] = 0;
    path[s] = -1;
    int current = s;
 
    // Set of vertices that has
    // a parent (one or more)
    // marked as visited
    unordered_set<int> sett;
    while (true) {
 
        // Mark current as visited
        visited[current] = true;
        for (int i = 0;
             i < g[current]->children.size();
             i++) {
            int v = g[current]->children[i].first;
            if (visited[v])
                continue;
 
            // Inserting into the
            // visited vertex
            sett.insert(v);
            int alt
                = dist[current]
                  + g[current]->children[i].second;
 
            // Condition to check the distance
            // is correct and update it
            // if it is minimum from the previous
            // computed distance
            if (alt < dist[v]) {
                dist[v] = alt;
                path[v] = current;
            }
        }
        sett.erase(current);
        if (sett.empty())
            break;
 
        // The new current
        int minDist = infi;
        int index = 0;
 
        // Loop to update the distance
        // of the vertices of the graph
        for (int a: sett) {
            if (dist[a] < minDist) {
                minDist = dist[a];
                index = a;
            }
        }
        current = index;
    }
    return dist;
}
 
// Function to print the path
// from the source vertex to
// the destination vertex
void printPath(vector<int> path,
               int i, int s)
{
    if (i != s) {
 
        // Condition to check if
        // there is no path between
        // the vertices
        if (path[i] == -1) {
            cout << "Path not found!!";
            return;
        }
        printPath(path, path[i], s);
        cout << path[i] << " ";
    }
}

bool NeighborExists(int r, int c) {
  if (r >= 0 && r < rows && c >= 0 && c < columns) {
    return true;
  }
  return false;
}

void ToAdjList(vector<vector<int>> T, vector<Node*> graph) {
  int currNode = 0, neighborNode = 0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < columns; c++) {
      // Check bottom neighbor
      if (NeighborExists(r + 1, c)) {
        neighborNode = c + ((r + 1) * columns);           // Finds the bottom neighbor node number
        graph[currNode]->add_child(neighborNode, T[r + 1][c]);
      }
      // Check top neighbor
      if (NeighborExists(r - 1, c)) {
        neighborNode = c + ((r - 1) * columns);           // Finds the top neighbor node number
        graph[currNode]->add_child(neighborNode, T[r - 1][c]);
      }
      // Check right neighbor
      if (NeighborExists(r, c + 1)) {
        neighborNode = (c + 1) + (r * columns);           // Finds the right neighbor node number
        graph[currNode]->add_child(neighborNode, T[r][c + 1]);
      }
      // Check left neighbor
      if (NeighborExists(r, c - 1)) {
        neighborNode = (c - 1) + (r * columns);           // Finds the left neighbor node number
        graph[currNode]->add_child(neighborNode, T[r][c - 1]);
      }
      currNode++;
    }
  }
}
 
// Driver Code
int main()
{

 int cases = 0, cost = 0;  
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    cin >> rows >> columns;

    if (rows == 1 && columns == 1) {
      cin >> cost;
      cout << cost << endl;
      continue;
    }
    
    V = rows * columns;
    
    vector<Node*> v;
    // Loop to create the nodes
    for (int i = 0; i < V; i++) {
        Node* a = new Node(i);
        v.push_back(a);
    }
    
    vector<vector<int>> T(rows, vector<int>(columns));
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < columns; c++) {
        cin >> cost;
        T[r][c] = cost;
      }
    }
    ToAdjList(T, v);
    vector<int> path(v.size());
    vector<int> dist
        = dijkstraDist(v, 0, path);
 
    cout << dist[V-1] + T[0][0] << endl;
  }
  return 0;
}