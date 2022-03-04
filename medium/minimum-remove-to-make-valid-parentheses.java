class Solution {
    public String minRemoveToMakeValid(String s) {
        Stack<Integer> st = new Stack<>();
        int countValidPair = 0;
        for (int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            switch (c) {
                case '(':
                    st.push(i);
                    break;
                case ')':
                    if (!st.isEmpty() && s.charAt(st.peek()) == '(') {
                        st.pop();
                        countValidPair++;
                        continue;
                    }
                    st.push(i);
                    break;
                default:
                    // do nothing
            }
        }
        
        // if contains no parentheses at all
        if (st.isEmpty() && countValidPair == 0) {
            return s;
        }
        
        StringBuilder sb = new StringBuilder(s);
        
        // means the parenthesis already valid, remove 1 pair of parentheses
        if (st.isEmpty()) {
            boolean isLeftDeleted = false;
            boolean isRightDeleted = false;
            int i = 0;
            while (!isLeftDeleted || !isRightDeleted) {
                if (sb.charAt(i) == '(' && !isLeftDeleted) {
                    sb.deleteCharAt(i);
                    isLeftDeleted = true;
                } else if (sb.charAt(i) == ')' && !isRightDeleted) {
                    sb.deleteCharAt(i);
                    isRightDeleted = true;
                }
                i++;
            }
        }
        
        while (!st.isEmpty()) {
            sb.deleteCharAt(st.pop());
        }
        
        return sb.toString();
    }
}