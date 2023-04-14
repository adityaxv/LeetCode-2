/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void tree(TreeNode* root, int k, priority_queue<int, vector<int>, greater<int>>& pq) {
        if (root == NULL) {
            return;
        }
        if (root -> left) tree(root -> left, k, pq);
        if (root -> right) tree(root -> right, k, pq);
        pq.push(root -> val);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        tree(root, k, pq);
        k--;
        while (k--) {
            pq.pop();
        }
        return pq.top();
    }
};