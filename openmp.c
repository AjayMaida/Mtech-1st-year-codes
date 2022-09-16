#include<stdio.h>
#include<omp.h>
#include<pthread.h>

int main(){
    #pragma omp parallel 
    {
        int tid=omp_get_thread_num();
        int t_thread=omp_get_num_threads();
        printf("this is the thread no. %d and total thread is %d \n",tid,t_thread);
    }
}