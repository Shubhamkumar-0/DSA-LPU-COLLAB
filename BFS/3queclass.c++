#include <iostream>
#include <queue>
using namespace std;
#define MAX_VERTICES 100
class DirectedGraph {
private:
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int vertexCount;
public:
    // Constructor to initialize the graph
    DirectedGraph(int vertices) {
        vertexCount = vertices;
        // Initialize the adjacency matrix
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                adjacencyMatrix[i][j] = 0; // 0 for no edges
            }
        }
    }
    // Function to add a directed edge with a weight
    void addEdge(int source, int destination, int weight) {
        adjacencyMatrix[source][destination] = weight; // Only set one direction
    }
    // Function to display the adjacency matrix
    void displayMatrix() {
        cout << "Adjacency Matrix (Weights):" << endl;
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    // Function to perform BFS on the graph
    void bfs(int start) {
        bool visited[MAX_VERTICES] = {false}; // Array to track visited vertices
        queue<int> q; // Queue for BFS

        visited[start] = true; // Mark the start vertex as visited
        q.push(start); // Enqueue the start vertex

        cout << "BFS starting from vertex " << start << ": ";
        while (!q.empty()) {
            int curr = q.front(); // Get the front vertex
            q.pop(); // Dequeue the front vertex
            cout << curr << " "; // Process the current vertex

            // Traverse the adjacency matrix
            for (int i = 0; i < vertexCount; i++) {
                if (adjacencyMatrix[curr][i] != 0 && !visited[i]) { // Check for an edge
                    visited[i] = true; // Mark it as visited
                    q.push(i); // Enqueue the vertex
                }
            }
        }
        cout << endl; // New line after BFS output
    }
};

int main() {
    int vertexCount = 4; // Example number of vertices
    DirectedGraph graph(vertexCount); // Create a directed graph with 4 vertices
    // Adding weighted directed edges
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 10);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 1);
    // Display the adjacency matrix
    graph.displayMatrix();

    // Perform BFS starting from vertex 0
    graph.bfs(0);

    return 0;
}
