def ft_rot_13(str):
	for x in str:
		if (ord(x) >= ord('a') and ord(x) <= ord('z')):
			print(chr(ord('a') + (ord(x) - ord('a') + 13) % 26), end = "")
		elif (ord(x) >= ord('A') and ord(x) <= ord('Z')):
			print(chr(ord('A') + (ord(x) - ord('A') + 13) % 26), end = "")
		else:
			print(x, end = "")
		
import sys
s = sys.argv
s = s[1 : ]
if (len (s) == 1):
	ft_rot_13("".join(s))
print("")