use crate::Solution;

impl Solution {
    pub fn defang_i_paddr(address: String) -> String {
        let mut result: String = String::new();
        address.chars().into_iter().for_each(|c| match c {
            '.' => result.push_str("[.]"),
            _ => result.push(c),
        });
        return result;
    }
}

#[test]
fn succeeding() {
    let a = String::from("1.1.1.1");
    assert_eq!(Solution::defang_i_paddr(a), String::from("1[.]1[.]1[.]1"));
}
