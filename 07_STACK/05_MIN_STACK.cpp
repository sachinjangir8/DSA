#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class minmaxstk{
public:
    stack<pair<int, int>> s;
    void push(int val){
        if(s.empty()){
            s.push({val, val});
        }else{
            int min_val = min(val, s.top().second);
            s.push({val, min_val});
        }
    }
    void pop() {
        s.pop();
    }
    int top() {
        return s.top().first;
    }
    int getMin() {
        return s.top().second;
    }
    // int getallelem(){
    //     int n = s.size();
    //     int res = s.top().first;
    //     for(int i=1; i<n; i++){
    //         res =  s.top().first;
    //         s.pop();
    //     }
    //     return res;
    // }
};
int main (){
    minmaxstk stk;
    stk.push(5);
    stk.push(3);
    stk.push(2);
    // cout << "All elements are " << stk.getallelem() << endl;
    cout << "Top element is " << stk.top() << endl;
    cout << "Minimum element is " << stk.getMin() << endl;
    stk.pop();
    cout << "Top element after pop is " << stk.top() << endl;
    cout << "Minimum element after pop is " << stk.getMin() << endl;
    // return 0;
}