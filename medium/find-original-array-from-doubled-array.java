class Solution {
    public int[] findOriginalArray(int[] changed) {
        if (changed.length % 2 != 0) {
            return new int[0];
        } 
        
        int[] result = new int[changed.length/2];
        int resultIdx = 0;
        
        Arrays.sort(changed);
        HashMap<Integer, Integer> valCounter = new HashMap<Integer, Integer>();
        for (int i = 0; i < changed.length; i++) {
            if (valCounter.containsKey(changed[i])) {
                valCounter.put(changed[i], valCounter.get(changed[i])+1);
            } else {
                valCounter.put(changed[i], 1);
            }
        }
        
        for (int i = 0; i < changed.length; i++) {
            int curr = changed[i];
            int pair = curr * 2;
            
            // Means the element already "deleted"
            if (valCounter.get(curr) == 0) {
                continue;
            }
            
            valCounter.put(curr, valCounter.get(curr)-1);
            
            if (valCounter.containsKey(pair) && valCounter.get(pair) > 0) {
                valCounter.put(pair, valCounter.get(pair)-1);
                result[resultIdx] = curr;
                resultIdx++;
            } else {
                return new int[0];
            }
        }
        
        return result;
    }
}