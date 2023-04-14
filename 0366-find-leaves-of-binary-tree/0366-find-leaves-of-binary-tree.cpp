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
    TreeNode* tree(vector<int>& temp, TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        if (root -> left == NULL and root -> right == NULL) {
            temp.push_back(root -> val);
            return NULL;
        }
        root -> left = tree(temp, root -> left);
        root -> right = tree(temp, root -> right);
        return root;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<int> temp;
        vector<vector<int>> ans;
        while (root != NULL) {
            temp.clear();
            root = tree(temp, root);
            ans.push_back(temp);
        }
        return ans;
    }
};