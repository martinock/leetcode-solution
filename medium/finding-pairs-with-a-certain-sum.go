type FindSumPairs struct {
	Nums1 []int
	Nums2 []int
	// Map to track count of values in Nums2
	// Example Nums2 = [2,3,5,1,2,6,1,1,7]
	// N2Count = {
	// 	1: 3,
	// 	2: 2,
	// 	3: 1,
	// 	5: 1,
	// 	6: 1,
	// 	6: 1
	// }
	N2Count map[int]int
}

func Constructor(nums1 []int, nums2 []int) FindSumPairs {
	n2c := make(map[int]int)
	for _, v := range nums2 {
		n2c[v]++
	}

	return FindSumPairs{
		Nums1:   nums1,
		Nums2:   nums2,
		N2Count: n2c,
	}
}

func (this *FindSumPairs) Add(index int, val int) {
	if index < 0 || index >= len(this.Nums2) {
		return
	}

	currVal := this.Nums2[index]
	this.Nums2[index] += val
	this.N2Count[currVal]--
	this.N2Count[this.Nums2[index]]++
}

func (this *FindSumPairs) Count(tot int) int {
	count := 0
	// since nums 1 will never change and by the constraints of the problems, it is told that len(nums1) way less than len(nums2),
	// we will use it as a base of iteration
	for _, v := range this.Nums1 {
		// a simple math technique: a + b = total -> b = total - a
		// since we track the count of each element in nums2, getting b values is a lot faster than brute force
		possibleNumber := tot - v
		count += this.N2Count[possibleNumber]
	}

	return count
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * obj := Constructor(nums1, nums2);
 * obj.Add(index,val);
 * param_2 := obj.Count(tot);
 */