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
    int current_pos = 0;
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
    int n,m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;
        insert(head, value);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int value, position;
        cin >> value >> position;
        insertAtPosition(head, value, position);
    }
    printList(head);
    return 0;
}
