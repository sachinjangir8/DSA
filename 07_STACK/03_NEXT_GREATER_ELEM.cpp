#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    vector<int> ar = {6, 7, 5, 4, 3, 6, 1};
    stack<int> stk;
    vector<int>ans(ar.size(),0);
    for (int i = ar.size()-1; i >= 0;i--){
        while (stk.size()>0 && stk.top()<=ar[i])
        {
            stk.pop();
        }
        if(stk.empty()){
            ans[i] = -1;
        }else{
            ans[i] = stk.top();
        }
        stk.push(ar[i]);
    }
    // printing.........
    for(int val :ans){
        cout<<val<<" ";
    }
    return 0;
}