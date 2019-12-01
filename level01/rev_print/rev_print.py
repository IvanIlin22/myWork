import sys
s = sys.argv
s = s[1 : ]
if (len (s) == 1):
		str = "".join(s)
		print(str[::-1])