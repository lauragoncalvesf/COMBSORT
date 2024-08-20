#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#define MAX 10

int main() {
    int qnt = 0;
    Aluno *alunos[MAX];
    const char *nomeArquivo = "aluno.txt";

    
    qnt = carregaAlunosDeArquivo(alunos, MAX, nomeArquivo);

    alunos[qnt] = criaAluno(&qnt);

    
    imprimeAlunos(alunos, qnt);

    ordenaAlunosPorMatricula(alunos, qnt);
    printf("Alunos ordenados por matrícula!\n");

    salvaAlunosEmArquivo(alunos, qnt, nomeArquivo);

    for (int i = 0; i < qnt; i++) {
        free(alunos[i]);
    }

    return 0;
}
