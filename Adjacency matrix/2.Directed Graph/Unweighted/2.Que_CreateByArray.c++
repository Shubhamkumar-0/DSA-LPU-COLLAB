#include <iostream>
using namespace std;
#define MAX_VERTICES 100
int vertexCount = 4; // Example number of vertices
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; // Declare the adjacency matrix

// Function to add a directed edge
void addEdge(int source, int destination) {
    adjacencyMatrix[source][destination] = 1; // Mark the edge as present
}

int main() {
    // Initialize the adjacency matrix
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            adjacencyMatrix[i][j] = 0; // 0 indicates no edge
        }
        // adjacencyMatrix[i][i] = 1; // 1 indicates a self-loop
    }

    // Adding directed edges
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);

    // Display the adjacency matrix
    cout << "Adjacency Matrix (Unweighted):" << endl;
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
