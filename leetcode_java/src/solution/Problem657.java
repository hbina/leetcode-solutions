package solution;

public class Problem657 {
	/**
	 * Accepted by LeetCode. O(n) at all cases.
	 * 
	 * The idea is that the pairs (Up,Down) and (Left,Right) must terminate if the
	 * robot moves in a circle. since (0,0) + (L + R, U + D) = (0,0) then |L| = -|R|
	 * and -|U| = |D|.
	 */
	public boolean solution(String movementString) {
		int left = 0;
		int right = 0;
		int up = 0;
		int down = 0;

		for (int a = 0; a < movementString.length(); a++) {
			if (movementString.charAt(a) == 'L') { // left
				left++;
			} else if (movementString.charAt(a) == 'R') { // right
				right++;
			} else if (movementString.charAt(a) == 'U') { // up
				up++;
			} else if (movementString.charAt(a) == 'D') { // down
				down++;
			}
		}

		if ((left == right) && (up == down)) {
			return true;
		} else {
			return false;
		}
	}

	public static void main(String[] args) {

	}
}
