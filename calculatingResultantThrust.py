#testing vector math

import numpy as np
import operator
import pylab

a = np.array([1,2,3]) 
b = np.array([4,5,6])
c = np.add(a,b)
d = np.delete(c,(2),axis=0) #covert to x-y projection
print(d)
pylab.plot(d)



'''#needs import operator to work. 
#converts arrays to tuples
class stuple(tuple):
	def __add__(self,other):
		return self.__class__(map(operator.add, self, other))
		#not checking lengths

a = stuple([4,5,6])
b = stuple([6,7,8])

c = a + b

d = c*([1,0],[0,1])

pylab.plot(d)
'''
#just creating values to plot.
'''x = numpy.linspace(-15,15,100)#100 linearly spaced numbers
y = numpy.sin(x)/x #computing the values of sin(x)/x
z = numpy.linspace(-5,50,100)#100 linearly spaced numbers

#compose plot
pylab.plot(x,y)
pylab.plot(x,2*y,x,3*y)'''



pylab.show()