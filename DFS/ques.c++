// // Single File Programming Question
// // Problem Statement



// Sharon is developing a program that analyzes the reachability of nodes in a graph. 
// Given an adjacency matrix representing the graph and its size, her goal is to determine 
// whether there exists a path from one vertex to another for all pairs of vertices.



// // Write a program to help Sharon perform this reachability analysis using Warshall's Algorithm.

// Input format :
// The first line of input consists of an integer N, 
// representing the number of vertices in the graph.
// The following N lines consist of N space-separated integers, 
// forming the adjacency matrix graph, where graph[i][j] is either 0 or 1.

// Output format :
// The output prints an NxN matrix representing 
// the reachability matrix for all pairs of vertices.

// Each element in the matrix should be 1 if there is a 
// path from the corresponding row vertex to the column vertex, and 0 otherwise.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// Each element of the adjacency matrix is either 0 or 1.

// Sample test cases :
// Input 1 :
// 4
// 0 1 0 0
// 0 0 1 0
// 0 0 0 1
// 0 0 0 0
// Output 1 :
// 0 1 1 1 
// 0 0 1 1 
// 0 0 0 1 
// 0 0 0 0 
// Input 2 :
// 3
// 0 1 0
// 0 0 1
// 0 0 0
// Output 2 :
// 0 1 1 
// 0 0 1 
// 0 0 0 



#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> graph(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> graph[i][j];
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (graph[i][k] && graph[k][j]) {
          graph[i][j] = 1;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}






// Single File Programming Question
// Problem Statement



// Harish is given a network of nodes and connections represented by a matrix of size NxN, where N is the number of nodes in the network. Each cell connections[i][j] in the matrix contains a value of either 1 or 0.



// If connections[i][j] is 1, it means there is a direct connection between Node i and Node j.
// If connections[i][j] is 0, it means there is no direct connection between Node i and Node j.


// Your task is to help Harish write a program using Warshall's Algorithm that determines whether there exists a chain of connections that can be followed to travel from a source node to a target node in the network.

// Input format :
// The first line of input consists of an integer N, representing the number of nodes in the network.

// The following N lines consist of N space-separated integers (1 or 0), representing the connections in the matrix.

// The last line consists of two space-separated integers i and j, representing the source node and the target node.

// Output format :
// If there exists a chain of connections from the source node to the target node, print "Yes".

// Otherwise, print "No".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// Each element of the matrix is either 0 or 1.

// Sample test cases :
// Input 1 :
// 3
// 0 1 0
// 0 0 1
// 1 0 0
// 1 2
// Output 1 :
// Yes
// Input 2 :
// 4
// 0 1 0 0
// 0 0 0 1
// 0 0 0 1
// 0 0 0 0
// 2 1
// Output 2 :
// No
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.







#include <stdio.h>
#define MAX_NODES 100
// C++ program to check if there is a chain of connections between two nodes in a graph

#include <stdio.h>
#define MAX_NODES 100

// Function to check if there is a chain of connections between two nodes in a graph
int hasChainOfConnections(int n, int connections[MAX_NODES][MAX_NODES], int source, int target) {
    // Create a queue to store nodes to be visited
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    // Mark the source node as visited and enqueue it
    int visited[MAX_NODES] = {0};
    visited[source] = 1;
    queue[rear++] = source;

    // While there are nodes in the queue
    while (front != rear) {
        // Dequeue the front node
        int current = queue[front++];

        // If the current node is the target node, return true
        if (current == target) {
            return 1;
        }

        // For each neighbor of the current node
        for (int i = 0; i < n; ++i) {
            // If there is a connection between the current node and the neighbor and the neighbor has not been visited
            if (connections[current][i] && !visited[i]) {
                // Mark the neighbor as visited and enqueue it
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    // If there is no chain of connections between the source and target nodes, return false
    return 0;
}


int main() {
    int n; // Number of nodes
    scanf("%d", &n);

    int connections[MAX_NODES][MAX_NODES] = {0};

    // Taking input for direct connections
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &connections[i][j]);
        }
    }

    int source, target;
    scanf("%d %d", &source, &target);

    if (hasChainOfConnections(n, connections, source, target)) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}
