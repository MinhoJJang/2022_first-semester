package as2;

import java.util.Scanner;

public class Hw2_3 {
	
	public static void findHighLow(double[] temp) {
		double low = temp[0];
		double high = temp[0];
		int len = temp.length;
		
		for(int i=1; i<len; i++) {
			if(low > temp[i]) {
				low = temp[i];
			}
			
			if(high < temp[i]){
				high = temp[i];
			}
		}

		System.out.println("Highest temperature is "+high);
		System.out.println("Lowest temperature is "+low);

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		String[] temperature_s = str.split(" ");
		int len = temperature_s.length;
		double[] temp = new double[len];
		double avg = 0;
		for(int i=0; i<len; i++) {
			temp[i] = Double.parseDouble(temperature_s[i]);
			avg += temp[i];
		}
		
		avg /= len;
		findHighLow(temp);
		System.out.printf("Average temperature is %.0f", avg);
	}

}
