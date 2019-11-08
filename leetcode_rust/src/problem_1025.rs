use crate::Solution;

impl Solution {
    pub fn divisor_game(n: i32) -> bool {
        n % 2 == 0
    }

    // TODO ::  This can be improved further by considering the
    //          distribution of the divisors of `N`.
    //          In particular, if `N` is even, we know that the largest divisor is `N/2`.
    //          Furthermore, if `N` is odd, then the smallest divisor must be `< sqrt(N)`
    pub fn divisor_game_dp(n: i32) -> bool {
        match n {
            1 => false,
            2 => true,
            3 => false,
            4 => true,
            _ => {
                (1..=n / 2)
                    .collect::<Vec<_>>()
                    .iter()
                    .filter(|&&x| n % x == 0)
                    .take_while(|&&x| !Solution::divisor_game_dp(n - x))
                    .collect::<Vec<_>>()
                    .len()
                    != 0
            }
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

    (5..20).for_each(|x| {
        assert_eq!(Solution::divisor_game_dp(x), Solution::divisor_game(x));
    });
}
