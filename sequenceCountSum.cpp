#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int generate(int ind, vector<int>& ds, int sum, vector<int>& nums, int n, int k) {
        if (ind == n) {
            if (sum == k) return 1;
            return 0;
        }

        // Include current element
        ds.push_back(nums[ind]);
        sum += nums[ind];
        int l = generate(ind + 1, ds, sum, nums, n, k);

        // Exclude current element
        ds.pop_back();
        sum -= nums[ind];
        int r = generate(ind + 1, ds, sum, nums, n, k);

        return l + r;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        vector<int> ds;
        int sum = 0;
        return generate(0, ds, sum, nums, nums.size(), k);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    int target = 2;

    int count = sol.countSubsequenceWithTargetSum(nums, target);
    cout << "Number of subsequences with sum " << target << ": " << count << endl;

    return 0;
}
