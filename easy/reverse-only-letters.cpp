class Solution {
public:
    string reverseOnlyLetters(string S) {
        string result;
        int j = S.length()-1;
        for (int i = 0; i < S.length(); ++i) {
            if (j < 0) {
                result += S[i];
                continue;
            }
            if ((S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122)) {
                while (!((S[j] >= 65 && S[j] <= 90) || (S[j] >= 97 && S[j] <= 122))) {
                    j--;
                }
                result += S[j];
                j--;
            } else {
                result += S[i];
                if (!((S[j] >= 65 && S[j] <= 90) || (S[j] >= 97 && S[j] <= 122))) {
                    j--;
                }
            }
        }
        return result;
    }
};