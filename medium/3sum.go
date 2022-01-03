// Writer's note: this solution still rated on 3-4s runtime. Which probably still open for improvements
func threeSum(nums []int) [][]int {
	var result [][]int
	numPosition := make(map[int]int)
	resElChecker := make(map[string]bool)

	for i := 0; i < len(nums)-1; i++ {
		for j := i + 1; j < len(nums); j++ {
			// nums1 + num2 + num3 = 0 <==> num3 = -num1 - num2
			target := (nums[i] * -1) - nums[j]
			// check idx is neither i nor j, to make sure we don't use the same number twice
			if idx, ok := numPosition[target]; ok && (idx != i) && (idx != j) {
				// result duplicate checker, since we can't put the same tuple over & over again
				resEl := []int{nums[i], nums[j], target}
				sort.Slice(resEl, func(i, j int) bool {
					return resEl[i] < resEl[j]
				})
				key := strconv.Itoa(resEl[0]) + strconv.Itoa(resEl[1]) + strconv.Itoa(resEl[2])
				if !resElChecker[key] {
					result = append(result, resEl)
					resElChecker[key] = true
				}
			}
			numPosition[nums[j]] = j
		}
		numPosition[nums[i]] = i
	}

	return result
}