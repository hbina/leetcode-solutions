package solution;

public class Problem219 {
	/**
	 * Given an array of integers and an integer k, find out whether there are two
	 * distinct indices i and j in the array such that nums[i] = nums[j] and the
	 * absolute difference between i and j is at most k.
	 */

	public static boolean solution(int[] arr, int k) {
		for (int a = 0; a < arr.length; a++) {
			for (int b = a + 1; b <= k + a; b++) {
				if (b < arr.length) {
					if (arr[a] == arr[b]) {
						return true;
					}
				}
			}
		}
		return false;
	}

	public static void main(String[] args) {
		System.out.println(solution(new int[] { 1, 2, 3, 1, 2, 3 }, 2));
	}
}
