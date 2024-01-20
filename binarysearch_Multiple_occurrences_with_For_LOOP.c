///// Binary search with multiple occurrences using for loop 
#include <stdio.h>
#include <conio.h>
int main()
{
  int a[10],lft=0,rt=9,md=(lft+rt)/2,val,i,temp ;
  for (i=0;i<10;i++)
  {
      scanf("%d",&a[i]) ;
      }
      printf("Enter the value to search") ;
      scanf("%d",&val) ;
      for(;lft<=rt;)
      {
  if (val>a[md])
  lft=md+1 ;
  else
  if (val<a[md])
  rt=md-1 ;
  else
  {
      printf("Found at location number = %d\n",md+1) ;
      temp=md+1 ;
      while(val==a[temp])
      {
	  printf("Found at location number = %d\n",temp+1) ;
	  ++temp;
	   if (temp==10)
	  break ;
	 
	 	   } // end of loop
	   
	  temp=md-1 ;
	  while(val==a[temp])
      {
	  printf("Found at location number = %d\n",temp+1) ;
	  --temp;
	  }  //end of loop
	  break ; // jumps out of the loop
      }    // end of else
      md=(lft+rt)/2 ;  // updating the value of md
      } // end of outer most loop
      if (lft>rt)
      printf("No Such element exists in the array") ;
      getch() ;
      }                    
