pub struct Solution{}

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */

impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let (mut left, mut right) = (1 as i64, n as i64);
        let mut n = n;
        let mut r = guess(n);
        while r != 0 {
            match r {
                1 => left = n as i64,
                -1 => right = n as i64,
                _ => unreachable!(),
            }
            n = ((left + right)/2) as i32;
            r = guess(n);
        }
        n as i32
    }
}

unsafe fn guess(num: i32) -> i32 {
    if num > 6 {
        return -1;
    } else if num < 6 {
        return 1;
    }
    0
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_guessNumber() {
        unsafe {
            assert_eq!(Solution::guessNumber(10), 6);
        }
    }
}