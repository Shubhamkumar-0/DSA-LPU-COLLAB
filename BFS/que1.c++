#include <iostream>
using namespace std;

// Structure to represent an edge in the adjacency list
struct Edge {
    int dest;       // Destination vertex of the edge
    Edge* next;     // Pointer to the next edge
};

// Function to add an edge to the adjacency list
void addEdge(Edge* list[], int src, int dest) {
    Edge* newEdge = new Edge; // Create a new edge
    newEdge->dest = dest;
    newEdge->next = list[src]; // Point to the previous head
    list[src] = newEdge;       // Update the head to the new edge
}

// Simple Queue Implementation
class Queue {
private:
    int* items;   // Array to hold queue elements
    int front;    // Index of the front element
    int rear;     // Index of the rear element
    int size;     // Maximum size of the queue

public:
    Queue(int s) : front(0), rear(0), size(s) {
        items = new int[size];
    }
    bool isEmpty() {
        return front == rear; // Check if the queue is empty
    }
    void enqueue(int item) {
        if (rear < size) {
            items[rear++] = item; // Add item to the queue
        }
    }
    int dequeue() {
        if (!isEmpty()) {
            return items[front++]; // Remove and return the front item
        }
        return -1; // Return -1 if the queue is empty (error case)
    }
};

// Function to perform BFS on the graph
void bfs(Edge* list[], int vCount, int start) {
    bool* visited = new bool[vCount]; // Array to track visited vertices
    for (int i = 0; i < vCount; i++) {
        visited[i] = false; // Initialize all vertices as unvisited
    }

    Queue q(vCount); // Create a simple queue
    visited[start] = true; // Mark the start vertex as visited
    q.enqueue(start); // Enqueue the start vertex

    cout << "BFS starting from vertex " << start << ": ";

    while (!q.isEmpty()) {
        int curr = q.dequeue(); // Dequeue the front vertex
        cout << curr << " "; // Process the current vertex

        // Traverse the adjacency list of the current vertex
        Edge* edge = list[curr];
        while (edge != nullptr) {
            int adj = edge->dest;
            if (!visited[adj]) { // If the vertex is not visited
                visited[adj] = true; // Mark it as visited
                q.enqueue(adj); // Enqueue the vertex
            }
            edge = edge->next; // Move to the next edge
        }
    }

    delete[] visited; // Free the visited array
}

// Function to free the allocated memory for the graph
void freeGraph(Edge* list[], int vCount) {
    for (int i = 0; i < vCount; i++) {
        Edge* edge = list[i];
        while (edge != nullptr) {
            Edge* temp = edge;
            edge = edge->next;
            delete temp; // Free memory
        }
    }
}

int main() {
    int vCount = 4; // Example number of vertices
    Edge* list[vCount] = {nullptr}; // Initialize adjacency list

    // Adding directed edges
    addEdge(list, 0, 1);
    addEdge(list, 0, 2);
    addEdge(list, 1, 2);
    addEdge(list, 2, 3);

    // Perform BFS starting from vertex 0
    bfs(list, vCount, 0);

    // Free the allocated memory
    freeGraph(list, vCount);

    return 0;
}
