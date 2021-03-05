class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0]) {
            return 0;
        }
        if (target > nums[nums.size()-1]) {
            return nums.size();
        }
        
        int left = 0;
        int right = nums.size()-1;
        int pivot = nums.size()/2;
        int pivotDistance = pivot;
        
        while (pivotDistance > 0) {
            if (target == nums[pivot]) {
                return pivot;
            }
            
            if (target > nums[pivot]) {
                left = pivot;
                pivotDistance = (right-pivot)/2;
                pivot = pivot + pivotDistance;
            } else {
                right = pivot;
                pivotDistance = (pivot-left)/2;
                pivot = pivot - pivotDistance;
            }
        }
        
        if (target > nums[left] && target <= nums[right]) {
            return right;
        }
        
        return pivot;
    }
};


// BETTER SOLUTION:
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int left = 0 ;
//         int right = nums.size()-1 ;
//         int mid ;
        
//         while (left <= right) {
//             mid = (left+right)/2 ;
//             if(nums[mid] == target) {
//                 return mid ;
//             } else if(nums[mid] > target) {
//                 right = mid-1;
//             } else {
//                 left = mid+1;
//             }
            
//         }

//         if(nums[mid] < target) {
//             mid++;
//         } 
//         return mid;
//     }
    
// };