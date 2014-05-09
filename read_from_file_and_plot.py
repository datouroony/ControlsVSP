import numpy as np
import operator
import pylab
import serial
import time
import math
from array import array

def read_line(dataFile):
	line = dataFile.readline();
	if (len(line) <2): return -1
	return parse_data(line)

def parse_data(data):
	if (data[0] == 't'):
		return float(data[1:])      #if just one number, return it as a float
	if (data[0] == 'c'):
		return int(data[1:]) 
	if (data[0] == 's'):
		data_new = data[1:].split(',')  # separates numbers from comma delimination
		return_data = []
		for x in data_new[1:]:
			if (len(x) > 0):
				if (x[0] != '\n' and x[0] != '\r' and x != ''):  #ignors end line characters
					return_data.append(float(x))  #makes list of floats
			else:
				print "x = 0"
		return return_data
	else:
		return ''

# Calculates the xy plane component of the sum magnitude of all the sensor forces
def calc_Fxy_magnitude(data_array):
	i = 0
	to_rad_30 = math.radians(30)
	to_rad_60 = math.radians(60)
	x_forces = []
	y_forces = []

	x_forces.append((data_array[0]*math.cos(math.radians(300))))
	y_forces.append(data_array[0]*math.sin(math.radians(300)))
	x_forces.append(-(data_array[1]*math.cos(to_rad_30)))
	y_forces.append((data_array[1]*math.cos(to_rad_30)))
	x_forces.append((data_array[2]*math.cos(to_rad_30)))
	y_forces.append((data_array[2]*math.cos(to_rad_30)))
	x_forces.append(-(data_array[3]*math.cos(to_rad_60)))
	y_forces.append(-(data_array[3]*math.cos(to_rad_60)))
	x_forces.append(-(data_array[4]*math.cos(to_rad_30)))
	y_forces.append((data_array[4]*math.cos(to_rad_30)))
	x_forces.append((data_array[5]*math.cos(to_rad_30)))
	y_forces.append((data_array[5]*math.cos(to_rad_30)))

	return sum(x_forces)+sum(y_forces)

#calculates a new averaged value based on an exponential rolling average
def exp_rolling_avg(current,previous):
	a = .5   #must be <1
	return (a*current + (1-a)*previous)

def main():
	filename = "May_6_test7"    #name of file to read from. Must .csv file
	dataFile = open(filename+'.csv','rb') #wb opens as a binary file
	parsed_data = 1
	prev_force = [0,0,0,0,0,0]
	sensor_forces = [0,0,0,0,0,0]
	time_array = []
	data_array = []
	command_array = []
	Fxy_magnitude_prev = 0
	command = 0
	while (parsed_data != -1):    # can do because time stamped first
		parsed_data = read_line(dataFile)
		if (isinstance(parsed_data, list)):    #if list, must be sensor data
			if (len(parsed_data) == 6): #include if appropriate amount of data (not cut off during collection)
				time_array.append(time_stamp)
				command_array.append(command)
				i = 0
				#averaging for each individual sensor force before combined
				for force in parsed_data:
					sensor_forces[i] = exp_rolling_avg(force,prev_force[i])
					i+=1

				Fxy_magnitude = exp_rolling_avg(calc_Fxy_magnitude(sensor_forces),Fxy_magnitude_prev)

				data_array.append(Fxy_magnitude)
				Fxy_magnitude_prev = Fxy_magnitude
				prev_forces = sensor_forces

		elif(isinstance(parsed_data, int)):           #if int, must be command
			print command + 1
			if(parsed_data < 10):
				command = parsed_data + 1
		else: 					      #otherwise, must be timestamp
			time_stamp = parsed_data
	pylab.plot(time_array,data_array)
	pylab.plot(time_array,command_array)
	pylab.show()

main()	
