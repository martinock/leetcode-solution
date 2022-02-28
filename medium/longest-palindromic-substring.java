class Solution {
    public String longestPalindrome(String s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int start = 0;
        int maxLen = 0;
        
        for (int i = 0; i < s.length()-1; i++) {
            int lenOdd = getLongestPalindromeLengthFromMiddle(s, i, i);
            int lenEven = getLongestPalindromeLengthFromMiddle(s, i, i+1);
            int length = Math.max(lenOdd, lenEven);
            if (maxLen < length) {
                maxLen = length;
                start = i - (length+1)/2 + 1;
            }
        }
        
        return s.substring(start, start+maxLen);
    }
    
    private int getLongestPalindromeLengthFromMiddle(String s, int l, int h) {
        if (s.isEmpty() || l > h) {
            return 0;
        }
        
        while (l >= 0 && h < s.length() && s.charAt(l) == s.charAt(h)) {
            l--;
            h++;
        }
        
        return h-l-1;
    }
}