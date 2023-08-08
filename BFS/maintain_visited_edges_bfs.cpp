#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

// Problem: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// QuestionType: Maintain visited Edges. (Similar Question asked in uber)
// Note: 
// 1. How to maintain map with struct as key
//      => Need to define equality.
//      => Need to define hashfunction.
// 2. 
//  

struct Node {
    int i;
    int j;
    Node(int i, int j): i(i), j(j) {};

    // Define equaltiy operator for unordered_map
    bool operator==(const Node &p) const {
        return i == p.i && j == p.j;
    }

};

struct hash_fn
{
    // Define hash operator for unordered_map
    std::size_t operator() (const Node &node) const
    {
        std::size_t h1 = std::hash<int>()(node.i);
        std::size_t h2 = std::hash<int>()(node.j);
 
        return h1 ^ h2;
    }
};


class Solution {
public:

    void make_graph(vector<vector<int>>& connections, 
                    unordered_map<int, vector<int>> &graph) {
        for (int i = 0; i < connections.size(); i++) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> graph;
        vector<bool> visited(n, false);
        int connected_comp = 0;
        int extra_edges = 0;
        make_graph(connections, graph);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                connected_comp++;
                extra_edges += bfs(i, graph, visited);
            }
        }
        cout<<"extra_edges="<<extra_edges<<endl;
        cout<<"connected_comp="<<connected_comp<<endl;
        if ((connected_comp - 1) > extra_edges) {
            return -1;
        }
        return connected_comp - 1;
    }


    int bfs(int i, 
            unordered_map<int, vector<int>> &graph, 
            vector<bool> &visited) {
        int extra_edges = 0;
        queue<int> q;
        unordered_map<Node, bool, hash_fn> visited_edges;
        visited[i] = true;
        q.push(i);
        while(!q.empty()) {
            queue<int> q2;
            while(!q.empty()) {
                int n1 = q.front();
                q.pop();
                for (int i = 0; i < graph[n1].size(); i++) {
                    if (!visited[graph[n1][i]]) {
                        visited[graph[n1][i]] = true;
                        visited_edges[Node(n1, graph[n1][i])] = true;
                        visited_edges[Node(graph[n1][i], n1)] = true;
                        q2.push(graph[n1][i]);
                    } else {
                        if (visited_edges.find(Node(n1, graph[n1][i])) == visited_edges.end()) {
                            cout<<"Node: =>"<<i<<","<<graph[n1][i]<<endl;
                            extra_edges += 1;
                            visited_edges[Node(n1, graph[n1][i])] = true;
                            visited_edges[Node(graph[n1][i], n1)] = true;
                        }
                    }
                }
            }
            q.swap(q2);
        }
        return extra_edges;
    }
};