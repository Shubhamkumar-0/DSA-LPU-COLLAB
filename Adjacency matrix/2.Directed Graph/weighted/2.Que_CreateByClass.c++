#include <iostream>
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
                adjacencyMatrix[i][j] = (i == j) ? 0 : 0; // 0 for self-loops and no edges
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
    return 0;
}
