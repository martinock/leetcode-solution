package easy

// twoSum search two numbers in array that sums is equal to target, then return the indices
// e.g. nums = [2, 7, 11, 15]; target = 9
// nums[0] + nums[1] = 2 + 7 = 9 -> return [0, 1]
// Problems: https://leetcode.com/problems/two-sum/
func twoSum(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}

	// default case that is mandatory in Golang
	return []int{}
}
