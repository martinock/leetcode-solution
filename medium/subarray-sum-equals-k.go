func subarraySum(nums []int, k int) int {
	totalCache := make([]int, len(nums))
	total := 0
	for i, v := range nums {
		total += v
		totalCache[i] = total
	}

	count := 0
	countMap := make(map[int]int) // map of sum to count
	countMap[0] = 1               // initial condition: means that there exists sum in totalCache that already == k
	for _, tc := range totalCache {
		if v, ok := countMap[tc-k]; ok {
			count += v
		}
		countMap[tc]++
	}

	return count
}