package medium

// ListNode definition for singly-linked list
type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 * addTwoNumbers adding two list of 1-digit integers. Numbers are reversed in list (e.g. 123 = 3 -> 2 -> 1)
 * Problems: https://leetcode.com/problems/add-two-numbers/submissions/
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	// isMoreThanTen storage for additional 1 to next digit
	isMoreThanTen := false
	result := l1

	// linked list iterators
	cur1 := l1
	cur2 := l2
	curRes := result

	for {
		// The iterators are reach last digit
		if cur1 == nil && cur2 == nil {
			break
		}

		// Edge case: If len(list1) < len(list2)
		if cur1 == nil {
			curRes.Val = cur2.Val
		} else if cur2 == nil { // Edge case: If len(list1) > len(list2)
			curRes.Val = cur1.Val
		} else {
			curRes.Val = cur1.Val + cur2.Val
		}

		// handling if sum of digits >= 10
		if isMoreThanTen {
			curRes.Val++
		}
		isMoreThanTen = curRes.Val >= 10
		curRes.Val = curRes.Val % 10

		// Edge case: if len(list1) < len(list2)
		if cur1 != nil {
			cur1 = cur1.Next
		}
		// Edge case: if len(list1) > len(list2)
		if cur2 != nil {
			cur2 = cur2.Next
		}

		// Edge case: if sum of two numbers need more additional digit (e.g. 5 + 5 = 10)
		if cur1 == nil && cur2 == nil && isMoreThanTen {
			curRes.Next = &ListNode{
				Val:  1,
				Next: nil,
			}
		}

		// FIXME: might not need this, since result is iterated based on list1, we need this checking
		if cur1 == nil && cur2 != nil {
			curRes.Next = &ListNode{
				Val:  cur2.Val,
				Next: nil,
			}
		}
		curRes = curRes.Next
	}
	return result
}
