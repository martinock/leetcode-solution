// writer notes: my initial solution got TLE, this is the mathematic approach.
// Lesson learned: see the mathematical pattern first so we can reuse precomputed values.
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        
        long long int sum = 0, funcVal = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            funcVal += nums[i] * i;
        }
        
        int maxVal = funcVal;
        for (int i = 1; i < nums.size(); ++i) {
            funcVal = funcVal + sum - nums.size()*nums[nums.size()-i];
            if (maxVal < funcVal) {
                maxVal = funcVal;
            }
        }
        return maxVal;
    }
};