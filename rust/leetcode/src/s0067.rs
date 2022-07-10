// 67. 二进制求和
// 
pub struct Solution{}

// code start
use std::mem::swap;
impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let (mut s1, mut s2) = (a, b);
        if s1.len() > s2.len() {
            swap(&mut s1, &mut s2);
        }
        s1 = format!("{:0>width$}", s1, width=s2.len());

        let mut c = 0;
        let mut chars = s1.chars().rev().zip(s2.chars().rev()).map(|(a, b)| {
            let t = a.to_digit(2).unwrap() + b.to_digit(2).unwrap() + c;
            c = t/2;
            char::from_digit((t%2) as u32, 2).unwrap()
        }).collect::<Vec<char>>();
        if c > 0 {
            chars.push('1');
        }
        chars.iter().rev().collect()

    }
}
// code end

#[test]
fn  test_add_binary() {
    assert_eq!(Solution::add_binary("11".to_string(), "1".to_string()), "100".to_string());
    assert_eq!(Solution::add_binary("11".to_string(), "1".to_string()), "100".to_string());
}