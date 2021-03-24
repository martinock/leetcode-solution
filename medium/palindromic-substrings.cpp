class Solution {
public:
    map<string, bool> m;
    int countSubstrings(string s) {
        if (s.length() == 0) {
            return 0;
        }
        
        if (s.length() == 1) {
            return 1;
        }
        
        int count = 0;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; (j + i) <= s.length(); ++j) {
                if (isPalindrome(s.substr(j, i))) {
                   count++; 
                }
            }
        }
        return count;
    }
    
    bool isPalindrome(string s) {
        if (m.find(s) != m.end()) {
            return m[s];
        }
        
        if (s.length() == 1) {
            m[s] = true;
            return true;
        }
        
        int i = 0;
        int j = s.length()-1;
        
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

// BETTER SOLUTION: no need to loop the palindrome
// class Solution {
//  public:
//     int countSubstrings(string s) {
//         int n = s.size(), ans = 0;

//         if (n <= 0)
//             return 0;

//         bool dp[n][n];
//         fill_n(*dp, n * n, false);

//         // Base case: single letter substrings
//         for (int i = 0; i < n; ++i, ++ans)
//             dp[i][i] = true;

//         // Base case: double letter substrings
//         for (int i = 0; i < n - 1; ++i) {
//             dp[i][i + 1] = (s[i] == s[i + 1]);
//             ans += dp[i][i + 1];
//         }

//         // All other cases: substrings of length 3 to n
//         for (int len = 3; len <= n; ++len)
//             for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
//                 dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
//                 ans += dp[i][j];
//             }

//         return ans;
//     }
// };