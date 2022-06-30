pub struct Solution{}

// code start
use std::collections::HashMap;
impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let map: HashMap<_,_> = ['I', 'V', 'X', 'L', 'C', 'D','M']
            .iter()
            .zip([1, 5, 10, 50, 100, 500, 1000]).collect();
        s.chars().rev().fold(0, |acc, c| {
            acc + if acc > 4 * map[&c] { -map[&c] } else { map[&c] }
        })
    }
}
// code end

#[test]
fn test_roman_to_int() {
    assert_eq!(Solution::roman_to_int("III".to_string()), 3);
    assert_eq!(Solution::roman_to_int("IV".to_string()), 4);
    assert_eq!(Solution::roman_to_int("IX".to_string()), 9);
    assert_eq!(Solution::roman_to_int("LVIII".to_string()), 58);
    assert_eq!(Solution::roman_to_int("MCMXCIV".to_string()), 1994);
}
