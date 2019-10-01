#![allow(dead_code)]
use std::cmp::Ordering;

pub fn brute_force(heights: Vec<i32>) -> i32 {
    if heights.len() == 1 {
        return heights[0];
    }
    let ic: Vec<(i32, i32)> = vec![(0, heights[0])];
    let max: i32 = heights[0];
    heights[1..]
        .into_iter()
        .map(move |x| match x.cmp(&ic[ic.len() - 1].1) {
            Ordering::Less => &ic[..].into_iter().filter(|sv| sv.1 < *x).map(|lv| {}),
            Ordering::Equal => println!("="),
            Ordering::Greater => println!(">"),
        });
    return 10;
}

#[test]
fn test() {
    let a = vec![2, 1, 5, 6, 2, 3];
    assert_eq!(brute_force(a), 10);
}
