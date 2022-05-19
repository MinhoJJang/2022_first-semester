package as2;

import java.util.Scanner;

public class Hw2_4 {
	public static void main(String[] args) {

		Scanner  sc = new Scanner(System.in);
		String str = sc.nextLine();
		char[] input_char = str.toCharArray();
	
		int len = input_char.length;
		int key = (int)(Math.random()*99)+1;
		System.out.println("key : "+  key);
		
		int[] ASCII_code = new int[len];
		
		for(int i=0; i<len; i++) {
			ASCII_code[i] = (int)input_char[i];
			ASCII_code[i] += key;
			input_char[i] = (char)ASCII_code[i];
			System.out.print(input_char[i]);
		}
		
	}
}
