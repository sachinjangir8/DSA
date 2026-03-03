#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int arrr[10] = {1,2,3,7,5,0,-2,1,4,2};
    int n = 10;
    int k = 24;
    int count=0;
    unordered_map<int, int> presum;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arrr[i];
        if(sum == k){
            cout << "Subarray found from index 0 to " << i << endl;
            return 0;
        }
        if(presum.find(sum - k) != presum.end()){
            count+=presum[sum - k];
            cout << "Number of subarrays with sum " << k << " is: " << count << endl;
            // cout << "Subarray found from index " << presum[sum - k] + 1 << " to " << i << endl;
            // return 0;
        }
        // presum[sum] = i;
        presum[sum]++;
    }
    cout << "Total number of subarrays with sum " << k << " is: " << count << endl;
}