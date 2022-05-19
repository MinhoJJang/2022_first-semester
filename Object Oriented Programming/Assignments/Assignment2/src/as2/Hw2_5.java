package as2;

public class Hw2_5 {

	final static int ORANGE = 0;
	final static int EGG = 1;
	final static int APPLE = 2;
	final static int WATERMELON = 3;
	final static int BAGEL = 4;

	public static void setPurchase(Purchase p, String newName, int count, double costForCount, int number) {
		p.setName(newName);
		p.setPrice(count, costForCount);
		p.setNumberBought(number);
		System.out.printf("The cost of %ss is $%.2f\n", newName, p.getTotalCost());
	}

	public static void main(String[] args) {
		Purchase[] p = new Purchase[5];
		double totalCost = 0;

		for (int product = 0; product < p.length; product++) {
			p[product] = new Purchase();
			switch (product) {
			case ORANGE:
				setPurchase(p[product], "Orange", 10, 2.99, 24);
				break;
			case EGG:
				setPurchase(p[product], "Egg", 12, 1.69, 36);
				break;
			case APPLE:
				setPurchase(p[product], "Apple", 3, 1.00, 20);
				break;
			case WATERMELON:
				setPurchase(p[product], "Watermelon", 1, 4.39, 2);
				break;
			case BAGEL:
				setPurchase(p[product], "Bagle", 6, 3.50, 12);
				break;
			default:
				break;
			}
			totalCost += p[product].getTotalCost();
		}

		System.out.printf("totalCost of these products: $%.2f", totalCost);

	}
}
