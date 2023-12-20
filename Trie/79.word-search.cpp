/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * Learnings: 
 * 1. Interesting Problem storing strings in trie and then
 * parsing the 2-d array.
 * 2. Store more information in trie node like word.
 * 
 */

// @lc code=start
class Solution {
public:

    struct TrieNode {
        bool isEndOfWord;
        vector<TrieNode*> children;
        string word;
        TrieNode(): isEndOfWord(false), children(vector<TrieNode*>(26, NULL)), word("") {};
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> foundWords;
        TrieNode* root = new TrieNode();
        insertWordsInTrie(root, words);
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int j = 0; j < board.size(); j++) {
            for (int k = 0; k < board[0].size(); k++) {
                search(board, visited, j, k, root, foundWords);
            }
        }
        return foundWords;
    }

    void insertWordsInTrie(TrieNode* &root, vector<string>& words) {
        TrieNode* cur = root;
        for (int i = 0; i < words.size(); i++) {
            cur = root;
            for (int j = 0; j < words[i].size(); j++) {
                if (cur->children[words[i][j]-'a'] == NULL) {
                    cur->children[words[i][j]-'a'] = new TrieNode();
                }
                cur = cur->children[words[i][j]-'a'];
                if (j == words[i].size() - 1 ) {
                    cur->isEndOfWord = true;
                    cur->word = words[i];
                }
            }
        }
    }

    void search(vector<vector<char>>& board,
                vector<vector<bool>> &visited,
                int i,
                int j,
                TrieNode* &root,
                vector<string> &foundWords) 
    {
            if (root->isEndOfWord) {
                foundWords.push_back(root->word);
                root->isEndOfWord = false;
            }
            if (!isValid(board, visited, i, j)) return;
            visited[i][j] = true;
            // cout<<board[i][j]<<","<<root->isEndOfWord<<endl;
            if (root->children[board[i][j] - 'a'] != NULL) {
                search(board, visited, i+1, j, root->children[board[i][j] - 'a'], foundWords);
                search(board, visited, i-1, j, root->children[board[i][j] - 'a'], foundWords);
                search(board, visited, i, j+1, root->children[board[i][j] - 'a'], foundWords);
                search(board, visited, i, j-1, root->children[board[i][j] - 'a'], foundWords);
            }
            visited[i][j] = false;
            return;
    }

    bool isValid(vector<vector<char>>& board, 
            vector<vector<bool>> &visited,
            int i,
            int j) {
                return i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && 
                !visited[i][j];
            }
};// @lc code=end

