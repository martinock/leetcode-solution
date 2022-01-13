func partitionLabels(s string) []int {
	var result []int
	lastPos := make(map[string]int)
	for i, c := range s {
		lastPos[string(c)] = i
	}

	prevBiggestPartition := -1
	biggestPartition := lastPos[string(s[0])]
	for i := 0; i < len(s); i++ {
		// Assume the first char's last position is the high limit of the partition
		// If between 0-lastPosition has another char which last position > current partition, we need to enlarge the partition
		if i > biggestPartition || lastPos[string(s[i])] > biggestPartition {
			biggestPartition = lastPos[string(s[i])]
		}

		if i == biggestPartition {
			result = append(result, i-prevBiggestPartition)
			prevBiggestPartition = biggestPartition
			continue
		}
	}

	return result
}