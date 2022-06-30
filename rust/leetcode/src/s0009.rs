pub struct Solution{}

// code start
impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        x.to_string() == x.to_string().chars().rev().collect::<String>()
    }
}

#[test]
fn test_is_palindrome() {
    assert!(Solution::is_palindrome(121));
    assert!(!Solution::is_palindrome(-121));
    assert!(!Solution::is_palindrome(10));
}