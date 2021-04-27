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
    int max;
    int longestZigZag(TreeNode* root) {
        max = 0;
        
        zigZagMove(root, false);
        zigZagMove(root, true);
        
        return max;
    }
    
    int zigZagMove(TreeNode* root, bool isNextLeft) {
        if (root == NULL) {
            return -1;
        }
        if (root->left == NULL && root->right == NULL) {
            return 0;
        }
        
        int left = zigZagMove(root->left, true);
        int right = zigZagMove(root->right, false);
        max = std::max(max, 1 + std::max(left, right));
        if (isNextLeft) {
            return 1 + right;
        } 
        return 1 + left;
    }
};