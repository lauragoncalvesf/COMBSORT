typedef struct aluno Aluno;
/*função que aloca memória para struct */

Aluno *criaAluno( int *qnt);

void imprimeAlunos (Aluno** alunos, int qnt);

void ordenaAlunosPorMatricula(Aluno **alunos, int qnt);