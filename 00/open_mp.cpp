#include <stdio.h>
#include <omp.h>
int main() {
    int counts_threads = omp_get_max_threads();
    int *arr = new int[counts_threads];
    omp_lock_t *mutexes = new omp_lock_t[counts_threads];
    for (int i = 0; i < counts_threads; ++i) {
        omp_init_lock(&mutexes[i]);
        omp_set_lock(&mutexes[i]);
    }
    omp_unset_lock(&mutexes[0]);
#pragma omp parallel
    {
        int id = omp_get_thread_num();
        omp_set_lock(&mutexes[id]);
        arr[id] = id;
        printf("Hello from process %d\n", arr[id]);
        omp_unset_lock(&mutexes[id + 1]);
    }
    return 0;
}
