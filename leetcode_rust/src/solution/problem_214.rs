#![allow(dead_code)]
use std::cmp::Ordering;

// NOTE ::  This does not work due to the fact that it is unable to distinguish
//          between 2 overlapping boxes of identical heights
pub fn transform_and_map(buildings: Vec<Vec<i32>>) {
    // Please use tuple next time Leetcode....this is 3 levels of indirection abomination
    let mut transformed_vec = buildings
        .iter()
        .flat_map(|dimensions| {
            let first = (dimensions[0], dimensions[2]);
            let second = (dimensions[1], dimensions[2]);
            vec![first, second]
        })
        .collect::<Vec<_>>();

    transformed_vec.sort_by(|left, right| left.0.cmp(&right.0));

    let mut previous_heights: Vec<i32> = Vec::new();
    let mut result_vec: Vec<Vec<i32>> = Vec::new();
    transformed_vec.iter().for_each(|current| {
        match previous_heights.iter().find(|x| **x == current.1) {
            Some(val) => {
                // This height existed before
            }
            None => {
                previous_heights.push(current.1);
            }
        }
    });
}

pub fn transform_and_dac(buildings: Vec<Vec<i32>>) {
    let mut transformed_vec = buildings
        .iter()
        .map(|dimensions| ((dimensions[0], dimensions[2]), (dimensions[1], 0)))
        .collect::<Vec<_>>();
}

#[test]
fn test() {
    // [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ]
    let mut a: Vec<Vec<i32>> = vec![];
    a.push(vec![2, 9, 10]);
    a.push(vec![3, 7, 15]);
    a.push(vec![5, 12, 12]);
    a.push(vec![15, 20, 10]);
    a.push(vec![19, 24, 8]);
    transform_and_map(a);
}
