package main

import "fmt"

func ArrayToListNode(nums []int) *ListNode {
	h := &ListNode{}
	p := h
	for i := 0; i < len(nums); i++ {
		p.Next = &ListNode{Val: nums[i]}
		p = p.Next
	}
	return h.Next
}

func PrintListNode(list *ListNode) {
	fmt.Print("[")
	p := list
	for ; p != nil; p = p.Next {
		fmt.Printf(" %d,", p.Val)
	}
	fmt.Print("]")
}
