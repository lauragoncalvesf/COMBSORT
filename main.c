#include <stdio.h>
#include<stdlib.h>
#include "aluno.h"

#define MAX 10

int main(){
    int qnt = 0;
    int opcao;
    Aluno *alunos[MAX];
    alunos[qnt] = criaAluno(&qnt);
    alunos[qnt] = criaAluno(&qnt);
    alunos[qnt] = criaAluno(&qnt);
    alunos[qnt] = criaAluno(&qnt);
    alunos[qnt] = criaAluno(&qnt);

    imprimeAlunos(alunos, qnt);
    ordenaAlunosPorMatricula(alunos, qnt);

    return 0;
}