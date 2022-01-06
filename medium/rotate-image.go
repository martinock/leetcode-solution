func rotate(matrix [][]int) {
	// init result
	result := make([][]int, len(matrix))
	for i := 0; i < len(result); i++ {
		result[i] = make([]int, len(matrix))
	}

	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix); j++ {
			// Pattern: y->x and x->y but start from behind, just like the rotation formula in math x,y -> y,-x
			// 0,0 -> 0,2
			// 0,1 -> 1,2
			// 0,2 -> 2,2
			// 1,0 -> 0,1
			// 1,1 -> 1,1
			// 1,2 -> 2,1
			// 2,0 -> 0,0
			// 2,1 -> 1,0
			// 2,2 -> 2,0
			newI := len(matrix) - 1 - i
			result[j][newI] = matrix[i][j]
		}
	}

	// Writer's note: deep copy because matrix = result not working
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix); j++ {
			matrix[i][j] = result[i][j]
		}
	}
}