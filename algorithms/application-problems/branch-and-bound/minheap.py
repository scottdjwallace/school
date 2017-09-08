#!/usr/bin/python
import time
import copy
import random 

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
				print "delete"
				print i
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
			#left child has smaller lower than parent
			if self.heap[left_c][0] < self.heap[smallest][0]:
				smallest = left_c
			#left child has equal lower bound with parent
			elif self.heap[left_c][0] == self.heap[smallest][0]:
				#left child has smaller upper bound than parent
				if self.heap[left_c][1] < self.heap[smallest][1]:
					smallest = left_c
				#left child has equal upper bound as parent
				elif self.heap[left_c][1] == self.heap[smallest][1]:
					#left child is closer to complete solution
					if len(self.heap[left_c][2]) > len(self.heap[smallest][2]):
						smallest = left_c
		#same logic as with left child, but for right child
		if right_c < self.getSize() - 1:
			if self.heap[right_c][0] < self.heap[smallest][0]:
				smallest = right_c
			elif self.heap[right_c][0] == self.heap[smallest][0]:
				if self.heap[right_c][1] < self.heap[smallest][1]:
					smallest = right_c
				elif self.heap[right_c][1] == self.heap[smallest][1]:
					if len(self.heap[right_c][2]) > len(self.heap[smallest][2]):
						smallest = right_c
		#if we changed smallest, then we need to swap and recursively start again
		if smallest != index:
			self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
			self.BubbleDown(smallest)
	