#include <iostream>
#include <stack>
using namespace std;

#define max_v 100
int graph[max_v][max_v] = {0}; // Initialize the graph with zeros

void dfs(int vCount, int start) {
    bool visited[vCount] = {false}; // Array to track visited vertices
    
    stack<int> s;                  // Stack for DFS
    visited[start] = true;         // Mark the starting vertex as visited
    s.push(start);                 // Push the starting vertex onto the stack
    cout << "DFS starting from vertex " << start << ": ";

    while (!s.empty()) {
        int current = s.top(); // Get the top vertex
        s.pop();               // Pop the top vertex
        cout << current << " "; // Process the current vertex

        // Traverse all adjacent vertices in reverse order
        for (int i = vCount - 1; i >= 0; i--) {
            if (graph[current][i] == 1 && !visited[i]) { // Check for an edge and if not visited
                visited[i] = true; // Mark as visited
                s.push(i);         // Push the adjacent vertex onto the stack
            }
        }
    }
    cout << endl;
}

int main() {
    int vCount = 10; // Number of vertices

    // Adding undirected edges
    graph[0][1] = 1; graph[1][0] = 1; // Edge between 0 and 1
    graph[0][2] = 1; graph[2][0] = 1; // Edge between 0 and 2
    graph[1][3] = 1; graph[3][1] = 1; // Edge between 1 and 3
    graph[1][4] = 1; graph[4][1] = 1; // Edge between 1 and 4
    graph[2][5] = 1; graph[5][2] = 1; // Edge between 2 and 5
    graph[3][6] = 1; graph[6][3] = 1; // Edge between 3 and 6
    graph[4][7] = 1; graph[7][4] = 1; // Edge between 4 and 7
    graph[5][8] = 1; graph[8][5] = 1; // Edge between 5 and 8
    graph[6][9] = 1; graph[9][6] = 1; // Edge between 6 and 9
    graph[7][9] = 1; graph[9][7] = 1; // Edge between 7 and 9

    dfs(vCount, 5); // Start DFS from vertex 5

    return 0;
}
