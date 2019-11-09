use crate::Solution;

impl Solution {
    pub fn is_subsequence<T>(s: T, t: T) -> bool
        where
            T: Into<String>,
    {
        let s = s.into();
        let t = t.into();
        false
    }
}

#[test]
fn test() {
    assert_eq!(Solution::is_subsequence("abc", "ahbgdc"), true);
    assert_eq!(Solution::is_subsequence("axc", "ahbgdc"), false);
}
