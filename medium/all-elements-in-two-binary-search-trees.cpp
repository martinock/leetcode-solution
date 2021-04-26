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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1 = getVector(root1);
        vector<int> v2 = getVector(root2);
        
        vector<int> result;
        int i = 0, j = 0;
        while(i < v1.size() || j < v2.size()) {
            if (i == v1.size()) {
                result.push_back(v2[j]);
                j++;
                continue;
            }
            
            if (j == v2.size()) {
                result.push_back(v1[i]);
                i++;
                continue;
            }
            
            if (v1[i] <= v2[j]) {
                result.push_back(v1[i]);
                i++;
            } else {
                result.push_back(v2[j]);
                j++;
            }
        }
        
        return result;
    }
    
    vector<int> getVector(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        
        vector<int> left = getVector(root->left);
        vector<int> right = getVector(root->right);
        
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(root->val);
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }
};