package day13;

public class SpeciesMain {

	public static void main(String[] args) {
		
		SpeciesFirstTry sft = new SpeciesFirstTry();
		
		Species sp1 = new Species();
		Species sp2 = new Species();
		
		sft.readInput(sp1);
		sft.readInput(sp2);
		sft.writeOutput(sp1);
		System.out.println("In ten years the population will be "+sft.getPopulationIn10(sp1));
		
		sp1.equals(sp2);
	}

}
