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
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        TreeNode* left = root->left;
        flatten(left);
        root->left = NULL;
        TreeNode* right = root->right;
        flatten(right);
        
        TreeNode* combined = combineTree(left, right);
        root->right = combined;
    }
    
    TreeNode* combineTree(TreeNode* left, TreeNode* right) {
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        
        TreeNode* curr = left;
        while (curr->right != NULL) {
            curr = curr->right;
        }
        curr->right = right;
        
        return left;
    }
};
