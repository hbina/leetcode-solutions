#![allow(dead_code)]

use crate::Solution;
use std::cmp::Ordering;
use std::fmt;

#[derive(Debug, Clone)]
enum Dimension {
    Left(i32, i32, i32),
    Right(i32, i32, i32),
}

impl fmt::Display for Dimension {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match &self {
            Dimension::Left(id, x, y) => write!(f, "Left({},{},{})", id, x, y),
            Dimension::Right(id, x, y) => write!(f, "Right({},{},{})", id, x, y),
        }
    }
}

// TODO :: Not sure what we need this for?
impl PartialEq for Dimension {
    fn eq(&self, other: &Self) -> bool {
        match &self {
            Dimension::Left(id1, x1, y1) => match other {
                Dimension::Left(id2, x2, y2) => id1 == id2 && x1 == x2 && y1 == y2,
                Dimension::Right(id2, x2, y2) => id1 == id2 && x1 == x2 && y1 == y2,
            },
            Dimension::Right(id1, x1, y1) => match other {
                Dimension::Left(id2, x2, y2) => id1 == id2 && x1 == x2 && y1 == y2,
                Dimension::Right(id2, x2, y2) => id1 == id2 && x1 == x2 && y1 == y2,
            },
        }
    }
}

// TODO :: Why is this empty, again??
impl Eq for Dimension {}

// TODO :: Document this?
impl Ord for Dimension {
    fn cmp(&self, other: &Dimension) -> Ordering {
        match &self {
            Dimension::Left(_, x1, y1) => match other {
                Dimension::Left(_, x2, y2) => match x1.cmp(x2) {
                    Ordering::Equal => y1.cmp(y2),
                    _ => x1.cmp(x2),
                },
                Dimension::Right(_, x2, _) => match x1.cmp(x2) {
                    Ordering::Equal => Ordering::Less,
                    _ => x1.cmp(x2), // FIXME :: If Xs are the same, this could be a bug?
                },
            },
            Dimension::Right(_, x1, y1) => match other {
                Dimension::Left(_, x2, _) => match x1.cmp(x2) {
                    Ordering::Equal => Ordering::Greater,
                    _ => x1.cmp(x2),
                },
                Dimension::Right(_, x2, y2) => match x1.cmp(x2) {
                    Ordering::Equal => y1.cmp(y2),
                    _ => x1.cmp(x2), // FIXME :: If Xs are the same, this could be a bug?
                },
            },
        }
    }
}

impl PartialOrd for Dimension {
    fn partial_cmp(&self, other: &Dimension) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    // FIXME :: There should be absolutely no lifetime issues here because
    //          the output is entirely based on the input...
    pub fn transform_and_map(buildings: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        // Local variables
        let mut previous_lefts: Vec<Dimension> = Vec::new();
        let mut previous_rights: Vec<Dimension> = Vec::new(); // TODO :: Do we even need this?
        let mut result = Vec::new();
        let mut id: i32 = -1;

        // Transform
        let mut collector: Vec<Dimension> = buildings
            .iter()
            .flat_map(|raw_iteration| {
                id = id + 1;
                vec![
                    Dimension::Left(id, raw_iteration[0], raw_iteration[2]),
                    Dimension::Right(id, raw_iteration[1], raw_iteration[2]),
                ]
            })
            .collect();
        collector.sort();

        // Map
        collector.iter().for_each(|iter| match iter {
            Dimension::Left(id, x, y) => match previous_lefts.iter().max() {
                Some(some) => match some {
                    Dimension::Left(id1, x1, y1) => match y.cmp(y1) {
                        Ordering::Equal => {
                            println!("{},{},{} is as tall as {},{},{}", id, x, y, id1, x1, y1);
                            previous_lefts.push(Dimension::Left(*id, *x, *y));
                        }
                        Ordering::Greater => {
                            println!("{},{},{} is higher than {},{},{}", id, x, y, id1, x1, y1);
                            previous_lefts.push(Dimension::Left(*id, *x, *y));
                        }
                        Ordering::Less => {
                            println!("{},{},{} is shorter than {},{},{}", id, x, y, id1, x1, y1);
                            previous_lefts.push(Dimension::Left(*id, *x, *y));
                        }
                    },
                    Dimension::Right(_, _, _) => {
                        panic!("previous_lefts should never contain right")
                    }
                },
                None => {
                    println!(
                        "previous_lefts is empty, so simply adding {},{},{}",
                        *id, *x, *y
                    );
                    previous_lefts.push(Dimension::Left(*id, *x, *y));
                }
            },
            // TODO :: Match when lefts are empty??
            // TODO :: Remove matches
            Dimension::Right(id, x, y) => previous_lefts.retain(|elem| match elem {
                Dimension::Left(id1, _, _) => id1 == id,
                Dimension::Right(_, _, _) => panic!("impossible situation..."),
            }),
        });
        result
    }
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
    Solution::transform_and_map(a);
}
