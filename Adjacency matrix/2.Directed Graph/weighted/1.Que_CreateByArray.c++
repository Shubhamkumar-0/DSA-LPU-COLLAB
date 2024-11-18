#include <iostream>
using namespace std;
#define MAX_VERTICES 100
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; // Declare the adjacency matrix
int vertexCount; // Number of vertices

// Function to initialize the graph
void initializeGraph(int vertices) {
    vertexCount = vertices;
    // Initialize the adjacency matrix
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            adjacencyMatrix[i][j] = 0; // 0 indicates no edges
        }
    }
}
// Function to add a directed edge with a weight
void addEdge(int source, int destination, int weight) {
    adjacencyMatrix[source][destination] = weight; // Set the weight for the edge
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

int main() {
    int vertexCount = 4; // Example number of vertices
    initializeGraph(vertexCount); // Initialize the graph with 4 vertices

    // Adding weighted directed edges
    addEdge(0, 1, 5);
    addEdge(0, 2, 10);
    addEdge(1, 2, 3);
    addEdge(2, 3, 1);

    // Display the adjacency matrix
    displayMatrix();

    return 0;
}
