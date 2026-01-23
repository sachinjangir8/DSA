#include<iostream>
using namespace std;

void merge(int arr[],int st,int end,int mid){
    int i = st, j = mid + 1;
    int k = 0;
    int temp[12];
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
        }else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=end){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int p = st; p <= end; p++) {
        arr[p] = temp[p - st];   // ✅ offset by st
    }
}
void mergesort(int arr[],int st,int end){
    if(st<end){
        int mid=st+(end-st)/2;
        mergesort(arr, st, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, st, end, mid);
    }

}


int main()
{
    int arr[12] = {4, 5, 3, 6, 6, 8, 6, 23, 87, 67, 12, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}