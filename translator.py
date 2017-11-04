morse=[".-","-...","-.-.",'-..','.','..-.','--.','....',
'..','.---','-.-','.-..','--','-.','---','.--.','--.-','.-.',
'...','-','..-','...-','.--','-..-','-.--','--..']
words=''
words=input("What is the message you would like to translate? Please leave a space between each letter.\n")
size = words.count(" ");
code = words.split();
for letter in code:
	for i in range(26):
		#print(letter, morse[i])
		if letter==morse[i]:
			print(chr(ord("A")+i) , end=" ")
			break
	else:
		print("Invalid Letter Code")
		break