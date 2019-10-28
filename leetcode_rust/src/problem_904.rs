use crate::Solution;

impl Solution {
    pub fn total_fruit(tree: Vec<i32>) -> i32 {
        // TODO ::  Find the first 2 couple.
        //          We can actually exit early based on this algorithm.
        //          For now we will just use HashMap
        // TODO ::  Calibrating the global maximum stuff can be extracted into a closure...
        match tree.len() {
            0 => 0, // vector is empty...exit early
            _ => {
                // TODO ::  To prevent additional indirection, this HashMap could be turned into a static array...
                // NOTE ::  `basket` maps f : key value => (frequency, first index)
                // Local variables
                let mut basket: std::collections::HashMap<i32, (i32, i32)> =
                    std::collections::HashMap::new();
                let mut index: i32 = 0;
                let mut global_frequency: i32 = 0;

                // Helper closures
                let update_global_frequency =
                    |p_basket: &std::collections::HashMap<i32, (i32, i32)>, p_freq: &mut i32| {
                        let local_freq_sum =
                            p_basket.iter().fold(0, |acc, (_, (freq, _))| acc + freq);
                        match local_freq_sum.cmp(&p_freq) {
                            std::cmp::Ordering::Greater => {
                                *p_freq = local_freq_sum;
                            }
                            _ => {}
                        }
                    };
                // Perform algorithm
                tree.iter().for_each(|&iter| {
                    match basket.len() {
                        0 | 1 => {
                            match basket.get_mut(&iter) {
                                Some(some) => {
                                    (*some).0 = (*some).0 + 1;
                                }
                                None => {
                                    basket.insert(iter, (1, index));
                                }
                            }
                        }
                        2 => {
                            match basket.get_mut(&iter) {
                                Some(some) => {
                                    (*some).0 = (*some).0 + 1;
                                }
                                None => {
                                    update_global_frequency(&basket, &mut global_frequency);
                                    let oldest_key = basket.iter().min_by(
                                        |(_, (_, left_index)), (_, (_, right_index))| {
                                            left_index.cmp(right_index)
                                        },
                                    );
                                    match oldest_key {
                                        Some((&old_key, &(_, _))) => {
                                            // NOTE :: This was actually problematic, but Rust type system catched this error :)
                                            basket.remove(&old_key);
                                            basket.insert(iter, (1, index));
                                        }
                                        None => {
                                            panic!("cannot find the oldest key in map. This is possible if the basket is empty somehow...");
                                        }
                                    }
                                }
                            }
                        }
                        _ => panic!(
                            "the basket appear to have more than 2 unique keys in it. You messed up..."
                        ),
                    }
                    index = index + 1;
                });
                update_global_frequency(&basket, &mut global_frequency);
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
