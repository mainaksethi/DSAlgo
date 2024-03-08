struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int val): val(val), left(NULL), right(NULL) {};
    Node(int val, Node* left): val(val), left(left), right(NULL) {};
    Node(int val, Node* left, Node *right): val(val), left(left), right(right) {};
}

class BinarySearchTree {

    Node* root;

    // O(log(n))
    void insert(int val) {
        insert(val, root);
    }

    // Recursive Insertion
    // O(log(n))
    void insert(int val, Node* node) {
        if (root == NULL) {
            return Node(val);
        }
        int rootVal = root->val;
        if (rootVal < val) {
            root->right = insert(val, root->right);
        } else {
            root->left = insert(val, root->left);
        }
    }

    // Recursive search
    // O(log(n))
    Node* search(int val) {
        if (root == NULL || root->val == val) {
            return root;
        }
        if (root->val < val) {
            search(val, root->right);
        } else {
            search(val, root->left);
        }
    }

    // Recursive deletion
    // Simply promote the node in case left is null or right is null.
    // Below is pretty complex. 
    // In scenario, where both child exists, 
    // make the successor value as the node value and do adjustments.  
    // 1. Case 1: 
    //     If right child has no left child, the simply make right->right as right and promote right node value to root.
    //  2. Case 2: 
    //     If right child has left subtree then find the left-most node and promote its value to root. Replace left most node with 
    //     its right child.
    // O(log(n))
    void delete(int val, Node *root) {
        if (root->val < val) {
            root->right = delete(val, root->right);
            return root;
        } else if (root->val > val) {
            root->left = delete(val, root->left);
            return root;
        } else {
            if (root->right == NULL) {
                Node *temp = root->left;
                delete root;
                return temp;
            } else if (root->left == NULL) {
                Node *temp = root->right;
                delete root;
                return temp;
            } else {
                Node *succParent = root;
                Node *succ = root->right;
                while(succ->left != NULL) {
                    succParent = succ;
                    succ = succ->left;
                }
                if (succParent != root) {
                    succParent->left = succ->right;
                } else {
                    succParent->right = succ->right;
                }
                root->val = succ->val;
                delete succ;
                return root;
            }
        }
        return root;
    }

    // Left most node of right subtree
    Node* successor(Node *root) {
        if (root->right == NULL) {
            return NULL;
        }
        Node *succ = root->right;
        while(succ->left != NULL) {
            succ = succ->left;
        }
        return succ;
    }

    // Right most node of left subtree
    Node* predecessor(Node *root) {
        if (root->left == NULL) {
            return NULL;
        }
        Node *pred = root->left;
        while(pred->right != NULL) {
            pred = pred->right;
        }
        return pred;
    }

    // Simply do inorder traversal and do the balancing.
    Node* balanceBST(Node* root) {
        vector<int> v;
        inorder(root, v);
        return balancedBST(v, 0, v.size()-1);
    }

    void inorder(Node* root, vector<int> &v) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        return;
    }

    Node* balancedBST(vector<int> &v, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = start + (end-start)/2;
        Node* leftNode = balancedBST(v, start, mid-1);
        Node* rightNode = balancedBST(v, mid+1, end);
        Node* root = new Node(v[mid]);
        root->left = leftNode;
        root->right = rightNode;
        return root;
    }
}