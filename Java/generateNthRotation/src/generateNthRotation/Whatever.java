package generateNthRotation;

public class Whatever
{
	public static void main(String[] args)
	{
		int[] array = {1,2,3,4,5,6,7,8,9};
		for (int i = 0; i < array.length; i++)
		{
			System.out.print(array[i] + ", ");
		}
		System.out.println();
		int n = 4;
		int[] finalArray = generateNthRotation(array, n);
		for (int i = 0; i < array.length; i++)
		{
			System.out.print(finalArray[i] + ", ");
		}
	}

	public static int[] generateNthRotation(int[] array, int n) 
	{
		int nthRotation = n % array.length;
		int[] returnArray = new int[array.length];

		for (int i = 0; i < array.length; i++) 
		{
			returnArray[i] = array[(array.length - nthRotation + i) % array.length];
		}
		
		return returnArray;
	}	
}