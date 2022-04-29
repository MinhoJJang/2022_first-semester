package day04;

public class EggBasket {

	public static void main(String[] args) {
		
		// Scanner 사용해서 숫자 받아도 됨! 
		
		int eggs = 6;
		int baskets = 10;
		int totalEggs = baskets * eggs;
		
		System.out.printf("If you have\n");
		System.out.printf("%d eggs per basket and\n", eggs);
		System.out.printf("%d baskets, then\n", baskets);
		System.out.printf("the total number of eggs is %d", totalEggs);
		

	}

}
