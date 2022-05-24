package as2;

public class Hw2_8 {

	final static int row = 4;
	final static int column = 5;

	public static double[][] findFigure(double[][] picture, double threshold) {

	
		double[][] newPicture = new double[row][column];
		double avg = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				avg += picture[i][j];
			}
		}
		avg /= (row * column);

		double referenceValue = avg * threshold;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (picture[i][j] > referenceValue) {
					newPicture[i][j] = 1.0;
				}
			}
		}

		return newPicture;
	}

	public static void printPicture(double[][] picture) {

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				System.out.print(picture[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		double[][] picture = { { 1.2, 1.3, 4.5, 6.2, 2.7 }, { 1.7, 3.3, 4.4, 10.5, 17.0 }, { 1.1, 4.5, 2.1, 25.3, 9.2 },
				{ 1.0, 9.5, 8.3, 2.9, 2.1 } };

		double avg = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				avg += picture[i][j];
			}
		}
		avg /= (row * column);

		double threshold = 1.4;
		double[][] newPicture1 = new double[row][column];
		newPicture1 = findFigure(picture, threshold);
		printPicture(newPicture1);
		
		System.out.println("=====================");

		threshold = 0.6;
		double[][] newPicture2 = new double[row][column];
		newPicture2 = findFigure(picture, threshold);
		printPicture(newPicture2);

	}
}
