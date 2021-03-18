class Solution {
public:
    map<string,int> mem;
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        } 
        string key = "" + to_string(m) + "," + to_string(n);
        if (mem.find(key) != mem.end()) {
            return mem[key];
        }
        
        int first = uniquePaths(m-1, n);
        int second = uniquePaths(m, n-1);
        string firstKey = "" + to_string(m-1) + "," + to_string(n);
        string secondKey = "" + to_string(m) + "," + to_string(n-1);
        mem[firstKey] = first;
        mem[secondKey] = second;
        return first + second;
    }
};