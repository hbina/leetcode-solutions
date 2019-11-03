use crate::Solution;

impl Solution {
    pub fn longest_palindrome<T: Into<String>>(s: T) -> String {
        let mut words: std::collections::HashMap<String, (bool, usize)> =
            std::collections::HashMap::new();
        s.into().chars().enumerate().for_each(|c| {
            println!("c:({},{})", c.0, c.1);
            words
                .iter()
                .filter(|(_, (_, index))| {
                    c.0 == *index + 1
                })
                .map(|pair| {
                    pair.0
                })
                .map(|pair| {
                    println!("string:{}", pair);
                    format!("{}{}", pair, c.1)
                })
                .map(|x| {
                    println!("new string:{}", x);
                });
            words.insert(c.1.to_string(), (true, c.0));
        });
        String::from("dd")
    }
}

#[test]
fn test() {
    assert_eq!(Solution::longest_palindrome("babad").len(), 3);
}
