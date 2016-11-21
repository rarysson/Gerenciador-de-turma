#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

#define CARACTERES_EM_MATRICULA 5
typedef struct aluno Aluno;
Aluno* aluno_cria(char* nome, char* matricula, float nota1, float nota2, float nota3);
void aluno_imprime(Aluno* aluno);
void aluno_edita(Aluno* aluno, char* nome, float nota1, float nota2, float nota3);
char* aluno_nome(Aluno* aluno);
char* aluno_matricula(Aluno* aluno);
float aluno_nota1(Aluno* aluno);
float aluno_nota2(Aluno* aluno);
float aluno_nota3(Aluno* aluno);
float aluno_media(Aluno* aluno);
void aluno_libera(Aluno* aluno);

#endif // ALUNO_H_INCLUDED
