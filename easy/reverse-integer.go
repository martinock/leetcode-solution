package easy

import "math"

// Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]
// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

func reverse(x int) int {
	result := 0
	for {
		result += x % 10
		x /= 10
		if x != 0 {
			result *= 10
		} else {
			break
		}
	}
	if result > int(math.Pow(2, 31)-1) || result < int(math.Pow(-2, 31)) {
		return 0
	}
	return result
}
