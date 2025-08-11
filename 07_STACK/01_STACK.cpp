#include <iostream>
#include<conio.h>
#include <vector>
#include <list>
using namespace std;

class Stack
{
    // vector<int> v;
    // stack using linked list...
    list<int> li;


public:
    void push(int val)
    {
        // v.push_back(val);
        li.push_front(val);
    }
    void pop(){
        // v.pop_back();
        li.pop_front();
    }
    int top(){
        // return v[v.size() - 1];
        return li.front();
    }
    bool empty(){
        // return v.size() == 0;
        return li.size() == 0;
    }
};
int main()
{
    Stack s;
    s.push(13);
    s.push(14);
    s.push(15);

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}