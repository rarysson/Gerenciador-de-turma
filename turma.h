#include <stdio.h>
#include "aluno.h"
#ifndef TURMA_H_INCLUDED
#define TURMA_H_INCLUDED

typedef struct no No;
typedef No* Turma;
Turma turma_cria(void);
Turma turma_carrega(FILE* fp);
Turma turma_insere(Turma turma, Aluno* aluno);
No* turma_busca(Turma turma, char* matricula);
Turma turma_remove(Turma turma, char* matricula);
void turma_edita(No* no, char* nome, float nota1, float nota2, float nota3);
void turma_imprime(Turma turma);
float turma_media(Turma turma);
void turma_salva(FILE* fp, Turma turma);

#endif // TURMA_H_INCLUDED
