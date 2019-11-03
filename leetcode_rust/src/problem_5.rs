use crate::Solution;

impl Solution {
    pub fn longest_palindrome<T: Into<String>>(s: T) -> String {
        let mut words: std::collections::HashMap<String, (bool, usize)> =
            std::collections::HashMap::new();
        s.into().chars().enumerate().for_each(|(iter_index, iter_char)| {
            println!("ch:({},{})", iter_index, iter_char);
            let new_words = words
                .iter()
                .filter(|(_, (_, index))| {
                    iter_index == *index + 1
                })
                .map(|(word, (palindrome, end_index))| {
                    println!("unfiltered word:{} palindrome:{} end_index:{}", word, palindrome, end_index);
                    (word, palindrome, end_index)
                })
                .map(|(word, palindrome, end_index)| {
                    match word.chars().next() {
                        Some(x) => {
                            let combined_word = format!("{}{}", word, iter_char);
                            let still_palindrome = x == iter_char;
                            let new_end_index = end_index + 1;
                            println!("new word:{} palindrome:{} end_index:{}", combined_word, still_palindrome, new_end_index);
                            (combined_word, still_palindrome, new_end_index)
                        }
                        None => {
                            panic!("something wrong happened...");
                        }
                    }
                })
                .map(|(word, palindrome, end_index)| {
                    println!("final word:{} palindrome:{} end_index:{}", word, palindrome, end_index);
                    (word, palindrome, end_index)
                }).collect::<Vec<_>>();
            new_words.iter().for_each(|(word, palindrome, end_index)| {
                words.insert(word.clone(), (palindrome.clone(), end_index.clone()));
            });
            words.insert(iter_char.to_string(), (true, iter_index));
        });
        String::from("dd")
    }
}

#[test]
fn test() {
    assert_eq!(Solution::longest_palindrome("babad").len(), 3);
}
