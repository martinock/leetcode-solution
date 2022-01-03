func majorityElement(nums []int) int {
	counter := make(map[int]int)

	for _, n := range nums {
		counter[n]++
	}

	max := 0
	maxElement := 0
	for k, v := range counter {
		if max < v {
			max = v
			maxElement = k
		}
	}

	return maxElement
}