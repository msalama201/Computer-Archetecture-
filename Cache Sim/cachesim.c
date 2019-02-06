#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct cc 
{
	int data;

	char * value;

	int place;

};
struct cc** csh;





char* rule;

int asoc;

char bin[49];

int mng;

int superb;

int ns;

int st;

int oo = 0;
int oi = 1;
int io = 2;
int ii = 3;






//First in first out
void fifo(int mnd){

free(csh[mnd][asoc-oi].value);

	int k;

// free the chs value dont forget for later 
	


	csh[mnd][asoc-oi].value = NULL;


	for(k = asoc-oi; k>oo;k--)

	{
		//cashe of the frist date equals date before 
		csh[mnd][k].data = csh[mnd][k-oi].data;
		// chase of the first vlaue queals chase before 

		csh[mnd][k].value = csh[mnd][k-oi].value;
		// chache of the first place and makes it equle to one bbefore 

		csh[mnd][k].place = csh[mnd][k-oi].place;
	}
}

int rmem;
int chit;
int cmiss;
int wmem;


//least recently used
void LRU(int mnd,int rnd){ 

	int k;

	int one;

	char* two;

	int three;

	three = csh[mnd][rnd].place;

	two = csh[mnd][rnd].value;
	
	one = csh[mnd][rnd].data;
	
	for(k = rnd;k > oo; k--)

	{

		
		csh[mnd][k].place = csh[mnd][k-oi].place; 
		
		csh[mnd][k].value = csh[mnd][k-oi].value; 
		
		csh[mnd][k].data = csh[mnd][k-oi].data;
		
	}

	csh[mnd][oo].place = three;


	csh[mnd][oo].value = two;
	
	csh[mnd][oo].data = one;
	
}

int rng;
int prewmem;


int cng;


void find(char* super, int mnd,char find){

	int i;
	if(find == 'W')
	{

		if(ns == oo)

		{
			wmem= wmem + oi;
		}

		else
		{
			prewmem= prewmem + oi;
		} 
	}
	for(i = oo;i<asoc;i++)
	{

		if(csh[mnd][i].data == oo)
		{

			fifo(mnd);

			csh[mnd][oo].data = oi;

			csh[mnd][oo].value = strdup(super);

			csh[mnd][oo].place = mnd;


			if(ns == oo)
			{

				cmiss = cmiss+oi;
				rmem = rmem + oi;

			}


			else
			{
				if(st == oo)
				{

					mng= mng + oi;
					rng=rng+oi;
					st = oi;
				}


				else
				{

					rng=rng+oi;
				}

			}
			break;
			
		}


		if(strcmp(super,csh[mnd][i].value) == oo)
		{

			if(ns==oo)

			{

				if(strcmp(rule,"lru")==oo){LRU(mnd,i);}
				chit++;
			}

			else{
				if(st == oo)
				{
					if(strcmp(rule,"lru")==oo){LRU(mnd,i);}

					cng=cng+oi;
				}
			}
			break;
		}

		if(i == asoc-oi)
		{

			fifo(mnd);

			csh[mnd][oo].data = oi;

			csh[mnd][oo].value = strdup(super);

			csh[mnd][oo].place = mnd;


			if(ns==oo){cmiss=cmiss+oi; rmem=rmem+oi;}	
			else
			{


				if(st == oo)
				{


				mng= mng + oi;

				rng = rng + oi;

				st = oi;

				}
				else
				{

					rng = rng + oi;
				}
			}
			break;

		
		}
	}


}



int pret;


//Converts binary to decimal
int b2d(char* words) 
{
    int result = oo;


    int x;

    int y = oo;


    for(x = strlen(words)-oi;x>=oo;x--)

    {
    	result = result + ((words[x]-'0')*pow(io,y));

   	y = y + oi;

    }

    return result;
}


void conHex(char table[],int length)
{
	int oo = 0;


	char c;
	int n; 
	int i;
	int k;
	int p;
	int indexPlace;
	n = length;	

	for(i = oo; i<48;i++)
	{
		bin[i] = '0';
	}


	k = 48 - 4*(n-io);

	for(p = io;p<n;p++)
	{
		c = table[p];
		switch(c){


        	case '0':
        	    for(indexPlace = k; indexPlace < k+4; indexPlace++){
        	    	bin[indexPlace] = '0';
        	    }
        	    k = k+4;
        	 
        	    break;
        	case '1':
        	for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k+3)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	    k = k+4;
        	    
        	
           	    break;
        	case '2':


        	for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k+2)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;
  

            	
        	case '3':

        	for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k+2 || indexPlace == k+3)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;



            case '4':

            	for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k+1)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;



        	case '5':


        	for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k+1 || indexPlace == k+3)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;

        	   


            	


        	case '6':


        	for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k+1 || indexPlace == k+2)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;


        	case '7':

        	for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k+1 || indexPlace == k+2 || indexPlace == k+3)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;
        	

               
        	case '8':

        	for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;

        	   
        


            case '9':

            for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k || indexPlace == k+3)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;
             
        	case 'a':
        	for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k || indexPlace == k+2)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;


              
          
        	case 'b':

        	  for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k || indexPlace == k+2 || indexPlace == k+3)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;
             	
        case 'c':
          for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k || indexPlace == k+1)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;


             	
        case 'd':
          for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k || indexPlace == k+1 || indexPlace == k+3)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;


         
        case 'e':
          for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k || indexPlace == k+1 || indexPlace == k+2)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;
             
            
        case 'f':
          for(indexPlace = k; indexPlace < k+4; indexPlace++){

        		if (indexPlace == k || indexPlace== k+1 || indexPlace == k+2 || indexPlace == k+3)
        	    	bin[indexPlace] = '1';
        	    else {
        	    	bin[indexPlace] = '0';
        	    }

        	    }
        	     k = k+4;

        	    break;
          
        }
	}
	return;
}

int main(int argc,char** argv){
	
	FILE* fp = NULL;
	char* ism = NULL;
	char one[30];
	char two;
	char three[30];

	
	int cs;
	char* ass;

	int sn;

	int iz;

	int ofs;

	int block;

	int bl;

	int i;

	int x;

	int y;

	int ic;

	int ifr;

	char ib[48];

	unsigned long longlong;
	
	rmem = 0;
	wmem = 0;
	chit = 0;
	cmiss = 0;
	rng = 0;
	prewmem = 0;
	cng = 0;
	mng = 0;

	cs = atoi(argv[1]);

	ass = argv[2];

	rule = argv[3];

	superb = atoi(argv[4]);

	ism = argv[5]; 

	asoc = cs/superb;

	if(ass[5] == ':')
	{
		asoc = atoi(&ass[6]);
	}

	if(ass[0] == 'd')

	{
		asoc = 1;
	} 

	block = cs/asoc;

	sn = block/superb;

	iz = (log(sn))/(log(2));

	ofs = log(superb)/log(2);

	ifr = pow(2,iz);

	csh = (struct cc**)malloc(ifr*sizeof(struct cc*));

	for(i = 0; i<ifr; i++)
	{
		csh[i] = (struct cc*)malloc(sizeof(struct cc)*asoc);
	}
	for(i = 0; i<ifr; i++)
	{
		for(x = 0;x<asoc; x++)
		{
			csh[i][x].value = strdup("no");
			csh[i][x].place = -1; 
			csh[i][x].data = 0;
			
			}
	}

	ns = 0;

	ism = argv[5];

	fp = fopen(ism, "r");
	
	//No. prefetch
	while(!feof(fp)){
		fscanf(fp, "%s %c %s",one,&two,three);
		if(strcmp(one,"#eof") == 0){
			break;
		}
		i = strlen(three);
		conHex(three,i);
		bl = strlen(bin);
		bin[bl - ofs] = '\0';
		bl = strlen(bin);
		y = iz-1;
		for(x = bl-1;x>=bl-iz;x--){
			ib[y] = bin[x];
			y--;
		}
		ib[iz] = '\0';
		bin[bl-iz] = '\0';
		ic = b2d(ib);
		find(bin,ic,two);
	}
	fclose(fp);

	for(i = 0; i<ifr; i++)
	{
		for(x = 0;x<asoc; x++)
		{

			csh[i][x].value = strdup("no");

			csh[i][x].place = -1; 

			csh[i][x].data = 0;
			
			}
	}
	fp = fopen(ism, "r");

	pret = oo;

	//Prefetch
	while(!feof(fp))
	{
		ns= oi;

		st = oo;

		fscanf(fp, "%s %c %s",one,&two,three);

		if(strcmp(one,"#eof") == oo)
		{
			break;
		}

		i = strlen(three);

		conHex(three,i);

		bl = strlen(bin);

		bin[bl - ofs] = '\0';

		bl = strlen(bin);

		y = iz-oi;

		for(x = bl-oi;x>=bl-iz;x--)

		{
			ib[y] = bin[x];
			y--;
		}

		ib[iz] = '\0';

		bin[bl-iz] = '\0';

		ic = b2d(ib);

		find(bin,ic,two);


		if(st == oi)
		{
			pret = pret + oi;

			conHex(three,i);

			bin[48] = '\0';

			longlong = strtoul(three,(char**)0,oo);

			longlong = longlong + superb;

			//~~~~~~~~~~~~~~~~~~~~~~~.   converts decimal to bin//
			int x;
			int y;

			for (x = 47; x >= oo; x--)
			{
    			y = longlong >> x;

   				if (y & oi)
   				{
    	  			bin[47-x] = '1';
    			}

   				else
   				{
   	  				bin[47-x] = '0';
        		}
   			}



	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
			bl = strlen(bin);	bin[bl - ofs] = '\0';	bl = strlen(bin);

			y = iz-oi;

			for(x = bl-oi;x>=bl-iz;x--)
			{
				ib[y] = bin[x];
				y--;
			}

			ib[iz] = '\0'; bin[bl-iz] = '\0';


			ic = b2d(ib);


			find(bin,ic,'R');
		}
	}
	fclose(fp);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~ print the results ~~~~~~~~~~~~~~~~~~
	printf("no-prefetch\n");

	printf("Cache hits: %d\n",chit);

	printf("Cache misses: %d\n",cmiss);

	printf("Memory reads: %d\n",rmem);

	printf("Memory writes: %d\n",wmem);

	printf("with-prefetch\n");

	printf("Cache hits: %d\n",cng);

	printf("Cache misses: %d\n",mng);

	printf("Memory reads: %d\n",rng);

	printf("Memory writes: %d\n",prewmem);
	
	
	return 0;
}
