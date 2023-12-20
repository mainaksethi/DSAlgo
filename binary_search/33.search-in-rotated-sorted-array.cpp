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

/**
 * Standard binary search problem. 
 * Remember template
 * 
 *         while (left <= right) {
            int mid = left + (right-left)/2;
            if (condition with mid right) {
                return mid;
            }
            if (nums[mid] >= nums[0] && nums[mid] >= nums[nums.size() - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

* Note: Above template don't need any exit condition beyond the loop.
* 
* Learning 2: 
* In ciruclar scenarios use % array.size to avoid array offset issues.
* Careful in equality conditions.
* Careful in edge scenarios where array is not sorted.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        if (nums[0] == target) {
            return 0;
        }
        if (nums[0] < nums[nums.size() - 1]) {
            return search(nums, 0, nums.size() -1, target);
        }
        int rotatedIndex = findRotatedIndex(nums);
        cout<<rotatedIndex<<endl;
        if (target > nums[0]) {
            return search(nums, 0, rotatedIndex, target);
        } else {
            return search(nums, rotatedIndex + 1, nums.size() - 1, target);
        }
    }
    
    int findRotatedIndex(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            cout<<mid<<endl;
            if (nums[mid] >= nums[(mid+1)%nums.size()] && nums[mid] > nums[(mid+nums.size()-1)%nums.size()]) {
                return mid;
            }
            if (nums[mid] >= nums[0] && nums[mid] >= nums[nums.size() - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    
    int search(vector<int> &nums, int start, int end, int target) {
        int left = start; 
        int right = end;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
