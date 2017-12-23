from sys import stdin, stdout
import numpy as np
import math
import sys

class Queue:

    # Constructor, which creates a new empty queue:
    def __init__(self):
        self.items = []
        # TODO: You must implement this constructor!

    # Adds a new item to the back of the queue, and returns nothing:
    def queue(self, item):
        return self.items.append(item)
        # TODO: You must implement this method!

    # Removes and returns the front-most item in the queue.  
    # Returns nothing if the queue is empty.
    def dequeue(self):
        if len(self.items)==0:
            return None
        else:
            return self.items.pop(0)
        # TODO: You must implement this method!

    # Returns the front-most item in the queue, and DOES NOT change the queue.  
    def peek(self):
        if len(self.items)==0:
            return None

        else:

            return self.items[0]
        # TODO: You must implement this method!

    # Returns True if the queue is empty, and False otherwise:
    def is_empty(self):
        return self.items == []
        # TODO: You must implement this method!


def main():


	dic = {}

	lis =[]
	for x in range(0,505):
		lis.append([])

	lis[1].append("0")
	lis[1].append("1")

	
	power2 =[]
	power2.append(1)
	power2.append(2)

	power5 =[]
	power5.append(1)
	power5.append(5)
	
	for i in range(2,1020) :
		power2.append(power2[i-1]*2)
		power5.append(power5[i-1]*5)
		

	tes =[]
	t = int(input())
	i=1
	while i<=t :
		
		n = int(input())
		tes.append(n)
		dic[n]=True
		i=i+1

	#numbers array 
	numbers =["0","1","2","3","4","5","6","7","8","9"]

	#now start using queue 
	q = Queue()
	q.queue("5")
	q.queue("6")


	while not q.is_empty() :

		n= q.dequeue()
		#print(n)
		#return
		tope = len(n)

		if tope>505 :
			break

		if tope in dic and n[0]!='0' :
			lis[tope].append(n)

		for j in range(0,10) :

			k = numbers[j] + n

			#now we do checking
			m=k.lstrip("0")
			l = int(m)
			if l%power2[len(m)]<=1 and l%power5[len(m)]<=1 :
				q.queue(k)


	for i in range(1,t+1):

		stdout.write("Case #"+str(i)+": ")
		if len(lis[tes[i-1]]) == 0:
			stdout.write("Impossible"+'\n')
		else : 

			lis[tes[i-1]].sort()
			for x in range( 0,len(lis[tes[i-1]]) ) :
				stdout.write(lis[tes[i-1]][x]+' ')

			stdout.write('\n')


		
		

if __name__ == "__main__":
	main()

