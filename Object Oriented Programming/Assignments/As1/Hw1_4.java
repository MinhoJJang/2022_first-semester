package practice_2_3;

import java.util.Random;

public class Hw1_4 {
	public static void main(String[] args) {
		
		final int dollar = 100;
		final int quarter = 25;
		final int dime = 10;
		final int nickel = 5;

		// 상품 가격을 랜덤함수로 뽑아내보자. 25~100 까지니까 25+a 로 가격이 나오면 된다. 또 5의 배수니까 price 가 5의 배수가
		// 될때까지 random 돌려준다.
		Random random = new Random();
		int price;
		do {
			price = random.nextInt(76) + 25;
		} while (price % 5 != 0);

		int change = dollar - price;
		int num_quarter;
		int num_dime;
		int num_nickel;

		// 동전 개수 구하기
		num_quarter = change / quarter;
		change -= num_quarter * quarter;

		num_dime = change / dime;
		change -= num_dime * dime;

		num_nickel = change / nickel;
		change -= num_nickel * nickel;

		System.out.printf(
				"for an item of %d cents, the change is %d cents, which is given by %d quarters, %d dimes and %d nickels",
				price, dollar - price, num_quarter, num_dime, num_nickel);

	}
}
