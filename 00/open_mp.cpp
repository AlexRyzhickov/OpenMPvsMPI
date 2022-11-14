#include <stdio.h>
#include <omp.h>
int main() {
    int counts_threads = 0;
#pragma omp parallel
    {
        if (omp_get_thread_num() == 0) {
            counts_threads = omp_get_num_threads();
        }
    }
    int *arr = new int[counts_threads];
#pragma omp parallel
    {
        arr[omp_get_thread_num()] = omp_get_thread_num();
    }
    for (int i = 0; i < counts_threads; ++i) {
        printf("Hello from process  %d\n", arr[i]);
    }
    return 0;
}
