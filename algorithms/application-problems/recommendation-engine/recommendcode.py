
from random import *
from math import *
from easygui import *


def fuzzy_similarity(p1,p2):
	p1_sum = 0 #all values we will use later, start at zero
	p2_sum = 0
	intersection_sum = 0 
	similarity = 0 

	for i in customer_ratings[p1]: #calculates p1_sum and p2_sum
		p1_sum = p1_sum + customer_ratings[p1][i]
	for j in customer_ratings[p2]:
		p2_sum = p2_sum + customer_ratings[p2][j]
	p1_sum = p1_sum*1.0 #ensures that the values will no be rounded to zero
	p2_sum = p2_sum*1.0	
	
	for f in customer_ratings[p1]: #this will find if the 2 people like the same flavour or not
		for g in customer_ratings[p2]:
			if f == g: #if p1 and p2 like the same flavour we calculate the intersection score
				intersection_sum  = intersection_sum + min(customer_ratings[p1][f], customer_ratings[p2][g])
	similarity = min(intersection_sum/p1_sum,intersection_sum/p2_sum) #similarity score is the lower between intersection_sum divided by p1 or p2 sum
	return similarity	#returns a similarity score between p1 and p2

def best_match(p1):			
	global highest_similarity_person #global variables
	global highest_similarity
	best_dict = {} #dictionary of best matchs
	for a in customers: #for every customer
		if a == p1: #prevents the person being a match with themselves
			highest_similarity = highest_similarity # does nothing, prevents an indentation error
		else:
			best_dict[a] = fuzzy_similarity(p1, a) # puts the similarity score between p1 and a
			if best_dict[a] >= highest_similarity: #finds the highest similarity score
				highest_similarity = best_dict[a] 
				highest_similarity_person = a #person with the highest similarity to p1 becomes a and then it gets returned
	return highest_similarity
	return highest_similarity_person

def recommend(p1):
	high_flavour_score = 0
	recommend_flavour = "none"
	best_match(p1)
	for d in customer_ratings[p1]:
		for e in customer_ratings[highest_similarity_person]:
			if d == e:
				skip = 1 #skips flavour when they're the same
			elif customer_ratings[highest_similarity_person][e] >= high_flavour_score:
					high_flavour_score = customer_ratings[highest_similarity_person][e]
					recommend_flavour = e
	if highest_similarity == 0 or recommend_flavour == "none":
		return "Sorry, no recommendation"				
	else:
		return recommend_flavour
	
def other_recommend(p1):
	average_dict = {} #dictionary of average scores for every flavour
	second_recommend = "none" #no second flavour to recommend exists yet
	highest_average_score=0 
	for f in real_ice_cream_flavours: #for every flavour that exists
		n = 0 #number of times it gets rated
		average_score = 0 #its average score
		flavour_score = 0 #sum of flavour's ratings
		for c in customer_ratings: #for every customer
			for g in customer_ratings[c]: #for every flavour each customer likes
				if f == g: #if the flavour they like is equal to flavour being calculated
					flavour_score = flavour_score + customer_ratings[c][g] #adds the rating to the sum of the flavour scores
					n = n+1 #the flavours has shown up so it has been rated one more time
		if n >0:	#prevents a division by zero		
			average_score = flavour_score*1.0/n	#calculates the average score by dividing the sum of ratings by the number of times it was rated	 	
			average_dict[f] = average_score #places the average score in a dictionary with its key being the flavour
	for a in average_dict: #for every flavour in the dictionary of averages
		if a == recommend(p1) or a == customer_ratings[p1]: #skips a flavour to recommend if the flavour has been ranked by p1 or it has been recommended already by recommend
			skip = 1 #does nothing, just put in place to skip
		else:
			if average_dict[a] >= highest_average_score: #finds highest average score
				highest_average_score = average_dict[a]
				second_recommend = a
	if highest_average_score == 0:
		return "Sorry, no recommendation." #if the highest average score is zero, there is no recommendation
	else:
		return second_recommend #returns the second recommendation
	
# initialize customers list and real_ice_cream_flavours list
customers = [
			'Khan Noonien Singh',
			'Gully Foyle',
			'The Doctor',
			'Doc Brown',
			'Big Brother',
			'Paul Atreides',
			'HAL 9000',
			'Dave Bowman',
			'Marvin',
			'Ensign Flandry',
			'Princess Leia',
			'Ellen Ripley',
			'Jean-Luc Picard',
			'River Song',
			'Jack Harkness',
			'Ford Prefect',
			'Captain Nemo',
			'Phileas Fogg',
			'Buck Rogers',
			'Flash Gordon',
			'Katherine Janeway',
			'R. Daneel Olivaw',
			'Delenn',
			'Obiwan Kenobi',
			'Palmer Eldritch',
			'Hiro Protagonist',
			'Ender Wiggin',
			'Louis Wu',
			'Gaea',
			'Cirocco Jones',
			'Hari Seldon',
			'Podkayne Fries',
			'Valentine Michael Smith',
			'Hagbard Celine',
			'Jaime Sommers',
			'Buckaroo Banzai',
			'Rick Deckard',
			'Jernau Morat Gurgeh'
		]
		
real_ice_cream_flavours = [
			'Octopus',
			'Squid Gut',
			'Ox Tongue',
			'Sweet Potato',
			'Fried Eggplant',
			'Crab',
			'Corn',
			'Wasabi',
			'Shrimp',
			'Eel',
			'Chicken Wings',
			'Cactus',
			'Raw Horseflesh',
			'Shark Fin',
			'Oyster',
			'Seaweed',
			'Spinach',
			'Garlic',
			'Potato Liquor',
			'Tulip',
			'Pit Viper',
			'Tomato',
			'Spaghetti Bolognaise',
			'Tuna Fish',
			'Onion',
			'Fried Pork Rind',
			'Carrot',
			'Stilton Cheese',
			'Peanuts and Wine',
			'Chunky Bacon',
			'Mushroom Pecan',
			'Haddock'
		]

			
# create nested dictionary
customer_ratings = {}
num_flavours = len(real_ice_cream_flavours)
for p in customers:
	customer_ratings[p] = {}
	num_ratings = randint(num_flavours/3,num_flavours*2/3)
	chosen_flavours = sample(real_ice_cream_flavours,num_ratings)
	for f in chosen_flavours:
		# note that randint(a,b) returns a randomly chosen integer that is >= a and <= b
		customer_ratings[p][f] = randint(1,10)



# add the rest of the main program here
highest_similarity_person = "none"
highest_similarity = 0
for c in customer_ratings:
	print c,customer_ratings[c]	
#compare similarities
p1 = choicebox("Choose Your Character: ",choices=customers) #picks our customer
print "We recommend you try these flavours: "
print recommend(p1) #first recommendation
print other_recommend(p1) #second recommendation

"""
So I ran my script 15 consecutive times, and it produced recommendations everytime.  
I believe with enough characters and enough ice cream flavours you are very likely to get 2 different recommended flavours.
Originally i tested my script on 3 characters and 3 flavours, and I found the program returned "sorry, no recommendation" much more often than
when running this script with 32 flavours and 38 characters.  In conclusion the program gives consistent results as long as there is sufficient 
characters, flavours, and ratings.  However if these values are low, the program becomes less consistent, in this case, I found the other_recommend
was more consistent as similarity scores would be zero more often the average score of a flavour would be zero.
"""
