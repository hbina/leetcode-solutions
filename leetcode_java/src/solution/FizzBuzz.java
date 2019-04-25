package solution;

import java.util.ArrayList;
import java.util.List;

public class FizzBuzz {

	public static List<String> Solution(int n) {

		ArrayList<String> theArray = new ArrayList<String>(n);

		for (int a = 1; a <= n; a++) {
			if (((a % 3) == 0) && ((a % 5) == 0)) {
				theArray.add("FizzBuzz");
			} else if ((a % 5) == 0) {
				theArray.add("Buzz");
			} else if (((a % 3) == 0)) {
				theArray.add("Fizz");
			} else {
				theArray.add(String.valueOf(a));
			}
		}
		for (int b = 0; b < theArray.size(); b++) {
			System.out.println(theArray.get(b));
		}
		return theArray;
	}

	public static void main(String[] args) {
		Solution(15);
	}
}
