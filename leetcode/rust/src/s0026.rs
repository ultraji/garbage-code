pub struct Solution{}

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        nums.dedup();
        nums.len() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test_remove_duplicates() {
        let mut nums = vec![1,1,2];
        assert_eq!(Solution::remove_duplicates(&mut nums), 2);
        assert_eq!(nums, vec![1, 2]);

        let mut nums = vec![0,0,1,1,1,2,2,3,3,4];
        assert_eq!(Solution::remove_duplicates(&mut nums), 5);
        assert_eq!(nums, vec![0,1,2,3,4]);
    }
}