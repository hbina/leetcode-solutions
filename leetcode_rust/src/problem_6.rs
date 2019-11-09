use crate::Solution;

// TODO :: Finish this...
impl Solution {
    pub fn convert<T>(s: T, num_rows: i32) -> String
    where
        T: Into<String>,
    {
        String::new()
    }
}

#[test]
fn test() {
    assert_eq!(Solution::convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    assert_eq!(Solution::convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}
