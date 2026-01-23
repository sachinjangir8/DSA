#include<iostream>
using namespace std;
class fect{
    public:
    int fectt(int n){
        if(n==0)return 1;
        return n*fectt(n-1);
    }
};
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    fect obj;
    cout<<obj.fectt(n);
    return 0;

}