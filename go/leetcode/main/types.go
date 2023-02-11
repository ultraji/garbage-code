package main

type ListNode struct {
	Val  int       // value
	Next *ListNode // next
}

// intHeap
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

// queue
type Element interface{}

type Queue struct {
	sli []Element
}

func NewQueue() *Queue {
	return &Queue{}
}

func (q *Queue) Size() int {
	return len(q.sli)
}

func (q *Queue) Push(e Element) {
	q.sli = append(q.sli, e)
}

func (q *Queue) Pop() Element {
	if q.Size() == 0 {
		return nil
	}
	e := q.sli[0]
	q.sli = q.sli[1:]
	return e
}
