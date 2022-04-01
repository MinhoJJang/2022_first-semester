package practice_2_1a;

import java.util.Scanner;

public class Hw1_1 {
	/*
Read a four-digit integer, such as 2017
– Display one digit per line, e.g., 2, 0, 1, and 7 in each line
	*/
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int year = sc.nextInt();
		int i = 10;
		
		
		while(year >0) {
			int num = year%i;
		System.out.printf("%d\n", num);
		year /= i;
		}
		
	}
	
	
}
