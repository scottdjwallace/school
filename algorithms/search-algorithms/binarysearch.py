#Performs a standard recursive binary search for a target value 
def BinarySearch(list, target, start, end):
	if start >= end:
		return "No."
	else:
		mid = (start+end)/2		
		if list[mid] == target:
			return "Yes."
		elif list[mid] > target:
			return BinarySearch(list,target,start,mid-1)
		else:
			return BinarySearch(list,target,mid+1,end)
			