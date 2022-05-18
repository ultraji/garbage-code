pub struct Solution{}

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut max = -1;
        let mut max_prices = prices.iter().rev().map(|x| {
            max = std::cmp::max(*x, max);
            max
        }).collect::<Vec<i32>>();
        max_prices.reverse();
        max = 0;
        prices.iter().zip(max_prices.iter()).for_each(|(x,y)| {
            max = std::cmp::max(*y-*x, max);
        });
        max
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_max_profit() {
        assert_eq!(Solution::max_profit(vec![7,1,5,3,6,4]), 5);
        assert_eq!(Solution::max_profit(vec![7,6,4,3,1]), 0);
    }
}