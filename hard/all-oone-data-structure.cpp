class AllOne {
public:
    
    
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        m[key]++;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        m[key]--;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        map<string, int>::iterator it;
        int max = 0;
        string key = "";
        for (it = m.begin(); it != m.end(); it++) {
            if (it->second > 0 && it->second > max) {
                key = it->first;
                max = it->second;
            }
        }
        
        return key;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        map<string, int>::iterator it;
        int min = 0;
        string key = "";
        for (it = m.begin(); it != m.end(); it++) {
            if (it->second > 0 && (it->second < min || min == 0)) {
                key = it->first;
                min = it->second;
            }
        }
        
        return key;
    }
    
    private:
        map<string, int> m;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */