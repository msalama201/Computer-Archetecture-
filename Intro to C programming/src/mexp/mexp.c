#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int ** multipy (int size,int ** matrixA, int ** matrixB, int ** result)
{
	int row;
	int col;
	int h;
	for (row = 0; row < size; row++)
	{
		for ( col = 0; col < size; col++)
		{

			for (h = 0; h < size; h++)
			{
				result[row][col]+= matrixA[row][h] * matrixB[h][col];

			}
			//printf("%d\n", result[row][col]);
		}
	}
return result;
} // mulltipy function that takes paramters and multiplies 2 matrix and puts them in result 



int main(int argc, char const *argv[])
{
	int exp;
	int i;
	int k;

	if (argc!=2)
	{
		printf("error\n");
		return 0;
	}

	FILE *fp = fopen(argv[1], "r");

	



	if (fp!=NULL)
	{

		int size;
		//Reads the size of the matrix
		fscanf(fp, "%d\n", &size);// reads the first line which is the size of matrix
		 //printf("%d\n", size); debugger 

		//After finding the size we can create the matrix aka 2d array
		int ** array;
		array=(int**) malloc(sizeof(int*)*size);

			for (i = 0; i < size; i++)
					{
						array[i]=(int*) malloc(sizeof(int)*size);
					}



			int ** result;
			result=(int**) malloc(sizeof(int*)*size);

				for (i = 0; i < size; i++)
				{
					result[i]=(int*) malloc(sizeof(int)*size);	
				}





				int ** array2;
				array2=(int**) malloc(sizeof(int*)*size);

					for (i = 0; i < size; i++)
					{
						array2[i]=(int*) malloc(sizeof(int)*size);
					}


				// we need to allocate memotry for all three arrays to allocate memtory 
				//for a 2d array we must allocate the top row and everycollom that the row points to 
				// we did this for all 3 2d arrays

int value; // value of the items in the array as well as tfinding the exponents
		//printf("enter loop for reading the file\n");
		for (i = 0; i < size+1; i++)
		{
			for (k = 0; k < size; k++)
			{
				//printf("enter\n");
				if(i==size)
				{
					//printf("stuff2\n");
					fscanf(fp, "%d\n",&exp);
					//printf("%d\n",exp );
					break;
				}

				else if (k==size-1)
				{
					//printf("Stuff1\n");
				fscanf(fp, "%d\n",&value);

				array[i][k]=value;
				array2[i][k]=value;
				//printf("%d\n",value );
				}

				

				//printf("Stuff3\n");
				


				else
				{
					//printf("Pass1\n");
					fscanf(fp, "%d ",&value);
					array2[i][k]=value;
				array[i][k]=value;
				//printf("%d ",value );
				}
				
			}
			//printf("passsssssss\n");
		}

		//printf("Pass\n");


int row;
int col;


// special case if the exponent is zero just print out an array of 1's
if (exp==0)
		{

			for (row = 0; row < size; row++)
	{
		for ( col = 0; col < size; col++)
		{

				if (col==size-1)
				{
				value =1;
				printf("%d\n",value );
				}


				else
				{
					
				value = 1;
				printf("%d ",value );
				}
		

			
		}
	}
			
		}		


// anyother exp just do the normal multiplication 
else
{
	int row;
	int col;
	int i;

	for (row = 0; row < size; row++)
	{
		for ( col = 0; col < size; col++)
		{
		result[row][col]= 0;
		}
	}

//printf("Enter loop for matrix expo\n");
			for ( i = 1; i < exp; i++)
			{
				result=multipy(size,array2,array,result);

				for (row = 0; row < size; row++)
				{
					for ( col = 0; col < size; col++)
					{
						array2[row][col]= result[row][col];
					}
				}

				for (row = 0; row < size; row++)
				{
					for ( col = 0; col < size; col++)
					{
						result[row][col]= 0;

			
					}
				}
			} // this for loop is used to multiply the matrix and then 

			for (row = 0; row < size; row++)
			{
				for ( col = 0; col < size; col++)
				{

					if (col==size-1)
					{
						value =array2[row][col];
						printf("%d\n",value );
					}


					else
					{
						value = array2[row][col];
						printf("%d ",value );
					}
		
				}
			} // for loop to print out the values in result after its done multiplying


		for (i = 0; i < size; i++)
		{
			free(array2[i]);
			free(result[i]);
			free(array[i]);
		}
			free(array2);
			free(result);
			free(array);
} /// ends the else 


}


else if(fp==NULL)
	{
	printf("error\n");
	fclose(fp);

	return 0;
	}


fclose(fp); 
//printf("pass\n");
// close the file 
return 0;
}
