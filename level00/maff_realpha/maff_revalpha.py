i = 26
j = 'z'
while i:
	if (i % 2 == 0):
		print(j, end = "")
	else:
		print(chr(ord(j) - ord('a') + ord('A')), end = "")
	j = ord(j) - 1
	j = chr(j)
	i -= 1
