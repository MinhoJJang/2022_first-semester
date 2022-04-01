package practice_Hw1_7;

import java.util.Scanner;

public class Hw1_7 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		        
		final double chocobar = 230;
		int weight = sc.nextInt();
		int height = sc.nextInt();
		int age = sc.nextInt();
		
		double BMR_W = 655 + (4.3*weight) + (4.7*height) - (4.7*age);
		double BMR_M = 66 + (6.3*weight) + (12.9*height) - (6.8*age);
		
		System.out.printf("(woman) number of chocolate bars : %.1f\n", BMR_W/chocobar);
		System.out.printf("(man) number of chocolate bars : %.1f", BMR_M/chocobar);
		
	}
}
