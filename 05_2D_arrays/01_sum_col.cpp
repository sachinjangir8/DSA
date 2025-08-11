#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void resub(vector<int> &arr, vector<int>& ans, int i, vector<vector<int>> &result) {
        if (i == arr.size()) {
            result.push_back(ans); // Store the subset
            return;
        }
        
        // Include the current element
        ans.push_back(arr[i]);
        resub(arr, ans, i + 1, result);
        ans.pop_back(); // Backtrack
        
        // Exclude the current element
        resub(arr, ans, i + 1, result);
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> result;
        vector<int> ans;
        resub(arr, ans, 0, result);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3}; // Example input
    vector<vector<int>> result = solution.subsets(nums);
    
    cout << "Subsets:" << endl;
    for (const auto &subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}
