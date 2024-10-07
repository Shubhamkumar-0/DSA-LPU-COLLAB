// Sharon is developing a character editor for a simple text-based game. 
// The editor allows users to maintain a singly linked list of characters 
// representing a sequence of moves in the game. 
// Initially, users input a series of characters to create their move
// sequence. Later, they can insert a new character at a specific position 
 //within the sequence to alter their gameplay strategy, ensuring the list 
//  is updated and displayed correctly. Assist Sharon in the task.
// Company tags: TCS
// Input format :
// The first line contains an integer n, the number of initial characters.
// The second line consists of n characters, representing the initial move sequence.
// The last line contains a character and an integer pos, representing the new move 
// to be added and its position(1-based) in the sequence.
// Output format :
// The first line displays "Current Linked List:" followed by the initial sequence of moves in the next line.
// The third line displays "Updated Linked List:" followed by the updated 
// sequence of moves after inserting the new move at the specified position in the next line.
// Refer to the sample output for formatting specifications.
// Code constraints :
// The given test cases fall under the following constraints:
// 1 ≤ n ≤ 10

// Sample test cases :
// Input 1 :
// 6
// A B C D E F
// G 7
// Output 1 :
// Current Linked List:
// A B C D E F 
// Updated Linked List:
// A B C D E F G 
// Input 2 :
// 3
// A O B
// M 1
// Output 2 :
// Current Linked List:
// A O B 
// Updated Linked List:
// M A O B 

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void append(Node*& head, char data) {
    Node* newNode = new Node{data, nullptr};
    if (head==nullptr) {     //if(!head)  ye v sirf likh sakte hai
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(Node*& head, char data, int pos) {
    Node* newNode = new Node{data, nullptr};
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }
    if (temp) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n;
    cin >> n;

    // Read initial characters
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        append(head, ch);
    }

    // Display current linked list
    cout << "Current Linked List:" << endl;
    display(head);

    // Read new character and position
    char newChar;
    int pos;
    cin >> newChar >> pos;

    // Insert new character at specified position
    insertAtPosition(head, newChar, pos);

    // Display updated linked list
    cout << "Updated Linked List:" << endl;
    display(head);

    // Cleanup
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp; // Free memory
    }

    return 0;
}
