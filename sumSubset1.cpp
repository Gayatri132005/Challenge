#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Recursive function to compute subset sums
    void func(int ind, int sum, const vector<int>& nums, int N, vector<int>& sumSet) {
        if (ind == N) {
            sumSet.push_back(sum);
            return;
        }
        // Include the current element
        func(ind + 1, sum + nums[ind], nums, N, sumSet);
        // Exclude the current element
        func(ind + 1, sum, nums, N, sumSet);
    }

    // Function to initiate the subset sum computation
    vector<int> subsetSums(vector<int>& nums) {
        int N = nums.size();
        vector<int> sumSet;
        func(0, 0, nums, N, sumSet);
        sort(sumSet.begin(), sumSet.end());
        return sumSet;
    }
};

int main() {
    Solution sol;
    // Example input
    vector<int> nums = {1, 2, 3};
    vector<int> result = sol.subsetSums(nums);

    
    cout << "Subset sums in sorted order:" << endl;
    for (int sum : result) {
        cout << sum << " ";
    }
    

    return 0;
}
