pub struct Solution{}

// code start
impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut v = vec![vec![1]];
        for i in 2..=num_rows as usize {
            let before = &v[i-2];
            let mut t = vec![1];
            for j in 1..i-1 {
                t.push(before[j-1]+before[j])
            }
            t.push(1);
            v.push(t);
        }
        v
    }
}
// code end

#[test]
fn test_generate() {
    assert_eq!(Solution::generate(5), vec![vec![1], vec![1,1], vec![1,2,1], vec![1,3,3,1],vec![1,4,6,4,1]]);
}