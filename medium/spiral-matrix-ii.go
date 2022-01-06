func generateMatrix(n int) [][]int {
	result := make([][]int, n)
	for i := 0; i < n; i++ {
		result[i] = make([]int, n)
	}

	current := 1
	for layer := 0; layer < (n+1)/2; layer++ {
		for right := layer; right < n-layer; right++ {
			result[layer][right] = current
			current++
		}

		for down := layer + 1; down < n-layer; down++ {
			result[down][n-layer-1] = current
			current++
		}

		for left := n - layer - 2; left >= layer; left-- {
			result[n-layer-1][left] = current
			current++
		}

		for up := n - layer - 2; up > layer; up-- {
			result[up][layer] = current
			current++
		}
	}

	return result
}