package day15;

import java.util.Scanner;

public class ArrayOfTemperatures {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("How many temperatures do you have?");
		int numberofTemp = sc.nextInt();
		double[] temp = new double[numberofTemp];
		
		System.out.printf("Enter %d temperatures\n", numberofTemp);
		double sum = 0;
		for(int i=0; i<temp.length; i++) {
			temp[i] = sc.nextDouble();
			sum += temp[i];
		}
		
		double avg = sum/numberofTemp;
		System.out.println("The average temperature is "+avg);
		System.out.println("The temperatures are");
		for(int i=0; i<temp.length; i++) {
			if(temp[i]<avg) {
				System.out.println(temp[i]+" below average");
			}
			else if(temp[i]>avg) {
				System.out.println(temp[i]+" above average");
			}
			else {
				System.out.println(temp[i]+" same as average");
			}
			
		}
		System.out.println("Have a nice week");
		
	}
}
