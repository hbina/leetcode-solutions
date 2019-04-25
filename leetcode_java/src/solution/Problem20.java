package solution;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.Arrays;

public class Problem20 {

	public static boolean solution(String s) {
		System.out.println("length:" + s.length());
		if (s.length() == 0) {
			return true;
		} else if (s.length() > 1) {
			final Character[] beg = new Character[] { '{', '[', '(' };
			final Character[] end = new Character[] { '}', ']', ')' };
			List<Character> begL = Arrays.asList(beg);
			List<Character> endL = Arrays.asList(end);
			Stack<Character> stackL = new Stack<Character>();
			for (int a = 0; a < s.length(); a++) {
				if (begL.contains(s.charAt(a))) {
					System.out.println("found beginning:" + s.charAt(a));
					stackL.add(s.charAt(a));
				} else if (endL.contains(s.charAt(a))) {
					if (stackL.empty()) {
						return false;
					} else {
						Character ss = stackL.pop();
						System.out.println("found end:" + s.charAt(a) + " pop:" + ss);
						if (begL.indexOf(ss) == endL.indexOf(s.charAt(a))) {
							System.out.println("correctly found the pair " + ss + ", " + s.charAt(a));
						} else {
							return false;
						}
					}
				} else {
					// do nothing
				}
			}
			if (stackL.isEmpty()) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

	public static void main(String[] args) {
		System.out.println(solution("(("));
	}
}
