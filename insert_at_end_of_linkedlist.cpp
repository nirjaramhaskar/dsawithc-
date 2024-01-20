/* Highly acclaimed online programming courses C, C++, Java, Data Strcutures, Python,
             HTML,etc.
              https://mahajanonlineclasses.teachable.com 
       Anand Mahajan,India - Online course creator -  
	   Whatsapp - 9812164949   */

#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <alloc.h>
typedef struct linklist  // self refrential structure
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
{
printf("\n%10u  %10d  %10u",temp,temp->no,temp->link);
}
printf("\n\n\t Press any key to goto MAIN BLOCK.....");
	 getch();
	 return;
	}


void search(node *start)
	{
	  int i=1,item;
	  node *temp;
      node *search1(int , node*),*search2(int,node *);
	  while(i)
	    {
	//	clrscr();
		fflush(stdin);
		printf("\n\t\t **** SEARCH BLOCK ****\n");
		printf("\n\t 1. Seaching location from Unsorted Linklist");
		printf("\n\t 2. Searching location from Sorted Linklist ");
		printf("\n\t 3. Exit to MAIN BLOCK");
		printf("\n\n\t   Enter your choice ==> ");
		ch=getchar();
		switch(ch)
		 {
		  case '1':
//				clrscr();
				printf("\n\n\t Enter the number to be found ==> ");
				scanf("%d",&item);
				temp=search1(item,start);
				if(temp != NULL)
				   {
				    printf("\n\n\t The number is found");
				    printf("\n\n\t The address of location is = %d",temp);
				   }
				else
				    printf("\n\n\t Number not found in the linklist ");
				getch();
				break;
		  case '2':
//				clrscr();
				printf("\n\n\t Enter the number to be found ==> ");
				scanf("%d",&item);
				temp=search2(item,start);
				if(temp != NULL)
				   {
				    printf("\n\n\t The number is found");
				    printf("\n\n\t The address of location is = %d",temp);
				   }
				else
				    printf("\n\n\t Number not found in the linklist ");
				getch();
				break;
		  case '3':
				i=0;
				break;
			}
		 }
	   return;
	  }

node *search1(int item,node *start)
	 {
	  node *temp;
	  for(temp=start;temp != NULL;temp=temp->link)
	   {
		if(temp->no == item)
		   return(temp);
	  }
		   return(NULL);

	 }

node *search2(int item,node *start)
	{
	  node *temp;
	  temp=start;
	  while(temp != NULL && item >= temp->no)
	    {
if(item == temp->no)
		    return(temp);
			
if(temp->no < item)
		   temp=temp->link;
			}
	  return(NULL);
	}
	
node *insf(int item,node *p,node *start)
	  {
		p->no=item;
		p->link=start;
		start=p;
printf("\n\n\t Element is succesfully Inserted ");
		getch();
		return(start);
	  }
	  
	  
void insa(int item,int var,node *p,node *start)
	  {
 node *temp;
 for(temp=start;(temp->no != item) && (temp !=NULL);temp=temp->link);

		if(temp == NULL)
		  {
		    printf("\n\n\t Number not found in the Linklist");
		    getch();
		    return;
		  }
		else
	  {
		    p->no=var;
		    p->link=temp->link;
		    temp->link=p;
		    printf("\n\n\t Element is succesfully Insrted ");
		    getch();
		  }
		return;
	  }


node *insb(int var,int item,node *p,node *start)
	{
  node *temp,*p1;
 for(temp=start;(temp->no != item) && (temp != NULL);temp=temp->link)
		  p1=temp;

	   if(temp==NULL)
		 {
		   printf("\n\n\t Number not found in the Linklist");
		   getch();
		 }
	   else
		 if(temp==start)
			start=insf(item,p,start);
		 else
		   {
		    p->no=var;
		    p->link=p1->link; // p->link=temp ;
		    p1->link=p;
		    printf("\n\n\t Element is succesfully Insrted ");
		    getch();
		   }
	   return(start);
	}



  void inse(int item,node *p,node *start)
	{
	 node *temp;
	 p->no=item;
	 for(temp=start;temp->link != NULL;temp=temp->link);
	 temp->link=p;
	 p->link=NULL;
	 printf("\n\n\t Element is succesfully Insrted ");
	 getch();
	 return;
	}

   node *insp(int item,int loc,node *p,node *start)
    {
	 node *new1,*temp,*temp1;
	 int i;
	 if(loc == 1)
	   {
	    start=insf(item,p,start);
	    return(start);
	   }

	 for(i=1,temp=start;i!=loc && temp!=NULL;i++,temp=temp->link)
	    temp1=temp;

	 if(temp == NULL)
	    {
		printf("\n\n\t Linklist is not too long ");
		getch();
		return(start);
	    }

	 else
	    {
		new1 = (node *)malloc(sizeof(node));
		new1->no=item;
		new1->link=temp1->link;
		temp1->link=new1;
		printf("\n\n\t Element is succesfully Insrted ");
		getch();
	    }
	  return(start);
	}


node *insert(node *start)
	 {
	  int i=1,item,var;
node *p ;
	   
	  while(i)
	    {
		//clrscr();
system("cls") ;
		fflush(stdin);

		p=(node *)malloc(sizeof(node));

		printf("\n\t\t **** INSERT BLOCK ****\n");
		printf("\n\t 1. Insert in the starting of linklist ");
		printf("\n\t 2. Insert after a given node ");
		printf("\n\t 3. Insert before a given node ");
		printf("\n\t 4. Insert at the end of link list ");
		printf("\n\t 5. Insertion at a particular location");
		printf("\n\t 6. Exit to MAIN BLOCK");
		printf("\n\t    Enter your choice ==> ");
		ch=getche();
		switch(ch)
		 {
		  case '1':
//				clrscr();
printf("\n\n\t Enter the element you want to insert ==> " );
				scanf("%d",&item);
				start=insf(item,p,start);
				break;
		  case '2':
				//clrscr();
				printf("\n\n\t Enter the number after which insert ==> ");
				scanf("%d",&item);
				printf("\n\n\t Enter the element you want to insert ==> ");
				scanf("%d",&var);
				insa(item,var,p,start);
				break;
		  case '3':
				//clrscr();
				printf("\n\n\t Enter the number before which insert ==> ");
				scanf("%d",&item);
				printf("\n\n\t Enter the element you want to insert ==> " );
				scanf("%d",&var);
				start=insb(var,item,p,start);
				break;
		  case '4':
				//clrscr();
				printf("\n\n\t Enter the element you want to insert ==> " );
				scanf("%d",&item);
				inse(item,p,start);
				break;
		  case '5':
				//clrscr();
				printf("\n\n\t Enter the location on which insert ==> " );
				scanf("%d",&var);
				printf("\n\n\t Enter the element you want to insert ==> " );
				scanf("%d",&item);
				start=insp(item,var,p,start);
				break;
		  case '6':
				i=0;
				break;
			} // end of switch case block
		 } // end of loop block
	   return(start);
	  }



 node *delete1(node *start)
	 {
	  int i=1,item;
	  void dele(node *);

	  node *delf(node *),*delp(int,node*),*dell(int,node*);

	  while(i)
	    {
		//clrscr();
		fflush(stdin);
		printf("\n\t\t **** delete1 BLOCK ****\n");
		printf("\n\t 1. delete from the starting of linklist ");
		printf("\n\t 2. delete a particular node from Linklist");
		printf("\n\t 3. delete at the end of link list ");
		printf("\n\t 4. delete node from a particular locaton ");
		printf("\n\t 5. Exit to MAIN BLOCK");
		printf("\n\t     Enter your choice ออ ");
		ch=getche();

	  switch(ch)
		 {
		  case '1':
				//clrscr();
				start=delf(start);
				break;
		  case '2':
				//clrscr();
				printf("\n\n\t Enter the no. you want to delete ==> ");
				scanf("%d",&item);
				start=delp(item,start);
				break;
		  case '3':
				//clrscr();
				dele(start);
				break;
		  case '4':
				//clrscr();
				printf("\n\n\t Enter the location on which you want to insert==> ");
				scanf("%d",&item);
				start=dell(item,start);
				break;
		  case '5':
				i=0;
				break;
			}
		 }
	   return(start);
	  }


 node *delf(node *start)
   {
	node *tmp=start ;
	start=start->link;
	printf("\n\n\t Element is succesfully deleted ");
	getch();
	free(tmp) ;  // garbage collection
	return(start);
    }

 node *delp(int item,node *start)
    {
	node *temp,*temp1;

	for(temp=start;(temp->no != item) && (temp != NULL);temp=temp->link)
	    temp1=temp;

	if(temp==NULL)
	   {
		 printf("\n\n\t Number not found in the Linklist");
		 getch();
		 return(start);
	   }

	if(temp==start)
	   start=delf(start);

	else
	  {
		temp1->link=temp1->link->link;   /* temp1->link=temp->link */
		printf("\n\n\t Element is succesfully deleted ");
		getch();
		free(temp) ; // garbage collection
		return(start);
		   }
	 return(start);
	}

 void dele(node *start)
	{
	 node *temp,*temp1;
	 for(temp=start;temp->link != NULL;temp=temp->link)
	 temp1=temp;

	 temp1->link=NULL;
	 free(temp) ;      /* deallocate space being pointed to by temp */
	 printf("\n\n\t Element is succesfully deleted ");
	 getch();
	 return;
	}

 node *dell(int loc,node *start)
    {
	 node *new1,*temp,*temp1;
	 int i;
	 if(loc == 1)
	   {
	    start=delf(start);
	    return(start);
	   }
	 for(i=1,temp=start;i!=loc;i++,temp=temp->link)
	    temp1=temp;
	 if(temp == NULL)
		printf("\n\n\t No. is not present at this location ");
	 else
	    {
		temp1->link = temp1->link->link;
		printf("\n\n\t Element is succesfully Deleted ");
	    }
	  getch();
	  return(start);
	}

 void sort(node *start)
   {
    int no;
    node *temp,*ptr,*ptr1;
    for(ptr1=start;ptr1->link!=NULL;ptr1=ptr1->link)
	{
	 for(ptr=start;ptr->link!=NULL;ptr=ptr->link)
	 {
	  if(ptr->no > ptr->link->no)
	   {
		no=ptr->link->no;
		ptr->link->no=ptr->no;
		ptr->no=no;
	    }
	  }
	}
	//clrscr();
	printf("\n\n\n\t Link List is succesfully sorted ");
	printf("\n\n\t   Press any key to see it ");
	getch();
	return;
   }
int  main()
  {
node *start;
void print(node *),search(node *),sort(node *);
node *create(node *),*insert(node *), *delete1(node *);

	start=NULL;

	while(1)
	 {
	  //clrscr();
	  fflush(stdin);
	  printf("\n\t\t **** MAIN BLOCK ****\n");
	  printf("\n\t 1.  To Create the Linklist");
	  printf("\n\t 2.  To Display the Linklist");
	  printf("\n\t 3.  To Search an element from Linklist");
	  printf("\n\t 4.  To Insert element in the linklist");
	  printf("\n\t 5.  To delete1 element from the Linklist");
	  printf("\n\t 6.  To Sort the Linklist");
	  printf("\n\t 7.  To Exit ");
	  printf("\n\n\t   Enter your choice ==> ");
	  ch=getchar();

	  switch(ch)
		  {
			case '1':
			start=create(start) ;
			  break;
			case '2':
			  print(start);
			  break;
			case '3':
			  search(start);
			  break;
			case '4':
			  start=insert(start);
			  break;
			case '5':
			  start=delete1(start);
			  break;
			case '6':
			  sort(start);
			  print(start);
			  break;
			case '7':
			  exit(0);
			}
		}
	}

