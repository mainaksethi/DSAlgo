/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 * Solution: https://www.youtube.com/watch?v=yD7wV8SyPrc
 * 
 */

// @lc code=start
// Ref: https://www.youtube.com/watch?v=yD7wV8SyPrc
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // Ensure nums1 is the smaller array
        if(n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int low = 0;
        int high = n1;
        
        while(low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (n1 + n2 + 1) / 2 - partition1;
            
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == n1) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n2) ? INT_MAX : nums2[partition2];
            
            if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if((n1 + n2) % 2 == 0) {
                    return (double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2;
                } else {
                    return (double)max(maxLeft1, maxLeft2);
                }
            } else if(maxLeft1 > minRight2) {
                high = partition1 - 1;
            } else {
                low = partition1 + 1;
            }
        }
        
        return -1;
    }
};
// @lc code=end

