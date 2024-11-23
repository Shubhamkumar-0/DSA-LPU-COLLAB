#include <iostream>
#include <queue>
using namespace std;

#define max_v 100
int graph[max_v][max_v] = {0}; // Initialize the graph with zeros

void bfs(int vCount, int start) {
    bool visited[max_v] = {false}; // Array to track visited vertices
    
    queue<int> q;           // Queue for BFS
    visited[start] = true; // Mark the starting vertex as visited
    q.push(start);         // Enqueue the starting vertex
    cout << "BFS starting from vertex " << start << ": ";

    while (!q.empty()) {
        int current = q.front();  // Get the front vertex
        q.pop();                  // Dequeue the front vertex
        cout << current << " ";   // Process the current vertex

        // Traverse all adjacent vertices
        for (int i = 0; i < vCount; i++) {
            if (graph[current][i] == 1 && !visited[i]) { // Check for an edge and if not visited
                visited[i] = true; // Mark as visited
                q.push(i);         // Enqueue the adjacent vertex
            }
        }
    }
    cout << endl;
}

int main() {
    int vCount = 10; // Number of vertices

    // Adding undirected edges
    graph[0][1] = 1; // Edge from 0 to 1
    graph[1][0] = 1; // Edge from 1 to 0 (undirected)
    
    graph[0][2] = 1; // Edge from 0 to 2
    graph[2][0] = 1; // Edge from 2 to 0 (undirected)
    
    graph[1][3] = 1; // Edge from 1 to 3
    graph[3][1] = 1; // Edge from 3 to 1 (undirected)
    
    graph[1][4] = 1; // Edge from 1 to 4
    graph[4][1] = 1; // Edge from 4 to 1 (undirected)
    
    graph[2][5] = 1; // Edge from 2 to 5
    graph[5][2] = 1; // Edge from 5 to 2 (undirected)
    
    graph[3][6] = 1; // Edge from 3 to 6
    graph[6][3] = 1; // Edge from 6 to 3 (undirected)
    
    graph[4][7] = 1; // Edge from 4 to 7
    graph[7][4] = 1; // Edge from 7 to 4 (undirected)
    
    graph[5][8] = 1; // Edge from 5 to 8
    graph[8][5] = 1; // Edge from 8 to 5 (undirected)
    
    graph[6][9] = 1; // Edge from 6 to 9
    graph[9][6] = 1; // Edge from 9 to 6 (undirected)
    
    graph[7][9] = 1; // Edge from 7 to 9
    graph[9][7] = 1; // Edge from 9 to 7 (undirected)

    bfs(vCount, 5); // Start BFS from vertex 5

    return 0;
}
