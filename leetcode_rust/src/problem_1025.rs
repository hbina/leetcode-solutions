use crate::Solution;

impl Solution {
    pub fn divisor_game(n: i32) -> bool {
        n % 2 == 0
    }
}

#[test]
fn test() {
    assert_eq!(Solution::divisor_game(1), false);
    assert_eq!(Solution::divisor_game(2), true);
    assert_eq!(Solution::divisor_game(3), false);
    assert_eq!(Solution::divisor_game(4), true);
    assert_eq!(Solution::divisor_game(5), false);
}
