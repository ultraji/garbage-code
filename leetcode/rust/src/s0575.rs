pub struct Solution{}

use std::collections::HashSet;
use std::iter::FromIterator;
impl Solution {
    pub fn distribute_candies(candy_type: Vec<i32>) -> i32 {
        let eat = candy_type.len() / 2;
        let set: HashSet<i32> = HashSet::from_iter(candy_type.into_iter());
        std::cmp::min(eat, set.len())  as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_distribute_candies() {
        assert_eq!(Solution::distribute_candies(vec![1,1,2,2,3,3]), 3);
        assert_eq!(Solution::distribute_candies(vec![1,1,2,3]), 2);
        assert_eq!(Solution::distribute_candies(vec![6,6,6,6]), 1);
    }
}