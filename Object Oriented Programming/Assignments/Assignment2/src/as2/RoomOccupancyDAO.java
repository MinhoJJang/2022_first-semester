package as2;

public class RoomOccupancyDAO {
	public void addOneToRoom(RoomOccupancy ro) {
		System.out.println("Add one to room "+ro.getRoomName());
		ro.setNumberInRoom(ro.getNumberInRoom()+1);
		ro.setTotalNumber(ro.getTotalNumber()+1);
	}
	
	public void removeOneFromRoom(RoomOccupancy ro) {
		if(ro.getNumberInRoom() == 0) {
			System.out.println("There is no person to remove");
		} else {
			System.out.println("remove one to room "+ro.getRoomName());
			ro.setNumberInRoom(ro.getNumberInRoom()-1);
			ro.setTotalNumber(ro.getTotalNumber()-1);
		}
	}
	
	public void roomStatus(RoomOccupancy[] ro, int len) {

		for(int i=0 ;i<len; i++) {
			System.out.printf("Room %c holds %d\n", ro[i].getRoomName(), ro[i].getNumberInRoom());
		}
	System.out.println("Total in all rooms is "+ ro[0].getTotalNumber());
	}
}
