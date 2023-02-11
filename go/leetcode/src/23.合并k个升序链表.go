package src

/*
 * @lc app=leetcode.cn id=23 lang=golang
 *
 * [23] 合并K个升序链表
 */
// heap

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type IntHeap struct {
	lists []*ListNode
}

func (h *IntHeap) Init() {
	h.lists = []*ListNode{}
}

func (h *IntHeap) Push(v *ListNode) {
	h.lists = append(h.lists, v)
	if len(h.lists) == 1 {
		return
	}
	i := len(h.lists) - 1
	for ; h.lists[(i-1)/2].Val > v.Val; i = (i - 1) / 2 {
		h.lists[i], h.lists[(i-1)/2] = h.lists[(i-1)/2], h.lists[i]
	}
}

func (h *IntHeap) Pop() *ListNode {
	if len(h.lists) == 0 {
		return nil
	}
	minVal := h.lists[0]
	h.lists[0] = h.lists[len(h.lists)-1]
	h.lists = h.lists[:len(h.lists)-1]
	for i := 0; i < len(h.lists)/2; {
		j := i*2 + 1
		if j+1 < len(h.lists) && h.lists[j].Val > h.lists[j+1].Val {
			j = j + 1
		}
		if h.lists[j].Val > h.lists[i].Val {
			break
		}
		h.lists[i], h.lists[j] = h.lists[j], h.lists[i]
		i = j
	}
	return minVal
}

func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	} else if len(lists) == 1 {
		return lists[0]
	}

	h := &IntHeap{}
	h.Init()
	for i := 0; i < len(lists); i++ {
		for p := lists[i]; p != nil; p = p.Next {
			h.Push(p)
		}
	}
	l := &ListNode{}
	q := l
	for p := h.Pop(); p != nil; p = h.Pop() {
		q.Next = p
		q = q.Next
	}
	q.Next = nil
	return l.Next
}

// type ptrHeap []*ListNode

// func (h ptrHeap) Len() int {
// 	return len(h)
// }

// func (h ptrHeap) Less(i, j int) bool {
// 	return h[i].Val < h[j].Val
// }

// func (h ptrHeap) Swap(i, j int) {
// 	h[i], h[j] = h[j], h[i]
// }

// func (h *ptrHeap) Push(x interface{}) {
// 	*h = append(*h, x.(*ListNode))
// }

// func (h *ptrHeap) Pop() interface{} {
// 	res := (*h)[len(*h)-1]
// 	*h = (*h)[:len(*h)-1]
// 	return res
// }

// func mergeKLists(lists []*ListNode) *ListNode {
// 	ans := &ListNode{}
// 	hp := &ptrHeap{}
// 	length := 0
// 	for i := 0; i < len(lists); i++ {
// 		if lists[i] == nil {
// 			continue
// 		}
// 		*hp = append(*hp, lists[i])
// 		length++
// 	}
// 	heap.Init(hp)
// 	for p := ans; length != 0; p = p.Next {
// 		p.Next = (*hp)[0]
// 		ptr := (*hp)[0].Next
// 		if ptr != nil {
// 			(*hp)[0] = ptr
// 			heap.Fix(hp, 0)
// 		} else {
// 			heap.Remove(hp, 0)
// 			length--
// 		}
// 	}
// 	return ans.Next
// }

// @lc code=end
