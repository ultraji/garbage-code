// 66. 加一
// 
pub struct Solution{}

// code start
impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut c = 1;
        let mut res = vec![];
        for d in digits.into_iter().rev() {
            res.push((d+c)%10);
            c = (d+c)/10;
        }
        
        if c == 1 { res.push(1) }
        res.into_iter().rev().collect()
    }
}
// code end

#[test]
fn test_plus_one() {
    assert_eq!(Solution::plus_one(vec![1,2,3]), vec![1,2,4]);
    assert_eq!(Solution::plus_one(vec![4,3,2,1]), vec![4,3,2,2]);
    assert_eq!(Solution::plus_one(vec![0]), vec![1]);
}