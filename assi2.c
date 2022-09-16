#include<omp.h>
#include<stdio.h>
int main(){
    #pragma omp parallel
    {
      printf("hello world\n");
      for(int i=0;i<10000;i++);
    }
}