import sys
s = sys.argv
s = s[1:]
str = "".join(s)
if (len(s) != 1):
	print('a')
else:	
	for x in str:
		if (x == 'a'):
			print(x)
			break

"""import sys
s = sys.argv
s = s[1:]
str = "".join(s)
if (len(s) != 1):
	print('a\n')
elif (str.find('a') == -1):
	print('\n')
else:
	print('a\n')"""