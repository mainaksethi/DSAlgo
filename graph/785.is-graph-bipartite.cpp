/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * Standard D.F.S assign a color.
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<int> colorArr(graph.size(), -1);
        bool isGraphBipartite = true;
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                isGraphBipartite = isGraphBipartite && isBipartite(graph, visited, i, 0, colorArr);
            }
        }
        return isGraphBipartite;
    }

    bool isBipartite(vector<vector<int>>& graph, vector<bool> &visited, int node, int color, 
                        vector<int> &colorArr) {
        colorArr[node] = color;
        visited[node] = true;
        int newColor = (color == 0 ? 1 : 0);
        bool ans = true;
        for (int i = 0; i < graph[node].size(); i++) {
            if (visited[graph[node][i]] && colorArr[graph[node][i]] != newColor) {
                cout<<graph[node][i]<<","<<colorArr[graph[node][i]]<<endl;
                return false;
            } else if (!visited[graph[node][i]]) {
                ans = ans && isBipartite(graph, visited, graph[node][i], newColor, colorArr);
            }
        }
        return ans;
    }
};// @lc code=end

