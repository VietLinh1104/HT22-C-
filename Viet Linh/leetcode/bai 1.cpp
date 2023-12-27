#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
#include<vector>
//#include<unordered_map>

using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++){
//            cout <<"(i = "<<i<<")";
            for(int j=i+1; j<n; j++){
//                cout << "(j = "<<j<<")";
                if( nums[i]+nums[j] == target){
                    cout <<"{"<< i <<","<<j<<"}";
					return {i,j} ;
                }
            }
        }
        return {}; // No solution found
    }
};

int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    Solution a;

   vector<int> b = a.twoSum(nums,6);
   cout <<b[0];
    // a.twoSum(nums,9);


    system("pause");
}
