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
    int n;
    insert(head, 1);
    insert(head, 3);
    insert(head, 5);
    insert(head, 6);
    insert(head, 8);
    insert(head, 9);
    cout << "Linked List: ";
    display(head);
    // insert(head, 1);
    // cout << "Linked List: ";
    // display(head);
    
    // insert(head, 3);
    // cout << "Linked List: ";
    // display(head);
    
    // insert(head, 5);
    // cout << "Linked List: ";
    // display(head);
    
    // insert(head, 6);
    // cout << "Linked List: ";
    // display(head);
    
    // insert(head, 8);
    // cout << "Linked List: ";
    // display(head);
    
    // insert(head, 9);
    // cout << "Linked List: ";
    // display(head);
    // return 0;
}
    return 0;
}
