#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
void insert(Node* &head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;
    int arr[] = {3, 4, 5, 6, 7, 8};
    // int n = sizeof(arr) / sizeof(arr[0]);
    int n=6;
    for (int i = 0; i < n; i++) {
        insert(head, arr[i]);
    }
    cout << "Initial Linked List: ";
    display(head);
    insert(head, 9);
    cout << "Linked List after inserting 9: ";
    display(head);
    return 0;
}
