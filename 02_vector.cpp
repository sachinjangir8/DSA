#include <iostream>
#include <vector>

using namespace std;

// Function to print a vector (read-only)
void printVector(const vector<int>& v) {
    cout << "Vector elements: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {10, 20, 30, 40};
    printVector(numbers); // Call function
    return 0;
}
