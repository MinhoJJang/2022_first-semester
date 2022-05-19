package as2;

public class RoomOccupancy {
	
	private char roomName;
	private int numberInRoom;
	private static int totalNumber = 0;
	
	public RoomOccupancy(char room, int num) {
		super();
		System.out.printf("Add one to room %c and add %d to it.\n", room, num);
		setRoomName(room);
		setNumberInRoom(num);
		totalNumber += num;
	}
	public int getNumberInRoom() {
		return numberInRoom;
	}
	public void setNumberInRoom(int numberInRoom) {
		this.numberInRoom = numberInRoom;
	}
	public int getTotalNumber() {
		return totalNumber;
	}
	public void setTotalNumber(int totalNumber) {
		this.totalNumber = totalNumber;
	}
	public char getRoomName() {
		return roomName;
	}
	public void setRoomName(char roomName) {
		this.roomName = roomName;
	}
	
}
