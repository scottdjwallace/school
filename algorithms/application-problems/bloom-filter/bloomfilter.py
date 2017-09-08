import string
import math

#stores set of values of S, into V, using k hashing functions
def bloom_filter_insert(V,S,k,m):
	#initialize all values in v to 0
	for i in range(m):
		V.append(0)
	#hash and store a 1 in V
	for x in S:
		for i in range(1,k):
			V[h(x,i,m)] = 1

#hashing function
def h(x,i,m):
	num = 0
	#turns word into a number
	for j in range(len(x)):
		num = int('%d%d' % (num, ord(x[j])))
	return ((hash(num) + i*hash(num)) % m)

#Now, to test a value z for membership in S:
def memb_test(z,V,k,m):
	for i in range(1,k):
		if V[h(z,i,m)] == 0:
			#print "not in S" # because if z is in S, this bit would = 1
			return 0
	#print "in S"	
	return 1

#main program

#reads in words1.txt and words2.txt
words1 = open('words1.txt', 'r')
words2 = open('words2.txt', 'r')

# false positive 2%
m = 12000000
V = []
k = 7

# false positive 1%
#m = 12138000
#V =[]
#k = 5

# false positive 0.5%
#m = 24276000
#V = []
#k = 10 

# false positive 0.2%
#m = 46023250
#V = []
#k = 13

#false positive 0.1%
#m = 77885500
#V= []
#k = 22

#creates bloom filter
S = words1.readlines()
bloom_filter_insert(V, S, k, m)

#testing for false positives
T = words2.readlines()
falpos = 0
words2total = 0
for b in T:
	words2total += 1.0
	falpos += memb_test(b,V,k,m)
falposperc = (falpos / words2total)*100
print "The Percentage false positive is:"
print falposperc
words1.close()
words2.close()

"""
#looping i used to test k and m values

for b in range(10,31):
	#creates bloom filter

	words1 = open('words1.txt', 'r')
	words2 = open('words2.txt', 'r')
	k = b
	m = k*20230*175
	V = []
	
	print k
	print m
	print V

	S = words1.readlines()
	bloom_filter_insert(V, S, k, m)

	#testing for false positives
	T = words2.readlines()
	falpos = 0
	words2total = 0
	for b in T:
		words2total += 1.0
		falpos += memb_test(b,V,k,m)
	falposperc = (falpos / words2total)*100
	print "The Percentage false positive is:"
	print falposperc
	print
	words1.close()
	words2.close()
"""	