import sys
s = sys.argv
s = s[1 : ]
str = "".join(s)
if (len(str) < 1):
	print()
else:
	print(s[0])

