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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        
        return isBalanced(root->left) && isBalanced(root->right) && abs(calculateHeight(root->left)-calculateHeight(root->right)) <= 1;
    }
    
    int calculateHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int hLeft = calculateHeight(root->left) + 1;
        int hRight = calculateHeight(root->right) + 1;
        
        if (hLeft >= hRight) {
            return hLeft;
        } else {
            return hRight;
        }
    }
};