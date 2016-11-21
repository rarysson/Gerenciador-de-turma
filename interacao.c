#include "interacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

int validacao_opcao(char *nome);

void apresenta_programa(char* msg){
    printf("%s", msg);
}

void mensagem_despedida(char* msg){
    printf("\n%s", msg);
}

void limpa_tela(void){
    system("cls || clear");
}

void limpa_buffer(void){
    setbuf(stdin, NULL);
}

int le_opcao(int menor_valor, int maior_valor){

    printf("\nDigite a opcao desejada: ");
    char *op = le_string();

    if(validacao_opcao(op)){ // se for verdade quer dizer que deu erro.
        printf("\nNumero invalido.");
        free(op);
        return le_opcao(menor_valor, maior_valor);
    }

    int opcao = atoi(op);
    free(op);

    if((opcao < menor_valor) || (opcao > maior_valor)){
        printf("\nOpcao invalida.");
        return le_opcao(menor_valor, maior_valor);
    }

return opcao;
}

char* le_string(void){
    char *caracteres = (char*) malloc(86*sizeof(char));

    if(caracteres == NULL){
        printf("\nSem memoria.");
        exit(1);
    }

    fgets(caracteres, 85, stdin);
    limpa_buffer();

return caracteres;
}

double le_double(void){
    double num;

    scanf("%lf", &num);

return num;
}

void apresenta_menu(int n_itens, int menor_opcao, ...){
    va_list menu;
    int i;

    va_start(menu, menor_opcao);

    for(i = 0; i < n_itens; i++)
        printf("\n%d - %s", menor_opcao++, va_arg(menu, char*));

    va_end(menu);
}

int validacao_opcao(char *nome){
    int i = 0;

    while(nome[i] != '\0'){

        if(isalpha(nome[i])) // se for verdade, quer dizer que é uma letra.
            return 1;

        if(ispunct(nome[i])) // se for verdade, quer dizer que é caractere de pontuação !@#$ por exemplo.
            return 1;

        i++;
    }

return 0;
}
