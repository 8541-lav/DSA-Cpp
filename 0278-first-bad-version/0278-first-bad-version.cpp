// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (isBadVersion(mid)) {
                // mid is bad
                // So answer can be mid or somewhere before it
                high = mid;
            }
            else {
                // mid is good
                // So answer must be after mid
                low = mid + 1;
            }
        }

        return low;
    }
};