/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 * 
 * Learnings: 
 * 1. If functions is monotonic, then it points to 
 *    binary search.
 */

// @lc code=start

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
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = getMax(piles);
        while(start < end) {
            int mid = start + (end-start)/2;
            if (isPossible(piles, mid, h)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return end;
    }

    bool isPossible(vector<int>& piles, int mid, int h) {
        int hoursTakenToFinish = 0;
        for (int i = 0; i < piles.size(); i++) {
            hoursTakenToFinish += piles[i]/mid + (piles[i]%mid == 0 ? 0 : 1);
        }
        return hoursTakenToFinish <= h;
    }

    int getMax(vector<int> &piles) {
        int maxValue = 1;
        for (int i = 0; i < piles.size(); i++) {
            maxValue = max(piles[i], maxValue);
        }
        return maxValue;
    }
};// @lc code=end

