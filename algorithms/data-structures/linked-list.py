class Node(object):
	
	def __init__(self,
				value = 0,
				next = None):
		self.value = value
		self.next = next
		
	def get_value(self):
		return self.value
		
		
		

class Linked_List(object):
	
	def __init__(self):
		self.head = None
		self.tail = None
		
		
	def append(self,value):
		new_node = Node(value)
		if self.head == None:
			self.head = new_node
			self.tail = new_node
		else:
			self.tail.next = new_node
			self.tail = new_node
			
	def prepend(self,value):
		new_node = Node(value)
		if self.head == None:
			self.head = new_node
			self.tail = new_node
		else:
			new_node.next = self.head
			self.head = new_node
			

	def insert_in_order(self,value):
		new_node = Node(value)
		if self.head == None:
			self.head = new_node
			self.tail = new_node
		elif value <= self.head.value:
			new_node.next = self.head
			self.head = new_node
		else:
			previous = self.head
			current = self.head.next
			while current != None and current.value < value:
				previous = current
				current = current.next
			new_node.next = current
			previous.next = new_node
			
	def insert_in_position(self,value,position):
		print "not written yet"
			
	def remove(self,value):
		if self.head == None:
			return
		elif self.head.value == value:
			print 'not written yet'
			
		else:
			print 'not written yet'
			
	def remove_all(self,value):
		print 'not written yet'

	def print_list(self):
		current = self.head
		while current != None:
			print current.value,
			current = current.next
		print
		
		
	def get_length(self):
		my_len = 0
		current == self.head
		while current != None:
			my_len += 1
			current = current.next
		return my_len
			
# main program

		
my_list = Linked_List()
my_list.append(1)
my_list.append(2)
my_list.prepend(3)
my_list.print_list()

sorted_list = Linked_List()
sorted_list.insert_in_order(7)
sorted_list.insert_in_order(2)
sorted_list.insert_in_order(23)
sorted_list.insert_in_order(11)
sorted_list.print_list()
