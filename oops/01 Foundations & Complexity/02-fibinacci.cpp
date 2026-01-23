#include<iostream>
using namespace std;
class fib{
    public:
        int n;
        int fibo(int n)
        {
            if (n == 0)return 0;
        if(n==1)return 1;
        return fibo(n-1)+fibo(n-2);
    }
     int printFibonacci(int n) {
        for (int i = 0; i < n; i++) {
            cout << fibo(i) << " ";
        }
        return 0;
    }
};
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    fib obj;
    cout<<obj.fibo(n);
    cout<<endl;
    obj.printFibonacci(n);
    return 0;
}