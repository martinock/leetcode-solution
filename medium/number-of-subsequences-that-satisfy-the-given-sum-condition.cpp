// Writer notes: I gave up with the overflow issue and see other solution for the overflow
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int m = 1e9+7;
        vector<int> powi(nums.size()+1,0);
        powi[0] = 1;
        for(int i=1;i<=nums.size();i++){
            powi[i] = (2*powi[i-1])%m; // to prevent overflow
        }
        sort(nums.begin(), nums.end());
        long long count = 0;
        int i = 0, j = nums.size()-1;
        while(i <= j) {
            if (nums[i]+nums[j] <= target) {
                count = (count%m + powi[j-i]%m)%m; // to prevent overflow
                i++;
            } else {
                j--;
            }
        }
        return count % m;
    }
};
