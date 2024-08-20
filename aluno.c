#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"aluno.h"

struct aluno{
    long int matricula;
    char nome[50];
};

Aluno *criaAluno(int *qnt){
    Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
    if (aluno == NULL){
        printf("Erro na alocação!\n");
        exit(1);
    }
    (*qnt)++;
    return aluno;
}

void imprimeAlunos(Aluno **alunos, int qnt){
    for(int i = 0; i < qnt; i++){
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Matrícula: %ld\n", alunos[i]->matricula);
        printf("---------------------\n");
    }
}

void ordenaAlunosPorMatricula(Aluno **alunos, int qnt){
    for (int i = 0; i < qnt - 1; i++) {
        for (int j = 0; j < qnt - i - 1; j++) {
            if (alunos[j]->matricula > alunos[j + 1]->matricula) {
                Aluno *temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

void salvaAlunosEmArquivo(Aluno **alunos, int qnt, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");  
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    for (int i = 0; i < qnt; i++) {
        fprintf(arquivo, "%ld\n", alunos[i]->matricula);
        fprintf(arquivo, "%s\n", alunos[i]->nome);
    }
    fclose(arquivo);
    printf("Alunos salvos com sucesso em %s!\n", nomeArquivo);
}

int carregaAlunosDeArquivo(Aluno **alunos, int maxAlunos, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w"); 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 0;
    }

    int qnt = 0;
    while (!feof(arquivo) && qnt < maxAlunos) {
        alunos[qnt] = (Aluno *) malloc(sizeof(Aluno));
        if (alunos[qnt] == NULL) {
            printf("Erro na alocação!\n");
            exit(1);
        }
        fscanf(arquivo, "%ld\n", &alunos[qnt]->matricula);
        fgets(alunos[qnt]->nome, 50, arquivo);
        alunos[qnt]->nome[strcspn(alunos[qnt]->nome, "\n")] = '\0';  
        qnt++;
    }
    fclose(arquivo);
    printf("Alunos carregados com sucesso de %s!\n", nomeArquivo);
    return qnt;
}
