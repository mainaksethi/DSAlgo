/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 * Learning: 
 * 1. To structure problem see the bottleneck, minimum
 * efficiency. 
 * 2. So sort the array by minimum efficiency in 
 * reverse order, and assume
 * if we take this element, then we have locked minimum
 * efficiency and we need to take best speed from the 
 * above set whose efficiency is greater than this element.
 * 
 * 3. This way we are able to structure the problem
 * by pivoting to the limiting condition.
 * 
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
    struct Node {
        int speed;
        int efficiency;
        Node (int speed, int efficiency): speed(speed), efficiency(efficiency) {};
    };

    struct sortFn {
        bool operator()(const Node &n1, const Node &n2) const {
            return n1.efficiency > n2.efficiency;
        }
    };

    struct pqFn {
        bool operator()(const Node &n1, const Node &n2) const {
            return n1.speed > n2.speed;
        }
    };

    int MOD = 1000000007;

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Node> arr;
        for (int i = 0; i < speed.size(); i++) {
            arr.push_back(Node(speed[i], efficiency[i]));
        }
        sort(arr.begin(), arr.end(), sortFn());
        priority_queue<Node, vector<Node>, pqFn> bestSpeedSoFar;
        int ans = INT_MIN;
        int totalSoFar = 0;
        for (int i = 0; i < arr.size(); i++) {
            int sum = ((totalSoFar%MOD) + (arr[i].speed%MOD))%MOD;
            int val = ((sum%MOD)*((arr[i].efficiency)%MOD))%MOD;
            // cout<<"Speed="<<arr[i].speed<<", Efficiency="<<arr[i].efficiency<<" Value = "<<val<<endl;
            if (val > ans) {
                ans = val;
            }
            if (bestSpeedSoFar.size() < k-1) {
                bestSpeedSoFar.push(Node(arr[i].speed, arr[i].efficiency));
                totalSoFar += ((arr[i].speed)%MOD);
            } else {
                if (bestSpeedSoFar.size() > 0 && (bestSpeedSoFar.top().speed < arr[i].speed)) {
                    totalSoFar -= bestSpeedSoFar.top().speed;
                    bestSpeedSoFar.pop();
                    bestSpeedSoFar.push(Node(arr[i].speed, arr[i].efficiency));
                    totalSoFar += arr[i].speed % MOD;
                }
            }
        }
        return ans;
    }

};// @lc code=end

