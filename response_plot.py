#calculate and plot response

import datetime
import random
import matplotlib.pyplot as plt

# make up some data
#x = [datetime.datetime.now() + datetime.timedelta(hours=i) for i in range(12)]
#y = [i+random.gauss(0,1) for i,_ in enumerate(x)]


string = "s,5,4,3,\nc,1"
mylist = string.split(',')
print mylist
print(len(mylist[4]))

#read serial string
#after line feed, look for first character


'''# plot
plt.plot(x,y)
# beautify the x-labels
plt.gcf().autofmt_xdate()

plt.show()'''