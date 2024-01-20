 ////// Creation and traversal of linear linked list   //////
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
	 system("cls") ;
	 printf("\n\n Base address    Number     Link");
	 printf("\n ===============================");
for(temp=start;temp != NULL;temp=temp->link)
printf("\n%10u  %10d  %10u",temp,temp->no,temp->link);
printf("\n\n\t Press any key to goto MAIN BLOCK.....");
	 getch();
	 return;
	}


 int  main()
  {
	node *start;
 
	start=NULL;

 			start=create(start) ;
 			  print(start);
 	}
