#include <omp.h>
#include <stdio.h>

int main() {
  printf("--- Default Outer Loop Parallelization ---\n");
#pragma omp parallel for
  for (int r = 1; r <= 5; r++) {
    for (int k = 1; k <= 10; k++) {
      printf("r = %d, k = %d, thread # = %d\n", r, k, omp_get_thread_num());
    }
  }

  printf("\n--- Collapsed (2-level) Parallelization ---\n");
#pragma omp parallel for collapse(2)
  for (int r = 1; r <= 5; r++) {
    for (int k = 1; k <= 10; k++) {
      printf("r = %d, k = %d, thread # = %d\n", r, k, omp_get_thread_num());
    }
  }

  return 0;
}
