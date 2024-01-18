#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define ONE  1
#define TWO  2 
#define THREE 3
//Dominic Szymanski - January 18th, 2024
//This program will take a file, make a copy of it, and then convert all characters within the original file to
//uppercase within the copy file. The program will be able to do this using command line arguments.

int main(int argc, char* argv[]) //using argc and argv to allow the use of command line arguments 
{
	char ch;
	FILE* mainfile; //Variable/File declaration 
	FILE* copyfile;

	if (argc != THREE) //If user does not enter three arguments, print error message, and then exit the program 
	{					
		printf("CAN NOT OPEN FILE FOR READING...\n");
		exit(EXIT_FAILURE);
	}
	
	mainfile = fopen(argv[ONE], "r");				//Opening and setting main file to read and copy file to write 
	copyfile = fopen(argv[TWO], "w");
	
	if (mainfile == NULL || copyfile == NULL) //If either files are empty/non existent, print error message then exit program 
	{
		printf("FILE OPENING ERROR OR FILE NOT FOUND");
		exit(EXIT_FAILURE);
	}
	
	ch = fgetc(mainfile); //setting char equal to text grabbed from file.
	
	while ((ch != EOF)) //while char is not at the end of the file
	{
		ch = toupper(ch); // set all characters to uppercase using toupper function
		fputc(ch, copyfile); //Putting uppercased characters into copied file
		ch = fgetc(mainfile); //characters are euqal to contents of main file
	}
	printf("FILE COPY SUCCESS\n"); //Telling user file is succesfully copied
	fclose(mainfile);	
	fclose(copyfile);	//close both streams and flush all buffers.

	/*For question 1 I have decided not to use functions as I think it would only make the project more complicated instead of
	simplifing. I believe that the code is already simple enough and very easy to understand.*/

	
}
