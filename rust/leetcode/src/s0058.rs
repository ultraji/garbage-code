pub struct Solution{}

// code start
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let s = s.trim_end().chars().rev().collect::<String>();
        s.find(' ').unwrap_or(s.len()) as i32
    }
}
// code end

#[test]
fn test_length_of_last_word() {
    assert_eq!(Solution::length_of_last_word("Hello World".to_string()), 5);
    assert_eq!(Solution::length_of_last_word("   fly me   to   the moon  ".to_string()), 4);
    assert_eq!(Solution::length_of_last_word("luffy is still joyboy".to_string()), 6);
}