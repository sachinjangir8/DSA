#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int partition(vector<int> &ar, int st, int e){
    int idx = st - 1, pivot = ar[e];
    for (int j = st;j<e;j++){
        if(ar[j] <= pivot){
            idx++;
            swap(ar[idx], ar[j]);
        }
    }
    idx++;
    swap(ar[idx], ar[e]);
    return idx;
}

void QUICKSORT(vector<int> &ar,int st,int e){
    if(st<e){
        int pivtidx = partition(ar, st, e);
        QUICKSORT(ar, st, pivtidx - 1); //left side of the pivot
        QUICKSORT(ar, pivtidx + 1, e);  //right side of the pivot

    }
}

int main(){
    vector<int> ar = {23, 45, 43, 2, 4, 1, 45, 33};
    int st = 0, n = ar.size() - 1;
    QUICKSORT(ar, st, n);
    for(int i=0; i<ar.size(); i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}