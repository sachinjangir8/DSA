#include<iostream>
using namespace std;

class maxheap {
    int *arr;
    int heap_size;
    int capacity;

public:
    maxheap(int cap) {
        heap_size = 0;
        capacity = cap;
        arr = new int[cap];
    }

    void insert(int value) {
        if (heap_size == capacity) {
            cout << "Overflow: Could not insert key" << endl;
            return;
        }

        arr[heap_size] = value;
        int index = heap_size;
        heap_size++;

        // Correct bubble-up for MAX HEAP
        while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << value << " is inserted in the heap" << endl;
    }

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap_size && arr[left] > arr[largest])
            largest = left;

        if (right < heap_size && arr[right] > arr[largest])
            largest = right;   // FIXED

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    void deleteRoot() {
        if (heap_size <= 0) {
            cout << "Underflow: Could not delete key" << endl;
            return;
        }

        cout << arr[0] << " is deleted from the heap" << endl;

        arr[0] = arr[heap_size - 1];
        heap_size--;

        if (heap_size > 0)
            heapify(0);
    }

    void printHeap() {
        for (int i = 0; i < heap_size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    maxheap h(10);

    for (int i = 10; i > 0; i--)
        h.insert(i);

    h.printHeap();
    h.deleteRoot();
    h.printHeap();

    return 0;
}
