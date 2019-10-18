#![allow(dead_code)]
use std::cmp::Ordering;
use std::fmt;

#[derive(Debug, Clone)]
struct Dimension(i32, i32);

impl fmt::Display for Dimension {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "({},{})", self.0, self.1)
    }
}

impl PartialEq for Dimension {
    fn eq(&self, other: &Self) -> bool {
        self.0 == other.0 && self.1 == other.1
    }
}

// TODO :: Why am I empty, again??
impl Eq for Dimension {}

impl Ord for Dimension {
    fn cmp(&self, other: &Dimension) -> Ordering {
        self.1.cmp(&other.1)
    }
}

impl PartialOrd for Dimension {
    fn partial_cmp(&self, other: &Dimension) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

// FIXME :: There should be absolutely no lifetime issues here because
//          the output is entirely based on the input...
pub fn transform_and_map(buildings: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut roofs: Vec<Dimension> = Vec::new();
    let mut result = Vec::new();
    buildings
        .iter()
        .map(|raw_iteration| {
            (
                Dimension(raw_iteration[0], raw_iteration[2]),
                Dimension(raw_iteration[1], raw_iteration[2]),
            )
        })
        .for_each(|(left, right)| {
            // Stuff on the right will book keep the current
            // highest roof.
            roofs.push(right.clone());
            match roofs.iter().max() {
                Some(roof) => {
                    // Compare y
                    match left.1.cmp(&roof.1) {
                        Ordering::Less => {
                        },Ordering::Greater => {
                            result.push(vec![left.0,left.1]);
                        },
                        Ordering::Equal =>{
                            result.push(vec![left.0,left.1]);
                        },
                    }
                }
                None => panic!("this is an impossible situation where the PQ does not have any element after we have pushed an element into it..."),
            };
        });
    return result;
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
