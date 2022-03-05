/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        
        traverse(root, result, 0);
        return result;
    }
    
    private void traverse(TreeNode node, List<List<Integer>> result, int level) {
        if (node == null) {
            return;
        }
        
        if (result.size() <= level) {
            List<Integer> res = new ArrayList<>();
            result.add(res);
        }
        
        List<Integer> collection = result.get(level);
        if (level % 2 == 0) {
            collection.add(node.val);
        } else {
            collection.add(0, node.val);
        }
        
        traverse(node.left, result, level+1);
        traverse(node.right, result, level+1);
    }
}