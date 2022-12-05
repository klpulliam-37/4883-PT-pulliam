// Credit to:
// https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/
// for the connected graph algorithm.
// 
// and 
// 
// https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
// for Prim's Spanning tree algorithm

// C++ program to print connected components in
// an undirected graph
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

// Global variables
int counter = 0;
int V = 0;

// Graph class represents a undirected graph
// using adjacency list representation
class Graph {
  int V; // No. of vertices

  // Pointer to an array containing adjacency lists
  list<int> *adj;

  // A function used by DFS
  void DFSUtil(int v, bool visited[]);

public:
  Graph(int V); // Constructor
  ~Graph();
  void addEdge(int v, int w);
  bool IsConnected();
};

// Method to print connected components in an
// undirected graph
bool Graph::IsConnected() {
  // Mark all the vertices as not visited
  bool *visited = new bool[V];
  for (int v = 0; v < V; v++)
    visited[v] = false;

  counter = 0;
  DFSUtil(0, visited);
  
  if (counter != V) {
    return false;
  }

  return true;

  delete[] visited;
}

void Graph::DFSUtil(int v, bool visited[]) {
  // Mark the current node as visited and print it
  visited[v] = true;
  counter++;

  // Recur for all the vertices
  // adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
      DFSUtil(*i, visited);
}

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

Graph::~Graph() { delete[] adj; }

// method to add an undirected edge
void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
  adj[w].push_back(v);
}

//-------------------------------------------------//

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[]) {
  // Initialize min value
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;

  return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], vector<vector<int>> graph) {
  int minWeight = 0;
  for (int i = 1; i < V; i++) {
    minWeight += graph[i][parent[i]];
  }
  cout << minWeight << endl;
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(vector<vector<int>> graph) {
  // Array to store constructed MST
  int parent[V];

  // Key values used to pick minimum weight edge in cut
  int key[V];

  // To represent set of vertices included in MST
  bool mstSet[V];

  // Initialize all keys as INFINITE
  for (int i = 0; i < V; i++)
    key[i] = INT_MAX, mstSet[i] = false;

  // Always include first 1st vertex in MST.
  // Make key 0 so that this vertex is picked as first
  // vertex.
  key[0] = 0;
  parent[0] = -1; // First node is always root of MST

  // The MST will have V vertices
  for (int count = 0; count < V - 1; count++) {
    // Pick the minimum key vertex from the
    // set of vertices not yet included in MST
    int u = minKey(key, mstSet);

    // Add the picked vertex to the MST Set
    mstSet[u] = true;

    // Update key value and parent index of
    // the adjacent vertices of the picked vertex.
    // Consider only those vertices which are not
    // yet included in MST
    for (int v = 0; v < V; v++)

      // graph[u][v] is non zero only for adjacent
      // vertices of m mstSet[v] is false for vertices
      // not yet included in MST Update the key only
      // if graph[u][v] is smaller than key[v]
      if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
        parent[v] = u, key[v] = graph[u][v];
  }

  // print the constructed MST
  printMST(parent, graph);
}

void MainDriver() {
  // Numerical representations of stations
  map<string, int> stations;

  // Create a graph given in the above diagram
  int cases = 0, connections = 0;
  string station = "", garbage = "";

  cin >> V >> connections;
  // while loop checking for ending condition
  while (V != 0 && connections != 0) {
    // if (V == 1 || connections == 0) {
    //   for (int i = 0; i < V; i++) {
    //     cin >> station;
    //   }
      
    //   for (int i = 0; i < connections; i++) {
    //     string s1, s1; 
    //     int cost;
    //     cin >> s1 >> s2 >> cost;
    //   }
    //   cin >> garbage;
    //   cout << 0 << endl;
    //   continue;
    // }

    // Reset variables
    stations.clear();

    pair<int, int> adjList[V];

    // Initialize map
    for (int i = 0; i < V; i++) {
      cin >> station;
      stations.insert({station, i});
    }

    // Initialize matrix
    vector<vector<int>> adjMatrix(V, vector<int>(V));
    for (int r = 0; r < V; r++) {
      for (int c = 0; c < V; c++) {
        adjMatrix[r][c] = 0;
      }
    }

    Graph g(V);
    for (int i = 0; i < connections; i++) {
      string s1 = "", s2 = "";
      int cost;

      cin >> s1 >> s2 >> cost;

      adjList[stations[s1]].first = stations[s2];
      adjList[stations[s1]].second = cost;

      // Assing connections for matrix
      adjMatrix[stations[s1]][adjList[stations[s1]].first] =
          adjList[stations[s1]].second;
      adjMatrix[adjList[stations[s1]].first][stations[s1]] =
          adjList[stations[s1]].second;

      g.addEdge(stations[s1], stations[s2]);
    }

    cin >> garbage;

    if (g.IsConnected()) {
      // Print the solution
      primMST(adjMatrix);
    } else {
      cout << "Impossible" << endl;
    }

    cin >> V >> connections;
  }
}

// Driver's code
int main() {

  MainDriver();
  return 0;
}