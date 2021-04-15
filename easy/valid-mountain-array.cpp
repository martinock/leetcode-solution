class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() == 1) {
            return false;
        }
        
        if (arr[0] >= arr[1]) {
            return false;
        }
        
        bool isUp = true;
        for (int i = 1; i < arr.size()-1; ++i) {
            if (arr[i] == arr[i+1]) {
                return false;
            }
            
            if (isUp && arr[i] > arr[i+1]) {
                isUp = false;
            } else if (!isUp && arr[i] < arr[i+1]) {
                return false;
            }
        }
        
        return !isUp;
    }
};
