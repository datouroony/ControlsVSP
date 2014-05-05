import numpy as np
import operator
import pylab

import time
from array import array
##12 hr format
print(time.strftime("%I:%M:%S"))

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
