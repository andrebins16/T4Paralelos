# T4Paralelos - Fractal de Newton

# Programa sequencial: newton_seq
## Compilação: gcc -o newton_seq newton_seq.c -lm
## Execução: ./newton_seq <multiplicador_de_trabalho>

# Programa so com mpi: newton_mpi
## Compilação: mpicc -o newton_mpi newton_mpi.c -lm  ||  ladcomp -env mpicc newton_mpi.c -o newton_mpi -lm
## Execução: mpirun -np <numero_de_nucleos> ./newton_mpi <multiplicador_de_trabalho>  ||  srun --exclusive -N 4 -n 5 ./newton_mpi <multiplicador_de_trabalho>

# Programa hibrido: newton_hybrid
## Compilação: mpicc -fopenmp -o newton_hybrid newton_hybrid.c -lm   ||   ladcomp -env mpicc -fopenmp newton_hybrid.c -o newton_hybrid -lm
## Execução: mpirun -np 5 ./newton_hybrid <multiplicador_de_trabalho> <num_threads_openmp>  ||  srun --exclusive -N 4 -n 5 ./newton_hybrid <multiplicador_de_trabalho> <num_threads_openmp>

# Programa hibrido otimizado: newton_optimized
## Compilação: mpicc -fopenmp -o newton_optimized newton_optimized.c -lm  ||   ladcomp -env mpicc -fopenmp newton_optimized.c -o newton_optimized -lm
## Execução: mpirun -np 5 ./newton_optimized <multiplicador_de_trabalho> <num_threads_openmp>  ||  srun --exclusive -N 4 -n 5 ./newton_optimized <multiplicador_de_trabalho> <num_threads_openmp>

# Programa para gerar gráficos
#$ Execução: python script_imagem_newton.py <arquivo_dados>