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
void insert(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head; 
    head = newNode;       
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
    insert(head, 1); 
    insert(head, 3); 
    insert(head, 6); 
    insert(head, 7); 
    insert(head, 4); 
    insert(head, 2);
    cout << "Linked List: ";
    display(head);
    return 0;
}
