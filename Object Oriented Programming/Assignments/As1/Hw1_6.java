package practice_Hw1_6;

import java.util.Scanner;

public class Hw1_6 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int decimal = sc.nextInt();
		int octal;
		
		// decimal 숫자를 10^ 로 나눠서 각 숫자 자리마다의 값을 구하고 octal 로 바꿔주면 된다. 	
		// 세자리밖에 안되서 하드코딩했다. 만약 자리수가 많아진다면, 아래 써놓은 100, 64 같은 숫자들을 모두 pow(10,i), pow(8,i) 같은 꼴로 바꿔서 for 문에 넣으면 된다. 
		int a = (decimal/100) * 64;
		decimal -= 100*(decimal/100);
		int b = (decimal/10) * 8;
		decimal -= 10*(decimal/10);
		int c = decimal;
		
		octal = a+b+c;
		System.out.println(octal);
		
	}
}
