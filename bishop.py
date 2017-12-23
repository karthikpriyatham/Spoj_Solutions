import sys
import math

while True :
	text = input()

	if text =="" :
		break

	num = long(text)

	if num <= 1:
		print(num)
	else :
		print(2*(num-1))