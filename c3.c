#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SIZE 5000

double *A, *B, *C;

void mult(int n) {
   int i,j,k;
   for (i=0;i<n; i++)
      for (k=0;k<n; k++)
        for (j=0; j<n; j++)
            A[i*n+j] += B[i*n+k]* C[k*n+j];
}

int main() {

int i,j;
int n=SIZE;
struct timeval a,b;

A=(double*)malloc(sizeof(double)*SIZE*SIZE);
B=(double*)malloc(sizeof(double)*SIZE*SIZE);
C=(double*)malloc(sizeof(double)*SIZE*SIZE);

for (i=0;i<n; i++)
   for (j=0; j<n; j++) {
      A[i*n+j]=0.0;
      B[i*n+j] = C[i*n+j] = 1.0;
   }

gettimeofday(&a,NULL);
mult(SIZE);
gettimeofday(&b,NULL);

printf ("Total time = %f seconds\n",
         (double) (b.tv_usec - a.tv_usec) / 1000000 +
         (double) (b.tv_sec - a.tv_sec));

free(A);
free(B);
free(C);

}
