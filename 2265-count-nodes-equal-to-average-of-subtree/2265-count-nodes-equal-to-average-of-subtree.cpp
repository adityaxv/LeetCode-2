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
    pair<int, int> tree(TreeNode* root, int& ans) {
        if (root == NULL) {
            return {0, 0};
        }
        pair<int, int> l = tree(root -> left, ans);
        pair<int, int> r = tree(root -> right, ans);
        int sum = (l.first + r.first + root -> val);
        int cnt = (l.second + r.second + 1);
        ans += ((sum / cnt) == (root -> val));
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        tree(root, ans);
        return ans;
    }
};
