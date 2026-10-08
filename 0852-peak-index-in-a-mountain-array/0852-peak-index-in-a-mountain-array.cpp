class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            
            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // We are on the increasing side
                // Peak is on the right
                low = mid + 1;
            }
            else {
                // We are on the decreasing side
                // Peak can be mid or on the left
                high = mid;
            }
        }

        return low;
    }
};