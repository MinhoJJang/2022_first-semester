package practice_Hw1_5;

import java.util.Scanner;

public class Hw1_5 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the roll number : ");	
		int roll_number = sc.nextInt();
		
		// enter 개행문자 제거용
		sc.nextLine();
		
		System.out.println("Enter the name : ");	
		String name = sc.nextLine();
		
		System.out.println("Enter the address : ");	
		String address = sc.nextLine();
		
		System.out.println("Enter the course : ");	
		String course = sc.nextLine();
		
		System.out.printf("%s has roll no. %d\n", name, roll_number);
		System.out.printf("his address is %s and the course he studies is %s", address, course);
		
	}
}
