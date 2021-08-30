/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var ans []string

func binaryTreePaths(root *TreeNode) []string {
	getPathString(root, "")
	return ans
}

func getPathString(root *TreeNode, path string) {
	if root == nil {
		return
	} else if root.Left == nil && root.Right == nil {
		newPath := path + strconv.Itoa(root.Val)
		ans = append(ans, newPath)
		return
	}
	newPath := path + strconv.Itoa(root.Val) + "->"
	getPathString(root.Left, newPath)
	getPathString(root.Right, newPath)
} 