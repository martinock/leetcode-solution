func productExceptSelf(nums []int) []int {
	answer := make([]int, len(nums))
	zeroIndex := -1
	totalProduct := nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i] == 0 {
			// if there are two zeros, means all product will be 0
			if zeroIndex > -1 {
				return answer
			}
			zeroIndex = i
			continue
		}
		totalProduct = totalProduct * nums[i]
	}

	if zeroIndex > -1 {
		answer[zeroIndex] = totalProduct
		return answer
	}

	// if no zero at all
	// edge case: if there's 0, divide by nums[i] will return error
	for i := 0; i < len(nums); i++ {
		answer[i] = totalProduct / nums[i]
	}

	return answer
}