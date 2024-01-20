 
#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <alloc.h>
typedef struct linklist
	 {
	  int no;
	  struct linklist *link;
	 } node;
char ch;
node *create(node *start)
	{
		node *temp,*p ;
		ch='y';
	//	clrscr();
		printf("\n\t\t **** INPUT BLOCK ****\n");
		if(start != NULL)
		  {
			printf("\n\n\t **** LIST ALREADY EXIST *****");
			getch();
			return(start);
		   }
		fflush(stdin);
		while(ch=='y')
		  {
		   temp=(node *)malloc(sizeof(node));
		   printf("\n\t Enter the no :==> " );
		   scanf("%d",&temp->no);
		   temp->link = NULL;
		   if(start == NULL)
			 p=start=temp ;
		   else
			{
			p->link=temp;
			p=temp;
			}
		   fflush(stdin);
		   printf("\t Do you want to continue (y/n) ? : ");
	 	   ch=getchar();
		  } // end of loop
		  return(start);
	 }


void print(node *start)
	{
	 node *temp;
	// clrscr(); system("cls") ;
	 printf("\n\n\t Base address    Number     Link");
	 printf("\n\t ===============================");
for(temp=start;temp != NULL;temp=temp->link)
printf("\n%10u  %10d  %10u",temp,temp->no,temp->link);
printf("\n\n\t Press any key to goto MAIN BLOCK.....");
	 getch();
	 return;
	}

node *insf(int item,node *start)
	  {
	  	node *p ;
	  	p=(node *) malloc(sizeof(node)) ;
		p->no=item;
		p->link=start;
		start=p;
printf("\n\n\t Element is succesfully Inserted ");
		getch();
		return(start);
	  }
 int  main()
  {
	node *start;
 int item,op ;
	start=NULL;
while(1)     // infinite loop
{
printf("\n**************** Menu ***************");
printf("\n1) Create the linked list");
printf("\n2) Insert a new node in the beginning");
printf("\n3) Display the linked list");
printf("\n4) Exit");
printf("\nEnter your option please ");
scanf("%d",&op);
switch(op)
{
case 1:
 			start=create(start) ;
 	        break ;
case 2:
	 		printf("Enter the value") ;
	 		scanf("%d",&item);
			start=insf(item,start);
	 		break ;
case 3:			  
 	        print(start) ;
			break ;
case 4: 
            exit(0) ;    // terminates the program			  
 	        
	 }
 	
}
	
	
