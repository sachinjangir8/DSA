#include <iostream>
using namespace std;
class heap
{
public:
    heap(int arr[], int n)
    {
        
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
        cout << "Min Heap array: ";
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
    }
    
    void heapify(int arr[], int n, int i)
    {
        int smallest = i;       
        int left = 2 * i + 1;  
        int right = 2 * i + 2; 

        if (left < n && arr[left] > arr[smallest])
            smallest = left;

        if (right < n && arr[right] > arr[smallest])
            smallest = right;

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(arr, n, smallest);
        }
    }
    void sort(int arr[], int n)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
        cout << "\nSorted array: ";
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
    }
};
int main()
{
    int arr[] = {3, 5, 1, 10, 2, 7, 6, 4, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    heap h(arr, n);
    h.sort(arr, n);
    return 0;
}