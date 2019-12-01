def ft_repeat(str):
	i = 0
	for x in str:
		j = 0
		if (ord(x) >= ord('a') and ord(x) <= ord('z')):
			j = ord(x) - ord('a') + 1
			while j:
				print (x, end = "")
				j -= 1
		elif (ord(x) >= ord('A') and ord(x) <= ord('Z')):
			j = ord(x) - ord('A') + 1
			while j:
				print (x, end = "")
				j -= 1
		else:
			print (x, end = "")

import sys
s = sys.argv
s = s[1 : ]
if (len(s) == 1):
	str = "".join (s)
	ft_repeat(str)
print("")