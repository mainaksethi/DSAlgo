/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 * Learning: 
 * 1. Similar problem asked in Uber where we need to keep
 * the visited edges.
 * 2. Note: To keep visited edges, we are removing the edges 
 * from adjacency list.
 */

// @lc code=start
class Solution {
public:

    void dfs( map<string,multiset<string>> &m,string node,vector<string>&ans) {
        cout<<node<<endl;
        vector<string> temp;
        for(auto a:m[node]) {
            temp.push_back(a);
        }
        for(auto a:temp) {
            if(m[node].find(a)!=m[node].end()) {
                m[node].erase(m[node].find(a));
                dfs(m,a,ans);
            }
        }
        ans.push_back(node);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,multiset<string>> m;
        for(auto a : tickets) {
            m[a[0]].insert(a[1]);
        }
        vector<string> ans;
        dfs(m,"JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }

};// @lc code=end

