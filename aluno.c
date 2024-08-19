#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"aluno.h"

struct aluno{
    long int matricula, documento;
    char nome[50];
};

Aluno *criaAluno( int *qnt){
    Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
    if (aluno == NULL){
        printf("erro na alocacao!\n");
        exit(1);
    }
    printf("Informe a matricula:\n");
    scanf("%ld", &aluno->matricula);
    printf("Informe o nome do aluno:\n");
    scanf(" %[^\n]", aluno->nome);
    printf("Informe o documento:\n");
    scanf("%ld", &aluno->documento);
    return aluno;
    *qnt++;
    return aluno;
}

void imprimeAlunos (Aluno** alunos, int qnt){
    for(int i = 0; i < qnt; i++){
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Matricula: %ld\n", alunos[i]->matricula);
        printf("Documento: %ld\n", alunos[i]->documento);
        printf("---------------------\n");
    }
}