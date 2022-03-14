package day04;

public class CreatePencil {

	public static void main(String[] args) {
		Pencil p1 = new Pencil();
		p1.setPrice(200);
		p1.printPrice();
		
		p1.setColor("Green");
		System.out.println(p1.getColor());
	}

}
