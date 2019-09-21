package stringArrayTest;

public class stringArrayTest {

	public static void main(String[] args) {
		String[][] array = new String[2][2];
		
		array[0][0] = "Gavin";
		array[0][1] = "Dorri";
		array[1][0] = "Brent";
		array[1][1] = "Thomas";
		
		System.out.println(array[0][0] + array[0][1] + array[1][0] + array[1][1]);
	}

}
