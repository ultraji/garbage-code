// 21. 合并两个有序链表
// 
pub struct Solution {}

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    #[allow(dead_code)]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

// code start
impl Solution {
    pub fn merge_two_lists(list1: Option<Box<ListNode>>, list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        match (list1, list2) {
            (Some(h1), Some(h2)) => {
                if h1.val < h2.val {
                    Some(Box::new(ListNode {
                        val: h1.val,
                        next: Solution::merge_two_lists(h1.next, Some(h2)),
                    }))
                } else {
                    Some(Box::new(ListNode {
                        val: h2.val,
                        next: Solution::merge_two_lists(Some(h1), h2.next),
                    }))
                }
            }
            (Some(h1), None) => Some(h1),
            (None, Some(h2)) => Some(h2),
            (None, None) => None,
        }
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
fn test_merge_two_lists() {
    let list1 = new_list(&[1, 2, 4]);
    let list2 = new_list(&[1, 3, 4]);
    let res = new_list(&[1, 1, 2, 3, 4, 4]);
    assert_eq!(Solution::merge_two_lists(list1, list2), res);

    let list1 = new_list(&[]);
    let list2 = new_list(&[]);
    let res = new_list(&[]);
    assert_eq!(Solution::merge_two_lists(list1, list2), res);

    let list1 = new_list(&[]);
    let list2 = new_list(&[0]);
    let res = new_list(&[0]);
    assert_eq!(Solution::merge_two_lists(list1, list2), res);
}
