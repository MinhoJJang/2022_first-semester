package day12;


import java.util.Scanner;

public class SpeciesFirstTry extends Species{
	
	Species sp = new Species();
	
	public void readInput() {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("What is the species' name?");
		sp.setName(sc.nextLine());
		System.out.println("What is the population of the species?");
		sp.setPopulation(sc.nextInt());
		System.out.println("Enter growth rate (% increase per year)");
		sp.setGrowth_rate(sc.nextDouble());
	}
	
	public void writeOutput() {
		System.out.println("Name = " + sp.getName());
		System.out.println("Population = " + sp.getPopulation());
		System.out.println("Growth rate = " + sp.getGrowth_rate());
	}
	
	public int getPopulationIn10() {
		
		int result = (int) (sp.getPopulation() * Math.pow((100 + sp.getGrowth_rate()) / 100, 10));
		
		return result;
	}
	
}
