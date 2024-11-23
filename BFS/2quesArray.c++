#include <iostream>
#include <queue>
using namespace std;
#define max_v 100
int graph[max_v][max_v];

void bfs(int vCount, int start) {
    bool visited[vCount] = {false}; // Array to track visited vertices
    
    queue<int> q;           // Queue for BFS
    visited[start] = true; // Mark the starting vertex as visited
    q.push(start);        // Enqueue the starting vertex
    cout << "BFS starting from vertex " << start << ": ";

    while (!q.empty()) {
        int current = q.front();  // Get the front vertex
        q.pop();                 // Dequeue the front vertex
        cout << current << " "; // Process the current vertex

        // Traverse all adjacent vertices
        for (int i = 0; i < vCount; i++) {
            if (graph[current][i] == 1 && !visited[i]) { // Check for an edge and if not visited
                visited[i] = true; // Mark as visited
                q.push(i); // Enqueue the adjacent vertex
            }
        }
    }
    cout << endl;
}

int main() {
    int vCount=4;
    // Adding directed edges
    graph[0][1] = 1; // Edge from 0 to 1
    graph[0][2] = 1; // Edge from 0 to 2
    graph[1][2] = 1; // Edge from 1 to 2
    graph[2][3] = 1; // Edge from 2 to 3

    bfs(vCount, 0); // Start BFS from vertex 0

    return 0;
}
