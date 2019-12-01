import sys
s = sys.argv
s = s[1 : ]
if (len (s) == 1):
	str = "".join(s)
	for x in str:
		if (x.isupper()):
			print(x.lower(), end = "")
		elif (x.islower()):
			print(x.upper(), end = "")
		else:
			print(x, end = "")
print("")