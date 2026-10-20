class Solution {
public:
    // Two Sum II helper: finds all unique pairs in sorted nums[start..end] summing to target
    void twoSumII(vector<int>& nums, int start, int target, vector<vector<int>>& res) {
        int l = start, r = nums.size() - 1;

        while (l < r) {
            int sum = nums[l] + nums[r];

            if (sum < target) l++;
            else if (sum > target) r--;
            else {
                res.push_back({-target, nums[l], nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) l++;   // skip duplicates
                while (l < r && nums[r] == nums[r + 1]) r--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;                          // no triplet possible
            if (i > 0 && nums[i] == nums[i - 1]) continue;   // skip duplicate first element

            // Reduce to Two Sum II: find pairs in nums[i+1..] summing to -nums[i]
            twoSumII(nums, i + 1, -nums[i], res);
        }
        return res;
    }
};