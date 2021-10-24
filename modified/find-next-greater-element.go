func findNextGreaterElement(arr []int) (result []int) {
    result = make([]int, len(arr))

	// results is initialized with -1, so if no bigger elements found, it will have a correct value already. 
	// And we don't need to handle anything.
    for int i = 0; i < len(arr); i++ {
        result[i] = -1
    }

	// since the position and the value of each elements matter (not just simply the highest value),
	// we need to introduce priority for each iteration we do. Thus the priority is exactly matcch with stack's LIFO traits
    var stack []int

	// iterating from right to left help us to understand the stack better, since we store the values
	// if we iterate from left to right, we will need to store index. CMIIW - if there're better solutions
    for int i = len(arr)-1; i >= 0; i-- {

		// during iteration we will always
		// 1. pop the stack until the stack top values is bigger than current element OR the stack is empty
        for len(stack) > 0 {
            if stack[len(stack)-1] <= arr[i] {
                stack = stack[:len(stack)-1]
            } else {
                result[i] = stack(len(stack)-1)
                break
            }
        }

		// 2. push the current element to stack
        stack = append(stack, arr[i])
    }

    return result;
}
