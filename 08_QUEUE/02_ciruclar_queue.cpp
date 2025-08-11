#include<iostream>
#include<conio.h>
using namespace std;

class CircularQ
{
    int *arr;
    int currsize, cap;
    int front, rear;
public:
    CircularQ(int size){
        cap = size;
        currsize = 0;
        arr = new int[cap]; // allocate a new array dinamically...
        front = 0;
        rear = -1;
    }
    void push(int data){
        if(currsize==cap){
            cout << "Circular is full!" << endl;
            return;
        }
        //back (rear) se data insert krte h..
        rear = (rear + 1) % cap;
        arr[rear] = data;
        currsize++;
    }
    void pop(){
        if(empty()){
            cout << "Circular is empty!" << endl;
            return;
        }
        front = (front + 1) % cap;
        currsize--;
    }
    int frontelem(){
        if(empty()){
            cout << "Circular is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        return currsize == 0;
    }
    
};


int main(){
    CircularQ q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.push(5); // circular queue is full now...
    cout << "Front element is: " << q.frontelem() << endl;
    while (!q.empty())
    {
        cout << "cue elem is : " << q.frontelem() << endl;
        q.pop();
    }
    
    return 0;

}