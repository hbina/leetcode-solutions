use crate::Solution;

impl Solution {
    pub fn simplify_path(path: String) -> String {
        let mut stack: Vec<&str> = Vec::new();
        path.split('/').for_each(|c: &str| {
            if c == ".." {
                if stack.len() > 0 {
                    stack.pop();
                }
            } else if c != "." && c.len() > 0 {
                stack.push(c);
            }
        });
        if stack.is_empty() {
            String::from("/")
        } else {
            stack
                .into_iter()
                .filter(|c| !c.is_empty())
                .fold(String::new(), |mut acc, x| {
                    acc.push_str("/");
                    acc.push_str(x);
                    acc
                })
        }
    }
}

#[test]
fn succeeding() {
    let a = String::from("/home/");
    assert_eq!(Solution::simplify_path(a), String::from("/home"));
    let a = String::from("/../");
    assert_eq!(Solution::simplify_path(a), String::from("/"));
    let a = String::from("/home//foo/");
    assert_eq!(Solution::simplify_path(a), String::from("/home/foo"));
    let a = String::from("/a/./b/../../c/");
    assert_eq!(Solution::simplify_path(a), String::from("/c"));
    let a = String::from("/a/../../b/../c//.//");
    assert_eq!(Solution::simplify_path(a), String::from("/c"));
    let a = String::from("/a//b////c/d//././/..");
    assert_eq!(Solution::simplify_path(a), String::from("/a/b/c"));
}
