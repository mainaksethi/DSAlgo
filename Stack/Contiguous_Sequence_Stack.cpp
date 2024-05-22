#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

/**
 * Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 * Type: Contiguous Sequence Stack
 * Thinking : 
 * 1. Come up with basic solution as largest rectangle with histogram as height. O(n^2)
 * 2. Contiguous things ideates towards stack with some eliminatio n criteria 
 *  we can come up with O(n) approach.
 * 3. Final Solution: 
 * Left to Right (Symmetric for Right To Left)
 * For every element all the left elements greater
 * than the element are irrelevant since that element will be breaking.
 * So we will keep only elements lesser than current element in the stack.
 * For storing left_max[i] we will pop all elements greater that the current element
 * and store left_max[i] = left_max[last_popped] since last_popped is greater_than_equal
 * to element as per algorithm so its left_max will be the elements left_max.  
 * 
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> left_max(heights.size(), 0);
        vector<int> right_max(heights.size(), heights.size()-1);
        for (int i = 0; i < heights.size(); i++) {
            int last_popped = i;
            if (!st.empty()) {
                while(!st.empty() && heights[st.top()] >= heights[i]) {
                    last_popped = st.top();
                    st.pop();
                }
            }
            left_max[i] = i == last_popped ? i : left_max[last_popped];
            st.push(i);
        }
        while(!st.empty()) {
            st.pop();
        }
        for (int i = heights.size()-1; i >= 0; i--) {
            int last_popped = i;
            if (!st.empty()) {
                while(!st.empty() && heights[st.top()] >= heights[i]) {
                    last_popped = st.top();
                    st.pop();
                }
            }
            right_max[i] = (i == last_popped ? i : right_max[last_popped]);
            st.push(i);
        }
        int max = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (max < (heights[i]*(right_max[i] - left_max[i] + 1))) {
                max = heights[i]*(right_max[i] - left_max[i] + 1);
            }
        }
        // print(left_max);
        // print(right_max);
        return max;
    }

    void print(vector<int> v) {
        for (int i = 0; i < v.size(); i++) {
            cout<<v[i]<<",";
        }
        cout<<endl;
    }

};