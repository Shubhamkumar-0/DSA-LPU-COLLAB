#include <iostream>
using namespace std;
#define MAX 10 // Maximum number of vertices
// Function to initialize the graph
void inputGraph(int graph[MAX][MAX], int& V) {
    cout << "Enter the number of vertices (max " << MAX << "): ";
    cin >> V;
    // Initialize the graph with 0s
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0; // No edges initially
        }
    }
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges (format: from to):" << endl;
    for (int i = 0; i < edges; i++) {
        int from, to;
        cin >> from >> to;
        graph[from][to] = 1; // Add edge from 'from' to 'to'
    }
}

void warshall(int graph[MAX][MAX], int V) {
    int reach[MAX][MAX];

    // Initialize the reachability matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            reach[i][j] = graph[i][j];
        }
    }

    // Update reachability matrix
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    // Print the reachability matrix
    cout << "Transitive Closure (Reachability Matrix):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int graph[MAX][MAX];
    int V; // Number of vertices

    inputGraph(graph, V); // Initialize the graph with user input
    warshall(graph, V);    // Compute the transitive closure
    return 0;
}
