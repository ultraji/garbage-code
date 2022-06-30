pub struct Solution{}

// code start
use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();
        for (index, num) in nums.iter().enumerate() {
            if let Some(&index1) = map.get(&(target-num)) {
                return vec![index1 as i32, index as i32];
            } else {
                map.insert(num, index);
            }
        }
        vec![]
    }
}
// code end

#[test]
fn test_two_sum() {
    assert_eq!(Solution::two_sum(vec![2,7,11,15], 9), vec![0, 1]);
    assert_eq!(Solution::two_sum(vec![3,2,4], 6), vec![1, 2]);
    assert_eq!(Solution::two_sum(vec![3,3], 6), vec![0, 1]);
}