#include <stdio.h>
#include <stdlib.h>

int rowCheck(char ** sudoku, char list[])
{
	int i,j,k,v,m;
	int count = 0;
	char array[9];
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			for(k = 0; k < 9; k++)
			{
				if(sudoku[i][j] == list[k])
				{
					//printf("%c %c\n", sudoku[i][j], list[k]);
					array[count] = list[k];
					count++;
					break;
				}
				else if(j == 8 && k==8 && list[k] != sudoku[i][j])
				{
					//printf("count = %d\n", count);
					return 2;
				}
			}
		}
		for(v = 0; v < 9; v++)
			{
				for(m = 0; m < 9; m++)
				{
					if(array[v] == array[m] && v != m)
					{
						//printf("%c %c\n", array[v], array[m] );
						//printf("break point\n");
						return 2;
					}
				}
			}
			count = 0;
	}
	//printf("count = %d\n", count);
	return 1;
}

int colCheck(char ** sudoku, char list[])
{
	int i,j,k, v,m;
	int count = 0;
	char array[9];
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			for(k = 0; k < 9; k++)
			{
				if(sudoku[j][i] == list[k])
				{
					array[count] = sudoku[j][i];
					count++;
					break;
				}
				else if(j == 8 && k==8 && list[k] != sudoku[j][i])
				{
					//printf("count = %d\n", count);
					return 2;
				}
			}
		}
		for(v = 0; v < 9; v++)
			{
				for(m = 0; m < 9; m++)
				{
					if(array[v] == array[m] && v != m)
					{
						//printf("%c %c\n", array[v], array[m] );
						//printf("break point\n");
						return 2;
					}
				}
			}
			count = 0;
	}
	//printf("count = %d\n", count);
	return 1;
}

int section(char ** sudoku, char list[])
{
	int i,j,k,temps0,temps1, s,v,m;
	int count = 0;
	temps0 = 0;
	temps1 = 0;
	char array[9];
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 3; j++)
		{
			for(k = 0; k < 3; k++)
			{
				for(s = 0; s < 9; s++)
				{
					if(sudoku[j+temps0][k+temps1] == list[s])
					{
						//printf("%c %c\n", sudoku[j+temps0][k+temps1], list[s]);
						array[count] = list[s];
						count++;
						break;	
					}
					else if(j == 2 && s==8 && list[k] != sudoku[j+temps0][k+temps1])
					{
						//printf("count = %d\n", count);
						return 2;
					}
				}
			}
		}

		for(v = 0; v < 9; v++)
			{
				for(m = 0; m < 9; m++)
				{
					if(array[v] == array[m] && v != m)
					{
						//printf("%c %c\n", array[v], array[m] );
						//printf("break point\n");
						return 2;
					}
				}
			}
			count = 0;

		temps1+=3;
		if((i+1) % 3 == 0 && i != 0){
			temps0 += 3;
			temps1 = 0;
		}
	}
	return 1;
}

void freeSudoku(char **sudoku)
{
	int i;
	for(i = 0; i < 9; i++)
	{
		free(sudoku[i]);
	}
	free(sudoku);
}

int checkForSolvability(char **sudoku, char list[], int x, int y)
{
	int i,j,k;
	char temp;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(sudoku[x][j] == ' ')
			{
				//printf("c1\n");
				continue;
			}
			else if(sudoku[x][j] == list[i])
			{
				//printf("c2\n");
				//printf("%c %c\n", sudoku[i][j], list[k]);
				break;
			}
			else if(j==8 && list[i] != sudoku[x][j])
			{
				//printf("c3\n");
				//printf("count = %d\n", count);
				temp = list[i];
				//printf("temp: %c\n", temp);
			}
		}
	}

	//printf("next1\n");

	for(i = 0; i < 9; i++)
	{
		if(sudoku[i][y] == temp)
		{
			return 2;
		}
	}

	for(j = 0; j < 3; j++)
	{
		for (k = 0; k < 3; k++)
		{
			if(sudoku[(x-(x%3))+j][(y-(y%3))+k] == temp)
			{
				return 2;
			}
		}
	}
	//printf("method finish\n");
	return 1;
}

int main(int argc, char *argv[]){
	if(argc != 2)
	{
		printf("error\n");
		return 0;
	}
	else
	{
		char *file = argv[1];
		FILE *fp;
		fp = fopen(file, "r");
		if(fp == NULL)
		{
			printf("error\n");
			return 0;
		}
		else
		{
			//Allocate space for the sudoku table
			char ** sudoku;
			sudoku = (char**)malloc(sizeof(char*)*9);
			int i,j;
			for(i = 0; i < 9; i++)
			{
				sudoku[i] = (char*)malloc(sizeof(char)*9);
			}

			char integer;
			char nl;
			int space = 0;
			int x1,y1,x2,y2;
			int option = 0;	//Determines what part of the project needs to be excuted
			for(i = 0; i < 9; i++)
			{
				for(j = 0; j < 9; j++)
				{
					fscanf(fp, "%c", &integer);
					//printf("%c ", integer);
					sudoku[i][j] = integer;
					if(integer == ' ')
					{
						option = 1;
						space++;
						if(space == 1)
						{
							x1 = i;
							y1 = j;
						}
						else if(space == 2)
						{
							x2 = i;
							y2 = j;
						}

					}
				}
				fscanf(fp, "%c", &nl);
				//printf("\n");
			}
			
			//prints the table
			/*for(i = 0; i < 9; i++)
			{
				for(j = 0; j < 9; j++)
				{
					printf("%c ", sudoku[i][j]);
				}
				printf("\n");
			}*/

			//Contains all the possible options in a sudoku row or col or section
			char list[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
			if(option == 0)	//correctness
			{
				//checks the row for correctness
				int checkrow = rowCheck(sudoku, list);
				if(checkrow == 2)
				{
					printf("incorrect\n");
					freeSudoku(sudoku);
					return 0;
				}
				else
				{
					//printf("continue\n");
					int checkCol = colCheck(sudoku, list);
					if(checkCol == 2)
					{
						printf("incorrect\n");
						freeSudoku(sudoku);
						return 0;
					}
					else
					{
						//printf("continue\n");
						int checkSection = section(sudoku, list);
						if(checkSection == 2)
						{
							//printf("this one\n");
							printf("incorrect\n");
							freeSudoku(sudoku);
							return 0;
						}
						else
						{
							printf("correct\n");
							freeSudoku(sudoku);
						}

					}

				}

			}
			else	//solvability
			{
				//printf("part 2: solvability\n");
				if(space == 1)
				{
					int check = checkForSolvability(sudoku, list, x1, y1);
					if(check == 2)
					{
						printf("unsolvable\n");
						freeSudoku(sudoku);
						return 0;
					}
					else
					{
						printf("solvable\n");
						freeSudoku(sudoku);
						return 0;
					}
				}
				else
				{
					int check = checkForSolvability(sudoku, list, x1, y1);
					if(check == 2)
					{
						printf("unsolvable\n");
						freeSudoku(sudoku);
						return 0;
					}
					else
					{
						int check2 = checkForSolvability(sudoku, list, x2, y2);
						if(check2 == 2)
						{
							printf("unsolvable\n");
							freeSudoku(sudoku);
							return 0;
						}
						else
						{
							printf("solvable\n");
							freeSudoku(sudoku);
						}

					}
				}

			}

		}
	}
	return 0;
}