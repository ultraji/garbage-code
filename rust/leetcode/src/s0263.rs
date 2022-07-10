// 263. 丑数
// 
pub struct Solution{}

// code start
impl Solution {
    pub fn is_ugly(n: i32) -> bool {
        if n <= 0 {
            return false;
        }
        let mut n = n;
        for c in [2,3,5] {
            while n%c == 0 { n = n/c; }
        }
        n == 1
    }
}
// code end

#[test]
fn test_is_ugly() {
    assert!(Solution::is_ugly(6));
    assert!(Solution::is_ugly(1));
    assert!(!Solution::is_ugly(14));
}