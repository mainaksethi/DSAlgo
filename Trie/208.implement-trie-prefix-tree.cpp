/*
 * @lc app=leetcode id=675 lang=cpp
 *
 * [675] Implement Trie Prefix Tree
 * 
 * Learning: 
 * 1. This is the standard implementation for trie prefix tree.
 * 2. Search and retrieve complexity is O(n).
 * 3. Majorly comprises of two parts 
 *  a. TrieNode* children.
 *  b. isEndOfWord.
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

typedef struct TrieNode {
    vector<TrieNode*> children;
    bool isEndOfWord;
    TrieNode(): children(vector<TrieNode*>(26, NULL)), isEndOfWord(false) {};
}TrieNode;

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
        vector<char> string_array;
    }
    
    void insert(string word) {
        TrieNode* parent = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (parent->children[index] == NULL) {
                parent->children[index] = new TrieNode();
            }
            if (i == word.size()-1) {
                parent->children[index]->isEndOfWord = true;
            }
            parent = parent->children[index];
        }
    }
    
    bool search(string word) {
        TrieNode* parent = root;
        for (int i = 0; i < word.size(); i++) {
            TrieNode* child = parent->children[word[i] - 'a'];
            if (child == NULL) {
                return false;
            }
            parent = child;
        }
        if (!parent->isEndOfWord) {
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* parent = root;
        for (int i = 0; i < prefix.size(); i++) {
            TrieNode* child = parent->children[prefix[i] - 'a'];
            if (child == NULL) {
                return false;
            }
            parent = child;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */