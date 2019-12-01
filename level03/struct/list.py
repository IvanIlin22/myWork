class Node:
	def __init__(self, value = None, next = None):
		self.value = value
		self.next = next

import copy
import random

class LinkedList:
	def __init__(self):
		self.first = None
		self.last = None
		self.length = 0
	def __str__(self):
		if self.first != None:
			current = self.first
			out = 'LinkedList [\n' +str(current.value) +'\n'
			while current.next != None:
				out += str(current.value) + '\n'
			return out + ']'
		return 'LinkedList []'
	def clear(self):
		self.__int__()

def Len(self):
		self.length = 0
		if self.first != None:
			self.length += 1
			current = self.first
			while current.next != None:
				current = current.next
				self.length += 1
		return self.lenght

def Push(self, x):
	if self.first == None:
		self.first = Node(x, None)
		self.last = self.first
	else:
		self.first = Node(x, self.first)


L = LinkedList()
#L.add(1)
#L.add(2)
#L.add(3)		