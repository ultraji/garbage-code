// 136. 只出现一次的数字
// 

pub struct Solution{}

// code start
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        nums.into_iter().fold(0, |a, b| a ^ b)
    }
}
// code end

#[test]
fn test_single_number() {
    assert_eq!(Solution::single_number(vec![2,2,1]), 1);
    assert_eq!(Solution::single_number(vec![4,1,2,1,2]), 4);
}