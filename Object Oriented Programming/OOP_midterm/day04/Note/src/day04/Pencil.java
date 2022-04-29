package day04;

public class Pencil {
	
	public String color = "white";
	public int length;
	public float diameter;
	private float price;
	public static long nextID = 0;

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	public int getLength() {
		return length;
	}

	public void setLength(int length) {
		this.length = length;
	}

	public float getDiameter() {
		return diameter;
	}

	public void setDiameter(float diameter) {
		this.diameter = diameter;
	}

	public float getPrice() {
		return price;
	}

	public void setPrice(float newPrice) {
		price = newPrice;
	}

	public void printPrice() {
		System.out.println(price);
	}

}