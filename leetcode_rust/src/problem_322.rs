use crate::Solution;

impl Solution {
    pub fn coin_change(mut coins: Vec<i32>, amount: i32) -> i32 {
        0
    }
    //  NOTE    ::  Current solution involves modding the value until the value is 0.
    //              Otherwise, the must be no solution available. However, I am not entirely
    //              confident that this is correct.
    //              This solution is apparently insufficient. It assumes that each denomination is used.
    pub fn coin_change_fold(mut coins: Vec<i32>, amount: i32) -> i32 {
        coins.sort_by(|a, b| b.cmp(a));
        let mut count: i32 = 0;
        if coins.iter().fold(amount, |acc, &x| {
            let remainder = acc % x;
            let frequency = acc / x;
            count += frequency;
            println!(
                "x:{} acc:{} remainder:{} frequency:{}",
                x, acc, remainder, frequency
            );
            acc - (frequency * x)
        }) == 0
        {
            return count;
        } else {
            return -1;
        }
    }
}

#[test]
fn test() {
    // assert_eq!(Solution::coin_change(vec![1, 2, 5], 11), 3);
    // assert_eq!(Solution::coin_change(vec![2], 3), -1);
    // assert_eq!(Solution::coin_change(vec![2, 4], 6), 2);
    // assert_eq!(Solution::coin_change(vec![10, 100], 45), -1);
    // assert_eq!(Solution::coin_change(vec![10, 100], 50), 5);
    assert_eq!(
        Solution::coin_change_fold(vec![186, 419, 83, 408], 6249),
        20
    );
}
