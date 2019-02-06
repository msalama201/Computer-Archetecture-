

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int length; 
	length = strlen(argv[1]);
	char array[length+1];
	strcpy (array,argv[1]);
	//printf("%s\n",array); debugger 
	//char* combine = (char*) malloc((10000 * sizeof(char)));
	int i,k;
	char small[3];
	char combine[100];
	int count = 0;
	int countA = 0;
	int temp =0;
	char buffer[3];

		for (i = 0; i < length+1; i++)
		{
			count = 0;
			for ( k = i; k < length+1; k++)
		{
			
				if (array[i]==array[k])
				{
				
				count++;
				}

					else if (isdigit(array[i])!=0 || isdigit(array[k]) != 0)
					{
						printf("%s\n","error");
						return 0;
					} // condition to check if its a digit and output error

						else
						{ 
							small[0]=array[i];// keeps track of the letters 
							combine[countA]=small[0]; // puts the letter in the combine array 
							countA++;
							//printf("%s\n", combine );
							temp=count;
							sprintf(buffer,"%d",temp);
							// printf("%s\n",buffer );  debugger

								if (count>=10)
								{
									combine[countA]=buffer[0];
									combine[countA+1]=buffer[1];
									countA=countA+2;
									i = count+i-1;
									break;
								}

									else{
										combine[countA]=buffer[0];
										//combine[countA+1]=buffer[1]; debugger
										countA=countA+1;
										i = count+i-1;
										break;
										}
							//printf("%c\n",buffer[0] ); debgger
						} // ends the else if the input doesnt have numbers
		} // ends secondary   for loop that cheks each character 


						
					
		} // ends main for loop that goes thorugh each char
		// end main for loop to go through the array


	 if (length >= strlen(combine))
	 {
	 	printf("%s\n", combine);
	 } // if the new array is shroter than original print aray

		else
			{ 
				printf("%s\n", argv[1]);

			} // if its original is shorter  print out original



	 

		return 0;
	} // closes main

	


