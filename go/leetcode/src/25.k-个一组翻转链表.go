package src

/*
 * @lc app=leetcode.cn id=25 lang=golang
 *
 * [25] K 个一组翻转链表
 */
// linked-list

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
	q := head
	h := &ListNode{}
	p2 := h
	for q != nil {
		p1 := q
		for p2.Next != nil {
			p2 = p2.Next
		}

		i := 0
		for ; i < k && q != nil; i++ {
			q = q.Next
		}
		if i != k && q == nil {
			p2.Next = p1
			break
		}
		for i := 0; i < k; i++ {
			p1, p1.Next, p2.Next = p1.Next, p2.Next, p1
		}
	}

	return h.Next
}

// @lc code=end
// func main() {
// 	list := ArrayToListNode([]int{1, 2, 3, 4, 5})
// 	PrintListNode(reverseKGroup(list, 3))
// }
