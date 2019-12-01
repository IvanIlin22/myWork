class FirstClass:				#Объект класса
	def setdata(self, value):	#метод класса	
		self.data = value		#присваивание значений атрибутам через сслыку self создает артрибут в каждом отдельном экземпляре
	def	display(self):
		print(self.data)
		
class SecondClass(FirstClass):
	def display(self):
		print('Current value = "%s"' % self.data)

class ThirdClass(SecondClass):
	def __init__(self, value):
		self.data = value
	def __add__(self, other):
		return ThirdClass(self.data + other)
	def __str__(self):
		return '[ThirdClass: %s]' % self.data
	def mul(self, other):
		self.data *= other

a = ThirdClass("abc")
a.display()

b = a + "xyz"
b.display()
print(b)
a.mul(3)
a.display()