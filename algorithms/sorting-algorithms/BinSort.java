public class BinSort {
	
	// Bin or Bucket sort
	public static void sort(int[] numbers)
	{
		int max = maxValue(numbers);
		int len = numbers.length;
		
		int[] Bucket = new int[max + 1];
		int[] sorted = new int[len];
		
		for (int i = 0; i < len; i++)
		{
			Bucket[numbers[i]]++;
		}
		
		int out = 0;
		for (int j = 0; j < Bucket.length; j++)
		{
			for (int k = 0; k < Bucket[j]; k++)
			{
				sorted[out++] = j;
			}
		}
		
	}
	
	public static int maxValue(int[] a)
	{
		int max = 0;
		for (int i = 0; i < a.length; i++)
		{
			if (max < a[i])
			{
				max = a[i];
			}
		}
		return max;
	}
	

}
