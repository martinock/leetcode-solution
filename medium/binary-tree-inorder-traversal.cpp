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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        
        vector<TreeNode*> stack;
        TreeNode* curr = root;
        while (!stack.empty() || curr != NULL) {
            while (curr != NULL) {
                stack.push_back(curr);
                curr = curr->left;
            }
            
            result.push_back(stack.back()->val);
            curr = stack.back()->right;
            stack.pop_back();
        }
        
        return result;
    }
};

// Easier solution (recursive)
// func inorder(root *TreeNode, arr []int) []int {
//     if root == nil {
//         return arr
//     }
//     arr =inorder(root.Left,arr)
//     arr = append(arr, root.Val)
//     arr =inorder(root.Right,arr)

//     return arr
// }