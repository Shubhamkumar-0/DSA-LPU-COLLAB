#include <iostream>
using namespace std;
#define MAX_VERTICES 100
class WeightedGraph {
private:
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int vertexCount;
public:
    // Constructor to initialize the graph
    WeightedGraph(int vertices) {
        vertexCount = vertices;
        // Initialize the adjacency matrix
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                adjacencyMatrix[i][j] = (i == j) ? 0 : 0; // 0 for self-loops and no edges
            }
        }
    }
    // Function to add an edge with a weight
    void addEdge(int source, int destination, int weight) {
        adjacencyMatrix[source][destination] = weight;
        adjacencyMatrix[destination][source] = weight; // For undirected graph
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
    WeightedGraph graph(vertexCount); // Create a graph with 4 vertices
    // Adding weighted edges
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 10);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 1);
    // Display the adjacency matrix
    graph.displayMatrix();
    return 0;
}
