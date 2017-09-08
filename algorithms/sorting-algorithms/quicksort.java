package quicksort;

public class quicksort {
	
	
	private static int[] a;
	
	public static void sort(){
		int left = 0;
		int right = a.length - 1;
		
		quickSort(left, right);
	}
	
	private static void quickSort(int left, int right){
		if(left >= right) return;
		
		int pivot = a[right];
		int partition = partition(left, right, pivot);
		
		quickSort(0, partition - 1);
		quickSort(partition + 1, right);
	}
	
	private static int partition(int left, int right, int pivot){
		int left_cursor = left - 1;
		int right_cursor = right;
		
		while (left_cursor < right_cursor){
			while(a[++left_cursor] < pivot);
			while(right_cursor > 0 && a[--right_cursor] > pivot);
			if (left_cursor >= right_cursor){
				break;
			} else {
				swap(left_cursor, right_cursor);
			}
		}
		swap(left_cursor, right);
		return left_cursor;
	}
	
	public static void swap(int left, int right){
		int temp = a[left];
		a[left] = a[right];
		a[right] = temp;
	}
	
	public static void printArray(){
		for(int i : a){
			System.out.println(i);
		}
	}
	
	public static int[] getArray(){
		int size = 50;
		int[] array = new int[size];
		for (int i = 0; i < size; i++){
			array[i] = (int)(Math.random()*100);
		}
		return array;
	}

	public static void main(String[] args){
		// Creates a random array
		a = getArray();
		
		printArray();
		
		sort();
		
		System.out.println("");
		printArray();
		
		
	}
}
