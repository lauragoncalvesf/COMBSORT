#include<stdio.h>
#include<stdlib.h>

typedef struct aluno Aluno;

Aluno *criaAluno( int *qnt);

void imprimeAlunos (Aluno** alunos, int qnt);

void combSort(Aluno **alunos, int qnt);

void salvaAlunosEmArquivo(Aluno **alunos, int qnt, const char *nomeArquivo);

int carregaAlunosDeArquivo(Aluno **alunos, int maxAlunos, const char *nomeArquivo);