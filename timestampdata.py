import numpy as np
import operator
import pylab
import sys
import serial
import time
from array import array

PORT = 'COM4' #Port Arduino is on
#open a connection to the serial port.
ser = serial.Serial(PORT, 9600, timeout = 1)

filename = str(sys.argv[1])
dataFile = open(filename+'.dat','w')

while True:
	try:
		"""retrieve raw analog number from arduino's ADC"""
		datum = arduino.read()
		"""write it to file, along with a timestamp"""
		print datum
		dataFile.write(time.strftime("%I:%M:%S")
		dataFile.write('\n')
		dataFile.write(datum)
		dataFile.write('\n')
	except KeyboardInterrupt:
		#---allows user to CTRL-C out of the loop and closes/saves
		dataFile.close()
		break

		'''time.sleep(1)
		ser.readline()
		#---------read in the data and split line
		data = ser.readline()
		timestamp = time.strftime("%I:%M:%S")

		#--- If at least 6 fields exist then parse data
		if (ast.literal_eval(data)>500):
			time.sleep(1)
		else


	#Now we can start receiving data
	read_val = ser.write(val)
	ser.close()'''



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
