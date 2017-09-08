#Mergesort function which alsongside Merge function, performs
#a mergesort on the gven list
def MergeSort(list):
	if len(list) < 2:
		return list
	else:
		mid = len(list) / 2
		left = MergeSort(list[:mid])
		right = MergeSort(list[mid:])
		return Merge(left, right)
		
def Merge(left, right):
	merged = []
	left_index = 0
	right_index = 0
	while left_index < len(left) and right_index < len(right):
		if left[left_index] <= right[right_index]:
			merged.append(left[left_index])
			left_index += 1
		else:
			merged.append(right[right_index])
			right_index += 1
	if left:
		merged.extend(left[left_index:])
	if right:
		merged.extend(right[right_index:])
	return merged	