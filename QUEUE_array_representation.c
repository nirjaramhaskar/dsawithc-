            /******** ARRAY REPRESENTATION OF QUEUE ********/
 
#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MX 5
typedef struct queue_type
   {
	 int arr[MX] ;     // array representing queue
	 int front ;
	 int rear ;
   } node;
 
 void insert(node *q, int item)
 {

 if ((q->front==0 && q->rear==MX-1) || q->front==q->rear+1)
 {
 	printf("Queue overflow error.....") ;

    getch();
 	return ;  // control returns (no value is being returned as function is void)
	  }
	  	if (q->front==-1)       // if queue is empty
		  q->front=q->rear=0 ;
		  else  
		if (q->rear==MX-1)
	  	  q->rear=0 ;
	  	  else
	  	  q->rear=q->rear+1 ; 

	  q->arr[q->rear]=item ;        // inserting new value in queue 
 }
 int delete(node *q)
 {
 	int val ;
 	if (q->front==-1)
 	{
	 printf("Queue underflow error ......") ;
 	getch() ;
	return ;
	 }
	 val=q->arr[q->front] ;       // extracting the element from front
	 if (q->front==q->rear)       // only one element was there in the queue
	 q->front=q->rear=-1 ;         // now queue is empty
	 else
	 if (q->front==MX-1)
	 q->front=0 ;
	 else
	 q->front++ ;
	 return val ;               // returning the deeted value
 	
 }
 
 
int main()
   {
   char ch ;
    int val,item;
 	node queue ;     //declared  structure variable
 	queue.front=-1 ;
 	queue.rear=-1 ;
 
	while(1)
	  {
		system("cls");  // clears the screen
		printf("\n\t     *** Main Block ***\n");
		printf("\n\tArray representation of Queue");
		printf("\n\t=================================");
 		printf("\n\n\t  1) Inserting element into Queue");
		printf("\n\n\t  2) Deleting element from Queue");
 		printf("\n\n\t  3) Exit from program");
		printf("\n\n\t    Enter your Choice :==> ");
		fflush(stdin);
		scanf("%c",&ch);
		switch(ch)
		  {
		   case '1':
			  printf("\n\n\t Enter the Number to Push :=> ");
			  scanf("%d",&item);
			  insert(&queue,item);
			  break;
			 
		    
		 case '2':
			 val=delete(&queue) ;
			 printf("The value of deleted element is %d",val) ;
			 break;
		   case '3':
			exit(0);
		  }
	   }
	}


/******************** End of the Program ****************************/
