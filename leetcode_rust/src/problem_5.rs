use crate::Solution;

impl Solution {
    // TODO ::  I am pretty sure this abomination can be improved by a lot...
    // TODO ::  Needs to improve the performance because we are failing on large palindromes
    //          The problem is mainly due to the fact that we are mostly doing repetitive works on them.
    pub fn longest_palindrome<T>(s: T) -> String
        where
            T: Into<String>,
    {
        let s = s.into();
        match s.len() {
            0 => String::new(),
            _ => {
                s.chars()
                    .enumerate()
                    .map(|(index, ch)| {
                        let mut palindrome_collector: Vec<String> = Vec::new();
                        {
                            // If single center
                            let left = (0..index)
                                .map(|index| {
                                    let ch = s.chars().enumerate().nth(index).unwrap();
                                    ch
                                })
                                .rev();
                            let right = (index..s.len())
                                .map(|index| {
                                    let ch = s.chars().enumerate().nth(index).unwrap();
                                    ch
                                })
                                .filter(|&x| x.0 != index);
                            let mut single = left
                                .zip(right)
                                .take_while(|(left, right)| right.1 == left.1)
                                .map(|(left, right)| vec![left, right])
                                .flatten()
                                .collect::<Vec<(usize, char)>>();
                            single.push((index, ch)); // Push the single character in the middle
                            single.sort_by(|&left, &right| left.0.cmp(&right.0));
                            let palindrome_single =
                                single.iter().fold(String::new(), |mut acc, &x| {
                                    acc.push(x.1);
                                    acc
                                });
                            palindrome_collector.push(palindrome_single);
                        }
                        {
                            // If dual center left
                            let left = (0..index)
                                .map(|index| {
                                    let ch = s.chars().enumerate().nth(index).unwrap();
                                    ch
                                })
                                .rev();
                            let right = (index..s.len()).map(|index| {
                                let ch = s.chars().enumerate().nth(index).unwrap();
                                ch
                            });
                            let mut single_left = left
                                .zip(right)
                                .take_while(|(left, right)| right.1 == left.1)
                                .map(|(left, right)| vec![left, right])
                                .flatten()
                                .collect::<Vec<(usize, char)>>();
                            single_left.sort_by(|&left, &right| left.0.cmp(&right.0));
                            let palindrome_single =
                                single_left.iter().fold(String::new(), |mut acc, &x| {
                                    acc.push(x.1);
                                    acc
                                });
                            palindrome_collector.push(palindrome_single);
                        }
                        palindrome_collector
                    })
                    .flatten()
                    .filter(|x| !x.is_empty())
                    .max_by(|left, right| left.len().cmp(&right.len()))
                    .unwrap()
            }
        }
    }

    pub fn longest_palindrome_dummy<T>(s: T) -> String
        where
            T: Into<String>,
    {
        String::from("dd")
    }
}

fn palindrome_length(left: &str, right: &str) -> usize {
    let left_chars = left.chars().rev();
    let right_chars = right.chars();

    left_chars
        .zip(right_chars)
        .take_while(|(c1, c2)| c1 == c2)
        .map(|(c, _)| c.len_utf8())
        .sum()
}

#[test]
fn failing() {
    assert_eq!(Solution::longest_palindrome("babad").len(), 3);
    assert_eq!(Solution::longest_palindrome("cbbd").len(), 2);
    assert_eq!(Solution::longest_palindrome("ccc").len(), 3);
    assert_eq!(Solution::longest_palindrome("aaaa").len(), 4);
    assert_eq!(Solution::longest_palindrome("").len(), 0);
    assert_eq!(Solution::longest_palindrome("b").len(), 1);
    assert_eq!(Solution::longest_palindrome("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
    ).len(), 1);
}
