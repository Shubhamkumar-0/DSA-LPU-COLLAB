#include <iostream>
using namespace std;

#define max_v 100
int graph[max_v][max_v] = {0}; // Initialize the graph with zeros

void dfs(int node, bool visited[]) {
    visited[node] = true; // Mark the current node as visited
    cout << node << " ";   // Print the current node

    // Traverse all adjacent nodes
    for (int i = 0; i < max_v; i++) {
        if (graph[node][i] == 1 && !visited[i]) { // Check for an edge and if not visited
            dfs(i, visited); // Recur for the adjacent node
        }
    }
}

int main() {
    int vCount = 10; // Number of vertices

    // Adding directed edges
    graph[0][1] = 1; // Edge from 0 to 1
    graph[0][4] = 1; // Edge from 0 to 4
    graph[1][2] = 1; // Edge from 1 to 2
    graph[1][3] = 1; // Edge from 1 to 3
    graph[2][5] = 1; // Edge from 2 to 5
    graph[3][6] = 1; // Edge from 3 to 6
    graph[4][7] = 1; // Edge from 4 to 7
    graph[5][8] = 1; // Edge from 5 to 8
    graph[6][9] = 1; // Edge from 6 to 9
    graph[7][9] = 1; // Edge from 7 to 9

    bool visited[max_v] = {false}; // Array to track visited vertices
    cout << "DFS starting from vertex 5: ";
    dfs(5, visited); // Start DFS from vertex 5
    cout << endl;

    return 0;
}
