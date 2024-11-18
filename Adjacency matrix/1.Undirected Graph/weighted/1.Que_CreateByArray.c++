#include <iostream>
using namespace std;

#define MAX_VERTICES 100

// Function to initialize the adjacency matrix
void initializeMatrix(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int vertexCount) {
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            adjacencyMatrix[i][j] = (i == j) ? 0 : 0; // 0 for self-loops and no edges
        }
    }
}

// Function to add an edge with a weight
void addEdge(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int source, int destination, int weight) {
    adjacencyMatrix[source][destination] = weight;
    adjacencyMatrix[destination][source] = weight; // Uncomment for undirected graph
}

// Function to display the adjacency matrix
void displayMatrix(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int vertexCount) {
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
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    // Initialize the adjacency matrix
    initializeMatrix(adjacencyMatrix, vertexCount);
    
    // Adding weighted edges
    addEdge(adjacencyMatrix, 0, 1, 5);
    addEdge(adjacencyMatrix, 0, 2, 10);
    addEdge(adjacencyMatrix, 1, 2, 3);
    addEdge(adjacencyMatrix, 2, 3, 1);
    
    // Display the adjacency matrix
    displayMatrix(adjacencyMatrix, vertexCount);

    return 0;
}
