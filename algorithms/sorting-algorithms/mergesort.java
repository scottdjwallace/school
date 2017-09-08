package merge;
import java.util.*;

public class mergesort {
	
	public static void main(String[] args) {
		Integer[] a = {2, 6, 3, 5, 1};
		mergeSort(a);
		System.out.println(Arrays.toString(a));
	}
	
	public static void mergeSort(Comparable[] array) {
		Comparable[] temp = new Comparable[array.length];
		mergeSort(array, temp,  0,  array.length - 1);
	}
	
	private static void mergeSort(Comparable[] array, Comparable[] temp, int left, int right) {
		if (left < right) {
			int mid = (left + right) / 2;
			mergeSort(array, temp, left, mid);
			mergeSort(array, temp, mid+1, right);
			merge(array, temp, left, mid+1, right);
		}
	}
	
	private static void merge(Comparable[] array, Comparable[] temp, int left, int right, int rightEnd) {
		int leftEnd = right - 1;
		int k = left;
		int num = rightEnd - left + 1;
		
		while (left <= leftEnd && right <= rightEnd) {
			if (array[left].compareTo(array[right]) <= 0) {
				temp[k++] = array[left++];
			} else {
				temp[k++] = array[right++];
			}
		}
		
		while (left <= leftEnd) {
			temp[k++] = array[left++];
		}
		
		while (right <= rightEnd) {
			temp[k++] = array[right++];
		}
		
		for (int i = 0; i < num; i++, rightEnd--) {
			array[rightEnd] = temp[rightEnd];
		}
	}

}
