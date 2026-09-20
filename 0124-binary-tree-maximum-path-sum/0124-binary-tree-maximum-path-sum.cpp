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
    int maxSum(TreeNode* root, int& ans) {
        if(root == NULL) {
            return 0;
        }

        int leftSum = max(0, maxSum(root->left, ans));  // So we treat the negative contribution as 0.
        int rightSum = max(0, maxSum(root->right, ans));

        int currentSum = root->val + leftSum + rightSum;

        ans = max(ans, currentSum);

        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;  // For single or multiple negative nodes where we choose maximum one of negative nodes

        maxSum(root, ans);

        return ans;
    }
};

// Time  : O(n)
// Space : O(h)