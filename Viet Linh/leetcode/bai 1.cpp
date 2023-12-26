#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) {
                return {i, numMap[complement]};
            }
        }

        return {}; // No solution found
    }
};

int main(){
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(2);
    Solution a;

    vector<int> b = a.twoSum(nums,9);
    cout <<"{"<<b[0]<<","<< b[1]<<"}"<<endl;

	int n = nums.size();
    for(int i=0; i<n; i++){
        cout << nums[i];
    }

    system("pause");
}
