#include <stdlib.h>   
#include <stdio.h>    
#include <omp.h>   
#define n 9 

int main (int argc, char *argv[]) 
{

	int a[n];
	int b[n];
	int c[n];
     
	int i;     
	for(i=0; i<n; i++)
	{
        a[i] = i;
    }
    for(i=0; i<n; i++) 
	{
        b[i] = i;
    }   
        
	omp_set_num_threads(3);
	

	#pragma omp parallel  
        for(i=0; i<n; i++) 
		{
			c[i] = a[i]*b[i];
			printf("Thread %d works on element %d\n", omp_get_thread_num(), i);
        }
	
		printf("i\ta[i]\t*\tb[i]\t=\tc[i]\n");
        
		for(i=0; i<n; i++) 
		{
			printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
        }
	
	
	return 0;
}
