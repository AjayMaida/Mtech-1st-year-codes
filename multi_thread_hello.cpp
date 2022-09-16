//header file for openMP(open multiprogramming)
#include<omp.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
//define the region of parallel programming
// by using the keyword
#pragma omp parallel 
{
int t_id=omp_get_thread_num();
printf("hello from thread %d\n",t_id);
}
return 0;
}