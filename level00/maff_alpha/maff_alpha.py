i = 1
j = 'a' 
while i < 27:
	if ((i % 2) == 0):
		print(chr(ord(j) - ord('a') + ord('A')), end = "");
	else:
		print(j, end = "")
	j = ord(j) + 1
	j = chr(j)
	i += 1