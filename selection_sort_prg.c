 
// selection sort
#include <stdio.h>
int main()
{
	int arr[10],i,j,temp ;
	for (i=0;i<10;++i)
	{scanf("%d",&arr[i]);
	}
	
	for (i=0;i<9;++i)   // outer loop for passes
	{
		for (j=i+1;j<10;++j)   // inner loop for comparisons
		{
			if (arr[i]>arr[j])
			{
				temp=arr[i] ;
				arr[i]=arr[j];
				arr[j]=temp ;
						
			}
			
		}  // end of inner loop
		
	}    // end of outer loop
	
	// printnig the sorted array
	for (i=0;i<10;++i) 
	printf("a[%d] = %d\n",i,arr[i]);
	
	
}
