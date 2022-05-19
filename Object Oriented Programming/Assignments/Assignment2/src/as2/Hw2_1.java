package as2;

import java.util.Scanner;

public class Hw2_1 {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String str;

		System.out.println("Please enter a line to be checked for profanity");
		str = sc.nextLine();
		System.out.println("Your input line");
		str = str.toLowerCase();
		boolean profane_flag = false;
		String[] profanity = new String[] { "cat", "dog", "llama" };

		for (int i = 0; i < profanity.length; i++) {
			if (str.contains(profanity[i])) {
				profane_flag = true;
				System.out.println("	contains " + profanity[i]);
			} else {
				System.out.println("	does not contain " + profanity[i]);
			}
		}

		if (profane_flag == true) {
			System.out.println("This line would be considered profane.");
		} else {
			System.out.println("This line wouldn't be considered profane.");
		}

	}
}
