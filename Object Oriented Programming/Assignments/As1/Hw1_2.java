package practice_2_1b;

import java.util.Scanner;

public class Hw1_2 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the temperature in Fahrenheit: ");
		double Fahrenheit = sc.nextDouble();
		double Celsius = (5*(Fahrenheit-32))/9;
		
		System.out.printf("Fahrenheit to Celsius = %.2f",Celsius);
	}
}
