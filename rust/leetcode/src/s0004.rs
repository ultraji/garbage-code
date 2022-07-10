
// 题解：
// 1. 如果两个数组长度和是偶数，则r1, r2为中间两个数；
// 2. 如果两个数组长度和是奇数，则r2为中位数；
pub struct Solution {}

// code start
impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let n = nums1.len() + nums2.len();
        let (mut i, mut j) = (0, 0);
        let (mut r1, mut r2) = (0, 0);
        while i + j < n/2+1 {
            let mid = match (nums1.get(i), nums2.get(j)) {
                (Some(&x), Some(&y)) => {
                    if x > y {
                        j += 1;
                        y
                    } else {
                        i += 1;
                        x
                    }
                }
                (Some(&x), None) => {
                    i += 1;
                    x
                }
                (None, Some(&y)) => {
                    j += 1;
                    y
                }
                (None, None) => unreachable!(),
            };
            (r1, r2) = (r2, mid);
        }

        if n % 2 == 0 {
            return (r1 as f64 + r2 as f64) / 2.0;
        }
        r2 as f64
    }
}
// code end

#[test]
fn test_find_median_sorted_arrays() {
    assert_eq!(Solution::find_median_sorted_arrays(vec![], vec![2, 3]), 2.50000);
    assert_eq!(Solution::find_median_sorted_arrays(vec![1, 3], vec![2]), 2.00000);
    assert_eq!(Solution::find_median_sorted_arrays(vec![1, 2], vec![3, 4]), 2.50000);
    assert_eq!(Solution::find_median_sorted_arrays(vec![0, 0], vec![0, 0]), 0.00000);
    assert_eq!(Solution::find_median_sorted_arrays(vec![], vec![1]), 1.00000);
    assert_eq!(Solution::find_median_sorted_arrays(vec![3], vec![-2, -1]), -1.00000);
}
