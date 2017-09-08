public class SelectionSort 
{
	public static void sort(int[] numbers)
	{
		for (int current = 0; current < numbers.length - 1; current++)
		{
			int smallest = Integer.MAX_VALUE;
			int smallestAt = current + 1;
			for (int check = current; check < numbers.length; check++)
			{
				if (numbers[check] < smallest)
				{
					smallestAt = check;
					smallest = numbers[check];
				}
			}
			int tmp = numbers[current];
			numbers[current] = numbers[smallestAt];
			numbers[smallestAt] = tmp;
		}
	}	
}
