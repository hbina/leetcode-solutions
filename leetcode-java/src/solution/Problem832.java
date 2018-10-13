package solution;

import tools.Tools;

public class Problem832 {
	/**
	 * Given a binary matrix A, we want to flip the image horizontally, then invert
	 * it, and return the resulting image.
	 * 
	 * To flip an image horizontally means that each row of the image is reversed.
	 * For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
	 * 
	 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced
	 * by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
	 */

	public static int[][] solution(int[][] giv) {
		Tools.printArray(giv);
		System.out.print("\nafter:");
		for (int i = 0; i < giv.length; i++) {
			int end = giv[i].length - 1;
			for (int j = 0; j < giv[i].length / 2; j++) {
				giv[i][j] = giv[i][j] ^ giv[i][end - j];
				giv[i][end - j] = giv[i][j] ^ giv[i][end - j];
				giv[i][j] = giv[i][j] ^ giv[i][end - j];
			}
		}
		for (int i = 0; i < giv.length; i++) {
			for (int j = 0; j < giv[i].length; j++) {
				giv[i][j] = giv[i][j] ^ 1;
			}
		}
		Tools.printArray(giv);
		return giv;
	}

	public static void main(String[] args) {
		solution(new int[][] { { 1, 1, 0 }, { 1, 0, 1 }, { 0, 0, 0 } });
		solution(new int[][] { { 0 } });
	}
}
