#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {  // ✅ Fixed constructor name
        data = val;
        next = NULL;
    }
};

class queue {
    Node* head;
    Node* tail;

public:
    queue() {
        head = tail = NULL;
    }

    void push(int val) {
        Node *newNode = new Node(val);  // ✅ Fixed type
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (empty()) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front() {
        return head->data;
    }

    bool empty() {
        return head == NULL;
    }
};

int main() {
    queue q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);

    // Optional display loop
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
