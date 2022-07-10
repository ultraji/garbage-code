// 70. 爬楼梯
// 
pub struct Solution{}

// code start
impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut dp = vec![1, 1];
        for i in 2..=n as usize {
            dp.push(dp[i-2] + dp[i-1]);
        }
        dp[n as usize]
    }
}
// code end

#[test]
fn test_climb_stairs() {
    assert_eq!(Solution::climb_stairs(2), 2);
    assert_eq!(Solution::climb_stairs(3), 3);
}