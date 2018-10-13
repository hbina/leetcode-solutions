package solution;

import java.util.ArrayList;
import java.util.List;

public class FindDisappearedNumbers {
	public static List<Integer> Solution(int[] nums) {

		// Read into the array
		List<Integer> list = new ArrayList<Integer>(nums.length);
		for (int a = 0; a < nums.length; a++) {
			int val = Math.abs(nums[a]) - 1;
			nums[val] = -Math.abs(nums[val]);
		}

		for (int b = 0; b < nums.length; b++) {
			if (nums[b] > 0) {
				list.add(b + 1);
			}
		}
		return list;
	}

	public static void main(String[] args) {
	}
}