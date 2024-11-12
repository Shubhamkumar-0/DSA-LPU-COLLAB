#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
void insert(Node*& head, int value) {
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
void insertAtPosition(Node*& head, int value, int position) {
    Node* newNode = new Node(value);

    if (head == nullptr || position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    int current_pos = 1;
    while (current_pos != position - 1) {
        temp = temp->next;
        current_pos++;
        if (temp == nullptr) {
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;
    insert(head, 4);
    insert(head, 6);
    insert(head, 8);
    insertAtPosition(head, 1, 1);
    insertAtPosition(head, 2, 2);
    insertAtPosition(head, 3, 1);
    printList(head);
    return 0;
}
