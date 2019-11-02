use crate::Solution;
use std::ops::Add;

impl Solution {
    pub fn num_trees(n: i32) -> i32 {
        let arr = (1..=n).collect::<Vec<_>>();
        arr.iter().fold(0, |acc, &middle| {
            // Accumulate left and right
            let left_begin = 1;
            let left_end = middle - 1;
            let right_begin = middle + 1;
            let right_end = n;

            println!("middle:{} left:({},{}) right:({},{})", middle, left_begin, left_end, right_begin, right_end);
            acc + internal_summation(left_begin, left_end) + internal_summation(right_begin, right_end)
        })
    }
}

fn internal_summation(left: i32, right: i32) -> i32 {
    // Evaluate left and right
    println!("left:{} right:{}", left, right);
    match left.cmp(&right) {
        std::cmp::Ordering::Greater => {
            println!("left > right --> returning 0");
            0
        }
        std::cmp::Ordering::Equal => {
            println!("left == right --> returning 1");
            1
        }
        std::cmp::Ordering::Less => {
            println!("left < right --> evaluating...");
            if right - left <= 3 {
                right - left
            } else {
                let arr = (left..=right).collect::<Vec<_>>();
                arr.iter().fold(0, |acc, &middle| {
                    // Accumulate left and right
                    let left_begin = left;
                    let left_end = middle - left;
                    let right_begin = middle + left;
                    let right_end = right;

                    println!("middle:{} left:({},{}) right:({},{})", middle, left_begin, left_end, right_begin, right_end);
                    acc + internal_summation(left_begin, left_end) + internal_summation(right_begin, right_end)
                })
            }
        }
    }
}

#[test]
fn test() {
    assert_eq!(Solution::num_trees(3), 5);
}
