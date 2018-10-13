package solution;

import tools.Performance;
import tools.Tools;

public class Problem5 {

	/**
	 * The retarded and naive way of solving this problem. I think its probably an
	 * O(n^2) or something tbh.
	 * 
	 * @param s
	 * @return the longest palindrome
	 */
	public static String solution1(String s) {

		// Local variables
		// int furthest = 0; // this is a placeholder that index will copy
		// int index = 0; // the index to iterate the string
		String currentLongestPal = "";
		/**
		 * The simplest case is that the string length is 1
		 */
		if (s.length() == 1) {
			currentLongestPal = s;
		} else {
			for (int index = 0; index < s.length(); index++) {
				if ((index + 1) != s.length()) {
					if (s.charAt(index) == s.charAt(index + 1)) {
						for (int i = 0; i < s.length(); i++) {
							int left = index - i;
							int right = index + i + 1;
							if ((left >= 0) && (right < s.length())) {
								/**
								 * Check if the current palindrome is the longest
								 */
								Tools.println("left:" + left + " right:" + right);
								if (s.charAt(left) == s.charAt(right)) {
									if (currentLongestPal.length() < s.substring(left, right + 1).length()) {
										Tools.println("The new longest palindrome is \"" + s.substring(left, right + 1)
												+ "\" replacing \"" + currentLongestPal + "\"");
										currentLongestPal = s.substring(left, right + 1);
									}
								}
							}
						}

						Tools.println("");
					} else {
						for (int i = 1; i < s.length(); i++) {
							int left = index - i;
							int right = index + i;
							if ((left >= 0) && (right < s.length())) {
								/**
								 * Check if the current palindrome is the longest
								 */
								Tools.println("left:" + left + " right:" + right);
								if (s.charAt(left) == s.charAt(right)) {
									if (currentLongestPal.length() < s.substring(left, right + 1).length()) {
										Tools.println("The new longest palindrome is \"" + s.substring(left, right + 1)
												+ "\" replacing \"" + currentLongestPal + "\"");
										currentLongestPal = s.substring(left, right + 1);
									}
								}
							}
						}

						Tools.println("");
					}
				}
			}
		}

		return currentLongestPal;
	}

	/**
	 * This method begins at index = 0, then find all identical characters in the
	 * string, then see if the pair contains the palindrome. I think this algorithm
	 * is O(n)??
	 * 
	 * @param s
	 * @return
	 */
	public static String solution2(String s) {
		String testSubstring = "", longestPal = "" + s.charAt(0);

		/**
		 * Iterate through the entire string and find a match on the other side of the
		 * string.
		 */
		for (int beginning = 0; beginning < s.length() - 1; beginning++) {
			Tools.println("" + beginning);
			for (int end = s.length() - 1; end > beginning + longestPal.length() - 1; end--) {
				if (s.charAt(beginning) == s.charAt(end)) {
					// Tools.println(beginning + ":" + s.charAt(beginning) + " " + end + ":" +
					// s.charAt(end));
					testSubstring = s.substring(beginning, end + 1);
					/**
					 * Check if the substring have even or odd length
					 */
					String left = "", right = "";
					if ((end - beginning) % 2 == 1) {
						// Tools.println(s.substring(beginning, end + 1) + " is even");
						left = s.substring(beginning, ((end + beginning) / 2) + 1);
						right = s.substring(((end + beginning) / 2) + 1, end + 1);
					} else {
						// Tools.println(s.substring(beginning, end + 1) + " is odd");
						if (beginning == ((end + beginning) / 2)) {
							// Tools.println("beginning == (end + beginning) / 2");
							left = "" + s.charAt(beginning);
							right = "" + s.charAt(end);
						} else {
							// Tools.println("beginning != (end + beginning) / 2");
							left = s.substring(beginning, ((end + beginning) / 2));
							right = s.substring(((end + beginning) / 2) + 1, end + 1);
						}
					}
					// Tools.println(left + " " + right + " from " + testSubstring +
					// System.lineSeparator());

					if (left.equals(Tools.inverseString(right))) {
						if (longestPal.length() < testSubstring.length()) {
							longestPal = testSubstring;
						}
					}
				}
			}
		}

		return longestPal;
	}

	/**
	 * 
	 * @param input:
	 *            The string to be checked.
	 * @return: The longest palindrome substring in the string.
	 */
	public static String solution3(String input) {
		return "";
	}

	public static void main(String[] args) {
		Performance perf = new Performance();
		perf.start();
		Tools.println("The longest palindrome found is \"" + solution2("aaaabaaa") + "\"");
		perf.end();
		Tools.println("executions take: " + perf.getTimeInSeconds() + " seconds.");
	}
}
