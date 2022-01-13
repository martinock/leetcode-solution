func wordPattern(pattern string, s string) bool {
	splitted := strings.Split(s, " ")
	dictionary := make(map[string]string)
	reverseDict := make(map[string]string)

	// Edge case: len can be different
	if len(pattern) != len(splitted) {
		return false
	}

	for i, c := range pattern {
		char := string(c)
		word, ok := dictionary[char]
		// Edge case: abba & dog dog dog dog. We also need to check the words, not just the pattern
		storedChar, ok2 := reverseDict[splitted[i]]
		if (ok && word != splitted[i]) || (ok2 && storedChar != char) {
			return false
		} else {
			dictionary[char] = splitted[i]
			reverseDict[splitted[i]] = char
		}
	}

	return true
}