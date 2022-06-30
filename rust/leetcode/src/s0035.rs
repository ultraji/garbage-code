pub struct Solution{}

// code start
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        for (i, n) in nums.iter().enumerate() {
            if *n >= target {
                return i as i32;
            }
        }
        nums.len() as i32
    }
}
// code end

#[test]
fn test_search_insert() {
    assert_eq!(Solution::search_insert(vec![1,3,5,6], 5), 2);
    assert_eq!(Solution::search_insert(vec![1,3,5,6], 2), 1);
    assert_eq!(Solution::search_insert(vec![1,3,5,6], 7), 4);
}