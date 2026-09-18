#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000000
#define STRIP_SIZE 64

int main() {
  double *A = (double *)malloc(N * sizeof(double));
  double *B = (double *)malloc(N * sizeof(double));
  double *C = (double *)malloc(N * sizeof(double));

  for (int i = 0; i < N; i++) {
    A[i] = 1.5;
    B[i] = 2.0;
  }

  double tstart = omp_get_wtime();

#pragma omp parallel for schedule(static)
  for (int i = 0; i < N; i += STRIP_SIZE) {
    int limit = (i + STRIP_SIZE > N) ? N : (i + STRIP_SIZE);
#pragma omp simd
    for (int j = i; j < limit; j++) {
      C[j] = A[j] * B[j];
    }
  }

  double tstop = omp_get_wtime();
  printf("Strip mining complete. C[0] = %f, C[N-1] = %f\n", C[0], C[N - 1]);
  printf("Time taken: %f seconds\n", tstop - tstart);

  free(A);
  free(B);
  free(C);
  return 0;
}
