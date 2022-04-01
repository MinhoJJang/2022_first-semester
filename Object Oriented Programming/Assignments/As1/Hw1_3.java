package practice_2_2;

import java.util.Scanner;

public class Hw1_3 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
					
		// 문장 입력
		String sent = sc.nextLine();
		//System.out.println("문장 확인"+sent);
		
		// 입력한 문장을 공백으로 구분해 저장 
		String[] str = sent.split(" ");
		//System.out.println("저장확인 "+str[0]);
		
		// 이제 문장의 맨 앞 글자가 몇글자인지 알아보자. 
		int len = str[0].length();
		//System.out.println("len : "+len);
		
		// 일단 맨 앞글자를 맨 뒤로 보내자. 
		String firstSent = sent.substring(0, len);
		String restSent = sent.substring(len+1, sent.length());
		
		sent = restSent +" "+ firstSent;
		//System.out.println("뒤로 보내면 : "+sent);
		
		// 우리는 맨 앞에 위치한 문자의 맨 앞글자를 대문자로 바꿔야 한다. 
		// line of a text 라고 했으므로 최소 두 단어 이상이라고 가정하였다. 
		String initSent = sent.substring(0,1);
		String restSent2 = sent.substring(1, sent.length());
		
		initSent = initSent.toUpperCase();
		sent = initSent + restSent2;
		System.out.println(sent);
		
	}

}


