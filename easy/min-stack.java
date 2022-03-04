class MinStack {
    
    private int minValueIndex;
    private List<Integer> store;

    public MinStack() {
        minValueIndex = -1;
        store = new ArrayList<>();
    }
    
    public void push(int val) {
        store.add(val);
        if (minValueIndex == -1 || val < getMin()) {
            minValueIndex = store.size()-1;
        }
    }
    
    public void pop() {
        store.remove(store.size()-1);
        
        if (store.size() == 0) {
            minValueIndex = -1;
        } else if (minValueIndex >= store.size()) {
            int min = store.get(0);
            minValueIndex = 0;
            for (int i = 1; i < store.size(); i++) {
                if (store.get(i) < min) {
                    min = store.get(i);
                    minValueIndex = i;
                }
            }
        }
    }
    
    public int top() {
        return store.get(store.size()-1);
    }
    
    public int getMin() {
        return store.get(minValueIndex);
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */