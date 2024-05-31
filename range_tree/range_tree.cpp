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

/**
 * Learning: 
 * Find max in a range.
*/


struct Node {
    int start; 
    int end;
    int max;
    Node* left;
    Node* right;
    Node(int start, int end, int max, Node* left, Node* right): start(start), end(end), max(max), left(left), right(right) {};
};

Node* create(vector<int> &v) {
    vector<Node*> nodes;
    for (int i = 0; i < v.size(); i++) {
        nodes.push_back(new Node(i, i, v[i], NULL, NULL));
    }
    while(nodes.size() != 1) {
        vector<Node*> nodes2;
        for (int i = 0; i < nodes.size(); i=i+2) {
            if (i+1 >= nodes.size()) {
                nodes2.push_back(nodes[i]);
            } else {
                Node* n = new Node(nodes[i]->start, nodes[i+1]->end, max(nodes[i]->max, nodes[i+1]->max), nodes[i], nodes[i+1]);
                nodes2.push_back(n);
            }
        }
        nodes.swap(nodes2);
    }
    return nodes[0];
}

bool intersects(vector<int> &query, Node *root) {
    return ! (query[1] < root->start || query[0] > root->end);
}

bool contains(vector<int> &query, Node *root) {
    return root->start >= query[0] && root->end <= query[1];
}

int findMax(vector<int> &query, Node* root) {
    if (root == NULL || !intersects(query, root)) {
        return INT_MIN;
    }
    if (contains(query, root)) {
        return root->max;
    }
    int ans = max(findMax(query, root->left), findMax(query, root->right));
    return ans;
}


int main() {
    vector<int> v = {1, 8, 5, 9, 6, 14, 2, 4, 3, 7};
    Node* root = create(v);
    vector<vector<int>> queries = {{0, 4}, {3, 7}, {1, 6}, {2, 5}, {0, 8}};
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++) {
        ans.push_back(findMax(queries[i], root));
    }
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<",";
    }
    return 0;
}