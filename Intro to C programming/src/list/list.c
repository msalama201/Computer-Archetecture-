#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {

	int x; 
	struct list *next;
}ll;

ll *createList(){
	ll *head = NULL;
	return head;
}


int insert(ll **head, int x)
{
	ll *now=*head; // current node is now pointing to the head 
	ll *addedItem=malloc(sizeof(ll)); //  allocate memory for new node
	addedItem->x=x;  // takes a data and put it in node 
	addedItem->next = NULL;

	if(!*head)
	{ // if list is emptty them the head is the new node 
		*head=addedItem;
		return 0;
	}

		else
		{ /// otherwise the node is added from the left becoming the head and then point to the old head
			addedItem->next = now;
			*head= addedItem;
		}

	return 0;

}


void printnum (ll *head){ // used to print the number of nodes 
	ll *now = head; // current is equal to head of list 
	int count=0; // counter set to 0

	while(now){
	// while loop to see if current exists continue 
		now=now->next;// if you find current then set it to the node after current , 
		//the while loop will check to see if next will exsists 
		count++;// add 1 to counter if there is a node
	}
printf("%d\n", count);
// prints out the numver of nodes 
} // ends priunt num function


void prlist (ll *head)
{ 
	ll *now = head; // current is equal to head of list 

		while(now)
		{ // while current exists 
			printf("%d ", now->x); // print the data of curent 
			now=now->next; // nincrease the count of current by making it = to its next value 
		}


} // ends print list function



int sort(ll *head){


ll *now=head; // current pointer is now the head of the list 

ll *holder = NULL; // temp pointer to equal null 


while(now){ // while current exsits 

	holder = now; // sets temp to current value 

while(holder->next){ // checks to see if temp next exists 

if (now->x > holder->next->x){ // if the current data is bigger than the temp(current)->next->
// data we need to check which number is
// bigger if the head is the biggest then it goes through , if head is not bigger just make current pint to th next node instead and compare again 
// this algoritmh is a basic bubble sort which is very uneffeicent but very simple to make 
	int value = now->x;
	now->x = holder->next->x;
	holder->next->x= value;
}// we are not swapping the nodes but in fact all we are doing is swappin the pointer to the values instead 
holder = holder->next;
} // inside while loop 

now= now->next;
} // outside while loop 

return 0;

}

// essential this sorting algoithm checks the frit and second element (nodes) if the frist is bigger swap the two data points, if its not bigger just make the next elemnt the element we use to check 
// so its elmnt 1> elemnt2 switch and now element 2, element 1 > element 3, switch and so on it does this the entire time of the nodes and then does it again for 2 more times 



void del(ll *head, int value) // this del function takes the list and the value it needs to delet 
{
    
    ll * now = head; // now node is now ewaul to head 
    ll * holder = head;  // this now will 



    while (now && now->x == value)
    {
        now = holder->next;   
        free(holder);               
        holder = now;        
    }
   

    while(now->next)
    {

    	if(now->next->x == value){
    		now->next = now->next->next;

    	}

    	else now = now->next;

    }

}



void deldup( ll *head)
{
     ll *now= head;
     ll *holder = NULL;
     //ll *rep = NULL;
    
 
  
    while (now && now->next) // if curent and current next exists 
    {
        holder = now; // make temp = to current

        while (holder->next)
        {
            
            if (now->x == holder->next->x) // if the data is duplicated then we have to skip over the node 
            {
                
                //rep = holder->next;
                holder->next = holder->next->next;
                
            }
            else 
                holder = holder->next;
        }
        now = now->next;
    }
}



void freeList(ll *head)
{
 ll * next= NULL;


 while ( head) { 
 	next = head->next;
 	free(head);

 		head = next;
}

}



int main(int argc, char const *argv[]){
	int d;
	char c;



	FILE *fp = fopen(argv[1], "r");

	if(fp==NULL){
	printf("error\n");
	exit(0);
}
	



	if(fp != NULL){
		ll *list = createList();

		


		

		while(fscanf(fp,"%c %d\n", &c , &d ) != EOF){
			//printf("%c %d\n", c, d); debugger

			if (c=='i')
			{
				insert(&list,d);		
			}

			

			if (c =='d')
			{

				del(list,d);
				

			}


	


			

}

			// while loop to go though the file while its not the end





sort(list);
deldup(list);
printnum(list);
prlist(list);
freeList(list);








		// end if to see if the file is  not null
}







	else 
	printf("error\n");
	exit(0);
	 // end else 



fclose(fp);



	return 0;




}

