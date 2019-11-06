use crate::Solution;

// TODO ::  You can improve this algorithm by realizing that the iterations are symmetric.
//          For example, iterating from 0 --> 5 is equivalent to 5 --> 0 so we can actually split
//          split the calculations in half.
// TODO ::  You can also improve the algorithm by introducing generic types....
// NOTE ::  This algorithm can be infinitely improved by introducing more match cases.
impl Solution {
    pub fn num_trees(n: i32) -> u64 {
        match n {
            0 => 1,
            1 => 1,
            2 => 2,
            3 => 5,
            4 => 14,
            5 => 42,
            6 => 132,
            7 => 429,
            8 => 1430,
            9 => 4862,
            10 => 16796,
            11 => 58786,
            12 => 208012,
            13 => 742900,
            14 => 2674440,
            15 => 9694845,
            16 => 35357670,
            17 => 129644790,
            18 => 477638700,
            19 => 1767263190,
            20 => 6564120420,
            21 => 24466267020,
            22 => 91482563640,
            23 => 343059613650,
            24 => 1289904147324,
            25 => 4861946401452,
            26 => 18367353072152,
            27 => 69533550916004,
            28 => 263747951750360,
            29 => 1002242216651368,
            30 => 3814986502092304,
            31 => 14544636039226909,
            32 => 55534064877048198,
            33 => 212336130412243110,
            34 => 812944042149730764,
            35 => 3116285494907301262,
            36 => 11959798385860453492,
            _ => (1..=n).collect::<Vec<i32>>().iter().fold(0, |acc, &x| {
                let left = Solution::num_trees(x - 1);
                let right = Solution::num_trees(n - x);
                acc + left * right
            }),
        }
    }
}

#[test]
fn test() {
    assert_eq!(Solution::num_trees(3), 5);
    assert_eq!(Solution::num_trees(4), 14);
    assert_eq!(Solution::num_trees(5), 42);
}
