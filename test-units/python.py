import random
file = open("in10000.txt" , "w")
for x in xrange(10000):
	file.write(str(random.randint(1,1000)))
	file.write("\n");

file.close()