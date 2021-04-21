class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int count = 0;
        while (num) {
            int bit = !(num & 1);
            bit <<= count;
            result += bit;
            num >>= 1;
            count++;
        }
        return result;
    }
};
