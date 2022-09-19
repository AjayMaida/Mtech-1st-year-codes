#include<omp.h>
#include<stdio.h>
#include<math.h>

int main(){
    int i=0,sum=0;
    int arr_siz=600;
    int arr[arr_siz];
    int step_siz=100;
    for(int i=0;i<arr_siz;i++)
    arr[i]=rand()%10;
    #pragma omp parallel
    {
        #pragma omp for
        for(int i=0;i<arr_siz;i+=step_siz)
        {
            int j,start=i,end=i+step_siz-1;
            printf("computing sum(%d , %d)from %d of %d\n",start,end,omp_get_thread_num(),omp_get_num_threads());
            #pragma omp task
            {
                int psum=0;
                printf("Task computing sum(%d,%d)from %d of %d \n",start,end,omp_get_thread_num(),omp_get_num_threads());
                for(j=start;j<=end;j++)
                psum+=arr[j];
                #pragma omp critical
                sum+=psum; 
            }
        }

    }
    printf("\nsum %d \n",sum);
}