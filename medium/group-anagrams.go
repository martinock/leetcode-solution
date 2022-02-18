func groupAnagrams(strs []string) [][]string {
	sortedStrs := make([]string, len(strs))
	for i, v := range strs {
		charV := []rune(v)
		sort.Slice(charV, func(i, j int) bool {
			return charV[i] < charV[j]
		})
		sortedStrs[i] = string(charV)
	}

	cache := make(map[string][]int)
	result := [][]string{}

	for i, v := range sortedStrs {
		if idx, ok := cache[v]; !ok {
			cache[v] = []int{i}
		} else {
			cache[v] = append(idx, i)
		}
	}

	for _, v := range cache {
		el := []string{}
		for _, idx := range v {
			el = append(el, strs[idx])
		}

		result = append(result, el)
	}

	return result
}