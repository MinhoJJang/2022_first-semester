package day13;

public class Species {
	
	private String name;
	private int population;
	private double growth_rate;
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getPopulation() {
		return population;
	}
	public void setPopulation(int population) {
		this.population = population;
	}
	public double getGrowth_rate() {
		return growth_rate;
	}
	public void setGrowth_rate(double growth_rate) {
		this.growth_rate = growth_rate;
	}
	
	public boolean equals(Species otherObject) {
		
		if(this.name.equals(otherObject.getName()) && this.population == otherObject.getPopulation() && this.growth_rate == otherObject.getGrowth_rate()) {
			System.out.println("equal 상태입니다!");
			return true;
		}
		
		return false;
	}
}
