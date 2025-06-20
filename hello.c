#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    char my_name[MPI_MAX_PROCESSOR_NAME];
    char master_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Get_processor_name(my_name, &name_len);

    // Rank 0 armazena seu hostname
    if (rank == 0) {
        strcpy(master_name, my_name);
    }

    // Broadcast do nome do mestre para todos os processos
    MPI_Bcast(master_name, MPI_MAX_PROCESSOR_NAME, MPI_CHAR, 0, MPI_COMM_WORLD);

    // Agora cada processo pode comparar seu hostname com o do mestre
    if (strcmp(my_name, master_name) == 0) {
        printf("Processo %d está na mesma máquina que o mestre (%s)\n", rank, my_name);
    } else {
        printf("Processo %d está em outra máquina (%s)\n", rank, my_name);
    }

    MPI_Finalize();
    return 0;
}
