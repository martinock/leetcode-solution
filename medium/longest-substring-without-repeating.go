package medium

// lengthOfLongestSubstring find the longest substring without duplicate
// Problems: https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Writer note:
// I almost make my code a sliding window as the solution suggested, but turns out I overthink the "dvdf" case
// Initially, my code didn't pass this test case, because I assign i = index of found duplicate char on the second loop (in "dvdf", I put i = 2)
// Because of this, my code return 2, which should be 3. At this point, I thought that I should put the i = index of duplicated char's neighbour
// Yeah, it's complicated that I can't even put the correct sentence to explain that.
// Example: "abca" I put i = index of b, because b is the neighbour of duplicated char (the first a).
func lengthOfLongestSubstring(s string) int {
	// Edge case: Empty String
	if len(s) == 0 {
		return 0
	}

	// map of char to it's position
	m := make(map[byte]int)
	length := 1
	tempCount := 0
	i := 0
	j := 0
	for i < len(s)-1 && j < len(s) {
		m[s[i]] = i
		tempCount++
		j = i + 1

		// Check the longest substring, expand [i,j] window
		for j < len(s) {
			// Check duplicate characters
			if _, ok := m[s[j]]; !ok {
				tempCount++
				if tempCount > length {
					length = tempCount
				}
				m[s[j]] = j // We take notes that current char is unique so far
			} else {
				// See writer note for this part, maybe it could help you
				i = m[s[j]] + 1

				// Since we need found a duplicate, let's forgot everything we remember
				// Because there might be another longer substring which characters are already there beforehand
				m = make(map[byte]int)

				// reset the temporary counter
				tempCount = 0
				break
			}
			j++
		}
	}

	return length
}
