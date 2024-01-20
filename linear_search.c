 ///////////// Implementation Program of linear search  /////////////


#include<stdio.h>
#include<conio.h>
int main()
{
 int sc[10] , i ,val ;
 
 printf("\nEnter array elements:\n");
 for(i=0 ; i<10 ; i++)
  scanf("%d",&sc[i]);

 printf("\nenter number to find : ");
 scanf("%d",&val);

 for(i=0 ; i<10; i++)
  if(sc[i] == val)
    { printf("\nExists at location %d",i+1);  
        break;  //to exit from loop  
    } 

if(i==10 )
  printf("\n%d This value doesn not exist ");
 getch();
}


