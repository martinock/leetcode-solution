class Solution {
    public int findTheWinner(int n, int k) {
        Queue<Integer> q = new LinkedList<>();
        
        for (int i = 1; i <= n; i++) {
            q.add(i);
        }
        
        int counter = 1;
        while (q.size() > 1) {
            if (counter != k) {
                q.add(q.remove());
                counter++;
            } else {
                q.remove();
                counter = 1;
            }
        }
        
        return q.remove();
    }
}