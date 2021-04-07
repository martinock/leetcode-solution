// Writer notes: not my solution
// Reference: https://www.geeksforgeeks.org/count-distinct-occurrences-as-a-subsequence/
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        if (m > n) {
            return 0;
        }
        
        // unsigned because the problem said it is guaranteed to fir 32-bit signed integer, but somehow it's not.
        unsigned int mat[m+1][n+1];
        
        for (int i = 0; i < m+1; i++) {
            mat[i][0] = 0;
        }
        
        for (int j = 0; j < n+1; j++) {
            mat[0][j] = 1;
        }
        
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if (t[i-1] != s[j-1]) {
                    mat[i][j] = mat[i][j-1];
                } else {
                    mat[i][j] = mat[i][j-1] + mat[i-1][j-1];
                }
            }
        }
        
        return mat[m][n];
    }
};