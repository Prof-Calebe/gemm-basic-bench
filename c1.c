#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SIZE 5000

double A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

void mult(int n) {
   int i,j,k;
   for (i=0;i<n; i++)
      for (j=0; j<n; j++)
        for (k=0;k<n; k++)
            A[i][j] += B[i][k]* C[k][j];
}

int main() {

int i,j;
int n=SIZE;
struct timeval a,b;

for (i=0;i<n; i++)
   for (j=0; j<n; j++) {
      A[i][j]=0.0;
      B[i][j] = C[i][j] = 1.0;
   }

gettimeofday(&a,NULL);
mult(SIZE);
gettimeofday(&b,NULL);

printf ("Total time = %f seconds\n",
         (double) (b.tv_usec - a.tv_usec) / 1000000 +
         (double) (b.tv_sec - a.tv_sec));

}
