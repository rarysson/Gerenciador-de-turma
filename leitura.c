#include "leitura.h"
#include "aluno.h"
#include "interacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int erro_nome(char *nome);
int erro_matricula(char *matricula);
int erro_nota(char *nota);
int quantidade_caracteres(char* matricula);
void caracteres_min(char *nome);

char *le_nome(void){

    printf("\nDigite o nome: ");
    char *nome = le_string();

    if(erro_nome(nome)){ // se o numero retornar 1, fazendo verdade a condição, quer dizer que esta invalido.
        printf("\nNome invalido, digite novamente.");
        free(nome);
        return le_nome();
    }

    caracteres_min(nome); // pegara todo caractere maiusculo e transformara em minusculo.

return nome;
}

char* le_matricula(void){

    printf("\nDigite a matricula: ");
    char *matricula = le_string();

    if(!quantidade_caracteres(matricula)){ // se a quantidade não for exata vai retornar 0, com o uso do !, vai tornar verdadeira a condição.
            printf("\nQuantidade de caracteres errada."
                   "\nA quantidade de caracteres certa e: %d", CARACTERES_EM_MATRICULA);
            free(matricula);
            return le_matricula();
    }

    if(erro_matricula(matricula)){ // se for verdade, quer dizer que contem caracteres invalidos.
        printf("\nMatricula invalida.\nContem caractere invalido.");
        free(matricula);
        return le_matricula();
    }

return matricula;
}

float le_nota(void){

    printf("\nDigite a nota : ");
    char *nota = le_string();

    if(erro_nota(nota)){ // se for verdadeiro, quer dizer que digitou caracteres invalidos.
        printf("\nNumero invalido.");
        free(nota);
        return le_nota();
    }

    float num = atof(nota);
    free(nota);

    if((num < 0) || (num > 10)){
       printf("\nA nota esta errada.\nSo e suportado numeros entre 0.0 e 10.0");
       return le_nota();
    }

return num;
}

int erro_nome(char *nome){
    int i = 0;

    if(nome[i] == '\n') // quer dizer que o usuario digitou sem querer.
        return 1;

    while(nome[i] != '\0'){
        if(isdigit(nome[i])) // se for verdade, quer dizer que é um número.
            return 1;

        if(ispunct(nome[i])) // se for verdade, quer dizer que contem caracteres invalidos.
            return 1;

        i++;
    }

return 0;
}

void caracteres_min(char *nome){ // nessa função irá transformar os caracteres maiusculos em minusculos.
   int i = 0;

        while(nome[i] != '\0'){
            if(isupper(nome[i]))
                nome[i] = tolower(nome[i]);

            i++;
        }
}

int quantidade_caracteres(char* matricula){ //verifica se a quantidade digitada na matricula está certa
    int i = 0;

    while(matricula[i] != '\0')
        i++;

    if((i-1) == CARACTERES_EM_MATRICULA)
        return 1;

return 0;
}

int erro_matricula(char *matricula){
    int i = 0;

     while(matricula[i] != '\0'){
            if(isalpha(matricula[i])) // se for verdade, quer dizer que é uma letra.
                return 1;

            if(ispunct(matricula[i])) // se for verdade, quer dizer que é caractere de pontuação !@#$ por exemplo.
                return 1;

            if(isspace(matricula[i])){
                if(i == CARACTERES_EM_MATRICULA){
                    i++;
                    continue;
                }
                return 1;
            }

            i++;
        }

return 0;
}

int erro_nota(char *nota){
    int i = 0, total = strlen(nota);

    if(nota[i] == '\n') // quer dizer que o usuario digitou sem querer.
        return 1;

    while(nota[i] != '\0'){
        if(isalpha(nota[i])) // se for verdade, quer dizer que é uma letra.
            return 1;

        if(isspace(nota[i])){ // se for verdade quer dizer que contem espaços em branco na leitura.
            if(i == total-1){ // quer dizer que é o \n lido por ultimo, então não importa se for.
                i++;
                continue;
            }

            return 1;
        }

        if(ispunct(nota[i])){ // se for verdade, quer dizer que é caractere de pontuação !@#$ por exemplo.
            if(nota[i] == '.'){ // se for .(ponto) deve ser considerado, por causa de numeros reias.
                i++;
                continue;
            }

            return 1;
        }
        i++;
    }

return 0;
}
