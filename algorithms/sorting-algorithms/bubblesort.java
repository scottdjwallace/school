package bubblesort;

public class bubblesort {

	// bubble sort in ascending order
	public static int[] bubbleSort(int[] values) {
		boolean sorted = false;
		while (!sorted) {
			sorted = true;
			for (int i = 0; i < values.length - 1; i++){
				if (values[i] > values[i+1]) {
					sorted = false;
					int temp = values[i];
					values[i] = values[i+1];
					values[i+1] = temp;
				}
			}
		}
		return values;
	}
	
	public static void main(String[] args) {
		int[] nums = {2,5,1,12,3,7,23,4};
		int[] new_nums = bubbleSort(nums);
		for (int i = 0; i < new_nums.length; i++){
			System.out.println(new_nums[i]);
		}
	}
	
}
