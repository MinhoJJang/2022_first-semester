package as2;

// HW 2-6
public class ConcertPromoterMain {
	public static void main(String[] args) {
		ConcertPromoter cp = new ConcertPromoter();
		cp.setCapacityOfTheVenue(100);
		cp.setNameOfTheBand("Beatles");
		cp.setPriceOfPhone(10.5);
		cp.setPriceOfVenue(15.8);
		cp.setNumberOfTicketsSold(0);
		cp.setTotalSale(0);
		cp.setTicketsOnPhone(0);
		cp.setTicketsOnVenue(0);
		
		ConcertPromoterDAO c = new ConcertPromoterDAO();
		
		c.getRemainTickets(cp);
		c.buyTicketsOverPhone(cp, 10);
		c.getRemainTickets(cp);
		c.changeTheBuyingMethod(cp);
		
		c.buyTicketsAtConertVenue(cp, 55);
		c.getRemainTickets(cp);
		c.buyTicketsOverPhone(cp, 40);
		c.changeTheBuyingMethod(cp);
		c.changeTheBuyingMethod(cp);
		
		c.totalNumberOfTicketsSold(cp);
		c.totalSalesAmount(cp);
		
	}
}
