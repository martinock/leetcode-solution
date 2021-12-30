func numberOfWeakCharacters(properties [][]int) int {
	sort.Slice(properties, func(i, j int) bool {
		if properties[i][0] == properties[j][0] {
			return properties[i][1] > properties[j][1]
		}
		return properties[i][0] < properties[j][0]
	})

	countWeak := 0
	// basic solution. TLE
	//     for i := 0; i < len(properties)-1; i++ {
	//         for j := i+1; j < len(properties); j++ {
	//             if properties[i][0] == properties[j][0] {
	//                 continue
	//             }

	//             if properties[i][1] < properties[j][1] {
	//                 countWeak++
	//                 break
	//             }
	//         }
	//     }

	tempHighestDef := -1
	for i := len(properties) - 1; i >= 0; i-- {
		char := properties[i]
		if char[1] < tempHighestDef {
			countWeak++
		} else {
			tempHighestDef = char[1]
		}
	}

	return countWeak
}