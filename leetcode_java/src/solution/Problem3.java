package solution;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

import tools.Performance;

public class Problem3 {

	/**
	 * My first answer. O(n^2) in the case where the string contain exclusively
	 * repeating characters.
	 * 
	 * This is a slower version of the LeetCode's given answer. This algorithm
	 * iterates through the whole string and whenever it finds a duplicate it will
	 * go back to that character and start iterating again from there.
	 * 
	 * This is based from the understanding that a candidate for the longest
	 * non-repeating substring is either the whole string (if all characters are
	 * unique) or within 2 duplicate characters i.e.
	 * a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,a,... <--- a candidate for the longest
	 * substring must be a_2 - a_1, ignoring everything in between.
	 * 
	 * @param givenString:
	 *            the string that we want to find the length of the longest
	 *            substring of.
	 * @return the length of the longest substring in a given string.
	 */
	public static int solution(String givenString) {
		HashMap<Character, Integer> charSet = new HashMap<Character, Integer>();
		int lengthCounter = 0;
		int maxCounter = 0;

		for (int a = 0; a < givenString.length(); a++) {
			// System.out.println(s.charAt(a));
			if (!charSet.containsKey(givenString.charAt(a))) { // we have NOT yet encountered a repeating character
				charSet.put(givenString.charAt(a), a);
				lengthCounter++;
			} else { // we have encountered a repeating character, reset
				if (lengthCounter > maxCounter) {
					maxCounter = lengthCounter;
				}
				lengthCounter = 0;
				a = charSet.get(givenString.charAt(a));
				charSet = new HashMap<Character, Integer>();
			}
		}

		if (lengthCounter > maxCounter) {
			return lengthCounter;
		} else {
			return maxCounter;
		}
	}

	/**
	 * LEETCODE'S ANSWER
	 * 
	 * Sliding Window algorithm. O(n).
	 * 
	 * This algorithm iterates through the string, leaving a tail of last duplicate.
	 * When it found one, it compares the distance (head - tail) and previously
	 * evaluated max distance.
	 * 
	 * ___________________________first run________________________________________
	 * tail----------head-------------------------------------------------------end
	 * 
	 * ___________________________second run_______________________________________
	 * 0----------- tail ------------head---------------------------------------end
	 * -----d_1----------- d_2-----------------------------------------------------
	 * 
	 * Then it checks if d_2 > d_1.
	 * 
	 * @param givenString:
	 *            the string that we want to check the longest non-repeating
	 *            substring of.
	 * @return the length of the longest substring in the given string
	 */
	public static int answer2(String givenString) {
		int stringLength = givenString.length();
		Set<Character> set = new HashSet<>();
		int ans = 0, tail = 0, head = 0;
		while (tail < stringLength && head < stringLength) {
			// try to extend the range [i, j]
			if (!set.contains(givenString.charAt(head))) {
				set.add(givenString.charAt(head++));
				ans = Math.max(ans, head - tail);
			} else {
				set.remove(givenString.charAt(tail++));
			}
		}
		return ans;
	}

	public static void main(String[] args) {

		Performance perf = new Performance();
		String[] testString = {
				"aniewqmoxkjwpymqorluxedvywhcoghotpusfgiestckrpaigocfufbubiyrrffmwaeeimidfnnzcphkflpbqsvtdwludsg" };
		for (String test : testString) {
			perf.start();
			System.out.println(solution(test));
			perf.end();

			System.out.println(perf.getTime());

			perf.start();
			System.out.println(answer2(test));
			perf.end();

			System.out.println(perf.getTime());
		}
	}
}
