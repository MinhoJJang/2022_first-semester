package day15;

import java.util.Scanner;

public class test {
	public static final int readings = 100;
	
	public static void main(String[] args) {
		
		// arr 생성 방법
		Scanner keyboard = new Scanner(System.in);
		int numScores = keyboard.nextInt();
		// 1. 
		int[] pressure = new int[numScores];
		
		// 2. 
		int[] pressure1;
		pressure1 = new int[100];
		
		// 3
		int pressure2[] = new int[100]; // possible but, discouraged!
		
		// 4 
		int[] pressure3 = new int[readings]; // constant length
		
		// 5
		
		//int numScores = keyboard.nextInt();
		//int[] scores = new int[numScores]; // dynamic allocation
		
		
		// arr 초기화 
		for(int i=0; i<pressure.length; i++) {
			pressure[i] = i*i;
			System.out.printf("pressure[%d] = %d\n", i, pressure[i]);
		}
		
		int[] scores = { 68, 97, 102 };
		for(int i=0; i<scores.length; i++) {
			System.out.println("scores: "+scores[i]);
		}
		
		String[] myStringArray = new String[]{"a","b","c"};
		for(int i=0; i<myStringArray.length; i++) {
			System.out.println("myStringArray: "+myStringArray[i]);
		}
		
		
		
	}
	
}
