#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
//#include <cstring>
#include <math.h>

#define mx 1002

int a[mx][mx];
int b[mx][mx];
int c[mx][mx];
int d[mx][mx];
void generate_matrix(int n)
{
  int i,j;
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
	a[i][j]=rand()%10;
	b[i][j]=rand()%10;
	printf("%d \t", a[i][j]);
	printf("%d \t", b[i][j]);	
     }
     printf("\n");
   }
}
//serial matrix multiplication
void matrix_mult_serial(int n)
{
	int i,j,k;
	double itime=omp_get_wtime();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
		          c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	double ftime=omp_get_wtime();
	printf("time elapsed in serial: %lf\n", ftime - itime);
}

//matrix multiplication where the two outermost loops are parallelized together with static scheduler
void matrix_mult_parallel1(int n)
{
	//Static Scheduler
	memset(d,0,sizeof d);
	int i,j,k;
	double itime=omp_get_wtime();
	#pragma omp parallel for schedule(static,50) collapse(2) private(i,j,k)shared(a,b,c)
	for(i=0;i<n;i++) 
	{
	  for( j=0;j<n;j++)
	  {
	     for(k=0;k<n;k++)
	     {
	        d[i][j]+=a[i][k]*b[k][j];
	     }
	  }
	}
	double ftime=omp_get_wtime();
	printf("time elapsed in parallel static scheduler %lf\n",ftime-itime);
	
}


void matrix_mult_parallel2(int n)
{
	//Dynamic Scheduler
	memset(d,0,sizeof d);
	int i,j,k;
	double itime=omp_get_wtime();
	#pragma omp parallel for schedule(dynamic,50) collapse(2) private(i,j,k) shared(a,b,c)
	for(i=0;i<n;i++) 
	{
	  for( j=0;j<n;j++)
	  {
	     for(k=0;k<n;k++)
	     {
	        d[i][j]+=a[i][k]*b[k][j];
	     }
	  }
	}
	double ftime=omp_get_wtime();
	printf("time elapsed in parallel dynamic scheduler %lf\n",ftime-itime);

}

//matrix multiplication where the two outermost loops are parallelized separately  
void matrix_mult_parallel3(int n)
{
	memset(d,0,sizeof d);
	double itime=omp_get_wtime();
	#pragma omp parallel for 
	for(int i=0;i<n;i++) 
	{
	#pragma omp parallel for 
	  for(int j=0;j<n;j++)
	  {
	     for(int k=0;k<n;k++)
	     {
	        d[i][j]+=a[i][k]*b[k][j];
	     }
	  }
	}
	double ftime=omp_get_wtime();
	printf("time elapsed in parallel dynamic scheduler %lf\n",ftime-itime);

}


int main() 
{
	int n=500;
	generate_matrix(n);
	matrix_mult_serial(n);
	
	matrix_mult_parallel1(n);
	
	matrix_mult_parallel2(n);
	matrix_mult_parallel3(n);

	return 0;
	
}