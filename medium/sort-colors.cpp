class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> dp;
        for (int i = 0; i < nums.size(); i++) {
            dp[nums[i]]++;
        }
        
        cout << dp[0] << " " << dp[1] << " " << dp[2] << "\n";
        
        int k = 0; 
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j < dp[i]; j++) {
                nums[k] = i;
                k++;
            }
        }
    }
};