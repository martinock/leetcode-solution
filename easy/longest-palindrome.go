// Idea: We don't care about how we construct the palindrome, so as long as there are symmetrical count of the same char it would be great.
// e.g: aabbcc = a:2 b:2 c:2
// Note that palindrome can also contain odd-count char but only once
// e.g: aabdbcc = a:2 b:2 c:2 d:1
func longestPalindrome(s string) int {
	charCount := make(map[string]int)

	for i := 0; i < len(s); i++ {
		charCount[string(s[i])]++
	}

	evenLength := 0
	oddLength := 0
	oddCount := 0
	for _, v := range charCount {
		if v%2 == 0 {
			evenLength += v
		} else {
			oddCount++         // to mark that we actually have odd character, we could add 1 in the end of calculation
			oddLength += v - 1 // just in case there 3 or more of the same char in odd numbers. We could utilize n-1 of it
		}
	}

	totalLength := evenLength + oddLength
	if oddCount > 0 {
		totalLength++
	}

	return totalLength
}