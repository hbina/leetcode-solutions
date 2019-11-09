use crate::Solution;

// TODO :: Finish this...
impl Solution {
    pub fn reverse(x: i32) -> i32 {
        x
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
