use crate::Solution;
use std::cmp::Ordering;
use std::collections::HashMap;

impl Solution {
    pub fn total_fruit(tree: Vec<i32>) -> i32 {
        // TODO ::  Find the first 2 couple.
        //          We can actually exit early based on this algorithm.
        //          For now we will just use HashMap
        match tree.len() {
            0 => 0, // vector is empty...exit early
            _ => {
                // map : key value => (frequency, first index)
                let mut fruits: std::collections::HashMap<i32, (i32, i32)> =
                    std::collections::HashMap::new();
                let mut index: i32 = 0;
                let mut global_frequency: i32 = 0;
                tree.iter().for_each(|&iter| {
                    println!("iter:{}", iter);
                    match fruits.len() {
                        0 | 1 => {
                            // There are only 0 or 1 unique keys in the map, no need to check.
                            println!("map contains {} unique key", fruits.len());
                            match fruits.get_mut(&iter) {
                                Some(some) => {
                                    println!(
                                        "already contains the key:{} must increment the frequency",
                                        iter
                                    );
                                    (*some).0 = (*some).0 + 1;
                                }
                                None => {
                                    println!("the key:{} does not exist, inserting...", iter);
                                    fruits.insert(iter, (1, index));
                                }
                            }
                        }
                        2 => {
                            // There are 2 keys in the map, must check if current is also not unique.
                            println!("map contains exactly {} unique keys...", fruits.len());
                            match fruits.get_mut(&iter) {
                                Some(some) => {
                                    println!(
                                        "already contains the key:{} with freq:{} must increment the frequency",
                                        iter,
                                        (*some).0
                                    );
                                    (*some).0 = (*some).0 + 1;
                                }
                                None => {
                                    println!(
                                        "the key:{} does not exist, must perform cleanup...",
                                        iter
                                    );
                                    let local_freq_sum = fruits.iter().fold(0, |acc, (value, (freq, index))|{
                                        println!("value:{} at index:{} have freq:{}",value, index, freq);
                                        acc + freq
                                    });
                                    println!("global max is {} while local max is {}", global_frequency, local_freq_sum);
                                    match local_freq_sum.cmp(&global_frequency) {
                                        Ordering::Greater => {
                                            global_frequency = local_freq_sum;
                                            println!("new global max frequency is {}", global_frequency);
                                        },
                                        _ => {}
                                    }
                                    let oldest_key = fruits.iter().min_by(|(_, (_, left_index)),(_, (_, right_index))|{
                                        left_index.cmp(right_index)
                                    });
                                    match oldest_key {
                                        Some((&old_key, &(old_freq, old_index))) =>{
                                             // NOTE :: This was actually problematic, but Rust type system catched this error :)
                                            println!("oldest key in map is {} with value:{} and freq:{}", old_key, old_freq, old_index);
                                            fruits.remove(&old_key);
                                            fruits.insert(iter, (1, index));
                                        },
                                        None=> {
                                            panic!("cannot find the oldest key in map...");
                                        }
                                    }
                                }
                            }
                        }
                        _ => panic!("unhandled case..."),
                    }
                    println!();
                    index = index + 1;
                });
                // FIXME :: Must recalculate the global maximum frequency again.
                //          This (and some more functions) can be made into closures.
                let local_freq_sum = fruits.iter().fold(0, |acc, (value, (freq, index))| {
                    println!("value:{} at index:{} have freq:{}", value, index, freq);
                    acc + freq
                });
                println!(
                    "global max is {} while local max is {}",
                    global_frequency, local_freq_sum
                );
                match local_freq_sum.cmp(&global_frequency) {
                    Ordering::Greater => {
                        global_frequency = local_freq_sum;
                        println!("new global max frequency is {}", global_frequency);
                    }
                    _ => {}
                }
                global_frequency
            }
        }
    }
}

#[test]
fn test() {
    assert_eq!(Solution::total_fruit(vec![1, 2, 1]), 3);
    assert_eq!(Solution::total_fruit(vec![0, 1, 2, 2]), 3);
    assert_eq!(Solution::total_fruit(vec![1, 2, 3, 2, 2]), 4);
    assert_eq!(
        Solution::total_fruit(vec![3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4]),
        5
    );
}
