package test;

public class Dog {
	public String name;
	public String breed;
	public int age;

	public void writeOutput() {
		
	}
	
	public int getAgeInHuman(int age) {
		
		int humanAge =0;
		if(age <= 2) {
			humanAge = age*11;
		}
		else {
			humanAge = 22+((age-2)*5);
		}
		
		return humanAge;
	}
}
