#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> PRESMALLELEM(vector<int>ar){
    vector<int> ans(ar.size(), 0);
    stack<int> stk;
    for(int i=0; i<ar.size();i++){
        while(stk.size()>0 && stk.top()>=ar[i]){
            stk.pop();
        }
        if(stk.empty()){
            ans[i]=-1;
        }else{
            ans[i]=stk.top();
        }
        stk.push(ar[i]);
    }
    return ans;

}

int main(){
    vector<int> ar = {3, 1, 0, 8, 6};
    // from PRESMALLERELEM function we will get ans it will return it.........
    vector<int>ans=PRESMALLELEM(ar);
    for(int val :ans){
        cout<<val<<" ";
    }
    return 0;
}