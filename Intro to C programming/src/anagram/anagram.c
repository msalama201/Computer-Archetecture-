#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
 int length;
 length = strlen(argv[1]);
 char array[length+1];
 array[0] = '\0';
 strcpy(array,argv[1]);
 char result [length+1];
	

// debugger printf("%s\n", array );

int i= 0;
int k=0;
int count=0;
char temp;

//printf("Entering nested forloop\n");
for (i = 0; i < length; i++)
{
	for (k=i; k < length; k++)
	{
		//debugger printf("%c -> %c\n", array[i], array[k]);
		// debugger printf("entered loop\n");
		if (array[i]>array[k])
		{
			temp = array[k];
			result[i]= temp;
			//printf("result -> %c\n", result[i]); debugger
			array[k] = array[i];
			array[i] = temp;
			count++;
		
		}
		if(array[i] == array[k] && k == length-1){
			result[i] = array[i];
		}
		if(k == length-1 && count == 0){
			result[i] = array[i];
		}
		if(array[i] == array[k]){
			continue;
		}
	
	}
	count = 0;
	array[i] = '~';
}

result[length] = '\0';
printf("%s\n", result);

return 0;
}
