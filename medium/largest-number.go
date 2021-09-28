func largestNumber(nums []int) string {
	if len(nums) == 1 {
		return strconv.FormatInt(int64(nums[0]), 10)
	}

	var newNums []string
	// convert to string
	for i := 0; i < len(nums); i++ {
		newNums = append(newNums, strconv.FormatInt(int64(nums[i]), 10))
	}

	// lexicographically sort with some criteria
	sort.Slice(newNums, func(i, j int) bool {
		if len(newNums[i]) == len(newNums[j]) {
			return newNums[i] > newNums[j]
		}
		temp1 := newNums[i] + newNums[j]
		temp2 := newNums[j] + newNums[i]

		return temp1 > temp2
	})

	result := strings.Join(newNums, "")
	result = strings.TrimLeft(result, "0")
	if result == "" {
		result = "0"
	}
	return result
}