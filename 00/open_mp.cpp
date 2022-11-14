#include <stdio.h>
#include <omp.h>
int main() {
    printf("number %d\n", omp_get_num_threads());
#pragma omp parallel
    {
        printf("Thread %d from %d says \"Hello World!\"\n", omp_get_thread_num(), omp_get_num_threads());
    }
    printf("Finished.\n");
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
