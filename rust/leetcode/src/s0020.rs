// 20. 有效的括号
// stack
pub struct Solution{}

// code start
use std::collections::HashMap;
impl Solution {
    pub fn is_valid(s: String) -> bool {
        let map: HashMap<_,_> = [')', ']', '}'].iter().zip(['(', '[', '{']).collect();
        let mut stack = vec![];
        for c in s.chars() {
            match c {
                '[' | '(' | '{' => stack.push(c),
                _ => {
                    if let Some(t) = stack.pop() {
                        if map[&c] != t {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
            }
        }
        stack.len() == 0
    }
}
// code end

#[test]
fn test_is_valid() {
    assert!(Solution::is_valid("()".to_string()));
    assert!(Solution::is_valid("()[]{}".to_string()));
    assert!(!Solution::is_valid("(]".to_string()));
    assert!(!Solution::is_valid("([)]".to_string()));
    assert!(Solution::is_valid("{[]}".to_string()));
}