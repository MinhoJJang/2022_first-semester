package as2;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Locale;
import java.util.Scanner;

public class Hw2_2 {

	final static int MONTH = 0;
	final static int DAY = 1;
	final static int YEAR = 2;

	public static boolean dateCheck(String checkDate) {
		
		SimpleDateFormat dateFormatParser = new SimpleDateFormat("MM/dd/yyyy/", Locale.KOREA);

		dateFormatParser.setLenient(false);
		try {
			dateFormatParser.parse(checkDate);
			return true;
		} catch (ParseException e) {
			System.out.println("It is not a valid date");
			return false;
		}
	}
	
	public static void whatIsNotValid(int[] date) {
		
		int month = date[MONTH];
		int day = date[DAY];
		int year = date[YEAR];
		
		// 1. month check 
		System.out.print("The reason it is invalid: ");
		if(month < 1 || month > 12) {
			System.out.println("The month value is not from 1 to 12.");
		return;
		}
		
		// 2. year check 
		boolean leapYear = false;
		if(year % 4 == 0) {
			leapYear = true;
		}
		if(year % 4 ==0 && year % 100 == 0) {
			leapYear = false;
		}
		if(year % 4 ==0 && year % 100 == 0 && year % 400 == 0) {
			leapYear = true;
		}
		
		// 3. day check 
		int maxDateOfMonth;
		switch (month) {
		case 2:
			maxDateOfMonth = 28;
			if(leapYear) {
				maxDateOfMonth = 29;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			maxDateOfMonth = 30;
			break;
		default:
			maxDateOfMonth = 31;
			break;
		}
		
		if(day > maxDateOfMonth || day < 1) {
			System.out.println("The day value is not from 1 to "+maxDateOfMonth);
		}
	}

	public static void main(String[] args) {

		System.out.println("Please enter a date to be checked using mm/dd/yyyy/ format");
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();

		String[] date_s = str.split("/");
		int[] date = new int[3];
		for(int i=0; i<3; i++) {
			date[i] = Integer.parseInt(date_s[i]);
		}
		System.out.printf("date is %d month %d day %d year\n", date[MONTH], date[DAY], date[YEAR]);
		
		boolean isValid = dateCheck(str);
		
		if (!isValid) {
			whatIsNotValid(date);
		}

	}
}
