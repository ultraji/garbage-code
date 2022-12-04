// 1774. 最接近目标价格的甜点成本
//

pub struct Solution {}

impl Solution {
    pub fn closest_cost(base_costs: Vec<i32>, topping_costs: Vec<i32>, target: i32) -> i32 {
        let m = base_costs.iter().min().unwrap();
        if *m > target {
            return *m;
        }

        let mut result = i32::MAX;
        let mut delta = target;
        let mut cmp = |x: i32| {
            if (x - target).abs() < delta || ((x - target).abs() == delta && x < result) {
                result = x;
                delta = (x - target).abs();
            }
        };

        let mut dp = vec![0; target as usize];
        base_costs.into_iter().for_each(|x| {
            if x < target {
                dp[x as usize] = x;
            }
            cmp(x);
        });


        for t in topping_costs {
            let mut add: Vec<i32> = vec![];
            for b in dp.iter().filter(|x| **x != 0) {
                add.append(&mut vec![b + t, b + t * 2]);
            }
            add.into_iter().for_each(|x| {
                if x < target {
                    dp[x as usize] = x;
                }
                cmp(x)
            });
        }

        result
    }
}

#[test]
fn test_closest_cost() {
    assert_eq!(Solution::closest_cost(vec![1, 7], vec![3, 4], 10), 10);
    assert_eq!(Solution::closest_cost(vec![2, 3], vec![4, 5, 100], 18), 17);
    assert_eq!(Solution::closest_cost(vec![10], vec![1], 1), 10);

    // 1：dp构造时，未判断数值大小，插入时out of bound。
    assert_eq!(Solution::closest_cost(vec![3, 10], vec![1], 9), 10);

    // 2：无需配料场景
    assert_eq!(Solution::closest_cost(vec![9], vec![7], 10), 9);
}
