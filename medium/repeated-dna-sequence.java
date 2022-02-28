class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        if (s.length() <= 10) {
            return new ArrayList<String>();
        }
        
        HashMap<String, Boolean> record = new HashMap<>();
        
        for (int i = 0; i <= s.length()-10; i++) {
            String sequence = s.substring(i, i+10);
            
            if (record.containsKey(sequence)) {
                record.put(sequence, true);
            } else {
                record.put(sequence, false);
            }
        }
        
        List<String> result = new ArrayList<>();
        
        for (Map.Entry<String, Boolean> kv: record.entrySet()) {
            if (kv.getValue()) {
                result.add(kv.getKey());
            }
        }
        
        return result;
    }
}