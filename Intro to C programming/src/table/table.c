#include <stdlib.h>
#include <stdio.h>

//HashTable

//Hash function for key -> n % 10000 = key
int hashKey(int number)
{
	int key;
	key = number%10000;
	return key;
}

void freeHashTable(int ** hashTable)
{
	int i;
	for(i = 0; i < 10000; i++){
		free(hashTable[i]);
	}
	free(hashTable);
}

int main(int argc, char *argv[])
{
	//If argument counter is not correct, exit the program
	if(argc != 2)
	{
		printf("error\n");
		return 0;
	}

	//Else continue
	else
	{
		char *file = argv[1];
		FILE *fp;
		fp = fopen(file, "r"); //Reads the file
		
		//File does not exist
		if(fp == NULL)
		{
			printf("error\n");
			return 0;
		}
		
		//continue
		else
		{
			//allocates space for the hashtable which is a 2d array
			int **hashTable;
			hashTable = (int**)malloc(sizeof(int*)*10000); //10000 buckets are needed
			int i = 0;
			for (i = 0; i < 10000; i++)
			{
				hashTable[i] = (int*)calloc(10000,sizeof(int));
			}

			
			int data;
			char operation;
			//Reads the file
			while(fscanf(fp, "%c %d\n", &operation, &data) != EOF){
				//does insert
				if(operation == 'i')
				{
					int key = hashKey(data);
					i = 0;
					for(;;i++)
					{
						if(hashTable[key][i] == data)
						{
							printf("duplicate\n");
							break;
						}
						if(hashTable[key][i] == 0)
						{
							hashTable[key][i] = data;
							printf("inserted\n");
							break;
						}
					}
				}
				//does search
				else if(operation == 's')
				{
					int key = hashKey(data);
					i = 0;
					for(;;i++)
					{
						if(hashTable[key][i] == data)
						{
							printf("present\n");
							break;
						}
						if(hashTable[key][i] == 0)
						{
							printf("absent\n");
							break;
						}
					}
				}
				//format error
				else
				{
					printf("error\n");
					return 0;
				}
			}
			freeHashTable(hashTable);	
		}
	}
	return 0;
}