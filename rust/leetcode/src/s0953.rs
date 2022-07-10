// 953. 验证外星语词典
// 
pub struct Solution{}

use std::collections::HashMap;
use std::cmp::Ordering;
impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        let mp: HashMap<char, usize> = order.chars().enumerate().map(|(i, c)| (c, i)).collect();
        let mut sorted = words.clone();
        sorted.sort_by(|a, b| {
            for (x, y) in a.chars().zip(b.chars()) {
                if mp[&x] < mp[&y] {
                    return Ordering::Less;
                } else if mp[&x] > mp[&y] {
                    return Ordering::Greater;
                }
            }
            if a.len() < b.len() {
                return Ordering::Less;
            }
            return Ordering::Equal;
        });
        sorted == words
    }
}
// code end

#[test]
fn tet_is_alien_sorted() {
    assert!(Solution::is_alien_sorted(vec!["hello".to_string(), "leetcode".to_string()],
        "hlabcdefgijkmnopqrstuvwxyz".to_string()));
    assert!(!Solution::is_alien_sorted(vec!["word".to_string(), "world".to_string(), "row".to_string()],
        "worldabcefghijkmnpqstuvxyz".to_string()));
    assert!(!Solution::is_alien_sorted(vec!["apple".to_string(), "app".to_string()],
        "abcdefghijklmnopqrstuvwxyz".to_string()));
}