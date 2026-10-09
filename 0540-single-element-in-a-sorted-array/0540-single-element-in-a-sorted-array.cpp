class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            // Make mid even
            if (mid % 2 == 1) {
                mid--;
            }

            if (nums[mid] == nums[mid + 1]) {
                // Pair is correct
                // Single element is on the right
                low = mid + 2;
            }
            else {
                // Pair is broken
                // Single element is on the left or at mid
                high = mid;
            }
        }

        return nums[low];
    }
};