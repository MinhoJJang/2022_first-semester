package as2;

public class ConcertPromoterDAO {
	
	public void buyTicketsOverPhone(ConcertPromoter cp, int ticket) {
		
		if(ticket > cp.getCapacityOfTheVenue() - cp.getNumberOfTicketsSold()) {
			System.out.println("There is no enough tickets. Let me check.");
			getRemainTickets(cp);
			return;
		}
		
		System.out.printf("It need $%.2f to buy a ticket over phone\n", cp.getPriceOfPhone()*ticket);
		cp.setNumberOfTicketsSold(cp.getNumberOfTicketsSold()+ticket);
		cp.setTicketsOnPhone(cp.getTicketsOnPhone()+ticket);
	}
	
	public void buyTicketsAtConertVenue(ConcertPromoter cp, int ticket) {
		if(ticket > cp.getCapacityOfTheVenue() - cp.getNumberOfTicketsSold()) {
			System.out.println("There is no enough tickets. Let me check.");
			getRemainTickets(cp);
			return;
		}
		System.out.printf("It need $%.2f to buy a ticket at the concert venue\n", cp.getPriceOfVenue()*ticket);
		cp.setNumberOfTicketsSold(cp.getNumberOfTicketsSold()+ticket);
		cp.setTicketsOnVenue(cp.getTicketsOnVenue()+ticket);
	}
	
	public void getRemainTickets(ConcertPromoter cp) {
		int remain = cp.getCapacityOfTheVenue() - cp.getNumberOfTicketsSold();
		if(remain > 0) {
			System.out.printf("you can buy up to %d tickets\n", remain);
		}
		else {
			System.out.println("Sorry, there is no ticket left.");
		}
	}
	
	public void changeTheBuyingMethod(ConcertPromoter cp) {
		System.out.printf("It need $%.2f more money to change the buying method\n", cp.getPriceOfVenue() - cp.getPriceOfPhone());
		cp.setTicketsOnPhone(cp.getTicketsOnPhone() - 1);
		cp.setTicketsOnVenue(cp.getTicketsOnVenue() + 1);
	}
	
	public void totalSalesAmount(ConcertPromoter cp) {
		cp.setTotalSale(cp.getPriceOfPhone()*cp.getTicketsOnPhone() + cp.getPriceOfVenue()*cp.getTicketsOnVenue());
		System.out.printf("The total sales amount is : %.2f", cp.getTotalSale());
	}
	
	public void totalNumberOfTicketsSold(ConcertPromoter cp) {
		System.out.println("The total number of tickets purchased by phone :"+cp.getTicketsOnPhone());
		System.out.println("The total number of tickets purchased on venue :"+cp.getTicketsOnVenue());
		System.out.println("The total number of tickets sold is: "+cp.getNumberOfTicketsSold());

	}
	
	
}
