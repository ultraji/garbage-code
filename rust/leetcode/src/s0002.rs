pub struct Solution {}

//Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

// code start
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut result = None;
        let mut tail = &mut result;
        let mut t = (l1, l2, 0, 0);
        loop {
            t = match t {
                (None, None, 0, _) => break,
                (None, None, c, _) => (None, None, 0, c),
                (Some(a), None, c, _) | (None, Some(a), c, _) => (a.next, None, (a.val+c)/10, (a.val+c)%10),
                (Some(a), Some(b), c, _) => (a.next, b.next, (a.val+b.val+c)/10, (a.val+b.val+c)%10),
            };
            *tail = Some(Box::new(ListNode::new(t.3)));
            tail = &mut tail.as_mut().unwrap().next;
        }
        result
    }
}
// code end

fn new_list(nums: &[i32]) -> Option<Box<ListNode>> {
    if nums.is_empty() {
        return None;
    }
    Some(Box::new(ListNode {
        val: nums[0],
        next: new_list(&nums[1..]),
    }))
}

#[test]
fn test_add_two_numbers() {
    assert_eq!(Solution::add_two_numbers(new_list(&[2,4,3]), new_list(&[5,6,4])), new_list(&[7,0,8]))
}
