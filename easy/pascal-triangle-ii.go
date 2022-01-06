var dp = make(map[int][]int)

func getRow(rowIndex int) []int {
	// base
	if rowIndex == 0 {
		return []int{1}
	} else if rowIndex == 1 {
		return []int{1, 1}
	}

	// Dynamic Programming, reuse stored value in map
	if res, ok := dp[rowIndex]; ok {
		return res
	}

	// Calculate if not exists
	prev := getRow(rowIndex - 1)
	result := []int{1}
	for i := 0; i < len(prev)-1; i++ {
		result = append(result, prev[i]+prev[i+1])
	}
	result = append(result, 1)
	dp[rowIndex] = result
	return result
}