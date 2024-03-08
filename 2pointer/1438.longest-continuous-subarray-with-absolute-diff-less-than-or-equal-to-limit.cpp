/**
 * Learning mentioned in problem statement. 
 * Similar problem asked in Roku.
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> minElements;
        multiset<int, greater<int>> maxElements;
        int start = 0, end = 0;
        int ans = 0;

        while(end != nums.size()) {
            minElements.insert(nums[end]);
            maxElements.insert(nums[end]);
            // Note here is the learning for boundary condition.
            /**
             * Template: 
             * while (end < array.size()) {
             *  // consume new element. 
             *  if (condition violated || end == (array.size() - 1)) {
             *      // Note here window size excludes last element if condition violated 
             *      // else if not violated then it means we have reached end and include last element.
             *      if (conditionViolated) {
             *          if (finalWindowSize < end - start) {
             *              finalWindowSize = end - start;
             *          }
             *      } else if (finalWindowSize < end - start + 1) {
             *              finalWindowSize = end - start;
             *      }
             *  }
             * }
            */
            if ((*(maxElements.begin()) - *(minElements.begin()) > limit) || 
                 (end == (nums.size() - 1))) {
                if ((*(maxElements.begin()) - *(minElements.begin()) > limit)) {
                    if (ans < (end - start)) {
                        ans = end - start;
                    }
                } else if (ans < (end - start + 1)) {
                    ans = end - start + 1;
                }
                while((*(maxElements.begin()) - *(minElements.begin()) > limit) && start < end) {
                    auto it = maxElements.find(nums[start]);
                    maxElements.erase(it);
                    auto it2 = minElements.find(nums[start]);
                    minElements.erase(it2);
                    start++;
                }
            }
            end++;
        }
        return ans;
    }
};