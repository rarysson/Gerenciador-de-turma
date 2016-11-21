#include "turma.h"
#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct no{
    struct no *anterior;
    Aluno *estudante;
    struct no *proximo;
};

Turma turma_cria(void){
return NULL;
}

Turma turma_carrega(FILE* fp){
    Turma nova_turma = turma_cria();

    char *nome = (char*) malloc(86*sizeof(char)), *matricula = (char*) malloc(CARACTERES_EM_MATRICULA*sizeof(char));

    if(nome == NULL){
        printf("\nSem memoria.");
        exit(1);
    }

    if(matricula == NULL){
        printf("\nSem memoria.");
        exit(1);
    }

    float n1, n2, n3, med;

    while(fscanf(fp, "%*s %[^\n]s", nome) != EOF){
            fscanf(fp, "\n%*s %s"
                   "\n%*s %f %*s %f %*s %f"
                   "\n%*s %f", matricula, &n1, &n2, &n3, &med);

        Aluno *novo = aluno_cria(nome, matricula,  n1, n2, n3);

        nova_turma = turma_insere(nova_turma, novo);
    }

return nova_turma;
}

Turma turma_insere(Turma turma, Aluno* aluno){
    Turma novo = (Turma) malloc(sizeof(No));

    if(novo == NULL){
        printf("\nSem memoria.");
        exit(1);
    }

    if(turma == NULL){ // caso a turma esteja vazia
        novo->anterior = NULL;
        novo->estudante = aluno;
        novo->proximo = NULL;
    return novo;
    }

    Turma aux = turma, ultimo;

    // o laço seguirá até que o nome do "Aluno* aluno" seja menor que algum nome da lista.
    while(strcmp(aluno_nome(aluno), aluno_nome(aux->estudante)) > 0){
        ultimo = aux;
        aux = aux->proximo;

        if(aux == NULL)
            break;
    }

    if(aux == turma){ // caso seja para inserir como primeiro da lista
        novo->anterior = NULL;
        novo->estudante = aluno;
        novo->proximo = aux;
        aux->anterior = novo;
    return novo;
    } else if(aux == NULL){ // caso seja para inserir como ultimo da lista
        novo->estudante = aluno;
        novo->anterior = ultimo;
        novo->proximo = NULL;
        ultimo->proximo = novo;
    } else {
        novo->estudante = aluno;
        novo->anterior = aux->anterior;
        novo->proximo = aux;
        aux->anterior->proximo = novo;
        aux->anterior = novo;
    }

return turma;
}

No* turma_busca(Turma turma, char* matricula){
    No* aux = turma;

    if(turma == NULL)
        return NULL;

    while((strcmp(aluno_matricula(aux->estudante), matricula)) != 0){
        aux = aux->proximo;

        if(aux == NULL) // quer dizer que não achou a matricula.
            return NULL;
    }

return aux;
}

Turma turma_remove(Turma turma, char* matricula){
    Turma aux = turma;

     while((strcmp(aluno_matricula(aux->estudante), matricula)) != 0){
        aux = aux->proximo;

        if(aux == NULL){
            printf("\nA matricula nao esta presente.");
            return turma;
        }
    }

    if(aux == turma){ //caso seja a primeira posição da lista.
        turma = aux->proximo;
        aluno_libera(aux->estudante);
        free(aux);
    } else if(aux->proximo == NULL){ //caso seja a ultima posição da lista.
        aux->anterior->proximo = NULL;
        aluno_libera(aux->estudante);
        free(aux);
    } else {
        aux->anterior->proximo = aux->proximo;
        aux->proximo->anterior = aux->anterior;
        aluno_libera(aux->estudante);
        free(aux);
    }

return turma;
}

void turma_edita(No* no, char* nome, float nota1, float nota2, float nota3){
    aluno_edita(no->estudante, nome, nota1, nota2, nota3);
}

void turma_imprime(Turma turma){
    while(turma != NULL){
        aluno_imprime(turma->estudante);
        turma = turma->proximo;
    }
}

float turma_media(Turma turma){
    float media = 0, total = 0;

    while(turma != NULL){
        media += aluno_media(turma->estudante);
        total++;
        turma = turma->proximo;
    }

return media/total;
}

void turma_salva(FILE* fp, Turma turma){
    while(turma != NULL){
        fprintf(fp,"Aluno: %s"
                "\nMatricula: %s"
                "\nNota1: %.2f\tNota2: %.2f\tNota3: %.2f"
                "\nMedia: %.2f\n\n", aluno_nome(turma->estudante), aluno_matricula(turma->estudante),
                aluno_nota1(turma->estudante), aluno_nota2(turma->estudante), aluno_nota3(turma->estudante), aluno_media(turma->estudante));
        turma = turma->proximo;
    }
}
