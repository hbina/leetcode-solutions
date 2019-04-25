package solution;

public class HammingDistance {
	public static int Solution(int x, int y) {
		// Solution here
		// --Convert integer to binary;
		// --Fill out the smaller bit to have the same bits as the larger one;
		// Compare the two;
		String a = Integer.toBinaryString(x);
		String b = Integer.toBinaryString(y);
		if (a.length() > b.length()) {
			String c = "";
			for (int d = 0; d < (a.length() - b.length()); d++) {
				c += "0";
			}
			b = c + b;
		} else if (b.length() > a.length()) {
			String c = "";
			for (int d = 0; d < (b.length() - a.length()); d++) {
				c += "0";
			}
			a = c + a;
		}
		int counter = 0;
		for (int d = 0; d < a.length(); d++) {
			if (a.charAt(d) != b.charAt(d)) {
				counter++;
			}
		}
		return counter;
	}

	public static void main(String[] args) {
		Solution(89, 75);
	}
}