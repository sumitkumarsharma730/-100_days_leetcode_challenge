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
    int maxSum(TreeNode* root, int& sum){
        if(root == NULL){
            return 0;
        }
        int leftSum = maxSum(root -> left, sum);
        int rightSum = maxSum(root -> right, sum);

        int value = root -> val;

        sum = max(sum, value);

        sum = max(sum, leftSum + value);  

        sum = max(sum, value + rightSum);   

        sum = max(sum, leftSum + value + rightSum);

        return max(value + max(leftSum, rightSum), value);
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxSum(root, sum);
        return sum;
    }
};