#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int data):data(data),next(nullptr){}
};
void push(Node** head_ref, int new_data){
    //Type your code here
    Node* new_node=new Node(new_data);
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void append(Node** head_ref, int new_data){
    //Type your code here
    Node* new_node = new Node(new_data);
    Node* last = *head_ref;
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;   
}
void printList(Node* node){
    //Type your code here
     while (node != nullptr) {
        cout << node->data;
        if (node->next != nullptr) cout << " ";
        node = node->next;        
    }
}
int main(){
    Node* head = NULL;
    int num_of_nodes, new_val;
    cin >> num_of_nodes;
    for (int i = 0; i < num_of_nodes; i++) {
        int val;
        cin >> val;
        push(&head, val);
    }
    cout << "Created Linked list:";
    printList(head);
    cin >> new_val;
    append(&head, new_val);
    cout << "\nFinal list:";
    printList(head);
    return 0;
}
