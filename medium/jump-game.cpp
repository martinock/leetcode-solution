// Writer note: not my solution
func canJump(nums []int) bool {
    total := len(nums)
    
    if total <= 1 {
        return true
    }
    
    if nums[0] == 0 {
        return false
    }

    target := total - 1

    for i := target - 1; i >= 0; i-- {
        if nums[i]+i >= target {
            target = i
        }
    }

    return target <= 1
}