
%%cu

#include<stdio.h>

__global__ void Factorial(int *gpunum,long int *gpures)
{
  int i;
 
  *gpures=1;
 
  for(i=1;i<=*gpunum;i++)
  {
    *gpures = *gpures * i;      
  }
}

int main()
{
  int Number = 5;   /*to store number on the host machine*/
  int *dev_number;
 
  long int *res, result;   

  
  /* to allocate memory for a number on the GPU/Device */
  cudaMalloc((void**)&dev_number,sizeof(int));
  cudaMalloc((void**)&res,sizeof(long int));
  
  /* copy number to the GPU/Device memory */
  cudaMemcpy(dev_number,&Number,sizeof(int),cudaMemcpyHostToDevice);
 
  /* call square function which will execute parallely on GPU */
  Factorial<<<5,2>>>(dev_number,res);

  /* copy result back from device/GPU back to CPU/Host */
  cudaMemcpy(&result,res,sizeof(long int),cudaMemcpyDeviceToHost);

  printf("\n\t Factorial of number %d is %ld \n",Number,result); 
 
  
  /* deallocate GPU/Device memory */
  cudaFree(dev_number);
  cudaFree(res);
 
  return 0; 
}