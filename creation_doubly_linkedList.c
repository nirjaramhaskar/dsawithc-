 /************************  Creation and traversal of doubly linked list  *////////
#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct dlink
	{
	 int no;
	 struct dlink *next;
	 struct dlink  *prev;
	} node;

 void create(node **start,node **end)
   {
	node *temp,*p;
	char ch='y';
	system("cls");
	if(*start != NULL)
	  {
		printf("\n\n\t **** LIST ALREADY EXISTS *****");
		getch();
		return;
	   }
	fflush(stdin);
	printf("\n\n\t\t **** INPUT BLOCK ****\n");
	while(ch == 'y')
	  {
	   temp=(node *)malloc(sizeof(node));
	   printf("\n\t Enter the no : ==> " );
	   scanf("%d",&temp->no);
	   temp->next = NULL;
	   if(*start==NULL)
		{
		 p=*start=temp;
		 temp->prev=NULL;
		}
	   else
		{
		 p->next=temp;
		 temp->prev=p;
		 p=temp;
		}
	   *end=temp ;
	   fflush(stdin);
	   printf("\n\t Do you want to continue (y/n) ? : ");
	   ch=getchar();
	 }
    return;
   }

void print(node *start,node *end)
   {
	 node *temp;
	 system("cls") ;
	 printf("\n\n\t\t **** DISPLAY BLOCK ****\n");
	 printf("\n\n\t Base address    Number     Next Link");
	 printf("\n\t ====================================");
	 for(temp=start;temp!=NULL;temp=temp->next)
		printf("\n       %10u  %10d  %10u",temp,temp->no,temp->next);
	 getch();
	 printf("\n\n\t End address    Number    Prev Link");
	 printf("\n\t ==================================");
	 for(temp=end;temp!=NULL;temp=temp->prev)
		printf("\n       %10u  %10d  %10u",temp,temp->no,temp->prev);
	 printf("\n\n\t Press any key to goto MAIN BLOCK.....");
	 getch();
	 return;
   }

 int main()
   {
	node *start,*end;
	start=end=NULL;
    char ch;
	while(1)
	 {
	  system("cls");
	  printf("\n\n\t\t **** MAIN BLOCK ****\n");
	  printf("\n\t 1. To Create the Doubly Linklist");
	  printf("\n\t 2. To Display the Doubly Linklist");
 	  printf("\n\t 3. To Exit ");
	  printf("\n\n\t  Enter your choice ==> ");
	  ch=getchar();
	  switch(ch)
		  {
			case '1':
			  create(&start,&end);
			  break;
			case '2':
			  print(start,end);
			  break;
			 case '3':
			  exit(0);
			}
		}
	return 0 ;
	
	}


 /******************** End of the Program ****************************/
