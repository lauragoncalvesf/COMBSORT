#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    long int matricula;
    char nome[120];
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
        if (strcmp(alunos[i]->nome, "\n") == 1){
            printf("Tem uma linha vazia");
        }
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s", alunos[i]->nome);
        printf("Matrícula: %ld\n", alunos[i]->matricula);
        printf("---------------------\n");
    }
}

void combSort(Aluno **alunos, int qnt) {
    int gap = qnt;
    float fator = 1.3;
    int troca;

    while (gap > 1 || troca) { // C1 * n
        gap = (int)(gap / fator);
        if (gap < 1) gap = 1;

        troca = 0;

        for (int i = 0; i + gap < qnt; i++) { // C2 * n
            if (alunos[i]->matricula > alunos[i + gap]->matricula) {
                Aluno *temp = alunos[i];
                alunos[i] = alunos[i + gap];
                alunos[i + gap] = temp;
                troca = 1;
            }
        }
    }
}
/*COMPLEXIDADE DE TEMPO:
    O(n²)
*/

void salvaAlunosEmArquivo(Aluno **alunos, int qnt, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");  
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    for (int i = 0; i < qnt; i++) {
        
        fprintf(arquivo, "%ld\n", alunos[i]->matricula);
        fprintf(arquivo, "%s", alunos[i]->nome);
     
    }
    fclose(arquivo);
    printf("Alunos salvos com sucesso em %s!\n", nomeArquivo);
}

int carregaAlunosDeArquivo(Aluno **alunos, int maxAlunos, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r"); 
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
        fgets(alunos[qnt]->nome, 120, arquivo);
         qnt++;
    }
    fclose(arquivo);
    printf("Alunos carregados com sucesso de %s!\n", nomeArquivo);
    return qnt;
}
