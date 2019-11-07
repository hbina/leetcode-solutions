use crate::Solution;

impl Solution {
    pub fn divisor_game(n: i32) -> bool {
        n % 2 == 0
    }

    pub fn divisor_game_dp(n: i32) -> bool {
        match n {
            1 => false,
            2 => true,
            3 => false,
            _ => (1..n / 2)
                .collect::<Vec<_>>()
                .iter()
                .fold(false, |acc, &x| acc | !Solution::divisor_game_dp(n - x)),
        }
    }
}

#[test]
fn test() {
    assert_eq!(Solution::divisor_game(1), false);
    assert_eq!(Solution::divisor_game(2), true);
    assert_eq!(Solution::divisor_game(3), false);
    assert_eq!(Solution::divisor_game(4), true);
    assert_eq!(Solution::divisor_game(5), false);

    assert_eq!(Solution::divisor_game_dp(1), false);
    assert_eq!(Solution::divisor_game_dp(2), true);
    assert_eq!(Solution::divisor_game_dp(3), false);
    assert_eq!(Solution::divisor_game_dp(4), true);
    assert_eq!(Solution::divisor_game_dp(5), false);
}
