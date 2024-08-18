#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"aluno.h"

struct aluno{
    char nome[50];
    long int matricula, documento;
};

Aluno *criaAluno(Aluno *aluno){
    aluno = (Aluno *) malloc(sizeof(Aluno));
    if (aluno == NULL){
        printf("erro na alocacao!\n");
        exit(1);
    }
    printf("Informe o nome do aluno:\n");
    scanf(" %[^\n]", aluno->nome);
    printf("Informe a matricula:\n");
    scanf("%ld", aluno->matricula);
    printf("Informe o documento:\n");
    scanf("%ld", aluno->documento);
}
