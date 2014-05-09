import numpy as np
import operator
import pylab
import sys
import serial
import time
from array import array

#open a connection to the serial port, try two probably options


def read_from_serial(ser):
	datum = ""
	buff = ""
	while (ser.inWaiting()<2):
		continue
	while (True):
		datum = ser.read()
		if (datum == '\n'):
			break
		buff+=datum	
	return buff

def main():
	
	''' Add in when get arroudn to figure out system args in windows
	if(len(sys.argv) != 2):
		print 'Example usage: python timestampdata.py "save_data_here"'
		exit(1)
	'''
	try:
		ser = serial.Serial('COM4', 9600, timeout = 1)
	except:
		ser = serial.Serial('COM3', 9600, timeout = 1)

	####CHANGE THIS EVERY TIME#####################################33
	filename = "May_6_test7"
	dataFile = open(filename+'.csv','wb') #wb opens as a binary file

	while True:
		try:
			"""retrive a line of data from the arduino"""
			data = read_from_serial(ser);
			"""write it to file, along with a timestamp"""
			#only save data if it seems to be a valid entry
			if ((data[0] == 'c' or data[0] == 's') and len(data)>1):
				print data
				dataFile.write("t" + str(time.clock()) + '\n')
				dataFile.write(data + "\n")

		except KeyboardInterrupt:
			#---allows user to CTRL-C out of the loop and closes/saves
			dataFile.close()
			break

		#Now we can start receiving data
		#read_val = ser.write(val)
	ser.close()

main()

# string is a
a ="s,5,4,3,\nc,1\n"
#split at newline
new_a = a.split('\n')[:-1]

#print new_a

##taking the first segment 
b = new_a[0]

b_new = b.split(',')
print b_new

#to plot the vector in 3d space, only need x and y components
d = b_new[1:3]
#convert from string to float
x = float(d[0])
y = float(d[1])

print(x,y)

#combine into array
thrust = ([x],[y])

#print d
pylab.plot(thrust)
pylab.show()
