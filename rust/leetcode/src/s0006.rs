// 6. Z 字形变换
// 模拟
pub struct Solution{}

// code start
impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        let mut j = 0;
        let mut c = -1;
        let mut idxs = vec![];
        for _ in 0..s.len() {
            idxs.push(j);
            if j == num_rows-1 || j == 0 {
                c = -c;
            }
            j += c;
        }
        let mut tmp: Vec<_> = s.chars().enumerate().zip(idxs).collect();
        tmp.sort_by_key(|&((idx, _), lows)| (lows, idx));
        
        tmp.iter().map(|&((_, c), _)| c).collect::<String>()
    }
}
// code end

#[test]
fn test_convert() {
    assert_eq!(Solution::convert("PAYPALISHIRING".to_string(), 3), "PAHNAPLSIIGYIR".to_string());
    assert_eq!(Solution::convert("PAYPALISHIRING".to_string(), 4), "PINALSIGYAHRPI".to_string());
    assert_eq!(Solution::convert("A".to_string(), 1), "A".to_string());
}