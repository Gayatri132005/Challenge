#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        bool generate(int ind, vector<int>& ds, int sum, vector<int>& nums, int n, int k) {
            if (ind == n) {
                if (sum == k) return true;
                return false;
            }
    
            // Include current element
            ds.push_back(nums[ind]);
            sum += nums[ind];
            if(generate(ind + 1, ds, sum, nums, n, k)==true){
                return true;
            }
    
            // Exclude current element
            ds.pop_back();
            sum -= nums[ind];
            if(generate(ind + 1, ds, sum, nums, n, k)==true){
                 return true;
            }
    
           
        }
    
        bool countSubsequenceWithTargetSum(vector<int>& nums, int k) {
            vector<int> ds;
            int sum = 0;
            return generate(0, ds, sum, nums, nums.size(), k);
        }
    };
    int main() {
        Solution sol;
        vector<int> nums = {1, 2, 1};
        int target = 2;
        bool result = sol.countSubsequenceWithTargetSum(nums, target);
        cout << (result ? "yes" : "No ") << endl;
     
    
        return 0;
    }