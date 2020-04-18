class FizzBuzz {
	
	public static void main(String[] args) {

		for (int i = 1; i <= 500; i++) {
			
			String output = "";
			int[] nums = {3, 5};
			String[] words = {"Fizz", "Buzz"};

			for (int j = 0; j <= 1; j++)
				if (i % nums[j] == 0)
					output += words[j];

			if (output == "")
				output = String.valueOf(i);

			System.out.println(output);
		}
	}
}
