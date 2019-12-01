import sys
s = sys.argv
s = s[1 : ]
if (len (s) == 3):
	if (len(s[1]) == 1 and len(s[2]) == 1):
		str = "".join(s[0])
		print(str.replace(s[1], s[2]), end = "")
print("")