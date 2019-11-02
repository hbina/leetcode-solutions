use crate::Solution;

impl Solution {
    pub fn num_trees(n: i32) -> i32 {
        match n {
            0 => 1,
            1 => 1,
            2 => 2,
            3 => 5,
            _ => (1..=n).collect::<Vec<i32>>().iter().fold(0, |acc, &x| {
                let left = Solution::num_trees(x - 1);
                let right = Solution::num_trees(n - x);
                acc + left * right
            }),
        }
    }
}

#[test]
fn test() {
    assert_eq!(Solution::num_trees(3), 5);
    assert_eq!(Solution::num_trees(4), 14);
    assert_eq!(Solution::num_trees(5), 42);
}
