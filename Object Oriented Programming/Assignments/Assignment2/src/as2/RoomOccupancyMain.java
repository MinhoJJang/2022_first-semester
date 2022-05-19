package as2;

// Hw 2-7
public class RoomOccupancyMain {
	
	final static int a = 0;
	final static int b = 1;
	final static int c = 2;

	public static void main(String[] args) {
		RoomOccupancy[] ro = new RoomOccupancy[3];
		RoomOccupancyDAO rdao = new RoomOccupancyDAO();
		
		int len = 0;
		ro[a] = new RoomOccupancy('a', 3);
		len++;
		
		rdao.addOneToRoom(ro[a]);
		rdao.addOneToRoom(ro[a]);
		rdao.removeOneFromRoom(ro[a]);
		rdao.roomStatus(ro, len);
		
		ro[b] = new RoomOccupancy('b', 2);
		len++;
		ro[c] = new RoomOccupancy('c', 1);
		len++;
		
		rdao.roomStatus(ro, len);
		rdao.addOneToRoom(ro[b]);
		rdao.removeOneFromRoom(ro[c]);
		rdao.removeOneFromRoom(ro[c]);
		rdao.roomStatus(ro, len);
}}
