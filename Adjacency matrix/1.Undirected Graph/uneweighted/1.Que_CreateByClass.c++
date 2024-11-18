#include <iostream>
using namespace std;
#define MAX_VERTICES 100
class Graph {
private:
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int vertexCount;
public:
    // Constructor
    Graph(int numVertices) {
        vertexCount = numVertices;
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }
    // Method to add an edge
    void addEdge(int source, int destination) {
        adjacencyMatrix[source][destination] = 1;
        adjacencyMatrix[destination][source] = 1; // Uncomment for undirected graph
    }
    // Method to display the adjacency matrix
    void displayMatrix() const {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    int numVertices = 5; // Example number of vertices
    Graph graph(numVertices);
    // Adding edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    // Display the adjacency matrix
    graph.displayMatrix();
    return 0;
}
