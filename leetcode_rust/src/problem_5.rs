use crate::Solution;

impl Solution {
    pub fn longest_palindrome<T: Into<String>>(s: T) -> String {
        let mut accumulation: std::collections::HashSet<String> = std::collections::HashSet::new();
        s.into().chars().enumerate().for_each(|(index, ch)| {
            println!("index:{} ch:{}", index, ch);
            accumulation.clone().iter().for_each(|word| {
                let new_word = word.clone() + ch.to_string().as_str();
                println!("new_word:{}", new_word);
                accumulation.insert(new_word);
            });
            accumulation.insert(ch.to_string());
        });
        accumulation.iter().for_each(|word| {
            println!("word:{}", word);
        });
        String::from("hello")
    }

    pub fn longest_palindrome_dummy<T: Into<String>>(s: T) -> String {
        let mut words: std::collections::HashMap<String, (bool, usize)> =
            std::collections::HashMap::new();
        s.into()
            .chars()
            .enumerate()
            .for_each(|(iter_index, iter_char)| {
                println!("ch:({},{})", iter_index, iter_char);
                let new_words = words
                    .iter()
                    .filter(|(_, (_, index))| iter_index == *index + 1)
                    .map(|(word, (palindrome, end_index))| {
                        println!(
                            "unfiltered word:{} palindrome:{} end_index:{}",
                            word, palindrome, end_index
                        );
                        (word, palindrome, end_index)
                    })
                    .map(|(word, _, end_index)| match word.chars().next() {
                        Some(x) => {
                            let combined_word = format!("{}{}", word, iter_char);
                            let still_palindrome = x == iter_char;
                            let new_end_index = end_index + 1;
                            println!(
                                "new word:{} palindrome:{} end_index:{}",
                                combined_word, still_palindrome, new_end_index
                            );
                            (combined_word, still_palindrome, new_end_index)
                        }
                        None => {
                            panic!("something wrong happened...");
                        }
                    })
                    .map(|(word, palindrome, end_index)| {
                        println!(
                            "final word:{} palindrome:{} end_index:{}",
                            word, palindrome, end_index
                        );
                        (word, palindrome, end_index)
                    })
                    .collect::<Vec<_>>();
                new_words.iter().for_each(|(word, palindrome, end_index)| {
                    words.insert(word.clone(), (palindrome.clone(), end_index.clone()));
                });
                words.insert(iter_char.to_string(), (true, iter_index));
            });
        String::from("dd")
    }
}

#[test]
fn failing() {
    assert_eq!(Solution::longest_palindrome("hello").len(), 4);
}
