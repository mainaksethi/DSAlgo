/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * Learing: 
 * Interesting problem of union find.
 * Standard template to keep size and parent.
 */

// @lc code=start
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> parent;
        unordered_map<int, int> size;
        for (int i = 0; i < stones.size(); i++) {
            parent.insert({stones[i][0], stones[i][0]});
            parent.insert({-1*stones[i][1]-1, -1*stones[i][1]-1});
            size.insert({stones[i][0], 1});
            size.insert({-1*stones[i][1] - 1, 1});
        }
        for (int i = 0; i < stones.size(); i++) {
            int p1 = find(stones[i][0], parent);
            int p2 = find(-1*stones[i][1] - 1, parent);
            if (p1 == p2) continue;
            if (p1 < p2) {
                parent[p2] = p1;
                size[p1] = size[p1] + size[p2];
                size[p2] = 0;
            } else {
                parent[p1] = p2;
                size[p2] = size[p1] + size[p2];
                size[p1] = 0;
            }
        }
        int leftOverStones = 0;
        for (auto it = size.begin(); it != size.end(); it++) {
            cout<<it->first<<","<<it->second<<endl;
            if (it->second != 0) leftOverStones++;
        }
        return stones.size() - leftOverStones;
    }
    
    int find(int index, unordered_map<int, int> &parent) {
        if (parent[index] == index) {
            return index;
        }
        return find(parent[index], parent);
    }
};
// @lc code=end

