# COMBSORT


<div>
<img align="right" width="110" height="170" src="https://assecom.ufersa.edu.br/wp-content/uploads/sites/24/2014/09/PNG-bras%C3%A3o-Ufersa.png">
<br>



## Como Funciona

*CombSort* é um algoritmo de ordenação que pode ser visto como uma melhoria sobre o *BubbleSort*. Ele funciona eliminando pequenos valores na extremidade direita que precisam ser trocados para a extremidade esquerda, o que aumenta o tamanho do passo (gap) usado para comparação.

O passo inicial (gap) é geralmente o tamanho do array dividido por um fator de encolhimento (geralmente 1.3). Após cada iteração, o passo é reduzido até que eventualmente se torne 1, onde o algoritmo então se comporta como um *BubbleSort*.

O algoritmo continua até que não haja mais trocas, o que indica que a lista está ordenada.

## Implementação

Aqui está um exemplo de como o *CombSort* pode ser implementado em C:

```c

void combSort(Aluno **alunos, int qnt) {
    int gap = qnt;
    float fator = 1.3;
    int troca;

    while (gap > 1 || troca) { //C1 * log n
        gap = (int)(gap / fator);
        if (gap < 1) gap = 1;

        troca = 0;

        for (int i = 0; i + gap < qnt; i++) { // C2 * n * log n
            if (alunos[i]->matricula > alunos[i + gap]->matricula) {
                Aluno *temp = alunos[i];
                alunos[i] = alunos[i + gap];
                alunos[i + gap] = temp;
                troca = 1;
            }
        }
    }
}

```



## Como rodar na minha maquina?

Primeiro Clone o repositorio na sua maquina:

```bash
git clone https://github.com/lauragoncalvesf/COMBSORT.git
```

Para executar você precisa navegar até o diretório onde o arquivo c se encontra, e no terminal use este comando:

```
gcc main.c -o main && ./main
```

  <h2 id="complexity" style="font-weight: bold; font-size: 2rem">Complexidade</h2>

### Pior Caso:


```

### Melhor Caso:


```

</div>
Contribuidores
<table> <tr> <td align="center"> <a href="#"> <img src="https://avatars.githubusercontent.com/u/162624679?v=4" width="100px;" alt="Fernanda Kipper Profile Picture"/><br> <sub> <a href="https://github.com/anavitoriaq"><b>Ana Vitória</b></a> </sub> </a> </td> <td align="center"> <a href="#"> <img src="https://avatars.githubusercontent.com/u/143735022?v=4" width="100px;" alt="Laura Gonçalves"/><br> <sub> <a href="https://github.com/lauragoncalvesf"><b>Laura Gonçalves</b></a> </sub> </a> </td> </tr> </table> ```