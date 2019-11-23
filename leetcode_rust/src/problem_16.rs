use crate::Solution;

impl Solution {
    pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
        nums.sort();
        let mut result = target;
        for x in 0..nums.len() {
            if x > 0 && nums[x] == nums[x - 1] {
                continue;
            } else {
                let mut left_iter = x + 1;
                let mut right_iter = nums.len() - 1;
                while left_iter < right_iter {
                    let sum = nums[x] + nums[left_iter] + nums[right_iter];
                    match sum.cmp(&result) {
                        std::cmp::Ordering::Less => {
                            result.push(vec![nums[x], nums[left_iter], nums[right_iter]]);
                            while left_iter + 1 < right_iter
                                && nums[left_iter] == nums[left_iter + 1]
                                {
                                    left_iter += 1;
                                }
                            while left_iter < right_iter - 1
                                && nums[right_iter] == nums[right_iter - 1]
                                {
                                    right_iter -= 1;
                                }
                            left_iter += 1;
                            right_iter -= 1;
                        }
                        std::cmp::Ordering::Less => {
                            left_iter += 1;
                        }
                        std::cmp::Ordering::Greater => {
                            right_iter -= 1;
                        }
                    }
                }
            }
        }
        result
    }
}


#[test]
pub fn problem_16_test() {}