pub struct Solution{}

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut dp = vec![1, 1];
        for i in 2..=n as usize {
            dp.push(dp[i-2] + dp[i-1]);
        }
        dp[n as usize]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_climb_stairs() {
        assert_eq!(Solution::climb_stairs(2), 2);
        assert_eq!(Solution::climb_stairs(3), 3);
    }
}