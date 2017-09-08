import random
import time
import re
import math

#Binary Search and MergeSort concepts 
#and psuedo from last year's CISC 121 course
#Merge function help from rosettacode.org, there were a few issues 
#debugging and this resource was used

#Algorithm A, takes an unsorted list and searches 
#for a target value given in the parameters
def AlgorithmA(list,target):
	for i in range(len(list)):
		if list[i] == target:
			return "Yes."
	return "No."

#Algorithm B, the mergesort happens in main before AlgorithmB
#is called, the reason for an Algorithm B function itself where 
#BinarySearch could be called is for style symmetry 
def AlgorithmB(list,target,start,end):	
	return BinarySearch(list, target, start, end)

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
			
#MAIN PROGRAM

k = 10
#k = 100
#k = 150
#k = 207
#k = 10000 
#how many k values are we searching for
print "K*(n) = ", k


#For n = 1000 tests Algorithm A and B with k many searches
print "n = 1000"
list1 = []
for i in range(1000):
	list1.append(random.randrange(1,10000,2))
#Algorithm A	
timeA = time.clock() 
for m in range(k):
	AlgorithmA(list1,m)	
print "Algorithm A Time = ", (time.clock() - timeA)
#Algorithm B
timeB = time.clock()
list1 = MergeSort(list1)
for m in range(k):
	AlgorithmB(list1,m,0,1000)
print "Algorithm B Time = ", (time.clock() - timeB)


#For n = 2000 tests Algorithm A and B with k many searches
print "n = 2000"
list2 = []
for i in range(2000):
	list2.append(random.randrange(1,10000,2))
#Algorithm A	
timeAA = time.clock() 
for m in range(k):
	AlgorithmA(list2,m)	
print "Algorithm A Time = ", (time.clock() - timeAA)
#Algorithm B
timeBB = time.clock()
list2 = MergeSort(list2)
for m in range(k):
	AlgorithmB(list2,m,0,2000)
print "Algorithm B Time = ", (time.clock() - timeBB)
	
	
#For n = 5000 tests Algorithm A and B with k many searches	
print "n = 5000"
list3 = []
for i in range(5000):
	list3.append(random.randrange(1,10000,2))
#Algorithm A	
timeAAA = time.clock() 
for m in range(k):
	AlgorithmA(list3,m)	
print "Algorithm A Time = ", (time.clock() - timeAAA)
#Algorithm B
timeBBB = time.clock()
list3 = MergeSort(list3)
for m in range(k):
	AlgorithmB(list3,m,0,5000)
print "Algorithm B Time = ", (time.clock() - timeBBB)	


#For n = 10000 tests Algorithm A and B with k many searches
print "n = 10000"
list4 = []
for i in range(10000):
	list4.append(random.randrange(1,10000,2))
#Algorithm A	
timeAAAA = time.clock() 
for m in range(k):
	AlgorithmA(list4,m)	
print "Algorithm A Time = ", (time.clock() - timeAAAA)
#Algorithm B
timeBBBB = time.clock()
list4 = MergeSort(list4)
for m in range(k):
	AlgorithmB(list4,m,0,10000)
print "Algorithm B Time = ", (time.clock() - timeBBBB)	