#testing vector math

import numpy
import operator

class stuple(tuple):
	def __add__(self,other):
		return self.__class__(map(operator.add, self, other))
		#not checking lengths

a = stuple([4,5,6])
b = stuple([6,7,8])

print a + b