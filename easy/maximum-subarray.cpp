class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int currentSum = nums[0];
        int max = currentSum;
        for (int i = 1; i < nums.size(); ++i) {
            currentSum += nums[i];
            
            if (currentSum < nums[i]) {
                currentSum = nums[i];
            }
            
             if (currentSum > max) {
                max = currentSum;
            }
        }
        
        return max;
    }
};