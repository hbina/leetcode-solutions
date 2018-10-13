package solution;

public class Problem217 {

	/**
	 * Given an array of integers, find if the array contains any duplicates.
	 * 
	 * Your function should return true if any value appears at least twice in the
	 * array, and it should return false if every element is distinct.
	 */
	public static boolean solution(int[] arr) {
		for (int a = 0; a < arr.length; a++) {
			for (int b = a + 1; b < arr.length; b++) {
				if (arr[a] == arr[b]) {
					return true;
				}
			}
		}
		return false;
	}
}
