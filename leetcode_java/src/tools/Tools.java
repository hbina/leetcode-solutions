package tools;

public class Tools {

	/**
	 * A shorted print function provided by Java.
	 * 
	 * @param string: The string to be printed.
	 */
	public static void println(String string) {
		System.out.println(string);
	}

	/**
	 * Inverses a given string.
	 * 
	 * @param input: The string to be inverted.
	 * @return: The inverted string.
	 */
	public static String inverseString(String input) {
		char[] temparray = input.toCharArray();
		int left, right = 0;
		right = temparray.length - 1;
		for (left = 0; left < right; left++, right--) {
			// Swap values of left and right
			char temp = temparray[left];
			temparray[left] = temparray[right];
			temparray[right] = temp;
		}
		input = "";
		for (char c : temparray)
			input += c;
		return input;
	}

	public static void printArray(int[][] giv) {
		System.out.println("");
		for (int a = 0; a < giv.length; a++) {
			for (int b = 0; b < giv[a].length; b++) {
				System.out.print(giv[a][b]);
				if (b < (giv[a].length - 1)) {
					System.out.print(" ");
				}
			}
			if (a < (giv.length - 1)) {
				System.out.println("");
			}
		}
	}
}
