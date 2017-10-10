#!/usr/bin/env python
import numpy as numpy
from datetime import datetime

count=0

def mult(X,Y,result):
	global count
	count +=1
	# iterate through rows of X
	for i in range(len(X)):
		# iterate through rows of Y
		for k in range(len(Y)):
	   		# iterate through columns of Y
	   		for j in range(len(Y[0])):
	           		result[i][j] += X[i][k] * Y[k][j]


size=200

X = numpy.random.random((size,size))
Y = numpy.random.random((size,size))
result = numpy.zeros(shape=(size,size))

a = datetime.now()
mult(X,Y,result)
b = datetime.now()
print (repr(count)+":"+repr((b-a).total_seconds()/count))
