//FUTURE NOTES:
//1) MIGHT NEED TO ADD CUSTOM STRCPY AND STRCMP

#include <iostream>
#include <string.h>
using namespace std;


//basically a custom datatype, every time there is a codepair variable, it will contain
//the letter it represents, the size of the morse code (integer), and the code itself.
//the code is an array of 6, because the max size of the code is 5, but there is also
// \0 at the end, which is a sentinel value to mark the end of the string.
struct codepair
{
	
	char letter;
	int size_of_code;
	char code[6];
};


int main()
{
	//dictionary of characters
	codepair characters[38];

	//the input that the user gives us. Used Twitter's character limit as a guidline, we can lower this as needed
	//again, the extra 1 character is for the sentinel value.
	char input[501];

	//Array to store the morse code translation of each letter in the input.
	char result[501][6];
	
	/////////////////////////FORMATTING MORSE CODE DICTIONARY/////////////////////////////////////////

	//LETTERS
	strcpy(characters[0].code 	,".-"	);	characters[0].letter='A' ;	characters[0].size_of_code=2;
	strcpy(characters[1].code 	,"-..."	);	characters[1].letter='B' ;	characters[1].size_of_code=4;
	strcpy(characters[2].code 	,"-.-."	);	characters[2].letter='C' ;	characters[2].size_of_code=4;
	strcpy(characters[3].code 	,"-.."	);	characters[3].letter='D' ;	characters[3].size_of_code=3;
	strcpy(characters[4].code 	,"."	);	characters[4].letter='E' ;	characters[4].size_of_code=1;
	strcpy(characters[5].code 	,"..-."	);	characters[5].letter='F' ;	characters[5].size_of_code=4;
	strcpy(characters[6].code 	,"--."	);	characters[6].letter='G' ;	characters[6].size_of_code=3;
	strcpy(characters[7].code 	,"...."	);	characters[7].letter='H' ;	characters[7].size_of_code=4;
	strcpy(characters[8].code 	,".."	);	characters[8].letter='I' ;	characters[8].size_of_code=2;
	strcpy(characters[9].code	,".--"	);	characters[9].letter='J' ;	characters[9].size_of_code=3;
	strcpy(characters[10].code	,"-.-"	);	characters[10].letter='K';	characters[10].size_of_code=3;
	strcpy(characters[11].code	,".-.."	);	characters[11].letter='L';	characters[11].size_of_code=4;
	strcpy(characters[12].code	,"--"	);	characters[12].letter='M';	characters[12].size_of_code=2;
	strcpy(characters[13].code	,"-."	);	characters[13].letter='N';	characters[13].size_of_code=2;
	strcpy(characters[14].code	,"---"	);	characters[14].letter='O';	characters[14].size_of_code=3;
	strcpy(characters[15].code	,".--."	);	characters[15].letter='P';	characters[15].size_of_code=4;
	strcpy(characters[16].code	,"--.-"	);	characters[16].letter='Q';	characters[16].size_of_code=4;
	strcpy(characters[17].code	,".-."	);	characters[17].letter='R';	characters[17].size_of_code=3;
	strcpy(characters[18].code	,"..."	);	characters[18].letter='S';	characters[18].size_of_code=3;
	strcpy(characters[19].code	,"-"	);	characters[19].letter='T';	characters[19].size_of_code=1;
	strcpy(characters[20].code	,"..-"	);	characters[20].letter='U';	characters[20].size_of_code=3;
	strcpy(characters[21].code	,"...-"	);	characters[21].letter='V';	characters[21].size_of_code=4;
	strcpy(characters[22].code	,".--"	);	characters[22].letter='W';	characters[22].size_of_code=3;
	strcpy(characters[23].code	,"-..-"	);	characters[23].letter='X';	characters[23].size_of_code=4;
	strcpy(characters[24].code	,"-.--"	);	characters[24].letter='Y';	characters[24].size_of_code=4;
	strcpy(characters[25].code	,"--.."	);	characters[25].letter='Z';	characters[25].size_of_code=4;
	
	//NUMBERS
	strcpy(characters[26].code	,".----");	characters[26].letter='1';	characters[26].size_of_code=5;
	strcpy(characters[27].code	,"..---");	characters[27].letter='2';	characters[27].size_of_code=5;
	strcpy(characters[28].code	,"...--");	characters[28].letter='3';	characters[28].size_of_code=5;
	strcpy(characters[29].code	,"....-");	characters[29].letter='4';	characters[29].size_of_code=5;
	strcpy(characters[30].code	,".....");	characters[30].letter='5';	characters[30].size_of_code=5;
	strcpy(characters[31].code	,"-....");	characters[31].letter='6';	characters[31].size_of_code=5;
	strcpy(characters[32].code	,"--...");	characters[32].letter='7';	characters[32].size_of_code=5;
	strcpy(characters[33].code	,"---..");	characters[33].letter='8';	characters[33].size_of_code=5;
	strcpy(characters[34].code	,"----.");	characters[34].letter='9';	characters[34].size_of_code=5;
	strcpy(characters[35].code	,"-----");	characters[35].letter='0';	characters[35].size_of_code=5;
	
	//SPACE
	strcpy(characters[36].code	,"/")	 ;	characters[36].letter=' ';	characters[36].size_of_code=1;

	//SENTINEL
	strcpy(characters[37].code	,"X")	 ;	characters[37].letter='\0';	characters[36].size_of_code=1;

	///////////////////////////////////END OF FORMATTING//////////////////////////////////////////////

	cout<<" Please enter you message (limited to 500 characters)  ";

	//input assumes caps lock, and no symbols. add function here to avoid needing to assume.
	
	//fgets is another way of getting input, except this one is per line.
	//I didnt want to deal with one variable per word, or trying to stich argv's together
	fgets(input, 500, stdin);

	int index=0;
	char current;
	
	//translating to morse
	while(input[index]!=0 )
	{
		current=input[index];
		//the thing in the for condtion is an iterator, it basically says for every codePair in characters
		for(codepair currCode:characters)
		{
			if(current==currCode.letter)
			{
				cout<<currCode.code<<" ";
				strcpy(result[index], currCode.code);
				break;
			}
		}
		index++;
	}
	cout<<"X"<<endl;
	strcpy(result[index],"X");

	//translating from morse to english
	index=0;
	//cout<<strcmp(result[index],"X" );
	while(strcmp(result[index],"X" )!=0)
	{
		//cout<<result[index]<<endl;
		for(codepair currCode:characters)
		{
			if(strcmp(result[index],currCode.code)==0)
			{
				cout<<currCode.letter;
			}
		}
		index++;
	}


	return 1;
}