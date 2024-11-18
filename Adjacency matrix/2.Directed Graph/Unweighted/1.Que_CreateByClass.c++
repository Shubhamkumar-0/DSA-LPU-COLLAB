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
                adjacencyMatrix[i][j] = 0; // 0 indicates no edge
            }
            adjacencyMatrix[i][i] = 1; // 1 indicates a self-loop
        }
    }

    // Function to add a directed edge
    void addEdge(int source, int destination) {
        adjacencyMatrix[source][destination] = 1; // Mark the edge as present
    }

    // Function to display the adjacency matrix
    void displayMatrix() {
        cout << "Adjacency Matrix (Unweighted):" << endl;
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
    DirectedGraph graph(vertexCount); // Create an unweighted directed graph with 4 vertices

    // Adding directed edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    
    // Display the adjacency matrix
    graph.displayMatrix();

    return 0;
}
