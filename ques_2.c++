#include <iostream>
using namespace std;

/* Linked list node */
struct Node {
    char data;
    struct Node* next;
};

// Function to reverse a linked list
Node* reverseLinkedList(Node* head) {
    //Type your code here
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev to current node
        current = next;       // Move to the next node
    }
    return prev; // New head of the reversed list
    
}

// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    //type your code here
        if (head == nullptr || head->next == nullptr) return true;

    // Find the middle of the linked list
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    Node* secondHalf = reverseLinkedList(slow);
    Node* copyOfSecondHalf = secondHalf; // For cleanup later

    // Compare the first half and the reversed second half
    Node* firstHalf = head;
    bool palindrome = true;

    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Restore the original list (optional)
    reverseLinkedList(copyOfSecondHalf);

    return palindrome;
    
}

// Function to create a new node in the linked list
Node* newNode(char key) {
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

// Function to create a linked list based on user input
Node* createLinkedList() {
    Node* head = NULL;
    Node* tail = NULL;
    char val;
    while (true) {
        cin >> val;
        if (val == '$') {
            break;
        }

        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    Node* head = createLinkedList();

    bool palindrome = isPalindrome(head);
    if (palindrome) {
        cout << "The linked list is a palindrome" << endl;
    } else {
        cout << "The linked list is not a palindrome" << endl;
    }

    return 0;
}