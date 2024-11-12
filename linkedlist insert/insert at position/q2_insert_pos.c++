#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
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
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value, position;
        cout << "Enter the value and position for node " << i + 1 << ": ";
        cin >> value >> position;
        insertAtPosition(head, value, position);
    }

    cout << "The linked list is: ";
    printList(head);
    return 0;
}
