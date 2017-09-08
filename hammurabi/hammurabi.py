from random import *
from sys import *



def badbushels(x,price_per_acre):
	msg =  "Hammurabi: Think again.  You have only " + str(x) + " bushels of grain.  Now then, " + price_per_acre + "?"
	return input(msg)
	
def badacres(x,price_per_acre):
	msg =  "Hammurabi: Think again.  You own only " + str(x) + " acres.  Now then, how many acres do you wish to " + price_per_acre + "?"
	return input(msg)
	
def rand5():
	return randint(1,6)
	
def cannot():
	print "Hammurabi: I cannot do what you wish. Get yourself another steward."

def impeached():
	msg = "You starved " + str(starving_people) + " people in one year!!!  " 
	msg += "Due to this extreme mismanagement you have not only " 
	msg += "been impeached and thrown out of office but you have " 
	msg += "also been declared 'National Fink' !!"
	print msg

def bad():
	msg =   "Your heavy-handed performance smacks of Nero and Ivan IV.  " 
	msg += "The people (remaining) find you an unpleasant ruler, and, " 
	msg += "frankly, hate your guts!"
	print msg

def ok():
	msg =   "Your performance could have been somewhat better, but " 
	msg += "really wasn't too bad at all. \n\n" +str(int(population*0.8*random())) 
	msg += " people would dearly like to see you assassinated but we all have our trivial problems."
	print msg

def fantastic():
	msg =   "A fantastic performance!!  Charlemagne, Disraeli, and " 
	msg += "Jefferson combined could not have done better!"
	print msg
	
def endgame():
	playagain = input("Would you like to play again? Enter 1 for Yes, or Enter 2 for no: ")
	if playagain==1:
		print "Have Fun!"
		difficulty()
	elif playagain==2:
		print "So long for now"
		exit("Done")
	else:
		endgame()
		
	
def status_report(population,acres_owned,price_per_acre,eaten_by_rats,bushels):	
	status =   "Population is now " + str(population) + "\n"
	status += "The city owns " +  str(acres_owned) + " acres of land.\n"
	status += "You harvested " + str(price_per_acre)  + " bushels of grain per acre.\n"
	status += "Rats ate " + str(eaten_by_rats) + " bushels.\n"
	status += "You now have " + str(bushels) + " bushels in store.\n\n"
	return status
	
def status_report_easy(population,acres_owned,price_per_acre,bushels):	
	status =   "Population is now " + str(population) + "\n"
	status += "The city owns " +  str(acres_owned) + " acres of land.\n"
	status += "You harvested " + str(price_per_acre)  + " bushels of grain per acre.\n"
	status += "You now have " + str(bushels) + " bushels in store.\n\n"
	return status	
	
def mini_status_report(population,acres_owned,bushels):
	status =   "Population is " + str(population) + "\n"
	status += "The city owns " +  str(acres_owned) + " acres of land.\n"
	status += "You have " + str(bushels) + " bushels in store.\n\n"
	return status
	
def population_under40(population):
	if population < 40:
		print "It's the hard mode for a reason, Your population dropped under 40, and now you lose!"
		endgame()
		
def city_overrun(population,acres_owned):
	if  population < acres_owned/15.0 :
		print "HAMMURABI THE CITY'S BEEN OVERRUN! You lose!"
		endgame()	
			
def game_standard(): #main game
	total_deaths = 0	#d1
	total_population = 0	#p1
	year = 0	#z
	population = 95	#p
	bushels = 2800	#s
	harvest = 3000	#h
	eaten_by_rats = harvest-bushels	#e
	price_per_acre = 3	#y
	acres_owned = harvest/3	#a
	pop_growth = 5	#i
	acres_bought = 1	#q
	starving_people = 0	#d0


	while year < 11:
		
		year = year+1
		msg =    "Hammurabi:\n\nI beg to report to you that "	
		msg +=  "in Year " + str(year) + ",\n" + str(starving_people) + " people starved, and " + str(pop_growth) + " came to the city.\n\n"
		
		population = population+pop_growth

		if acres_bought <= 0:
			population = population/2
			msg = msg + "A horrible plague struck!  Half the people died.\n\n"
		
		print msg + status_report(population,acres_owned,price_per_acre,eaten_by_rats,bushels)
		
		c = randint(0,10)
		price_per_acre = c + 17					# price of land
		
		msg = mini_status_report(population,acres_owned,bushels) + "Land is trading at " +  str(price_per_acre) + " bushels per acre.  How many acres do you wish to buy?"
		acres_bought = input(msg)
		
		while price_per_acre*acres_bought > bushels:
			acres_bought = badbushels( bushels,"how many acres do you wish to buy")
			
		if acres_bought < 0:
			cannot()
			endgame()
			
		if acres_bought > 0:
			acres_owned = acres_owned + acres_bought
			bushels = bushels - price_per_acre*acres_bought
			c = 0
		else:
			msg = mini_status_report(population,acres_owned,bushels) + "Land is trading at " +  str(price_per_acre) + " bushels per acre.  How many acres do you wish to sell?"
			acres_bought = input(msg)
			
			while acres_bought > acres_owned:   
				acres_bought = badacres(acres_owned,"sell")
				
			if acres_bought < 0:
				cannot()
				endgame()
				
			acres_owned = acres_owned - acres_bought			# a = remaining land (acres)
			bushels = bushels + price_per_acre*acres_bought
			c = 0
		
		msg = mini_status_report(population,acres_owned,bushels) + "How many bushels do you wish to feed your people?"
		acres_bought = input(msg)
		
		while acres_bought > bushels:
			acres_bought = badbushels(bushels,"how many bushels do you wish to feed your people")
			
		if acres_bought < 0:
			cannot()
			endgame()
			
		bushels = bushels - acres_bought
		c = 1
		
		msg = mini_status_report(population,acres_owned,bushels) + "How many acres do you wish to plant with seed?"
		
		starving_people = input(msg)
		
		while ((starving_people > acres_owned) or (starving_people > 2*bushels) or (starving_people > 10*population)):
			if starving_people > 10*population:
				msg2 = "But you only have " + str(population) + " people to tend the fields."
				print msg2
			elif starving_people > 2*bushels:
				msg2 = "But you only have enough grain to plant " + str(2*bushels) + " acres."
				print msg2
			else:
				msg2 = "But you only have " + str(acres_owned) + " acres."
				print msg2
			starving_people = input(msg)
		if starving_people < 0:
			cannot()
			endgame()
		
		bushels = bushels - starving_people/2
			
		c = rand5()
		
		price_per_acre = c
		harvest = starving_people*price_per_acre						# harvest
		eaten_by_rats = 0
		
		c = rand5()
		
		if c % 2 == 0:					# rats
			eaten_by_rats = bushels/c
			
		bushels = bushels - eaten_by_rats + harvest
		
		c = rand5()
		
		pop_growth = int(c*(20.0*acres_owned + bushels)/population/100 + 1)	# population growth
		
		c = acres_bought/20						# people fed
		
		acres_bought = int(10*(2*random() - 0.3))	# 
		
		if population > c:
			starving_people = population - c					# number starved
			if starving_people > 0.45*population:
				impeached()
				endgame()
			else:
				total_population = ((year-1)*total_population + starving_people*100.0/population)/year
				population = c
				total_deaths = total_deaths + starving_people
		else:
			starving_people = 0
		
		city_overrun(population,acres_owned) #is the city getting overrun at the end of the year?
		
	# closing of game	
		
	msg =   "In your 10-year term of office, " + str(int(total_population)) + " percent of the " 
	msg += "population starved per year on average, i.e. a total of " +	  str(total_deaths) + " people died.\n\n"

	l = 1.0*acres_owned/population

	msg += "You started with 10 acres per person and ended with " + str(l) + " acres per person.\n\n"

	print msg

	if ((total_population > 33) or (l < 7)):
		impeached()
	elif ((total_population > 10) or (l < 9)):
		bad()
	elif ((total_population > 3) or (l < 10)):
		ok()
	else:
		fantastic()	
		
	endgame()

def game_easy(): #main game easy
	total_deaths = 0	#d1
	total_population = 0	#p1
	year = 0	#z
	population = 95	#p
	bushels = 3000	#s
	harvest = 3000	#h
	price_per_acre = randint(2,8)	#y also yield per acre
	acres_owned = harvest/price_per_acre	#a
	pop_growth = 5	#i
	acres_bought = 1	#q
	starving_people = 0	#d0


	while year < 11:
		
		year = year+1
		msg =    "Hammurabi:\n\nI beg to report to you that "	
		msg +=  "in Year " + str(year) + ",\n" + str(starving_people) + " people starved, and " + str(pop_growth) + " came to the city.\n\n"
		
		population = population+pop_growth

		#no plagues

		print msg + status_report_easy(population,acres_owned,price_per_acre,bushels)
		
		c = randint(0,10)
		price_per_acre = c + 17					# price of land
		
		msg = mini_status_report(population,acres_owned,bushels) + "Land is trading at " +  str(price_per_acre) + " bushels per acre.  How many acres do you wish to buy?"
		acres_bought = input(msg)
		
		while price_per_acre*acres_bought > bushels:
			acres_bought = badbushels( bushels,"how many acres do you wish to buy")
			
		if acres_bought < 0:
			cannot()
			endgame()
			
		if acres_bought > 0:
			acres_owned = acres_owned + acres_bought
			bushels = bushels - price_per_acre*acres_bought
			c = 0
		else:
			msg = mini_status_report(population,acres_owned,bushels) + "Land is trading at " +  str(price_per_acre) + " bushels per acre.  How many acres do you wish to sell?"
			acres_bought = input(msg)
			
			while acres_bought > acres_owned:   
				acres_bought = badacres(acres_owned,"sell")
				
			if acres_bought < 0:
				cannot()
				endgame()
				
			acres_owned = acres_owned - acres_bought			# a = remaining land (acres)
			bushels = bushels + price_per_acre*acres_bought
			c = 0
		
		msg = mini_status_report(population,acres_owned,bushels) + "How many bushels do you wish to feed your people?"
		acres_bought = input(msg)
		
		while acres_bought > bushels:
			acres_bought = badbushels(bushels,"how many bushels do you wish to feed your people")
			
		if acres_bought < 0:
			cannot()
			endgame()
			
		bushels = bushels - acres_bought
		c = 1
		
		msg = mini_status_report(population,acres_owned,bushels) + "How many acres do you wish to plant with seed?"
		
		starving_people = input(msg)
		
		while ((starving_people > acres_owned) or (starving_people > 2*bushels) or (starving_people > 10*population)):
			if starving_people > 10*population:
				msg2 = "But you only have " + str(population) + " people to tend the fields."
				print msg2
			elif starving_people > 2*bushels:
				msg2 = "But you only have enough grain to plant " + str(2*bushels) + " acres."
				print msg2
			else:
				msg2 = "But you only have " + str(acres_owned) + " acres."
				print msg2
			starving_people = input(msg)
		if starving_people < 0:
			cannot()
			endgame()
		
		bushels = bushels - starving_people/2 #review
			
		c = rand5()
		
		price_per_acre = c
		harvest = starving_people*price_per_acre						# harvest
		
		c = rand5()
		
		#no rats
			
		bushels = bushels + harvest
		
		c = rand5()
		
		pop_growth = int(c*(20.0*acres_owned + bushels)/population/100 + 1)	# population growth
		
		c = acres_bought/15						# people fed
		
		acres_bought = int(10*(2*random() - 0.3))	# chance of plague ... 15% ????
		
		if population > c:
			starving_people = population - c					# number starved
			if starving_people > 0.45*population:
				impeached()
				endgame()
			else:
				total_population = ((year-1)*total_population + starving_people*100.0/population)/year
				population = c
				total_deaths = total_deaths + starving_people
		else:
			starving_people = 0
		
		city_overrun(population,acres_owned)
		
	# closing of game	
		
	msg =   "In your 10-year term of office, " + str(int(total_population)) + " percent of the " 
	msg += "population starved per year on average, i.e. a total of " +	  str(total_deaths) + " people died.\n\n"

	l = 1.0*acres_owned/population

	msg += "You started with 10 acres per person and ended with " + str(l) + " acres per person.\n\n"

	print msg

	if ((total_population > 33) or (l < 7)):
		impeached()
	elif ((total_population > 10) or (l < 9)):
		bad()
	elif ((total_population > 3) or (l < 10)):
		ok()
	else:
		fantastic()	
		
	endgame()

def game_hard(): #main game
	total_deaths = 0	#d1
	total_population = 0	#p1
	year = 0	#z
	population = 95	#p
	bushels = 2800	#s
	harvest = 3000	#h
	eaten_by_rats = harvest-bushels	#e
	price_per_acre = randint(1,4)	#y also yield
	acres_owned = harvest/3	#a
	pop_growth = 5	#i
	acres_bought = 1	#q
	starving_people = 0	#d0


	while year < 11:
		
		year = year+1
		msg =    "Hammurabi:\n\nI beg to report to you that "	
		msg +=  "in Year " + str(year) + ",\n" + str(starving_people) + " people starved, and " + str(pop_growth) + " came to the city.\n\n"
		
		population = population+pop_growth

		if acres_bought <= 0:
			population = population/2
			msg = msg + "A horrible plague struck!  Half the people died.\n\n"
		
		population_under40(population)

		print msg + status_report(population,acres_owned,price_per_acre,eaten_by_rats,bushels)
		
		c = randint(0,10)
		price_per_acre = c + 17					# price of land
		
		msg = mini_status_report(population,acres_owned,bushels) + "Land is trading at " +  str(price_per_acre) + " bushels per acre.  How many acres do you wish to buy?"
		acres_bought = input(msg)
		
		while price_per_acre*acres_bought > bushels:
			acres_bought = badbushels( bushels,"how many acres do you wish to buy")
			
		if acres_bought < 0:
			cannot()
			endgame()
			
		if acres_bought > 0:
			acres_owned = acres_owned + acres_bought
			bushels = bushels - price_per_acre*acres_bought
			c = 0
		else:
			msg = mini_status_report(population,acres_owned,bushels) + "Land is trading at " +  str(price_per_acre) + " bushels per acre.  How many acres do you wish to sell?"
			acres_bought = input(msg)
			
			while acres_bought > acres_owned:   
				acres_bought = badacres(acres_owned,"sell")
				
			if acres_bought < 0:
				cannot()
				endgame()
				
			acres_owned = acres_owned - acres_bought			# a = remaining land (acres)
			bushels = bushels + price_per_acre*acres_bought
			c = 0
		
		msg = mini_status_report(population,acres_owned,bushels) + "How many bushels do you wish to feed your people?"
		acres_bought = input(msg)
		
		while acres_bought > bushels:
			acres_bought = badbushels(bushels,"how many bushels do you wish to feed your people")
			
		if acres_bought < 0:
			cannot()
			endgame()
			
		bushels = bushels - acres_bought
		c = 1
		
		msg = mini_status_report(population,acres_owned,bushels) + "How many acres do you wish to plant with seed?"
		
		starving_people = input(msg)
		
		while ((starving_people > acres_owned) or (starving_people > 2*bushels) or (starving_people > 10*population)):
			if starving_people > 10*population:
				msg2 = "But you only have " + str(population) + " people to tend the fields."
				print msg2
			elif starving_people > 2*bushels:
				msg2 = "But you only have enough grain to plant " + str(2*bushels) + " acres."
				print msg2
			else:
				msg2 = "But you only have " + str(acres_owned) + " acres."
				print msg2
			starving_people = input(msg)
		if starving_people < 0:
			cannot()
			endgame()
		
		bushels = bushels - starving_people/2
			
		c = rand5()
		
		price_per_acre = c
		harvest = starving_people*price_per_acre						# harvest
		eaten_by_rats = 0
		
		c = randint(2,4)
		
		if c % 2 == 0:					# rats probabilty is 2/3, c can be 2,3,4, 2/3 of these values are divisible by 2 with a remainder 0
			eaten_by_rats = bushels/c
			
		bushels = bushels - eaten_by_rats + harvest
		
		c = rand5()
		
		pop_growth = int(c*(20.0*acres_owned + bushels)/population/100 + 1)	# population growth
		
		c = acres_bought/25						# people fed
		
		acres_bought = int(10*(2*random() - 0.3))	# chance of plague ... 15% ????
		
		if population > c:
			starving_people = population - c					# number starved
			if starving_people > 0.45*population:
				impeached()
				endgame()
			else:
				total_population = ((year-1)*total_population + starving_people*100.0/population)/year
				population = c
				total_deaths = total_deaths + starving_people
		else:
			starving_people = 0
			
		population_under40(population)
		city_overrun(population,acres_owned)
		
	# closing of game	
		
	msg =   "In your 10-year term of office, " + str(int(total_population)) + " percent of the " 
	msg += "population starved per year on average, i.e. a total of " +	  str(total_deaths) + " people died.\n\n"

	l = 1.0*acres_owned/population

	msg += "You started with 10 acres per person and ended with " + str(l) + " acres per person.\n\n"

	print msg

	if ((total_population > 33) or (l < 7)):
		impeached()
	elif ((total_population > 10) or (l < 9)):
		bad()
	elif ((total_population > 3) or (l < 10)):
		ok()
	else:
		fantastic()	
		
	endgame()

def difficulty():
	difficulty = input("Which difficulty would you like to play? Enter 1 (Easy), 2(Standard),or 3 (Hard): ")
	if difficulty==1:
		game_easy()
	elif difficulty==2:
		game_standard()
	elif difficulty==3:
		game_hard()
	else:
		print "That's not a difficulty silly, I suggest you select 1 for easy next time!"
		
	
total_deaths = 0	#d1
total_population = 0	#p1
year = 0	#z
population = 95	#p
bushels = 2800	#s
harvest = 3000	#h
eaten_by_rats = harvest-bushels	#e
price_per_acre = 3	#y
acres_owned = harvest/price_per_acre	#a
pop_growth = 5	#i
acres_bought = 1	#q
starving_people = 0	#d0
difficulty()	