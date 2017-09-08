import random

class Graph_Vertex (object):
	
	def __init__(self,
				value = '',
				neighbours = [],
				visited = 0,
				parent = '',
				distance = 0
				):
		self.value = value
		self.neighbours = neighbours
		self.visited = visited
		self.parent = parent
		self.distance = distance
	
	def search(self, target):
		#searches to see if the target is a neighbour
		for value in self.neighbours:
			if value == target:
				return True #they are neighbours
		return False #they are not neighbours		
		
		
class Graph (object):		

	def __init__(self,
				vertices = []
				):
		self.vertices = vertices
	
	def Find_Diameter(self,vertices):
		diam = 0
		max = 0
		for vrtx in range(vertices):
			self.BFS(vrtx)
			for x in range(vertices):
				diam = self.vertices[x].distance
				if diam > max:
					max = diam
				self.vertices[x].distance = 0
				self.vertices[x].visited = 0
		return max		
				
	def BFS(self,start):
		Q = [] #queue
		self.vertices[start].visited = 1
		Q.append(start) #add start to queue
		while (Q):
			#let rtx be first vertex in Q
			vrtx = Q[0]
			parent = vrtx
			#dequeue v from Q
			Q.remove(vrtx)
			for y in self.vertices[vrtx].neighbours:
				if (self.vertices[y].visited != 1):
					self.vertices[y].parent = parent
					self.vertices[y].distance = 1 + self.vertices[parent].distance
					self.vertices[y].visited = 1
					Q = [y] + Q

	def Create_Graph(self,vertices):
		#creates all vertices in our Graph Object
		for i in range(vertices):
			self.vertices.append(i)
			self.vertices[i] = Graph_Vertex()
			self.vertices[i].value = i
			self.vertices[i].neighbours = []
		
		#this makes i and p neighbours
		for i in range(1,vertices):
			p = random.randint(0,i-1)
			self.vertices[i].neighbours.append(p)
			self.vertices[p].neighbours.append(i)
			
		
	def Add_Edges(self,edges):
		for k in range(1,edges):
			v1 = random.randint(0,edges-1)
			v2 = random.randint(0,edges-1)
			already_neighbours = self.vertices[v1].search(v2)
			if (v1 != v2): 
				if (already_neighbours == False):
					self.vertices[v1].neighbours.append(v2)
					self.vertices[v2].neighbours.append(v1)
#PART 1 
vertices = 8
edges = 8
graph_p1 = Graph()
graph_p1.Create_Graph(vertices)
diameter_p1 = graph_p1.Find_Diameter(vertices)

#Print for Part 1 Correctness Proof before more edges are added
print "Correctness Proof for Part 1, Before Extra Edges\n"
for i in range(vertices):
	print "Adjacency List For Vertex", graph_p1.vertices[i].value
	print graph_p1.vertices[i].neighbours,"\n"
print "Diameter of the Tree, before: ", diameter_p1, "\n"	

graph_p1.Add_Edges(edges)
diameter_p1_2 = graph_p1.Find_Diameter(vertices)
			
#Print for Part 1 Correctness Proof after more edges are added
print "Correctness Proof for Part 1, After Extra Edges\n"
for i in range(vertices):
	print "Adjacency List For Vertex", graph_p1.vertices[i].value
	print graph_p1.vertices[i].neighbours,"\n"
print "Diameter of the Tree, after: ", diameter_p1_2, "\n"


#PART 2
k = 10
# vertices and edges
n = 100  
#n = 200
#n = 400
#n = 800
#n = 1600
tree_list = []
graph_list = []
for test in range(1,k+1):
	test_graph = Graph()
	test_graph.Create_Graph(n)
	tree_diameter = test_graph.Find_Diameter(n)
	tree_list.append(tree_diameter)
	test_graph.Add_Edges(n)
	graph_diameter = test_graph.Find_Diameter(n)
	graph_list.append(graph_diameter)
#average tree diameter
tree_sum = 0
tree_avg = 0
for x in tree_list:
	tree_sum = tree_sum + x
tree_avg = tree_sum / (k * 1.0)	
#average graph diameter
graph_sum = 0
graph_avg = 0
for y in graph_list:
	graph_sum = graph_sum + y
graph_avg = graph_sum / (k * 1.0)
#print info
print "Experiment on Sample Size K: ", k
print "Number of Vertices: ",n
print "Added Edges: ", n
print "Average Tree Diameter: ", tree_avg
print "Average Graph Diameter: ", graph_avg

