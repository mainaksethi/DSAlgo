/*
 * @lc app=leetcode id=1000 lang=cpp
 *  Learnings: 
 * 1. Complex Dynamic Programming Problem with 
 *    multiple parts. 
 * 2. First break into 2 piles. 
 * 3. Then solve for k piles. 
 * 4. Detailed Explanation Solution: https://leetcode.com/problems/minimum-cost-to-merge-stones/solutions/247657/java-bottom-up-top-down-dp-with-explaination/?envType=list&envId=ri6a8p9g
 * 
 * [1000] Minimum Cost to Merge Stones
 */

// @lc code=start
class Solution {
public:
    struct Node {
        int left;
        int right;
        int k;
        Node(int left, int right, int k): left(left), right(right), k(k) {};

        bool operator==(const Node &n1) const {
            return n1.left == left && n1.right == right && n1.k == k;
        };
    };

    struct hash_fn {
        size_t operator()(const Node &n1) const {
            return hash<int>()(n1.k) ^ hash<int>()(n1.left) ^ hash<int>()(n1.right);
        }
    };

    int find(int start, int end, int pileCount, int k, 
        vector<int> &stones, unordered_map<Node, int, hash_fn> &dp) {
        if (pileCount == 1 && start == end) {
            return 0;
        }
        if (end-start+1 < pileCount) {
            return INT_MAX;
        }
        // check edge case;
        Node n = Node(start, end, pileCount);
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        int ans = INT_MAX;
        int sum = 0;
        for (int i = start; i <= end; i++) {
            sum += stones[i];
        }
        if (pileCount == 1) {
            int val = find(start, end, k, k, stones, dp);
            ans = val == INT_MAX ? val : val+sum;
        } else {
            ans = INT_MAX;
            for (int i = start; i < end; i++) {
                int left = find(start, i, pileCount-1, k, stones, dp);
                int right = find(i+1, end, 1, k, stones, dp);
                if (left != INT_MAX && right != INT_MAX) {
                    ans = min(ans, left + right);
                }
            }
        }
        dp[n] = ans;
        return ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        unordered_map<Node, int, hash_fn> dp;
        int val = find(0, stones.size()-1, 1, k, stones, dp);
        return val == INT_MAX ? -1 : val;
    }
};// @lc code=end

