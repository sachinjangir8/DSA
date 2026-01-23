#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> pq ; //max heap
    priority_queue<int,vector<int>,greater<int>> minpQ; //min heap
    for (int i = 0; i < 7; i++)
    {
        pq.push(i);
        minpQ.push(i);
    }
    cout<<"Max Heap: ";
    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    cout<<"Min Heap: ";
    while (!minpQ.empty())
    {
        cout<<minpQ.top()<<" ";
        minpQ.pop();
    }
    return 0;

}