#!/usr/bin/env python
import numpy as numpy
from datetime import datetime

count=0

def mult(X,Y,result):
	global count
	count+=1
	numpy.matmul(X,Y,result)

size=5000

X = numpy.random.random((size,size))
Y = numpy.random.random((size,size))
result = numpy.zeros(shape=(size,size))

a = datetime.now()
mult(X,Y,result)
b = datetime.now()
print (repr(count)+":"+repr((b-a).total_seconds()/count))
