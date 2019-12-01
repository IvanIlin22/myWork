def ft_swap():
	global a
	global b
	a = b + a
	b = a - b
	a = a - b

a = 10
b = 5
print ("a =",a)
print("b =",b)
ft_swap()
print ("swap_a =",a)
print("swap_b =",b)