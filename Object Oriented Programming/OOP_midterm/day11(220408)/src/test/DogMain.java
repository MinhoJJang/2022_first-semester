package test;

public class DogMain {

	public static void main(String[] args) {
			Dog dog = new Dog();		
			dog.age = 5;
			System.out.println(dog.getAgeInHuman(dog.age));
	}
}
