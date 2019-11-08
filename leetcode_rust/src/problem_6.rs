use crate::Solution;

impl Solution {
    pub fn convert<T>(s: T, num_rows: i32) -> String
        where
            T: Into<String>,
    {
        let mut iter = 0;
        let mut map: std::collections::HashMap<usize, usize> = std::collections::HashMap::new();
        s.into().chars().enumerate()
            .map(|(index, ch)| {
                let id = num_rows*2
                (index, ch)
            })
            .for_each(|(index, ch)| {
                println!("index:{} ch:{}", index, ch);
            });
        String::new()
    }
}

#[test]
fn test() {
    assert_eq!(Solution::convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    assert_eq!(Solution::convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}
