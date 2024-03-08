/*
 * @lc app=leetcode id=435 lang=cpp
 *      
 * [435] Non-overlapping Intervals
 * 
 * Learning: 
 * 1. This is classical problem for greedy approach in intervals.
 * Between first and second interval if intersecting,
 * we need to remove 1 interval. Since the ones going
 * further is better candidate we remove that interval. 
 * We check for the next one if it still intersects with the 
 * better one, we do the same algorithm and remove the worst one.
 * Note. removing the further one is a good call since if the
 * next one intersects with the previous one then it is definitely
 * intersecting the further one.
 * 
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n=intervals.size();
        
        //sort the intervals based on starting point

        sort(intervals.begin(),intervals.end());

        int prev=INT_MIN; 
        int res=0;

        for(int i=0;i<n;i++){
          //no overlap 
            if(intervals[i][0]>=prev){
                prev=intervals[i][1];
            }
            //overlap case
            else{
                res++;
                prev=min(prev,intervals[i][1]);
            }
        }

        return res;
    }
};
// @lc code=end

