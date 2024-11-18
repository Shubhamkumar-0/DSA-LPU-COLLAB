#include <iostream>
using namespace std;
#define MAX_VERTICES 100
// Function to initialize the adjacency matrix
void initializeMatrix(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int vertexCount) {
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}
// Function to add an edge
void addEdge(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int source, int destination) {
    adjacencyMatrix[source][destination] = 1;
    adjacencyMatrix[destination][source] = 1; // Uncomment for undirected graph
}
// Function to display the adjacency matrix
void displayMatrix(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int vertexCount) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int vertexCount = 5; // Example number of vertices
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    // Initialize the adjacency matrix
    initializeMatrix(adjacencyMatrix, vertexCount);
    // Adding edges
    addEdge(adjacencyMatrix, 0, 1);
    addEdge(adjacencyMatrix, 0, 4);
    addEdge(adjacencyMatrix, 1, 2);
    addEdge(adjacencyMatrix, 1, 3);
    addEdge(adjacencyMatrix, 1, 4);
    addEdge(adjacencyMatrix, 2, 3);
    addEdge(adjacencyMatrix, 3, 4);
    // Display the adjacency matrix
    displayMatrix(adjacencyMatrix, vertexCount);
    return 0;
}
