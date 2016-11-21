#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct aluno{
    char nome[85];
    char matricula[CARACTERES_EM_MATRICULA];
    float nota1, nota2, nota3;
    float media;
};

Aluno* aluno_cria(char* nome, char* matricula, float nota1, float nota2, float nota3){
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));

        if(novo == NULL){
            printf("\nSem memoria desponivel");
            exit(1);
        }

    strcpy(novo->nome, nome);
    strcpy(novo->matricula, matricula);
    novo->nota1 = nota1;
    novo->nota2 = nota2;
    novo->nota3 = nota3;
    novo->media = (nota1 + nota2 + nota3) / 3;

return novo;
}

void aluno_imprime(Aluno* aluno){
    printf("\nNome: %s"
           "\nMatricula: %s"
           "\nPrimeira Nota: %.2f"
           "\nSegunda Nota: %.2f"
           "\nTerceira Nota: %.2f"
           "\nMedia das notas: %.2f\n",
           aluno->nome, aluno->matricula, aluno->nota1, aluno->nota2, aluno->nota3, aluno->media);
}

void aluno_edita(Aluno* aluno, char* nome, float nota1, float nota2, float nota3){
    strcpy(aluno->nome, nome);
    aluno->nota1 = nota1;
    aluno->nota2 = nota2;
    aluno->nota3 = nota3;
    aluno->media = (nota1 + nota2 + nota3) / 3;
}

char* aluno_nome(Aluno* aluno){
return aluno->nome;
}

char* aluno_matricula(Aluno* aluno){
return aluno->matricula;
}

float aluno_nota1(Aluno* aluno){
return aluno->nota1;
}

float aluno_nota2(Aluno* aluno){
return aluno->nota2;
}

float aluno_nota3(Aluno* aluno){
return aluno->nota3;
}

float aluno_media(Aluno* aluno){
return aluno->media;
}

void aluno_libera(Aluno* aluno){
free(aluno);
}
