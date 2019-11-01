use crate::Solution;
use std::ops::Add;

impl Solution {
    pub fn num_trees(n: i32) -> i32 {
        let arr = (1..=n).collect::<Vec<_>>();
        arr.iter().fold(0, |acc, &x| {
            // Accumulate left and right
            match x {
                1 => {}
                => {}
            }
            let left = (1..=x).collect::<Vec<_>>();
            let right = (x..=n).collect::<Vec<_>>();
            println!("left:{:?} right:{:?}", left, right);
            acc + internal_summation(&left) + internal_summation(&right)
        })
    }
}

fn internal_summation(arr: &Vec<i32>) -> i32 {
    // Evaluate left and right
    match arr.len() {
        1 => 1,
        _ => 10
    }
}

#[test]
fn test() {
    assert_eq!(Solution::num_trees(4), 10);
}
