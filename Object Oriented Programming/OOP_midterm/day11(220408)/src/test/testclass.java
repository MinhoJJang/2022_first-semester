package test;

import java.util.Scanner;

public class testclass {
	public static void main(String[] args) {
		System.out.println("두 수를 입력하세요 (큰수, 작은수 입력)");
		
		int n1, n2;
		Scanner sc = new Scanner(System.in);
		n1 = sc.nextInt();
		n2 = sc.nextInt();
		
		double result;
		result = (n1+n2)/2.0;
		System.out.printf("두 수 사이의 숫자는 : %.2f 입니다", result);
		
	}
}
