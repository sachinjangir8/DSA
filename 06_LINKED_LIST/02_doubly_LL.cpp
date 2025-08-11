#include <iostream>
using namespace std;

// Node structure this is only for a single element....
class Node
{
public:
    int data;   // Stores the node's value
    Node *next; // Pointer to the next node in the linked list
    Node *prev; // Pointer to the previous node in the linked list

    // Constructor to initialize a node
    Node(int val)
    {
        data = val;            // Set the data field
        next = prev = nullptr; // Set next pointer to null (no next node yet)
    }
};
class doubly_LL
{
    Node *head; // Pointer to the first node in the linked list
    Node *tail; // Pointer to the last node in the linked list
public:
    doubly_LL(){
        head = tail = nullptr;
        // Initialize an empty linked list
    }
    void pushfront(int val){
        Node *newNode = new Node(val); // Create a new node with given value
        if(head == nullptr){ // If the list is empty
            head = tail = newNode; // newNode becomes both head and tail
        }
        else{
            newNode->next = head; // Make the new node's next pointer point to the current head
            head->prev = newNode; // Make the current head's previous pointer point to the new node
            head = newNode; // Move the head pointer to the new node
        }
    }
    void pushback(int val){
        Node* newNode =new Node(val); // Create a new node with given value
        if(tail == nullptr){ // If the list is empty
            head = tail = newNode; // newNode becomes both head and tail
        }
        else{
            newNode->prev = tail; // Make the new node's previous pointer point to the current tail
            tail->next = newNode; // Make the current tail's next pointer point to the new node
            tail = newNode; // Move the tail pointer to the new node
        }
    }
    void popfront(){
        if(head == nullptr) return; // If the list is empty
        Node* temp = head; // Store the current head
        head = head->next; // Move the head pointer to the next node
        if(head!= nullptr) head->prev = nullptr; // Update the previous pointer of the new head
        delete temp; // Delete the previous head
    }
    void popback(){
        if(tail == nullptr) return; // If the list is empty
        Node* temp = tail; // Store the current tail
        tail = tail->prev; // Move the tail pointer to the previous node
        if(tail!= nullptr) tail->next = nullptr; // Update the next pointer of the new tail
        delete temp; // Delete the previous tail
    }
    void display(){
        Node *temp = head; // Start from the head
        cout << " NULL<=> ";
        while(temp!=nullptr){
            cout << temp->data << " <=> "; // Print the node's data
            temp = temp->next; // Move to the next node
        }
        cout <<"NULL"<< endl;
    }

};
int main()
{
    // Creating a doubly linked list
    cout << "push front : ";

    doubly_LL dll;
    dll.pushfront(1); // Add 10 to the front of the list
    dll.pushfront(2); // Add 10 to the front of the list
    dll.pushfront(3); // Add 10 to the front of the list
    dll.display(); // Display the list 
    cout << "push back : ";

    // pushing the list from back...
    dll.pushback(20); // Add 20 to the back of the list
    dll.pushback(30); // Add 30 to the back of the list
    dll.pushback(40); // Add 40 to the back of the list
    dll.display(); // Display the list 

    // Deleting the first node
    cout << "after Delete the first node : ";
    dll.popfront();
    dll.display(); // Display the list

    // Deleting the last node
    cout << "after Delete the last node : ";
    dll.popback();
    dll.display(); // Display the list
}
