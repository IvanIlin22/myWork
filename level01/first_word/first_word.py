import sys
s = sys.argv
s = s[1 : ]
str = "".join (s)
i = 0
while (str[i] == ' ' or str[i] == '\n' or str[i] == '\t'):
	i += 1
if (len(s) == 1):
	while (not (str[i] == ' ' or str[i] == '\n' or str[i] == '\t')):
		if (not(str[i] == " " or str[i] == "\t" or str[i] == "\n")):
			print(str[i], end = "")
		else:
			break
		i += 1
print();