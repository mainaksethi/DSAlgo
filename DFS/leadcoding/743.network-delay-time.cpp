/*
 * [743] Network Delay Time
 * Learning: 
 * 1. Standard Dijkstra Problem. 
 * 2. Look at the comments for explanation.
 * 3. C++ has max-heap by default and we create min_heap by
 *    creating comparator function. Note in comparator the 
 *    operator is greater than which is unintuitive.
 * 4. Map don't overwrite value rather it first delete and insert
 *    in c++;
 * Algorithm:
 * 1. Start from source node.
 * 2. Update distance of neighbors in min_distance_map and insert
 *    into the heap.
 * 3. Pop from the heap and check if its not already visited
 *    Mark it as visited and update its neighbors distance.
 * 4. recur from step 1.
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
struct Node {
    int node;
    int dist;
    Node(int node, int dist): node(node), dist(dist) {};
};

struct comp {
    bool operator()(Node &a, Node &b) {
        return a.dist > b.dist;
    }
};

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Initialize adjacency List 
        vector<vector<Node>> adjList(n);
        // Initialize visited array 
        vector<bool> visited(n, false);
        // Initialize minDistance Map
        unordered_map<int, int> minDistMap;
        for (int i = 0; i < n; i++) {
            minDistMap.insert({i, INT_MAX});
        }
        for (int i = 0; i < times.size(); i++) {
            Node n = Node(times[i][1]-1, times[i][2]);
            adjList[times[i][0]-1].push_back(n);
        }
        priority_queue<Node, vector<Node>, comp> pq;
        pq.push(Node(k-1, 0));
        // Note to first erase and then insert minDistMap
        minDistMap.erase(k-1);
        minDistMap.insert({k-1, 0});
        int visited_count = 0;
        int final_time = INT_MIN;
        // Iterate till priority queue is not empty.
        while(!pq.empty()) {
            Node n = pq.top();
            pq.pop();
            // Continue if already visited.
            if (visited[n.node]) {
                continue;
            } else {
            // Insert into priority queue.
                visited[n.node] = true;
                visited_count++;
                if (final_time < minDistMap[n.node]) {
                    final_time = minDistMap[n.node];
                }
                for (int i = 0; i < adjList[n.node].size(); i++) {
                    Node neighbr = adjList[n.node][i];
                    cout<<n.node<<endl;
                    cout<<neighbr.node<<endl;
                    cout<<minDistMap[n.node]<<endl;
                    cout<<neighbr.dist<<endl;
                    if (!visited[neighbr.node] && (
                            minDistMap.find(neighbr.node) == minDistMap.end() ||
                            minDistMap[neighbr.node] > minDistMap[n.node] + neighbr.dist
                            )
                        ) {
                        minDistMap[neighbr.node] = minDistMap[n.node] + neighbr.dist;
                        pq.push(Node(neighbr.node, minDistMap[neighbr.node]));
                    }
                }
            }
        }
        if (visited_count == n) {
            return final_time;
        }
        return -1;
    }
};// @lc code=end