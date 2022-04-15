package day12;

public class SpeciesMain {

	public static void main(String[] args) {
		
		SpeciesFirstTry sft = new SpeciesFirstTry();
		
		sft.readInput();
		sft.writeOutput();
		System.out.println("In ten years the population will be "+sft.getPopulationIn10());
		

	}

}
