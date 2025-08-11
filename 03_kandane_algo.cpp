#include <iostream>
#include <climits> // Include for INT_MIN
//                              the following is broute force algorithm

using namespace std;

int main() {
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};

    int maxSum = INT_MIN; // Initialize with the smallest possible value

    // Brute-force approach to find the max subarray sum
    for (int st = 0; st < n; st++) {
        int currSum = 0;
        for (int end = st; end < n; end++) {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }

    // Print the maximum subarray sum
    cout << "Max subarray sum = " << maxSum << endl;

    return 0;
}
                    //         this is kadanes algorithm