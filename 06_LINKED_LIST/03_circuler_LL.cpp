#include<iostream>
#include<conio.h>
using namespace std;

class Node{
    public:
        int data;   
        Node* next;
        Node(int val){
            data = val;
            next = NULL;
        }
};

class LinkedList{
    Node* head;
    Node* tail;
    public:
    LinkedList(){
        head =tail= NULL;
    }
    // inserting data at head
    void insertAtHead(int val){
        Node* newNode = new Node(val);
        // when circular linked list is empty then.....
        if(head == NULL){
            head = tail = newNode;
            tail->next = head; //also can be written newNode
        }else{
            newNode->next = head;
            head = newNode;
            tail->next = newNode;
        }
    }
    // inserting data at tail
    void insertAtTail(int val){
        Node* newNode =new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head; //tail ka next head hi h beacuse of single node...
        }else{
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }
    void deleteathead()
{
        if(head == NULL) return;  //empty LL
        else if(head==tail){ //1 elem
            delete head;
            head = tail = NULL;
        }else{ //2 or more elem
            Node* temp = head; //
            head = head->next;
            tail->next = head;
            delete temp;
        }
} 
    void deleteattail(){
        if(head == NULL) return;  //empty LL
        else if(head==tail){ //1 elem
            delete head;
            head = tail = NULL;
        } else{ //2 or more elem
            Node* temp = tail;
            Node* prev = head;
            while(prev->next!=tail) prev = prev->next; //to reach tail
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
            
        }
    }
   void display(){
        if(head == NULL)return;

        cout<< head->data<<" ->. ";
        Node* temp = head->next;
        while(temp != head){
            cout << temp->data<< " -> ";
            temp = temp->next; // Move to the next node
        }
        cout  << temp->data << endl; //from wher circulerity started....
    }
};
int main(){
    LinkedList cr;
    cout << "head data : ";
    cr.insertAtHead(4);
    cr.insertAtHead(3);
    cr.insertAtHead(2);
    cr.insertAtHead(1);
    cr.display();

    //inserting the data from tail...
    cout << "tail data : ";

    cr.insertAtTail(5);
    cr.insertAtTail(6);
    cr.display();

    //deleting the data from head...
    cout << "deleted data from head : ";
    cr.deleteathead();
    cr.display();

    //deleting the data from tail...
    cout << "deleted data from tail : ";
    cr.deleteattail();
    cr.display();
}