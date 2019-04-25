package solution;

public class AnonymousInterviewQuestions {

	public static void main(String[] args) {
		question2();
	}

	public static void question1(String name) {
		System.out.println(name);
	}

	public static void question2() {
		for (int a = 700; a >= 200; a = a - 13) {
			System.out.println(a);
		}
	}

	public static void question3() {
		int[] array = new int[10];
		System.out.println(array[1]);
	}
	
	
}
