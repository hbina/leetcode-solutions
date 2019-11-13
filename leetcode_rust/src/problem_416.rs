use crate::Solution;

impl Solution {
    //  NOTE    ::  Naive implementation, simply collect the permutations as we go.
    pub fn can_partition_v1(nums: Vec<i32>) -> bool {
        let mut sum: i32 = nums.iter().sum();
        let mut result: Vec<(i32, i32)> = Vec::new();
        nums.iter().for_each(|&x| match result.len() {
            0 => {
                sum -= x;
                result.push((x, 0))
            }
            _ => {
                let new_result = result
                    .iter()
                    .map(|&(left, right)| (left, right + x))
                    .collect::<Vec<(i32, i32)>>();
                result.iter().for_each(|&(mut left, right)| {
                    left += x;
                });
                result.extend(new_result);
            }
        });
        result
            .iter()
            .filter(|&&(left, right)| left == right)
            .collect::<Vec<_>>()
            .len()
            != 0
    }

    //  NOTE    ::  Checks if no possible combination exists. We do this by taking the absolute
    //              difference and checking if its more than the sum of the whats left.
    pub fn can_partition_v2(nums: Vec<i32>) -> bool {
        let mut sum: i32 = nums.iter().sum();
        let mut result: Vec<(i32, i32)> = Vec::new();
        nums.iter().for_each(|&x| match result.len() {
            0 => {
                sum -= x;
                result.push((x, 0))
            }
            _ => {
                let new_result = result
                    .iter()
                    .filter(|&&(left, right)| match left.cmp(&right) {
                        std::cmp::Ordering::Greater => left - right <= sum,
                        _ => right - left <= sum,
                    })
                    .map(|&(left, right)| vec![(left + x, right), (left, right + x)])
                    .flatten()
                    .collect::<Vec<(i32, i32)>>();
                result = new_result;
                sum -= x;
            }
        });
        result
            .iter()
            .filter(|&&(left, right)| left == right)
            .collect::<Vec<_>>()
            .len()
            != 0
    }

    //  NOTE    ::  This function cannot produce false positive!
    pub fn can_partition_v3(mut nums: Vec<i32>) -> bool {
        nums.sort_by(|x, y| y.cmp(x));
        nums.iter().fold(0, |acc, &x| {
            println!("acc:{}", acc);
            match acc > 0 {
                true => acc - x,
                false => acc + x,
            }
        }) == 0
    }

    pub fn can_partition(nums: Vec<i32>) -> bool {
        // Must sanitize
        let sum: i32 = nums.iter().sum();
        let sanitize = nums.iter().fold(true, |acc, &x| {
            println!("sum-x:{} sum:{} x:{}", sum - x, sum, x);
            acc && (sum - x) >= x
        });
        if !sanitize {
            return false;
        }
        // Perform actual algorithm...
        let (mut twos, mut ones) = (0, 0);
        nums.iter().for_each(|&x| match x % 2 == 0 {
            true => {
                twos += x / 2;
            }
            false => {
                ones += 1;
                twos += (x - 1) / 2;
            }
        });
        println!("before twos:{} ones:{}", twos, ones);
        if twos % 2 != 0 && ones >= 2 {
            twos -= 1;
            ones -= 2;
        }
        println!("after twos:{} ones:{}", twos, ones);
        twos % 2 == 0 && ones % 2 == 0
    }
}

#[test]
fn test() {
    // assert_eq!(Solution::can_partition(vec![1, 5, 11, 5]), true);
    // assert_eq!(Solution::can_partition(vec![5, 3, 4, 4]), true);
    // assert_eq!(Solution::can_partition(vec![3, 3, 1, 94]), false);
    // assert_eq!(Solution::can_partition(vec![5, 3, 1, 4]), false);
    assert_eq!(
        Solution::can_partition_v1(vec![
            100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
            100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
            100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
            100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
            100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
            100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100
        ]),
        true
    );
    assert_eq!(Solution::can_partition(vec![3, 3, 3, 4, 5]), true);
    assert_eq!(Solution::can_partition(vec![1, 2, 5]), false);
}

#[test]
fn failing() {
    assert_eq!(Solution::can_partition(vec![2, 2, 3, 5]), false);
}
