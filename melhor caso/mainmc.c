#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"

#define MAX 100000

int main() {
    clock_t start, end;
    double time_total;
    start = clock();
    int qnt = 0;
    Aluno *alunos[MAX];
    const char *nomeArquivo = "alunosOrd.txt";

    
    qnt = carregaAlunosDeArquivo(alunos, MAX, nomeArquivo);
    
    combSort(alunos, qnt);

    imprimeAlunos(alunos, qnt);


    printf("Alunos ordenados por matrícula!\n");

    salvaAlunosEmArquivo(alunos, qnt, nomeArquivo);

    for (int i = 0; i < qnt; i++) {
        free(alunos[i]);
    }
    end = clock(); 
    time_total = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos/n", time_total);

    return 0;
}

