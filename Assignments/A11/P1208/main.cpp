/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P1208
*  Title:            1208 - Oreon
*  Course:           4883-Programming-Techniques
*  Semester:         Fall 2022
* 
*  Description:
*        Uva Problem 1208 - Oreon
*        from Online Judge
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
        main.cpp
*****************************************************************************/
// Credit to:
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/
// for Kruskal's MST algorithm.
#include<bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;

// Creating shortcut for an integer pair
typedef pair<int, int> iPair;
  
// Structure to represent a graph
struct Graph
{
    int V, E;
    vector< pair<int, iPair> > edges;
  
    // Constructor
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
  
    // Utility function to add an edge
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }
  
    // Function to find MST using Kruskal's
    // MST algorithm
    int kruskalMST();
};
  
// To represent Disjoint Sets
struct DisjointSets
{
    int *parent, *rnk;
    int n;
  
    // Constructor.
    DisjointSets(int n)
    {
        // Allocate memory
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
  
        // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
  
            //every element is parent of itself
            parent[i] = i;
        }
    }
  
    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
        /* Make the parent of the nodes in the path
        from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
  
    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
  
        /* Make tree with smaller height
        a subtree of the other tree */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;
  
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};
  
/* Functions returns weight of the MST*/
  
int Graph::kruskalMST()
{
    int mst_wt = 0; // Initialize result
  
    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());
  
    // Create disjoint sets
    DisjointSets ds(V);
  
    // Iterate through all sorted edges
    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
        int cost = it->first;
  
        int set_u = ds.find(u);
        int set_v = ds.find(v);
  
        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST
            // so print it
            cout << char(u+64) << '-' << char(v+64) << ' ' << cost << endl;
  
            // Update MST weight
            mst_wt += it->first;
  
            // Merge two sets
            ds.merge(set_u, set_v);
        }
    }
  
    return mst_wt;
}

// Function to read in input and returns a matrix
// describing the graphs connections
vector<vector<int>> GetMatrix() {
  vector<vector<int>> graph;
  vector<int> row;
  int size;
  string line, word;
  
  cin >> size;
  cin.ignore(); // Gets around the empty string in input
  
  // Parses through the spaces and commas in the input
  // and adds each row of numbers to the graph vector, 
  // essentially making a matrix.
  for (int r = 0; r < size; r++) {
    getline(cin, line);
    stringstream s(line);
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    row.clear();
    
    while (getline(s, word, ',')) {
      row.push_back(stoi(word));
    }
    graph.push_back(row);
  }
  return graph;
}

void CalculateGuards() {
  vector<vector<int>> matrix = GetMatrix();
  int v = matrix.size();
  int e = 0;
  
  // Gets the number of edges to create graph
  int diagonal = 0;
  for (int r = 0; r < matrix.size(); r++) {
    for (int c = diagonal; c < matrix.size(); c++) {
      if (matrix[r][c] != 0) {
        e++;
      }
    }
    diagonal++;
  }

  Graph g(v, e);

  // Creates the edges for the graph
  for (int r = 0; r < matrix.size(); r++) {
    int diagonal = 0;
    for (int c = diagonal; c < matrix.size(); c++) {
      if (matrix[r][c] != 0) {
        g.addEdge((r+1), (c+1), matrix[r][c]);
      }
    }
    diagonal++;
  }

  int mst_wt = g.kruskalMST();

}

// Driver program to test above functions
int main()
{
  int cases = 0;
  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    cout << "Case " << i << ':' << endl;
    CalculateGuards();
  }
  
  return 0;
}
