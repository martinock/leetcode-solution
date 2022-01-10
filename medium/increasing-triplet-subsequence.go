func increasingTriplet(nums []int) bool {
	smallIdx := 0
	midIdx := 0
	for i := 0; i < len(nums); i++ {
		current := nums[i]
		if current <= nums[smallIdx] {
			smallIdx = i
		} else if midIdx == 0 || current <= nums[midIdx] {
			midIdx = i
		} else {
			return true
		}
	}

	return false
}