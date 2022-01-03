func singleNumber(nums []int) int {
	checker := make(map[int]bool)

	for _, n := range nums {
		if v, ok := checker[n]; !ok {
			checker[n] = false
		} else if v == false {
			checker[n] = true
		}
	}

	for n, v := range checker {
		if v == false {
			return n
		}
	}

	// default return for golang to compile
	return 0
}

// WRITER NOTES: Breakthrough solution - use XOR
// class Solution {
// 	public:
// 	int singleNumber(vector& nums) {
// 		int d=nums.size();
// 		int m=0;

// 		// XOR return 1 if and only the bit is different,
// 		// hence same number will cancel each other (return 0) and the only unique number will be XOR-ed with that 0
// 		for(int i=0;i<d;i++) {
// 			m=m^nums[i];
// 		}
// 		return m;
// 	}
// };