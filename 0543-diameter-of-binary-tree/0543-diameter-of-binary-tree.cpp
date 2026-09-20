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
    int checkHeight(TreeNode* root, int& ans) {
        if(root == NULL) {
            return 0;
        }

        int leftHeight = checkHeight(root->left, ans);
        int rightHeight = checkHeight(root->right, ans);

        ans = max(ans, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;

        checkHeight(root, ans);

        return ans;
    }
};
// Time: O(n)
// Space: O(h) recursion stack.