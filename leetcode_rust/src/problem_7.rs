use crate::Solution;

impl Solution {
    pub fn reverse(mut x: i32) -> i32 {
        let mut value = 0;
        let mut largest_power_of_10 = 1;
        while largest_power_of_10 < x {
            largest_power_of_10 *= 10;
        }
        value
    }
}

#[test]
fn test() {
    assert_eq!(Solution::reverse(1234), 4321);
    assert_eq!(Solution::reverse(123), 321);
    assert_eq!(Solution::reverse(12), 21);
    assert_eq!(Solution::reverse(345), 543);
    assert_eq!(Solution::reverse(765), 567);
    assert_eq!(Solution::reverse(321), 123);
    assert_eq!(Solution::reverse(0), 0);
    assert_eq!(Solution::reverse(1), 1);
    assert_eq!(Solution::reverse(10), 10);
}
