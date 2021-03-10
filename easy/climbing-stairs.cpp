class Solution {
public:
    map<int, int> m;
    
    int climbStairs(int n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 1;
        } else if (m.find(n) != m.end()) {
            return m[n];
        } else {
           int x = climbStairs(n-1) + climbStairs(n-2);
           m[n] = x;
           return x;
        }
    }
};