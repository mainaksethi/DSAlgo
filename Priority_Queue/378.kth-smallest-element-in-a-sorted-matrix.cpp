/*
 * @lc app=leetcode id=378 lang=cpp
 * Solution: 
 * You might start with 2 pointer approach but that won't work
 * since as pointer diverge far away it won't make sense
 * to compare pointers. 
 * 
 * The other straightforward approach is to dump first element 
 * of each row into a heap.
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */
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

// @lc code=start
struct Node {
    int x;
    int y;
    int val;
    Node(int x, int y, int val): x(x), y(y), val(val) {};
};

struct comp {
    bool operator()(const Node& a, const Node& b) {
        return a.val > b.val; // '>' for min heap
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Node, vector<Node>, comp> minHeap;
        for (int i = 0; i < matrix.size(); i++) {
            minHeap.push(Node(i, 0, matrix[i][0]));
        }
        int cur = 0;
        int ans = 0;
        while (cur < k) {
            Node n = minHeap.top();
            ans = n.val;
            minHeap.pop();
            if (n.y + 1 < matrix[0].size()) {
                Node next = Node(n.x, n.y+1, matrix[n.x][n.y+1]);
                minHeap.push(next);
            }
            cur++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int> > v = { { 1, 5, 9 },
                              { 10, 11, 13 },
                              {12, 13, 15} };
    s.kthSmallest(v, 8);
}
// @lc code=end

