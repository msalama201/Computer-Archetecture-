#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {	
int k;// k is a variable used to keep count of argc
for (k = 1; k < argc; k++){ //for loop used to go through each argc so you can enter many arguments
	int length;
	length = strlen(argv[k]);  // used to get length of the arguments 
	char array[length+1]; // make an array to store the agrugments 
	strcpy (array, argv[k]);// used to copy the arguments to a new array 
// debugger	printf("%s\n",array );
	int i;
	char cap[length+1];// made a new array to store capital letters 
	for (i = 0; i < length+1; i++){// for loops to convert each index of regular array and convert it to caps and store it in the same location on the caps array 
		cap[i] = toupper(array[i]);// used to convert to upper case
		}
	printf("%s ", cap); //prints the output of the array 
}//	 end main for loop for the entire thing bro pls i need A
printf("\n");// new line after everything is printed 
return 0;
}


