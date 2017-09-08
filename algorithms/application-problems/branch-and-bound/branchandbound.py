#!/usr/bin/python
import time
import copy
import random 

"""
Min-Heap class
-Stores our partial solutions.

Methods
-getSize = get size of heap
-getHeap = returns the heap
-parent = gets the parent of parameter
-left = gets the left child of the parameter
-right = gets the right child of the parameter
-Insert = add a value to heap
-BubbleUp = Used to keep the heap obeying the min heap property, moves updwards through heap
-BubbleDown = Used to keep the heap obeying the min heap property, moves upwards through heap
-DeleteRoot = saves root, removes root, returns root
-DeleteIndex = deletes value at index, and reshapes heap if necessary
-Fathom = removes all partials in heap with greater lower bound, than new global

"""

class Heap(object):
	
	def __init__(self):
		self.heap = []
		
	def getSize(self):
		return len(self.heap)
		
	def getHeap(self):
		return self.heap
		
	def parent(self,idx):
		return int((idx-1)/2)
		
	def left(self,idx):
		return idx*2 + 1
	
	def right(self,idx):
		return idx*2 + 2
		
	def Insert(self, value):
		self.heap.append(value)
		self.BubbleUp(self.getSize() - 1)
		
	def DeleteRoot(self):
		size = self.getSize() - 1
		if size == -1:
			return None
		elif size == 0:
			return self.heap.pop(0)
		else:
			current = self.heap[0]
			self.heap[0] = self.heap.pop(size)
			self.BubbleDown(0)
			return current
			
	def DeleteIndex(self,index):
		size = self.getSize() - 1
		if index == size:
			del self.heap[index]
		else:
			self.heap[index] = self.heap.pop(size)
			self.BubbleDown(index)
		
	def Fathom(self, upper):
		#delete all partials inside with higher lower bound, than new global upper bound
		i = self.getSize() - 1
		while i != 0:
			if self.heap[i][0] > upper:
				self.DeleteIndex(i)
			i -= 1
			
	def BubbleUp(self, index):
		parent = self.parent(index)
		while index != 0:
			#Parent lower lower bound than child
			if self.heap[parent][0] < self.heap[index][0]:
				break
			#Parent has equal bound as child
			elif self.heap[parent][0] == self.heap[index][0]:
				#Parent lower upper bound than child
				if self.heap[parent][1] < self.heap[index][1]:
					break
				#Parent has equal upper bound as child
				elif self.heap[parent][1] == self.heap[index][1]:
					#Parent is further from complete solution
					if len(self.heap[parent][2]) < len(self.heap[index][2]):
						self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
						index = parent
						parent = int((index-1)/2)
					else:
						break
				#Parent has greater  upper bound than child
				else:
					self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
					index = parent
					parent = int((index-1)/2)
			#Parent greater lower bound than child
			else:
				self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
				index = parent
				parent = self.parent(index)
		
	def BubbleDown(self, index): 
		left_c = self.left(index)
		right_c = self.right(index)
		smallest = index
		if left_c < self.getSize() - 1:
			if self.heap[left_c][0] < self.heap[smallest][0]:
				smallest = left_c
			elif self.heap[left_c][0] == self.heap[smallest][0]:
				if self.heap[left_c][1] < self.heap[smallest][1]:
					smallest = left_c
				elif self.heap[left_c][1] == self.heap[smallest][1]:
					if len(self.heap[left_c][2]) > len(self.heap[smallest][2]):
						smallest = left_c
		if right_c < self.getSize() - 1:
			if self.heap[right_c][0] < self.heap[smallest][0]:
				smallest = right_c
			elif self.heap[right_c][0] == self.heap[smallest][0]:
				if self.heap[right_c][1] < self.heap[smallest][1]:
					smallest = right_c
				elif self.heap[right_c][1] == self.heap[smallest][1]:
					if len(self.heap[right_c][2]) > len(self.heap[smallest][2]):
						smallest = right_c
		if smallest != index:
			self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
			self.BubbleDown(smallest)


"""
RowColReduction takes 2 lists as parameters.
These lists are the lists of previously made decisions in our partial solution.
Based on this it creates a guaranteed future cost using row, column reduction.
First row reduction is done, then column reduction.
Returns GFC (guaranteed future cost). 

"""	
def RowColReduction(illegal_rows, illegal_cols):
	global size
	global dataset
	min = 0
	GFC = 0
	copy_data = copy.deepcopy(dataset)
	for row in range(size):
		if row not in illegal_rows:
			min = copy_data[row][0]
			for col in range(size):
				if col not in illegal_cols:
					if min > copy_data[row][col]:
						min = copy_data[row][col]
			for col in range(size):
				if col not in illegal_cols:
					copy_data[row][col] -= min
		GFC += min
	for col in range(size):
		if col not in illegal_cols:
			min = copy_data[0][col]
			for row in range(size):
				if row not in illegal_rows:
					if min > copy_data[row][col]:
						min = copy_data[row][col]
			for row in range(size):
				if row not in illegal_rows:
					copy_data[row][col] -= min
		GFC += min
	return GFC
	
"""
RowReduction takes 2 lists as parameters.
These lists are the lists of previously made decisions in our partial solution.
Based on this it creates a guaranteed future cost using only row reduction.
Returns GFC (guaranteed future cost).

"""	
def RowReduction(illegal_rows, illegal_cols):
	global size
	global dataset
	min = 0
	GFC = 0
	copy_data = copy.deepcopy(dataset)
	for row in range(size):
		if row not in illegal_rows:
			min = copy_data[row][0]
			for col in range(size):
				if col not in illegal_cols:
					if min > copy_data[row][col]:
						min = copy_data[row][col]
			for col in range(size):
				if col not in illegal_cols:
					copy_data[row][col] -= min
		GFC += min
	return GFC

"""
SumOfDiagonals takes 2 lists as parameters.
These lists are the lists of previously made decisions in our partial solution.
Based on this it creates a feasible future cost using sum of diagonals.
Returns FFC (feasible future cost).

"""
def SumOfDiagonals(illegal_rows, illegal_cols):
	global size
	global dataset
	rows_copy = copy.deepcopy(illegal_rows)
	cols_copy = copy.deepcopy(illegal_cols)
	FFC = 0
	for row in range(size):
		if row not in rows_copy:
			for col in range(size):
				if col not in cols_copy:
					FFC += dataset[row][col]
					rows_copy += [row]
					cols_copy += [col]
					break
	return FFC

"""
GreedyHeuristics takes 2 lists as parameters.
These lists are the lists of previously made decisions in our partial solution.
Based on this it creates a feasible future cost using the greedy heuristics.
Returns FFC (feasible future cost).

"""	
def GreedyHeuristics(illegal_rows, illegal_cols):
	global size
	global dataset
	rows_copy = copy.deepcopy(illegal_rows)
	cols_copy = copy.deepcopy(illegal_cols)
	smallest = 100000000000
	smallest_row = 0
	smallest_col = 0
	col = 0
	FFC = 0
	for row in range(size):
		if row not in rows_copy:
			for col in range(size):
				if col not in cols_copy:
					if dataset[row][col] < smallest:
						smallest = dataset[row][col]
						smallest_row = row
						smallest_col = col
		FFC += smallest
		rows_copy += [smallest_row]
		cols_copy += [smallest_col]
		smallest = 100000000000
	return FFC

"""
MAIN PROGRAM
# Starts clock
# Open input file and create dataset matrix
# Creates initial upper and lower bound
# Creates initial heap with all first row choices
# Branch and Bound Algorithm

"""
start = time.clock() # Starts clock
heap = Heap()
dataset = []
complete_solution = []
optimal_pairs = []
partials_generated = 0
best_cost = 0
upper_bound = 0
lower_bound = 0

"""
Open input file and create dataset matrix

"""
for line in open('dataset3.txt').readlines():
    dataset.append(line.split())
size = int(dataset[0][0])
del dataset[0]
for i in range(size):
	for j in range(size):
		dataset[i][j] = int(dataset[i][j])

"""
Creates initial upper and lower bound
cost_so_far = 0
L = cost so far + guaranteed future cost
U = cost so far + feasible future cost

"""
upper_bound = SumOfDiagonals([],[])
#lower_bound = RowColReduction([],[])
#upper_bound = GreedyHeuristics([],[])
lower_bound = RowReduction([],[])

"""
Creates initial heap with all first row choices.
Heap has (0,0), (0,1), .... (0,size of dataset - 1)

"""
for i in range(size):
	chosen_rows = [0]
	chosen_cols = [i]
	cost_so_far = dataset[0][i] 
	#lower = cost_so_far + RowColReduction([0],[i])
	upper = cost_so_far + SumOfDiagonals([0],[i])
	lower = cost_so_far + RowReduction([0],[i])
	#upper = cost_so_far + GreedyHeuristics([0],[i])
	heap.Insert([lower, upper, chosen_rows, chosen_cols, cost_so_far])

"""
Branch and Bound Algorithm using Best first
Similar design to that from class notes.
"""
while True:
	current = heap.DeleteRoot()
	if current == None:
		break
	if len(current[2]) == size:
		best_cost = current[4]
		complete_solution = current
		break
	else:
		rows_selected = current[2]
		cols_selected = current[3]
		cost_so_far = current[4]
		new_rows = current[2] + [len(current[2])]
		for col in range(size):
			if col not in current[3]:
				new_cols = current[3] + [col]
				new_cost = cost_so_far + dataset[len(current[2])][col]
				#new_lower = new_cost + RowColReduction(new_rows, new_cols)
				new_upper = new_cost + SumOfDiagonals(new_rows, new_cols)
				new_lower = new_cost + RowReduction(new_rows, new_cols)
				#new_upper = new_cost + GreedyHeuristics(new_rows, new_cols)
				partial = [new_lower, new_upper, new_rows, new_cols, new_cost]
				#if new_lower <= upper_bound: 
				partials_generated += 1
				heap.Insert(partial)
				if new_upper < upper_bound:
					upper_bound = new_upper
					heap.Fathom(upper_bound)

"""
Creates optimals pairs list, from complete solution data

"""
for i in range(len(complete_solution[2])):
	optimal_pairs.append([complete_solution[2][i], complete_solution[3][i]])

#Ends timer
elapsed_time = time.clock() - start

#Prints results
print "***************************************"
print "Running B+B on dataset size", size
print "Optimal list of pairs: ", optimal_pairs #(candidate, constituency)
print "Partial solutions generated: ", partials_generated
print "Cost of Matching: ", best_cost
print "Elapsed time", elapsed_time
print "***************************************"