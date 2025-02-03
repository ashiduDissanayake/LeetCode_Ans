#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        int halfLen = (m + n + 1) / 2;
        
        while (left <= right) {
            int partitionX = (left + right) / 2;
            int partitionY = halfLen - partitionX;
            
            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            
            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            
            if (maxX <= minY && maxY <= minX) {
                // We have found the correct partition
                if ((m + n) % 2 == 0) {
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                } else {
                    return max(maxX, maxY);
                }
            } else if (maxX > minY) {
                // Move partitionX to the left
                right = partitionX - 1;
            } else {
                // Move partitionX to the right
                left = partitionX + 1;
            }
        }
        
        // If we reach here, it means the input arrays are not sorted
        throw invalid_argument("Input arrays are not sorted");
    }
};

