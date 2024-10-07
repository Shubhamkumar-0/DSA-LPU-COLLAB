#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    // Constructor using member initializer list
    Node(int value) : data(value), next(nullptr) {}
};
// Function to insert a new node at the end of the linked list
void insert(Node*& head, int data) {
    Node* newNode = new Node(data); // Use the constructor
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
// Function to sort the linked list using Bubble Sort
void bubbleSort(Node* head) {
    if (!head) return;
    bool swapped = true; // Initialize swapped to true
    while (swapped) { // Continue until no swaps are made
        swapped = false; // Reset swapped flag for this iteration
        Node* current = head; // Start from the head

        while (current->next) { // Traverse the list
            if (current->data > current->next->data) {
                // Swap data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true; // Set swapped to true if a swap occurs
            }
            current = current->next; // Move to the next node
        }
    }
}
int main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        insert(head, value); // Insert at the end
    }
    int newData;
    cin >> newData;
    cout << "Original data points: ";
    display(head);
    cout << endl;
    insert(head, newData); 
    bubbleSort(head); // Sort the linked list using Bubble Sort

    cout << "Updated data points: ";
    display(head);
    cout << endl;

    // Clean up memory
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}