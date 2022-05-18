pub struct Solution{}

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        nums.into_iter().fold(0, |a, b| a ^ b)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_single_number() {
        assert_eq!(Solution::single_number(vec![2,2,1]), 1);
        assert_eq!(Solution::single_number(vec![4,1,2,1,2]), 4);
    }
}