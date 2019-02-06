#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

double ** multiply (int size,int sizeRow, double ** matrixA, double ** matrixB, double ** result)
{
	int row;
	int col;
	int h;
	for (row = 0; row < size; row++)
	{
		for ( col = 0; col < size; col++)
		{

			 result[row][col] = 0.0000;

			for (h = 0; h < sizeRow; h++)
			{
				result[row][col]+= matrixA[row][h] * matrixB[h][col];

			}
			//printf("%lf\n", result[row][col]);
		}
	}
return result;
} // mulltipy function that takes paramters and multiplies 2 matrix and puts them in result 


double ** multiply2 (int sizeR,int sizeC, double ** matrixA, double ** matrixB, double ** result)
{
	int row;
	int col;
	int h;
	//printf("%d\n",sizeR );
	//printf("%d\n",sizeC );
	
	for (row = 0; row < sizeC; row++)
	{
		for ( col = 0; col < sizeR; col++)
		{

			 result[row][col] = 0.00000000;

			for (h = 0; h < sizeC; h++)
			{
				result[row][col]+= matrixA[row][h] * matrixB[h][col];
				


			}


		}
	}
return result;
} // mulltipy function that takes paramters and multiplies 2 matrix and puts them in result 




double ** multiply3 (int sizeR, int sizeC, double ** matrixA, double ** matrixB, double ** result)
{
	int row;
	int col;
	int h;
	//printf("%d\n",sizeR );
	//printf("%d\n",sizeC );
	
	for (row = 0; row < sizeC; row++)
	{
		for ( col = 0; col < 1; col++)
		{

			 result[row][col] = 0.00000000;

			for (h = 0; h < sizeR; h++)
			{
				result[row][col]+= matrixA[row][h] * matrixB[h][col];

			}
//printf("%lf\n", result[row][col]);

		}
	}
return result;
} // mulltipy function that takes paramters and multiplies 2 matrix and puts them in result 


int main(int argc, char const *argv[])
{


FILE *fp = fopen(argv[1], "r");
FILE *ff = fopen(argv[2], "r");

	if (fp!=NULL)
{
int col=0;
int row =0;
int i;
int k; 
double pivot = 1.00;
int placeHolder = 1;
int negative = 0;

	char train [6];
    fscanf(fp,"%s %d %d \n",train,&col,&row);
	col = col +1;

		//printf("%s\n", train);
		//printf("%d\n",col );
		//printf("%d\n",row );


double ** array;
		array=(double**) malloc(sizeof(double*)*row);

			for (i = 0; i < row; i++)
					{
						array[i]=(double*) malloc(sizeof(double)*col);
					}

double value; // value of the items in the array as well as tfinding the exponents
		//printf("enter loop for reading the file\n");
		for (i = 0; i < row; i++)
		{
			for (k = 0; k < col; k++)
			{
				

					//printf("Pass1\n");
					fscanf(fp, "%lf ",&value);
			
				array[i][k]=value;
				//printf("%lf ",value );
				}
			}

			/*

for (i = 0; i < row; i++)
			{
				for ( k = 0; k < col; k++)
				{

					if (k==col-1)
					{
						value =array[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = array[i][k];
						printf("%lf ",value );
					}
		
				}
			} 




			//printf("passsssssss\n");
		
*/
// allocates memory for the x arrat 
double ** arrX;
		arrX=(double**) malloc(sizeof(double*)*row);

			for (i = 0; i < row; i++)
					{
						arrX[i]=(double*) malloc(sizeof(double)*col);
					}




			for (i = 0; i < row; i++)
			{
				for ( k = 0; k < col-1; k++)
				{				
						arrX[i][k+1]= array[i][k];
					}
				}
			

			for (i = 0; i < row; i++)
			{
				for ( k = 0; k < col-1; k++)
				{

					if (k==0)
					{					
						arrX[i][k]= 1.0;
					}
					}

				}



//printf("passed ener 1\n");

 //allocated memoery for x tranpose 
		

double ** xT;
		xT=(double**) malloc(sizeof(double*)*col);


		for (i = 0; i < col; i++)
		{
			xT[i] = malloc (sizeof(double)*row);
		}


/*

printf("empty xt\n");

	for (i = 0; i < col; i++)
			{
				for ( k = 0; k < row; k++)
				{

					if (k==row-1)
					{
						xT[i][k] = 0;
						value= xT[i][k];
						printf("%lf\n",value );
					}


					else
				{
						xT[i][k] = 0;
						value= xT[i][k];
						printf("%lf ",value );
					}
		
				}
			} // for loop to print out the values in result after its done multiplying
*/



			for (i = 0; i < col; i++)
			{
				for ( k = 0; k < row; k++)
				{				
						xT[i][k]= arrX[k][i];
					}
				}
// this just makes x transpose
/*
printf("xxxxxxxxx\n");

for (i = 0; i < row; i++)
			{
				for ( k = 0; k < col; k++)
				{

					if (k==col-1)
					{
						value =arrX[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = arrX[i][k];
						printf("%lf ",value );
					}
		
				}
			} // for loop to print out the values in result after its done multiplying

			*/
/*
printf("xt //////////////////////////\n");

	for (i = 0; i < col; i++)
			{
				for ( k = 0; k < row; k++)
				{

					if (k==row-1)
					{
						value =xT[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = xT[i][k];
						printf("%lf ",value );
					}
		
				}
			} // for loop to print out the values in result after its done multiplying

*/
// allocated memory for the x times x transpose 
double ** xxt;
		xxt=(double**) malloc(sizeof(double*)*col);


		for (i = 0; i < col; i++)
		{
			xxt[i] = malloc (sizeof(double)*col);
		}


/*
		for (i = 0; i < col; i++)
			{
				for ( k = 0; k < col; k++)
				{

					if (k==col-1)
					{
						value =xxt[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = xxt[i][k];
						printf("%lf ",value );
					}
		
				}
			}

*/

//printf("%d\n", row);
//printf("%d\n", col );

xxt=multiply(col,row,xT,arrX,xxt);

/*
printf("xt * x\n");


	for (i = 0; i < col; i++)
			{
				for ( k = 0; k < col; k++)
				{ 



					if (k==col-1)
					{
						value =xxt[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = xxt[i][k];
						printf("%lf ",value );
					}
		
				}
			}

			*/






double ** y;
		y=(double**) malloc(sizeof(double*)*row);

			for (i = 0; i < row; i++)
					{
						y[i]=(double*) malloc(sizeof(double)*1);
					}

/*

	for (i = 0; i < row; i++)
			{
				for ( k = 0; k < 1; k++)
				{

					if (k==1-1)
					{
						value =y[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = y[i][k];
						printf("%lf ",value );
					}
		
				}
			}

			DEBUGGER prints out the empty matrix whih lets me see if i allocated it right 
			*/



for (i = 0; i < row; i++)
{
	for ( k = 0; k < 1; k++)
		{
			y[i][k]= array[i][col-1];
		}
}
//  this lets me find y by taing the oroginal array and just using the last colum 

/*

				for (i = 0; i < row; i++)
			{
				for ( k = 0; k < 1; k++)
				{

					if (k==1-1)
					{
						value =y[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = y[i][k];
						printf("%lf ",value );
					}
		
				}
			}

 DEBUGGER to print out y matrix 
*/


double ** iden;
		iden=(double**) malloc(sizeof(double*)*col);


		for (i = 0; i < col; i++)
		{
			iden[i] = malloc (sizeof(double)*col);
		}
// allocaed momery for the identiy matrix 


	for (i = 0; i < col; i++)
			{
				for ( k = 0; k < col; k++)
				{
					if (k==i)
					{
						iden[i][k]=1.0;
					}
					else 
					{
						iden[i][k]=0.0;
					}
				}
			} 
// creats the i denity matrix and puts 1 acrros the diagonal and 0 everywhere else 

/*
	printf("pringing the iden. matrix \n");


	for (i = 0; i < col; i++)
			{
				for ( k = 0; k < col; k++)
				{

					if (k==col-1)
					{
						value =iden[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = iden[i][k];
						printf("%lf ",value );
					}
		
				}
			}

			*/
// instead of doing *2 in every place i just mulitlied by 2 to creat an matrix with the size of the xt and the identity 
int colDub = col * 2;


double ** aug;
		aug=(double**) malloc(sizeof(double*)*col);


		for (i = 0; i < col; i++)
		{
			aug[i] = (double*) malloc(sizeof(double)*colDub);
		}


/*

printf("pringing the combined. matrix \n");


	for (i = 0; i < col; i++)
			{
				for ( k = 0; k < colDub; k++)
				{

					if (k==colDub-1)
					{
						value =aug[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = aug[i][k];
						printf("%lf ",value );
					}
		
				}
			}

			*/



int count= 0; // allows me to count the number of columsin the matrix so i can take the
// valus inthe identity matrix and placehtem next to the x times transpose 

for (i = negative; i < col; i++)
			{
				count ++;
				for ( k = negative; k < col; k++)
				{
						aug [i][k] =xxt[i][k];					
					//	printf("%d\n",count );
				}
			}

		for (i = negative; i < col; i++)
			{				
				for ( k = negative; k < col; k++)
				{	
						aug [i][count+k] =iden[i][k];										
						//printf("%d\n",count );
				}
			} 



/*

for (i = 0; i < col; i++)
			{
				for ( k = 0; k < colDub; k++)
				{

					if (k==colDub-1)
					{
						value =aug[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = aug[i][k];
						printf("%lf ",value );
					}
		
				}
			}


*/

			double div; // this will be the devisor 
			int w;
			int x;
			int yy;
			int z;
			// fresh new variables so i dont confse them with other ones 		
w= 0;
// this is for the lower triagular 
    while(w < col) 
    {
    	x = 0;
      for(; x < col; x = x + placeHolder)
        {
            if(w > x)
            {          	
                continue;
            }
            else if(aug[w][x] != 1.0 && w==x  )
            { 
                   div = aug[w][x]; 
                   	yy = negative;
                   while(yy < (colDub))
                   {
                       aug[w][yy] = aug[w][yy] / div;
                       yy = yy+placeHolder;
                   }       
       			        continue;
            }


            else if(aug[x][w] != 0.0 && (w!=x)  )
            {
            	z = x;
                while(z < col)
                {  
                    div = aug[z][w];
                    yy = negative;
                    while(yy < (colDub))
                    {

                        aug[z][yy] +=  (  ( aug[x - placeHolder][yy] )  * ( (negative-(div)) ) );
                        yy = yy+placeHolder;
                    }

                    	z = z+placeHolder;
                }
              continue;
            }
        }
				w = w+placeHolder;
    }
  // this is for the upper triangluar 000



    w = (col+ (negative - (placeHolder+placeHolder)));
    			while(w > (negative-placeHolder))
    			{ 
    				int temp = col - placeHolder;
    				x = temp;
       				 while(aug[w][x] != pivot)
       				 {
       				 	z= w;
          			  while( z > (negative - placeHolder))
           				 {
             			   div = aug[w][x];
             			   	yy = negative;
             			  while(yy < (colDub)) 
            			    {
                  				  aug[z][yy] += (aug[x][yy] * (negative-div) ); 
                  				  yy++;
               				 }  // ends the loop to put the devisor times the aguments matrix in the agument matrix value at index
 							z= z- placeHolder;
           				 } //  if its not a 1 take the value and make the value eqaul the devisor 
           				 x = x - placeHolder;
        			} // ends the for loop to check if the index is not a 1 
   						w = w- placeHolder;
   				 } // ends the main for loop to get the upper triangluar 00

/* // this ends the rref 

printf(" the finial result \n");


    for (i = 0; i < col; i++)
			{
				for ( k = 0; k < colDub; k++)
				{

					if (k==colDub-1)
					{
						value =aug[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = aug[i][k];
						printf("%lf ",value );
					}
		
				}
			}
*/

			





//printf("finished \n");
//printf("%d\n", count);



// 
double ** inv;
		inv=(double**) malloc(sizeof(double*)*col);


		for (i = 0; i < col; i++)
		{
			inv[i] = malloc (sizeof(double)*col);
		}




		for (i = 0; i < col; i++)
			{				
				for ( k = 0; k < col; k++)
				{					 
						 inv [i][k] = aug [i][count+k];					
				}
			}


/*

	for (i = 0; i < col; i++)
			{
				for ( k = 0; k < col; k++)
				{

					if (k==col-1)
					{
						value =inv[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = inv[i][k];
						printf("%lf ",value );
					}
		
				}
			}

*/ // allocates momeoty 
double ** invXt;
		invXt=(double**) malloc(sizeof(double*)*col);


		for (i = 0; i < col; i++)
		{
			invXt[i] = malloc (sizeof(double)*row);
		}

invXt=multiply2(row,col,inv,xT,invXt);  // this gets you xt x inverse 


/*
printf("xt //////////////////////////\n");

	for (i = 0; i < col; i++)
			{
				for ( k = 0; k < row; k++)
				{

					if (k==row-1)
					{
						value =xT[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = xT[i][k];
						printf("%lf ",value );
					}
		
				}

			} // for loop to print out the values in result after its done multiplying
*/
/*
printf("invxt\n");

	for (i = 0; i < col; i++)
			{
				for ( k = 0; k < row; k++)
				{

					if (k==row-1)
					{
						value =invXt[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = invXt[i][k];
						printf("%lf ",value );
					}
		
				}

			} 

*/




double ** all;
		all=(double**) malloc(sizeof(double*)*row);

		for (i = 0; i < row; i++)
		{
			all[i] = malloc (sizeof(double)*1);
		}

//printf(" %d, %d \n", row, col );
all=multiply3(row,col,invXt,y,all);  // multiplies to get W
/*
printf("all\n");

	for (i = 0; i < col; i++)
			{
				for ( k = 0; k < 1; k++)
				{

					if (k==1-1)
					{
						value =all[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = all[i][k];
						printf("%lf ",value );
					}
		
				}
			}

*/




	if (ff!=NULL)
{
int col=0;
int row =0;
int i;
int k;

char data [5]; // 
fscanf(ff,"%s %d %d \n",data,&col,&row);


		//printf("%s\n", data);
		//printf("%d\n",col );
		//printf("%d\n",row );


double ** arrayData;
		arrayData=(double**) malloc(sizeof(double*)*row);
			for (i = 0; i < row; i++)
					{
						arrayData[i]=(double*) malloc(sizeof(double)*col);
					}

double value; // value of the items in the array as well as tfinding the exponents
		//printf("enter loop for reading the file\n");
		for (i = 0; i < row; i++)
		{
			for (k = 0; k < col; k++)
			{
					//printf("Pass1\n");
					fscanf(ff, "%lf ",&value);
					arrayData[i][k]=value;
				//printf("%lf ",value );
			}		
		}
/*
for (i = 0; i < row; i++)
			{
				for ( k = 0; k < col; k++)
				{

					if (k==col-1)
					{
						value =arrayData[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = arrayData[i][k];
						printf("%lf ",value );
					}
		
				}
			} 
*/
 // alocated memory for the array x on data

double ** arrXData;
		arrXData=(double**) malloc(sizeof(double*)*(row));

			for (i = 0; i < (row); i++)
					{
						arrXData[i]=(double*) malloc(sizeof(double)*(col+1));
					}


/*

					printf("empty x \n");

for (i = 0; i < row; i++)
			{
				for ( k = 0; k < col+1; k++)
				{

					if (k==col)
					{
						value =arrXData[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = arrXData[i][k];
						printf("%lf ",value );
					}
		
				}
			} // for loop to print out the values in result after its done multiplying

*/

			for (i = 0; i < row; i++)
			{
				for ( k = 0; k < col; k++)
				{
					arrXData[i][k+1]= arrayData[i][k];
				}
			}
			for (i = 0; i < row; i++)
			{
				for ( k = 0; k < col+1; k++)
				{

					if (k==0)
					{
						arrXData[i][k]= 1.0;
					}
						
				}
			}
// this is to take the new x prime and make it have 1 in the 0 col and combine into an array called arrayxdata 



/*
//printf("xxxxxxxxx\n");

for (i = 0; i < row; i++)
			{
				for ( k = 0; k < col+1; k++)
				{

					if (k==col)
					{
						value =arrXData[i][k];
						printf("%lf\n",value );
					}


					else
				{
						value = arrXData[i][k];
						printf("%lf ",value );
					}
		
				}
			}

			*/  // DBUGGER // for loop to print out the values in result after its done multiplying


// allocaed memory for the finial answer
double ** fin;
		fin=(double**) malloc(sizeof(double*)*row);
		for (i = 0; i < row; i++)
		{
			fin[i] = malloc (sizeof(double)*1);
		}
//printf("%d, %d\n", row ,col);
fin=multiply3(col+1,row,arrXData,all,fin);
//printf("fin\n");

	for (i = 0; i < row; i++)
			{
				for ( k = 0; k < 1; k++)
				{
					if (k==1-1)
					{
						value =fin[i][k];
						printf("%.0f\n",value );
					}


					else
					{
						value = fin[i][k];
						printf("%.0f",value );
					}
		
				}
			} // just a for loop to print out the answer 


} // ends the 2nd file pointer to check for data 
} // ends the 1st file pointer to check for train 

	return 0;	
} // ends the main 











