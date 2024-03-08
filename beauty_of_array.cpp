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
    int maximumBeauty(vector<int> arr) {
        vector<int> trimmed_arr;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= (i+1) && arr[i] <= arr.size()) {
                trimmed_arr.push_back(arr[i]);
            } else {
                trimmed_arr.push_back(INT_MAX);
            }
        }
        vector<int> dp(trimmed_arr.size(), 1);
        int ans = 0;
        for (int i = 0; i < trimmed_arr.size(); i++) {
            int max = 0;
            for (int j = 0; j < i; j++) {
                if (trimmed_arr[j] < trimmed_arr[i] && max < dp[j]) {
                    max = dp[j];
                }
            }
            dp[i] = max + 1;
            if (arr[i] != INT_MAX && ans < dp[i]) {
                ans = dp[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v = {1,3,2,5,4,5,3};
    cout<<s.maximumBeauty(v)<<endl;
    return 0;
}