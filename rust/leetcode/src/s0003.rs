// 3. 无重复字符的最长子串
// hash-table|two-pointers|string|sliding-window
pub struct Solution{}

// code start
use std::{collections::HashSet, cmp::max};
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let chars: Vec<_> = s.chars().collect();
        let mut set = HashSet::new();
        let mut i: usize = 0;
        let mut res = 0;
        for (j, c) in chars.iter().enumerate() {
            if set.contains(c) {
                while chars[i] != *c {
                    set.remove(&chars[i]);
                    i += 1;
                }
                i += 1;
            } else {
                res = max(j-i+1, res);
                set.insert(c);
            }   
        }
        res as i32
    }
}
// code end

#[test]
fn test_length_of_longest_substring() {
    assert_eq!(Solution::length_of_longest_substring("abcabcbb".to_string()), 3);
    assert_eq!(Solution::length_of_longest_substring("bbbbb".to_string()), 1);
    assert_eq!(Solution::length_of_longest_substring("pwwkew".to_string()), 3);
}