#include <iostream>
using namespace std;

// Node structure this is only for a single element....
class Node
{
public:
    int data;       // Stores the node's value
    Node *next;     // Pointer to the next node in the linked list

    // Constructor to initialize a node
    Node(int val)
    { 
        data = val;      // Set the data field
        next = nullptr;  // Set next pointer to null (no next node yet)
    }
};

// Linked List class
class LinkedList
{
public:
    Node *head;  // Pointer to the first node (start of the list)
    Node *tail;  // Pointer to the last node (end of the list)

    // Constructor: Initializes an empty linked list
    LinkedList() { 
        // empty linked list....
        head = tail = nullptr;  
    }


    // Push at front
    void pushFront(int val)
    {
        // here we  create a new node that will contain the value and push it
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = nullptr;
            return;
        }
        // yha new node ka next poninter head ko pint kr rha h
        newNode->next = head;
        // newnode ki value head me store hio jayegi...
        head = newNode;
    }

    // Push at back (same as insert at end)
    void pushBack(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head =tail= newNode;
            return;
        }else{
            // here tail's next poninting to the newnode
            tail->next = newNode;
            tail = newNode;
        }
        // Node *temp = head;
        // while (temp->next != nullptr)
        // {
        //     temp = temp->next;
        // }
        // temp->next = newNode;
    }

    // Pop from front
    void popFront()
    {
        if (head == nullptr)
            return; // Empty list
// here we are storing the address of head node in tamp
        Node *temp = head;
        // now updating the head
        head = head->next;
        delete temp; //it mean temp->next is nullptr
    }

    // Pop from back
    void popBack()
    {
        Node* temp = head;
        if (head == nullptr)
            return; // Empty list
        
        while (tail->next != nullptr)
        {
            temp = temp->next;  
        }
        temp->next = nullptr;
        delete temp->next;
        tail = temp; // updating tail to the second last node...
        
        // if (head->next == nullptr)
        // { // Single node case
        //     delete head;
        //     head = nullptr;
        //     return;
        // }
    //  when we have only head not the tail...
        // Node *temp = head;
        // while (temp->next->next != nullptr)
        // {
        //     temp = temp->next;
        // }

        // delete temp->next;
        // temp->next = nullptr;
    }

    // Insert at a specific position (1-based index)
    void insert(int pos, int val)
    {
        if (pos <= 0)
        {
            cout << "Invalid position!\n";
            return;
        }

        if (pos == 0)
        {
            pushFront(val);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos-1; i++)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        
        
    }

    // Display the linked list
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    int search(int key){
        Node *temp = head;
        int idx = 0;
        while(temp !=nullptr){
            if(temp->data==key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
    int middle(){
        Node *temp = head;
        int idx = 0;
        while(temp !=nullptr && temp->next != nullptr){
            temp = temp->next;
            idx++;
        }
        return (idx/2);
    }
};

// Main function to test the linked list
int main()
{
    LinkedList ll;

    ll.pushBack(10);
    ll.pushBack(20);
    ll.pushBack(40);
    ll.pushBack(30);
    ll.pushBack(50);
    ll.pushBack(30);
    ll.pushFront(5);
    ll.insert(4, 15); // Insert 15 at position 4

    cout << "Linked List: ";
    ll.display(); // Output: 5 -> 10 -> 20 -> 15 -> 30 -> NULL

    ll.popFront();
    cout << "After popFront: ";
    ll.display(); // Output: 10 -> 20 -> 15 -> 30 -> NULL

    // ll.popBack();
    cout << "After popBack: ";
    ll.display(); // Output: 10 -> 20 -> 15 -> NULL
    cout<<"search value : "<<ll.search(20)<<"\n";
    
    cout<<"middle of the linked list : "<<ll.middle();

    return 0;

    return 0;
}
