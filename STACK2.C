 /* Push and pop in stacks .... push stands for insert and pop stands for delete */   
  
#include <stdlib.h>
#include<stdio.h>
#include <conio.h>
#define MAX 5
typedef struct stack_node
   {
	 int arr[MAX];
	 int top;
   }node ;   // alias (second name)

 void push(int item,node *ptr)
   {
	if(ptr->top == MAX-1)
	   {
		printf("\n\n\t ******** Overflow *******");
		printf("\n\n\t Element can't be inserted into Stack ");
	   }
	else
	   {
		ptr->top++;
		ptr->arr[ptr->top]=item;
		printf("\n\n\t Element is pushed into Stack ");
	   }
	getch();
	
   }


void pop(node *ptr)
   {
	int item;
	
	if(ptr->top < 0)
	   printf("\n\n\t ******* Underflow *********");
	else
	  {
item=ptr->arr[ptr->top];	
ptr->top--;
printf("\n\n\t Element [ %d ] is poped from Stack ",item);
	  }
	getch();
	return ;
   }



int main()
  {
	int i,item;  char ch;
	node stack; // decl. of a structure variable
	stack.top=-1;  // empty
	while(1)
	  {
	//	clrscr();
system("cls") ;	
	printf("\n\n\t  ****** Main Menu ******\n");
		printf("\n\t Array representation of Stack");
		printf("\n\t =============================");
		printf("\n\n\t  1)  Push Operation on Stack");
		printf("\n\n\t  2)  Pop Operation on Stack");
		printf("\n\n\t  3)  Display Elements of Stack");
		printf("\n\n\t  4)  Exit from program");
		printf("\n\n\t  Enter your Choice :");
		fflush(stdin);
		scanf("%c",&ch);
		switch(ch)
		  {
		  case '1':
	printf("\n\n\t Enter the no. you want to add :");
	scanf("%d",&item);
	  push(item,&stack);
			  break;
		  case '2':
pop(&stack);
			 break;
		  case '3':
//			 clrscr();
			 printf("\n\n\t  ****** Display Block ******\n");
//			 disp(&stack);
			 break;
		  case '4':
			 exit(0);  // terminates the program
		  }
	    }  // END OF LOOP
	}


/******************** End of the Program ****************************/
