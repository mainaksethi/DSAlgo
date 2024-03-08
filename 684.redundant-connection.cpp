/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 * 
 * Learning: 
 * 1. Standard template for union find data-structure. 
 * Theory: 
 * Kruskal/Prim for finding minimum spanning tree. 
 * Sort the edges and use union find data-structure to combine
 * nodes. Remove edges having same parent. 
 * 
 * Time Order: 
 * 1. O(E)LogV
 * Since we iterate over all edges and finding parent would be
 * logV.
 * Other Similar Problems: 
    https://leetcode.com/problems/number-of-provinces
    https://leetcode.com/problems/redundant-connection
    https://leetcode.com/problems/most-stones-removed-with-same-row-or-column
    https://leetcode.com/problems/satisfiability-of-equality-equations
    https://leetcode.com/problems/number-of-operations-to-make-network-connected
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_set<int> nodes;
        for (int i = 0; i < edges.size(); i++) {
            nodes.insert(edges[i][0]);
            nodes.insert(edges[i][1]);
        }
        int size = nodes.size() + 1;
        vector<int> parent(size, -1);
        for (int i = 1; i < parent.size(); i++) {
            parent[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            int p1 = find(edges[i][0], parent);
            int p2 = find(edges[i][1], parent);
            if (p1 == p2) {
                return edges[i];
            } else if (p1 < p2) {
                parent[p2] = p1;
            } else {
                parent[p1] = p2;
            }
        }
        return vector<int>();
    }
    
    void print(vector<int> &parent) {
        for (int i = 1; i < parent.size(); i++) {
            cout<<parent[i]<<",";
        }
        cout<<endl;
    }
    
    int find(int node, vector<int> &parent) {
        if (parent[node] == node) {
            return node;
        }
        return find(parent[node], parent);
    }
};// @lc code=end

