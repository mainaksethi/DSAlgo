/*
 * Learning: 
 * Its a non-intutive example of stack scenario where we need to find
 * the next larger number. Problems like these fall in bracket of
 * stack category.
 *
 * [739] Daily Temperatures
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
typedef struct Node {
    int index;
    int value;
    Node(int index, int value): index(index), value(value) {};
} Node;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<Node> st;
        vector<int> ans(temperatures.size(), 0);
        int i = 0;
        while (i < temperatures.size()) {
            while(!st.empty() && st.top().value < temperatures[i]) {
                Node n = st.top();
                st.pop();
                ans[n.index] = (i-n.index);
            }
            st.push(Node(i, temperatures[i]));
            i++;
        }
        return ans;
    }
};// @lc code=end

