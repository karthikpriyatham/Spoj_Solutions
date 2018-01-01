import numpy as np
import math
import atexit
import io
import sys


_OUTPUT_BUFFER = io.BytesIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

n= int(raw_input())



i=1
j=1
mo = 109546051211

for x  in range(2,n+1):
	i = (i*x)%mo
	j = (j*i)%mo
	if j==0 : 
		break

print j
