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
    int maxHeight = 0;
    int deepestLeavesSum(TreeNode* root) {
        maxHeight = getHeight(root);            
        return sum(root, 1);
    }
    
    int sum(TreeNode* root, int depth) {
        if (root == NULL) {
            return 0;
        }
        
        if (depth == maxHeight) {
            return root->val;
        }
        
        return sum(root->left, depth+1) + sum(root->right, depth+1);
    }
    
    int getHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int left = 1 + getHeight(root->left);
        int right = 1 + getHeight(root->right);
        if (left >= right) {
            return left;
        } else {
            return right;
        }
    }
};