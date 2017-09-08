#image manipulation program
from png import *
from math import *
from easygui import *
from os import *

def get_image(f):
	# Convert a PNG image into an integer-based representation
	# This is a 'because that's the way it works' function, dictated by
	# the mechanics of the pypng library
	print "starting to read",f
	r = Reader(filename=f)
	image = list(r.read()[2])
	print "finished reading", f
	new_image = []
	for row in image:
		new_row = row.tolist()
		new_image.append(new_row)
	return new_image
	
def choose_png(msg):
	# select a PNG image file and call get_image to load it
	filenames = listdir('.')
	fn2 = filenames[:]
	for f in fn2:
		if f[-3:] != 'png':
			filenames.remove(f)
	f = choicebox(msg,"",filenames)
	return get_image(f)
	
def negative_image(image):
	# convert an image to its negative
	if len(image) == 0:
		msgbox("No image to process")
		return image
	rows = len(image)
	cols = len(image[0])
	new_image = []
	for r in range(rows):
		new_row = []
		for c in range(cols):
			# replace every value by its complement
			new_row.append(255-image[r][c])
		new_image.append(new_row)
	return new_image
	
def left_to_right(image):
	#left to right flip
	if len(image) == 0:
		msgbox("No image to process")
		return image
	rows = len(image)
	cols = len(image[0])
	new_image = []
	for r in range(rows):
		new_row = []
		for c in range(0,cols,3):
			new_row.insert(0, image[r][c+2])
			new_row.insert(0, image[r][c+1])
			new_row.insert(0, image[r][c])
		new_image.append(new_row)
	return new_image
	
def top_to_bottom(image):
	#top to bottom flip
	if len(image) == 0:
		msgbox("No image to process")
		return image
	new_image = image[::-1]
	return new_image
	
def rotate90(image):
	#rotates clockwise 90 degrees 3 times, thus giving a couterclockwise 90 degrees
	for i in range(3):
		if len(image) == 0:
			msgbox("No image to process")
			return image
		rows = len(image)
		cols = len(image[0])
		new_image = []
		for c in range(0,cols,3):
			new_row = []
			for r in range(rows):
				new_row.append(image[-r-1][c])
				new_row.append(image[-r-1][c+1])
				new_row.append(image[-r-1][c+2])
			new_image.append(new_row)
		image = new_image	
	return new_image	

def greyscale(image):
	#greyscale the image
	if len(image) == 0:
		msgbox("No image to process")
		return image
	rows = len(image)
	cols = len(image[0])
	new_image = []
	for r in range(rows):
		new_row = []
		for c in range(0,cols,3):
			sum = (image[r][c] + image[r][c+1] + image[r][c+2])/3
			new_row.append(sum)
			new_row.append(sum)
			new_row.append(sum)
		new_image.append(new_row)
	return new_image
		
def new_background(image):
	#takes an image, the images background, a new background, and swaps the backgrounds
	imagebg = choose_png("Select original image's background.")
	new_imagebg = choose_png("Select original image's new background.")
	if len(image) == 0:
		msgbox("No image to process")
		return image
	rows = len(image)
	cols = len(image[0])
	new_image = image
	for r in range(rows):
		for c in range(0,cols,3):
			if (image[r][c]+50 >= imagebg[r][c]) & (image[r][c]-50 <= imagebg[r][c]) & (image[r][c+1]+50 >= imagebg[r][c+1]) & (image[r][c+1]-50 <= imagebg[r][c+1]) & (image[r][c+2]+55 >= imagebg[r][c+2]) & (image[r][c+2]-50 <= imagebg[r][c+2]):
				new_image[r][c] = new_imagebg[r][c]
				new_image[r][c+1] = new_imagebg[r][c+1]
				new_image[r][c+2] = new_imagebg[r][c+2]
	return new_image		
		
def blend_image(image):
	#blends 2 images together
	image2 = choose_png("Select image to blend with original image.")
	if len(image) == 0:
		msgbox("No image to process")
		return image
	rows = len(image)
	cols = len(image[0])
	cols3 = cols/3
	new_image = []
	for r in range(rows):
		new_row = []
		for c in range(0,cols,3):
			red = (((cols-c)*(image[r][c])) + ((c)*(image2[r][c])))/cols3
			green = (((cols-c)*(image[r][c+1])) + ((c)*(image2[r][c+1])))/cols3
			blue = (((cols-c)*(image[r][c+2])) + ((c)*(image2[r][c+2])))/cols3
			if red < 0: #these prevent overflow and underflow errors, not sure why i get them,
				red = 0 #the average should never go above or below 255 and 0
			if green < 0:
				green = 0 #replace with white value
			if blue < 0:
				blue = 0
			if red > 255:
				red = 255 #replace with black value
			if green > 255:
				green = 255
			if blue > 255:
				blue = 255
			new_row.append(red)
			new_row.append(green)
			new_row.append(blue)
		new_image.append(new_row)
	return new_image	
			
def save_image(image):
	# save the current image to a file
	if len(image) == 0:
		msgbox("No image to save")
		return image
	name = enterbox("Please enter the file name for the saved image")
	if name[-4:] != '.png':
		name = name + '.png'
	from_array(image,"RGB").save(name)  
	return image
	
def choose_operation(image):
	# choose an operation
	choices = ['1. Select Original Image',
			'2. Negative Image',
			'3. Save Image',
			'4. Left To Right Reflection',
			'5. Top to Bottom Reflection',
			'6. Rotate 90 Degrees to the left',
			'7. Greyscale Image',
			'8. Remove and Add a New Background',
			'9. Blend with another Image',
			'10. Exit Program'
		      ]
	op = choicebox("Choose an Operation","",choices)
	if op[:2] == '1.':
		image = choose_png("Select original image")
	elif op[:2] == '2.':
		image = negative_image(image)
	elif op[:2] == '3.':
		save_image(image)
	elif op[:2] == '4.':
		 image = left_to_right(image)
	elif op[:2] == '5.':
		image = top_to_bottom(image)
	elif op[:2] == '6.':
		image = rotate90(image)
	elif op[:2] == '7.':
		image = greyscale(image)	
	elif op[:2] == '8.':
		image = new_background(image)	
	elif op[:2] == '9.':
		image = blend_image(image)
	else:
		exit("Done")		# halts the program immediately
	return image	
		
		
		
		
# main program
image = []
while True:
	# loop until the user selects "Exit Program" 
	image = choose_operation(image)
	
	