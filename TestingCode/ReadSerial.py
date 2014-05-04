import serial
import time
import matplotlib
import math
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt


##Use for realtime reading. Have as sepperate thread and access the
##global variable "last_recie"
def receiving(ser):
    global last_received
    buffer = ''
    last_recieved = ''
    while True:
        buffer = buffer + ser.read(ser.inWaiting())
        if '\n' in buffer:
            lines = buffer.split('\n') # Guaranteed to have at least 2 entries
            last_received = lines[-2]
            #If the Arduino sends lots of empty lines, you'll lose the
            #last filled line, so you could make the above statement conditional
            #like so: if lines[-2]: last_received = lines[-2]
            buffer = lines[-1]
            return last_received

try:
    ser = serial.Serial('/dev/ttyACM0',9600,timeout=1)
except:
    ser = serial.Serial('/dev/ttyACM1',9600,timeout=1)

while 1:
    print receiving(ser) #How do