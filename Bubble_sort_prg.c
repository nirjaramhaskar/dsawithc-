 
//WAP of bubble sorting an array
#include<stdio.h>
#include<conio.h>
int main()
{
 int A[20] , i, j , temp ;
printf("\n enter array elements\n");
for(i=0 ; i<10 ; i++)
  scanf("%d",&A[i]);

for(i=0 ; i<9 ; i++)
  for( j = 0 ; j <10-1-i ; j++)
     if(A[j] > A[j+1] ) 
      {
         temp = A[j] ; 
         A[j] = A[j+1] ;
         A[j+1] = temp ; 
      }
printf("\n the sorted array elements\n");
for(i=0 ; i<10 ; i++)
  printf("\t%d\n",A[i]);
getch();
}

