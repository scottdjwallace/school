#algorithm used source: http://stackoverflow.com/questions/895371/bubble-sort-homework
#algorithm was modified to account for the list of lists, and keeping track of the agencies index
def bubblesort(values):
	length = len(values) - 1
	sorted = False
	#creates list of agency's index, this is so we know which agency is applied to, after the sort
	for i in range(length+1):
		agencies.append(i+1)	
	#bubblesort's in descending order based on the funding values
	while not sorted:
		sorted = True
		for i in range(length):
			if values[i][1] < values[i+1][1]:
				sorted = False
				values[i], values[i+1] = values[i+1], values[i]
				agencies[i], agencies[i+1] = agencies[i+1], agencies[i]
	print values			
	return values

#This is my greedy algorithm that calculates an optimal solution to the problem	
def valuesAlg(input):
	#only sort from 1-61, skips the first index of input, because its not an agency
	sorted = bubblesort(input[1:]) 
	a = 0
	while a != 60:
		#checks to see if we can do it on its deadline day
		day = sorted[a][0] - 1 
		if sorted[a][1] > opt[day][1]:
			opt[day] = sorted[a]
			opt_agcy[day] = agencies[a]
		#if theres already an application being done on that deadline then the else
		#keeps going backwards to see if there is a free day for that application
		else:  
			b = day
			while b >= 0 :
				if sorted[a][1] > opt[b][1]:
					opt[b] = sorted[a]
					opt_agcy[b] = agencies[a]
					b = 0
				b -= 1	
		a += 1 		
	return opt 
	
	
""" MAIN PROGRAM """

#Takes lab1input.txt and puts it into 2d matrix
agencies = []
with open('lab1input.txt') as lab1input:
	input =  [line.split() for line in lab1input]
#changes input data from strings to int's	
for x in input:
	x[0] = int(x[0])
	x[1] = int(x[1])
	
#initializes the optimal solution list, the agency index	
opt = [[0,0] for x in xrange(20)]
opt_agcy = [0]*20

#creates solution, from running the valuesAlg with the input
solution = valuesAlg(input)

#WRITING OUTPUT FILE
f = open('lab1output.txt','w')
day = 1
for x in solution:
	string = "Day: " + str(day) + "		Agency: " + str(opt_agcy[day-1]) + "	value " + str(x[1]) + "\n"
	f.write(string) 
	day += 1
funding = 0
for x in solution:
	funding += x[1]	
string2 = "Total Funding: " + str(funding)	
f.write(string2)	
f.close()
