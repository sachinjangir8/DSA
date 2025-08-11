#include <iostream>
#include <vector>

using namespace std;

bool findPairSum(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
            cout << "Pair found: (" << nums[left] << ", " << nums[right] << ")\n";
            return true;  // Pair found
        } 
        else if (sum < target) {
            left++;  // Move left pointer forward to increase sum
        } 
        else {
            right--; // Move right pointer backward to decrease sum
        }
    }

    cout << "No pair found\n";
    return false;  // No valid pair found
}

int main() {
    vector<int> sortedVec = {1, 2, 3, 4, 5, 6, 8, 9}; // Sorted vector
    int target = 10;

    findPairSum(sortedVec, target);

    return 0;
}
