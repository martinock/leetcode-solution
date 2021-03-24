class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,bool> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = true;
        }
        int smallest = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == smallest) {
                smallest++;
                while (m[smallest]) {
                    smallest++;
                }
            }
        }
        
        return smallest;
    }
};