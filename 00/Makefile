.PHONY: compile-openmp
compile-openmp:
	@g++ -o open_mp -fopenmp open_mp.cpp

.PHONY: run-openmp
run-openmp:
	@OMP_NUM_THREADS=8 ./open_mp

.PHONY: compile-mpi
compile-mpi:
	@mpicc mpi.c -o mpi

.PHONY: run-mpi
run-mpi:
	@mpirun -np 8 ./mpi