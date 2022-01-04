func merge(intervals [][]int) [][]int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	result := [][]int{}

	i := 0
	for i < len(intervals) {
		// Writer's notes -- Edge cases:
		// 1. [[0,5],[2,3]] -- upper interval of next element doesn't always higher. Use math.Max()
		// 2. [[1,4],[0,2],[3,5]] --> should keep merge until [[0,5]]. Instead of appending to array immediately, we replace the last element with temp result.
		if i < len(intervals)-1 && intervals[i][1] >= intervals[i+1][0] {
			mergeResult := []int{intervals[i][0], int(math.Max(float64(intervals[i][1]), float64(intervals[i+1][1])))}
			intervals[i+1] = mergeResult
		} else {
			result = append(result, intervals[i])
		}
		i++
	}

	return result
}